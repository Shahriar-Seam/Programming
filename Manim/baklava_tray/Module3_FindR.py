from manim import *
from baklava_config import *

class Module3_FindR(Scene):
    def construct(self):
        # --- SETUP ---
        setup_camera(self)
        self.subtitle = VGroup()
        
        # Position constants
        LEFT_SIDE = LEFT * 3.5 + DOWN * 0.5
        RIGHT_SIDE = RIGHT * 3.0 
        
        # --- SECTION 1: THE FULL SHAPE & ANGLES ---
        self.play_subtitle("We need to find 'R', the shrinkage factor.")
        
        # Create Hexagon
        r = 2.5
        hexagon = get_regular_polygon(6, r, color=CRUST_COLOR)
        # Rotate PI/2 (90 deg) to put vertex 0 at the absolute TOP
        hexagon.rotate(PI/2) 
        hexagon.set_fill(NUT_PALETTE[0], opacity=0.3)
        
        # Labels
        vertices = hexagon.get_vertices()
        top_vertex = vertices[0]  # Top (90 deg)
        top_left_vertex = vertices[1] # Top-Left (150 deg)
        bot_left_vertex = vertices[2] # Bottom-Left (210 deg)
        right_vertex = vertices[5] # Top-Right (30 deg)
        
        # Brace on Left Vertical Edge (Vertex 1 to 2)
        brace_s = Brace(Line(top_left_vertex, bot_left_vertex), buff=0.1, direction=LEFT)
        label_s = brace_s.get_text("S").set_color(BAKLAVA_GOLD)
        
        self.play(DrawBorderThenFill(hexagon), FadeIn(brace_s), FadeIn(label_s))
        self.wait(1)

        # --- GOAL DEFINITION & STRATEGY ---
        self.play_subtitle("Our specific goal is to find the new side length 'C'.")
        
        # Visualize the target side (The Cut)
        mid_right = (top_vertex + right_vertex) / 2
        mid_left = (top_vertex + top_left_vertex) / 2
        
        goal_line = Line(mid_left, mid_right, color=RED, stroke_width=6)
        goal_label = MathTex("C", color=RED).next_to(goal_line, DOWN, buff=0.1)
        
        self.play(Create(goal_line), Write(goal_label))
        self.wait(2)

        # Highlighting Knowns
        self.play_subtitle("We know the two adjacent sides are exactly S/2.")
        
        side_a = Line(top_vertex, mid_right, color=BAKLAVA_GOLD, stroke_width=6)
        side_b = Line(top_vertex, mid_left, color=BAKLAVA_GOLD, stroke_width=6)
        
        # Labels for known sides
        # Using simple offsets for clarity in full view
        lbl_a = MathTex("S/2", color=BAKLAVA_GOLD).scale(0.7).next_to(side_a, RIGHT, buff=0.05).shift(UP*0.2)
        lbl_b = MathTex("S/2", color=BAKLAVA_GOLD).scale(0.7).next_to(side_b, LEFT, buff=0.05).shift(UP*0.2)

        self.play(Create(side_a), Create(side_b), Write(lbl_a), Write(lbl_b))
        self.wait(2)

        # Highlighting Missing Angle
        self.play_subtitle("If we find the angle between them...")
        
        unknown_arc = Arc(radius=0.5, start_angle=210*DEGREES, angle=120*DEGREES, arc_center=top_vertex, color=YELLOW)
        lbl_angle = MathTex("?").next_to(unknown_arc, 0, buff=0.05).shift(UP*0.1)
        
        self.play(Create(unknown_arc), Write(lbl_angle))
        self.wait(2)

        # Stating the Strategy
        self.play_subtitle("...we can use the Law of Cosines to solve for C.")
        
        strategy_text = create_text("Strategy: Law of Cosines", scale=0.6).to_corner(UR).set_color(BAKLAVA_GOLD)
        self.play(FadeIn(strategy_text))
        self.wait(3)
        
        # Clear specific highlighting visuals to proceed with proof
        self.play(
            FadeOut(goal_line), FadeOut(goal_label),
            FadeOut(side_a), FadeOut(side_b), FadeOut(lbl_a), FadeOut(lbl_b),
            FadeOut(unknown_arc), FadeOut(lbl_angle), FadeOut(strategy_text)
        )
        
        # --- GEOMETRIC PROOF: 360 / N ---
        self.play_subtitle("So... what is this exterior angle?")
        
        # Visualizing the "Walk"
        path = hexagon.copy().set_fill(opacity=0)
        walker = Dot(color=YELLOW).move_to(vertices[0])
        
        self.play(FadeIn(walker))
        self.play(MoveAlongPath(walker, path), run_time=3, rate_func=linear)
        
        self.play_subtitle("One full lap around the shape is a 360 degree turn.")
        self.wait(2)
        
        # Show exterior angles popping up
        ext_lines = VGroup()
        ext_arcs = VGroup()
        for i in range(6):
            v = vertices[i]
            prev = vertices[i-1] # python handles -1 index correctly
            
            # Extension line (extend the previous side forward)
            direction = normalize(v - prev)
            line = DashedLine(v, v + direction * 1.0, color=GREY)
            ext_lines.add(line)
            
            # Arc
            angle_in = angle_of_vector(direction)
            arc = Arc(radius=0.4, start_angle=angle_in, angle=PI/3, arc_center=v, color=YELLOW)
            ext_arcs.add(arc)

        self.play(Create(ext_lines), Create(ext_arcs))
        self.play_subtitle("There are N corners. So each turn is 360 divided by N.")
        
        # Formula for Exterior Angle
        theta_eq = MathTex("\\theta_{ext} = \\frac{360^{\\circ}}{N}").scale(0.8).to_edge(UP).shift(RIGHT * 2)
        self.play(Write(theta_eq))
        self.wait(2)
        
        self.play_subtitle("The interior angle, Alpha, is 180 minus that.")
        
        # Focus on Top Vertex
        self.play(
            FadeOut(walker), FadeOut(path), 
            FadeOut(ext_lines[1:]), FadeOut(ext_arcs[1:]), # Keep top one (index 0)
            FadeOut(theta_eq)
        )
        
        # Label Alpha (Inside Top Vertex)
        alpha_arc = Arc(
            radius=0.6,
            start_angle= 210 * DEGREES, 
            angle= 120 * DEGREES,
            arc_center=top_vertex,
            color=RED
        )
        
        alpha_label = MathTex("\\alpha").next_to(alpha_arc, DOWN, buff=0.1)
        
        alpha_eq = MathTex("\\alpha = 180^{\\circ} - \\frac{360^{\\circ}}{N}").scale(0.8).to_edge(UP).shift(RIGHT * 2)
        
        self.play(Create(alpha_arc), Write(alpha_label), Write(alpha_eq))
        self.wait(2)
        
        # --- SECTION 2: THE "CUT & ZOOM" ---
        self.play_subtitle("Let's isolate the top corner to solve for 'C'.")
        
        # Define the triangle visually
        # Reuse midpoints from before
        cut_triangle = Polygon(top_vertex, mid_right, mid_left, color=WHITE, fill_color=NUT_PALETTE[0], fill_opacity=0.5)
        cut_line = Line(mid_left, mid_right, color=RED, stroke_width=4)
        
        # Create a "Zoomed" version for the left side
        # Scale factor approx 2.5
        zoomed_scale = 2.5
        zoomed_tri = cut_triangle.copy().scale(zoomed_scale).move_to(LEFT_SIDE)
        zoomed_cut_line = cut_line.copy().scale(zoomed_scale).move_to(zoomed_tri.get_bottom())
        
        # Labels for Zoomed Version
        vertices_z = zoomed_tri.get_vertices()
        z_top = vertices_z[0]
        z_mr = vertices_z[1] # Right Midpoint (visually on right)
        z_ml = vertices_z[2] # Left Midpoint
        
        # Right Label (Slope is negative -30 deg)
        mid_z_right = (z_top + z_mr) / 2
        norm_right = np.array([np.cos(PI/3), np.sin(PI/3), 0])
        lbl_s2_right = MathTex("S/2", color=BAKLAVA_GOLD).scale(0.8).rotate(-PI/6)
        lbl_s2_right.move_to(mid_z_right + norm_right * 0.3)
        
        # Left Label (Slope is positive 210 deg or -150 deg)
        mid_z_left = (z_top + z_ml) / 2
        norm_left = np.array([np.cos(2*PI/3), np.sin(2*PI/3), 0])
        lbl_s2_left = MathTex("S/2", color=BAKLAVA_GOLD).scale(0.8).rotate(PI/6)
        lbl_s2_left.move_to(mid_z_left + norm_left * 0.3)
        
        lbl_c = MathTex("C", color=RED).next_to(zoomed_cut_line, DOWN)
        
        # Alpha on zoomed
        z_alpha = alpha_label.copy().next_to(z_top, DOWN, buff=0.5)
        
        # Transition: Fade out old, Transform to new
        self.play(
            FadeOut(hexagon), FadeOut(brace_s), FadeOut(label_s), 
            FadeOut(ext_lines), FadeOut(ext_arcs), FadeOut(alpha_eq),
            FadeOut(alpha_arc), FadeOut(alpha_label),
            ReplacementTransform(cut_triangle, zoomed_tri),
            ReplacementTransform(cut_line, zoomed_cut_line)
        )
        
        self.play(
            Write(lbl_s2_right), Write(lbl_s2_left), Write(lbl_c), Write(z_alpha)
        )
        self.wait(1)
        
        # --- SECTION 3: LAW OF COSINES (EXTENSIVE) ---
        self.play_subtitle("We use the Law of Cosines to find side C.")
        
        # 1. Standard Formula
        eq1 = MathTex("C^2 = a^2 + b^2 - 2ab\\cos(\\alpha)").scale(0.8).move_to(RIGHT_SIDE + UP * 2)
        self.play(Write(eq1))
        self.wait(2)
        
        # 2. Substitution
        self.play_subtitle("Substitute the side lengths (S/2).")
        eq2 = MathTex("C^2 = (S/2)^2 + (S/2)^2 - 2(S/2)(S/2)\\cos(\\alpha)").scale(0.8).next_to(eq1, DOWN)
        self.play(Write(eq2))
        self.wait(2)
        
        # 3. Expansion
        self.play_subtitle("Expand the squares.")
        eq3 = MathTex("C^2 = \\frac{S^2}{4} + \\frac{S^2}{4} - 2(\\frac{S^2}{4})\\cos(\\alpha)").scale(0.8).next_to(eq2, DOWN)
        self.play(Write(eq3))
        self.wait(2)
        
        # 4. Simplification
        self.play_subtitle("Combine terms.")
        eq4 = MathTex("C^2 = \\frac{S^2}{2} - \\frac{S^2}{2}\\cos(\\alpha)").scale(0.8).next_to(eq3, DOWN)
        self.play(
            FadeOut(eq1), FadeOut(eq2), # Clear space
            ReplacementTransform(eq3, eq4)
        )
        # Move eq4 up
        self.play(eq4.animate.move_to(RIGHT_SIDE + UP * 1))
        self.wait(2)
        
        # 5. Factoring
        self.play_subtitle("Factor out S squared over 2.")
        eq5 = MathTex("C^2 = \\frac{S^2}{2} (1 - \\cos(\\alpha))").scale(0.8).next_to(eq4, DOWN)
        self.play(Write(eq5))
        self.play(Indicate(eq5, color=BAKLAVA_GOLD))
        self.wait(2)
        
        # --- SECTION 4: CALCULATING R ---
        self.play_subtitle("Now we find R, the Ratio of Areas.")
        
        # Clear math space
        self.play(FadeOut(eq4), FadeOut(eq5))
        
        # Definition
        r_def = MathTex("R = \\frac{\\text{New Area}}{\\text{Old Area}}").scale(0.8).move_to(RIGHT_SIDE + UP * 2)
        self.play(Write(r_def))
        
        # Side Squared Proportionality
        self.play_subtitle("Area is proportional to side length squared.")
        r_sides = MathTex("R = \\frac{C^2}{S^2}").scale(0.8).next_to(r_def, DOWN)
        self.play(Write(r_sides))
        self.wait(2)
        
        # Substitution
        self.play_subtitle("Substitute our formula for C squared.")
        
        r_sub = MathTex("R = \\frac{ \\frac{S^2}{2}(1 - \\cos \\alpha) }{ S^2 }").scale(0.8).next_to(r_sides, DOWN)
        self.play(Write(r_sub))
        self.wait(2)
        
        # Cancellation (No lines shown)
        self.play_subtitle("The S squared terms cancel out!")
        self.wait(1)
        
        # Final Result
        r_final = MathTex("R = \\frac{1 - \\cos(\\alpha)}{2}").scale(1.2).move_to(RIGHT_SIDE)
        r_final.set_color(BAKLAVA_GOLD)
        
        self.play(
            FadeOut(r_def), FadeOut(r_sides), FadeOut(r_sub),
            ReplacementTransform(r_sub.copy(), r_final) # visual continuity
        )
        self.play(Circumscribe(r_final, color=WHITE))
        self.wait(3)
        
        self.play_subtitle("We have the formula for R. Next: Trigonometry!")
        self.wait(3)

    # Helper for subtitles (Standard Scene)
    def play_subtitle(self, text_str):
        new_sub = create_text(text_str, scale=0.7).to_edge(DOWN, buff=0.5)
        bg = SurroundingRectangle(new_sub, color=BLACK, fill_color=BLACK, fill_opacity=0.8, buff=0.2)
        bg.set_stroke(width=0)
        sub_group = VGroup(bg, new_sub)
        
        if len(self.subtitle) > 0:
            self.play(Transform(self.subtitle, sub_group), run_time=0.5)
        else:
            self.subtitle = sub_group
            self.play(FadeIn(self.subtitle), run_time=0.5)