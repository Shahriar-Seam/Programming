from manim import *
import numpy as np

# ==========================================
# --- MATH ENGINE ---
# ==========================================

def orientation(p, q, r):
    """0=Collinear, 1=Clockwise, 2=Counter-Clockwise"""
    val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
    if abs(val) < 1e-9: return 0
    return 1 if val > 0 else 2

def on_segment(p, a, b):
    return (p[0] <= max(a[0], b[0]) and p[0] >= min(a[0], b[0]) and
            p[1] <= max(a[1], b[1]) and p[1] >= min(a[1], b[1]))

def do_intersect(p1, q1, p2, q2):
    o1 = orientation(p1, q1, p2)
    o2 = orientation(p1, q1, q2)
    o3 = orientation(p2, q2, p1)
    o4 = orientation(p2, q2, q1)

    if o1 != o2 and o3 != o4: return True
    if o1 == 0 and on_segment(p2, p1, q1): return True
    if o2 == 0 and on_segment(q2, p1, q1): return True
    if o3 == 0 and on_segment(p1, p2, q2): return True
    if o4 == 0 and on_segment(q1, p2, q2): return True
    return False

def get_intersection_point(p1, q1, p2, q2):
    """Calculates exact (x,y) intersection of lines p1q1 and p2q2"""
    # Line 1: a1*x + b1*y = c1
    a1 = q1[1] - p1[1]
    b1 = p1[0] - q1[0]
    c1 = a1*(p1[0]) + b1*(p1[1])
    
    # Line 2: a2*x + b2*y = c2
    a2 = q2[1] - p2[1]
    b2 = p2[0] - q2[0]
    c2 = a2*(p2[0]) + b2*(p2[1])
    
    determinant = a1*b2 - a2*b1
    
    if abs(determinant) < 1e-9: return None # Parallel
    
    x = (b2*c1 - b1*c2)/determinant
    y = (a1*c2 - a2*c1)/determinant
    return np.array([x, y, 0])

# ==========================================
# --- DATA OBJECTS ---
# ==========================================

class Segment:
    def __init__(self, x1, y1, x2, y2, id, color):
        self.id = id
        self.color = color
        self.p1 = np.array([x1, y1, 0])
        self.p2 = np.array([x2, y2, 0])
        
        # Define Left/Right for Sweep Line logic
        # If vertical, bottom is "start" for logic, but we handle sorting carefully
        if x1 < x2:
            self.left, self.right = self.p1, self.p2
        elif x1 > x2:
            self.left, self.right = self.p2, self.p1
        else:
            # Vertical: sort by Y to define range
            if y1 < y2:
                self.left, self.right = self.p1, self.p2
            else:
                self.left, self.right = self.p2, self.p1
        
        # Equation properties
        dx = self.right[0] - self.left[0]
        if abs(dx) < 1e-9:
            self.is_vertical = True
            self.slope = None
            self.intercept = None
        else:
            self.is_vertical = False
            self.slope = (self.right[1] - self.left[1]) / dx
            self.intercept = self.left[1] - self.slope * self.left[0]
            
        # Visual placeholders
        self.vis_line = None
        self.vis_group = None

    def get_y(self, x):
        """Returns Y at given X. For vertical lines, returns MAX Y to keep it sorted high."""
        if self.is_vertical: return max(self.left[1], self.right[1])
        return self.slope * x + self.intercept

# ==========================================
# --- MAIN SCENE ---
# ==========================================

class USACO_Ultimate_Solution(Scene):
    def construct(self):
        # 1. SETUP UI
        self.setup_ui()
        
        # 2. INIT DATA
        # Problem Input:
        # 1: 2 1 6 1 (Horiz)
        # 2: 4 0 1 5 (Diag)
        # 3: 5 6 5 5 (Vert)
        # 4: 2 7 1 3 (Diag)
        raw_data = [
            (2, 1, 6, 1, RED),
            (4, 0, 1, 5, BLUE),
            (5, 6, 5, 5, GREEN),
            (2, 7, 1, 3, ORANGE)
        ]
        
        self.segments = []
        for i, (x1, y1, x2, y2, col) in enumerate(raw_data):
            self.segments.append(Segment(x1, y1, x2, y2, i+1, col))

        # 3. PLOT GRAPH
        self.plot_graph()
        
        # 4. SWEEP LINE (Find collision)
        culprit_candidates = self.run_sweep_algorithm()
        
        # 5. THE TRIAL (Find which candidate is the culprit)
        if culprit_candidates:
            self.run_culprit_trial(culprit_candidates)
            
        self.wait(3)

    # ----------------------------------------
    # UI SETUP
    # ----------------------------------------
    def setup_ui(self):
        # Zones
        self.zone_graph = Rectangle(height=6, width=7.5).to_corner(UL).shift(DOWN*0.5).set_opacity(0)
        self.zone_data = Rectangle(height=6, width=5).to_corner(UR).shift(DOWN*0.5).set_opacity(0)
        
        # Log Box
        self.log_bg = Rectangle(height=1.5, width=13, color=GRAY, fill_opacity=0.2).to_edge(DOWN)
        self.log_text = Text("Initializing...", font_size=22).move_to(self.log_bg)
        
        # Header
        self.header = Text("USACO Cow Steeplechase II", font_size=32).to_edge(UP)
        
        self.add(self.log_bg, self.log_text, self.header, self.zone_data)
        
        # Groups for cleanup
        self.active_set_visuals = VGroup()

    def log(self, text, col=WHITE, wait=0.8):
        new_text = Text(text, font_size=22, color=col, font="Consolas").move_to(self.log_bg)
        self.play(Transform(self.log_text, new_text), run_time=0.4)
        self.wait(wait)

    # ----------------------------------------
    # GRAPH PLOTTING
    # ----------------------------------------
    def plot_graph(self):
        self.log("Step 1: Plotting Segments...")
        
        # Coordinate System
        self.plane = NumberPlane(
            x_range=[0, 7, 1], y_range=[0, 8, 1],
            background_line_style={"stroke_opacity": 0.3}
        ).scale(0.65).move_to(self.zone_graph)
        
        lbls = self.plane.get_axis_labels(x_label="x", y_label="y").scale(0.6)
        self.add(self.plane, lbls)
        
        # Draw Lines
        for s in self.segments:
            p1 = self.plane.c2p(*s.p1)
            p2 = self.plane.c2p(*s.p2)
            
            line = Line(p1, p2, color=s.color, stroke_width=4)
            
            # Label
            mid = line.get_center()
            lbl = Text(str(s.id), font_size=16, weight=BOLD, color=s.color)\
                .next_to(mid, UP, buff=0.1).add_background_rectangle(opacity=0.6, buff=0.05)
                
            s.vis_line = line
            s.vis_group = VGroup(line, lbl, Dot(p1, radius=0.05, color=s.color), Dot(p2, radius=0.05, color=s.color))
            
            self.play(Create(s.vis_group), run_time=0.5)
            self.add(s.vis_group)
            
        self.log("Segments plotted. Ready for Sweep Line.")

    # ----------------------------------------
    # SWEEP LINE ALGORITHM
    # ----------------------------------------
    def run_sweep_algorithm(self):
        self.log("Step 2: Sweep Line (Left -> Right)")
        
        # 1. Events (x, type, index)
        # Type 0=Start, 1=End. 
        # Sort key: x first. If x equal, Start(0) processed before End(1)
        events = []
        for i, s in enumerate(self.segments):
            events.append((s.left[0], 0, i))
            events.append((s.right[0], 1, i))
        events.sort(key=lambda e: (e[0], e[1]))
        
        # 2. Visuals
        sweep_x = ValueTracker(0)
        sweep_line = always_redraw(lambda: DashedLine(
            self.plane.c2p(sweep_x.get_value(), 0, 0),
            self.plane.c2p(sweep_x.get_value(), 8, 0),
            color=YELLOW
        ))
        self.add(sweep_line)
        
        active_indices = []
        
        # Update Table Helper
        def update_table(curr_x):
            # Sort by Y
            active_indices.sort(key=lambda idx: self.segments[idx].get_y(curr_x), reverse=True)
            
            new_grp = VGroup()
            title = Text("ACTIVE SET (Y-Sorted)", font_size=20, color=YELLOW, weight=BOLD)
            new_grp.add(title)
            
            for idx in active_indices:
                s = self.segments[idx]
                val = s.get_y(curr_x)
                entry = Text(f"#{s.id}: y≈{val:.1f}", font_size=18, color=s.color, font="Consolas")
                new_grp.add(entry)
            
            new_grp.arrange(DOWN, aligned_edge=LEFT)
            new_grp.move_to(self.zone_data.get_top() + DOWN*1.0)
            
            if len(self.active_set_visuals) > 0:
                self.remove(self.active_set_visuals)
            self.active_set_visuals = new_grp
            self.add(self.active_set_visuals)

        # Check Neighbors Helper
        def check(idx1, idx2):
            s1, s2 = self.segments[idx1], self.segments[idx2]
            self.log(f"Checking Neighbors: #{s1.id} vs #{s2.id}...", wait=0.5)
            
            # Highlight
            self.play(
                s1.vis_line.animate.set_stroke(width=9, opacity=0.8),
                s2.vis_line.animate.set_stroke(width=9, opacity=0.8),
                rate_func=there_and_back, run_time=0.6
            )
            
            if do_intersect(s1.p1, s1.p2, s2.p1, s2.p2):
                self.log(f"INTERSECTION FOUND: #{s1.id} & #{s2.id}", RED, wait=1.5)
                
                # Show intersection point
                pt = get_intersection_point(s1.p1, s1.p2, s2.p1, s2.p2)
                if pt is not None:
                    vis_pt = self.plane.c2p(*pt)
                    dot = Dot(vis_pt, color=YELLOW, radius=0.1).set_z_index(10)
                    flash = Circle(color=RED).move_to(vis_pt).scale(0)
                    self.play(Create(dot), flash.animate.scale(2).set_opacity(0), run_time=1)
                
                return True
            return False

        # 3. Execution Loop
        for x, type, idx in events:
            self.play(sweep_x.animate.set_value(x), run_time=0.8)
            s = self.segments[idx]
            
            if type == 0: # Insert
                self.log(f"Start of #{s.id}. Adding to Set.")
                active_indices.append(idx)
                update_table(x)
                
                # Check neighbors
                pos = active_indices.index(idx)
                if pos > 0:
                    if check(idx, active_indices[pos-1]): return (idx, active_indices[pos-1])
                if pos < len(active_indices) - 1:
                    if check(idx, active_indices[pos+1]): return (idx, active_indices[pos+1])
                    
            else: # Remove
                self.log(f"End of #{s.id}. Removing.")
                
                # Find neighbors before deleting
                pos = active_indices.index(idx)
                upper = active_indices[pos-1] if pos > 0 else None
                lower = active_indices[pos+1] if pos < len(active_indices)-1 else None
                
                active_indices.remove(idx)
                update_table(x)
                
                if upper is not None and lower is not None:
                    self.log(f"#{s.id} removed. New neighbors formed.")
                    if check(upper, lower): return (upper, lower)
        
        return None

    # ----------------------------------------
    # CULPRIT TRIAL
    # ----------------------------------------
    def run_culprit_trial(self, pair):
        idx1, idx2 = pair
        s1, s2 = self.segments[idx1], self.segments[idx2]
        
        self.log("Step 3: The Trial. Finding the Culprit.", YELLOW)
        self.play(FadeOut(self.active_set_visuals))
        
        # Setup scoreboard
        score_grp = VGroup()
        header = Text("INTERSECTION COUNTER", font_size=20, color=YELLOW, weight=BOLD)
        s1_txt = Text(f"Seg #{s1.id}: 0", font_size=24, color=s1.color)
        s2_txt = Text(f"Seg #{s2.id}: 0", font_size=24, color=s2.color)
        score_grp.add(header, s1_txt, s2_txt).arrange(DOWN, aligned_edge=LEFT).move_to(self.zone_data)
        self.add(score_grp)
        
        # Helper to update score
        def update_score(idx_local, count):
            new_txt = Text(f"Seg #{self.segments[idx_local].id}: {count}", font_size=24, color=self.segments[idx_local].color)
            target = s1_txt if idx_local == idx1 else s2_txt
            new_txt.move_to(target.get_center(), aligned_edge=LEFT)
            self.play(Transform(target, new_txt), run_time=0.2)

        # COUNT FOR S1
        c1 = 0
        self.log(f"Checking #{s1.id} against ALL others...")
        for i, other in enumerate(self.segments):
            if i == idx1: continue
            if do_intersect(s1.p1, s1.p2, other.p1, other.p2):
                c1 += 1
                self.play(other.vis_line.animate.set_color(WHITE), rate_func=there_and_back, run_time=0.3)
                update_score(idx1, c1)
        
        # COUNT FOR S2
        c2 = 0
        self.log(f"Checking #{s2.id} against ALL others...")
        for i, other in enumerate(self.segments):
            if i == idx2: continue
            if do_intersect(s2.p1, s2.p2, other.p1, other.p2):
                c2 += 1
                self.play(other.vis_line.animate.set_color(WHITE), rate_func=there_and_back, run_time=0.3)
                update_score(idx2, c2)

        # VERDICT
        culprit = None
        if c1 > c2:
            self.log(f"#{s1.id} causes more collisions.", GREEN)
            culprit = s1
        elif c2 > c1:
            self.log(f"#{s2.id} causes more collisions.", GREEN)
            culprit = s2
        else:
            culprit = s1 if s1.id < s2.id else s2
            self.log(f"Tie! Removing smaller ID: #{culprit.id}", GREEN)

        self.log(f"FINAL VERDICT: Remove Segment #{culprit.id}", RED, wait=2)
        
        # Eliminate
        box = SurroundingRectangle(culprit.vis_group, color=RED, buff=0.1)
        self.play(Create(box))
        self.play(FadeOut(culprit.vis_group), FadeOut(box), run_time=2)
        
        self.log("Solution Complete. Graph Valid.", GREEN)