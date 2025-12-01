from manim import *
from baklava_config import *

class Module5_SolutionCode(Scene):
    def construct(self):
        # --- SETUP ---
        setup_camera(self)
        self.subtitle = VGroup()
        
        # --- SECTION 1: THE FORMULA RECAP ---
        self.play_subtitle("We did the math. Now let's write the code.")
        
        # Bring back the formula from the previous module
        formula = MathTex("E = \\frac{10000}{\\sin^2(\\pi / N)}").scale(1.5).to_edge(UP)
        formula.set_color(BAKLAVA_GOLD)
        
        self.play(Write(formula))
        self.wait(2)
        
        # Shrink and move formula to make room for code
        self.play(
            formula.animate.scale(0.7).to_corner(UR).set_opacity(0.8)
        )
        
        # --- SECTION 2: THE CODE STRUCTURE ---
        self.play_subtitle("Here is the clean C++ implementation.")
        
        code_str = """#include <bits/stdc++.h>
using namespace std;

// Helper to square a number
double sq(double n) {
    return n * n;
}

void solve() {
    int n;
    cin >> n;

    // PI = acos(-1)
    double angle = acos(-1) / n;
    
    // Formula: 10000 / sin^2(angle)
    double result = 10000 * 1.0 / sq(sin(angle));

    cout << result << "\\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(5);

    int t; 
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}"""
        
        # Create Code Mobject
        # STRICT ADHERENCE TO YOUR CONSTRUCTOR SIGNATURE:
        code_listing = Code(
            code_string=code_str,          # Explicit keyword argument
            tab_width=4,
            language="cpp",
            formatter_style="monokai",     # Correct keyword for style
            background="window",           # Correct keyword
            add_line_numbers=True,         # Correct keyword (not insert_line_no)
            background_config={"fill_opacity": 0.9, "fill_color": "#1e1e1e", "stroke_width": 0}
        ).scale(0.60).to_edge(LEFT)
        
        self.play(FadeIn(code_listing))
        self.wait(2)
        
        # --- SECTION 3: LINE-BY-LINE EXPLANATION ---
        
        # Highlight: Square Helper (Lines 4-6)
        self.play_subtitle("First, a tiny helper function to square numbers.")
        self.highlight_line(code_listing, 4) 
        self.wait(2)
        
        # Highlight: Precision (Line 26)
        self.play_subtitle("We need 5 decimal places, so we set precision.")
        self.highlight_line(code_listing, 25)
        self.wait(2)
        
        # Focus on the 'solve' function
        self.play_subtitle("Now, the core logic inside the solve function.")
        self.wait(1)
        
        # Highlight: Input N (Line 11)
        self.highlight_line(code_listing, 11)
        self.play_subtitle("We read N, the number of sides.")
        self.wait(2)
        
        # Highlight: Angle Calculation (Line 14)
        self.highlight_line(code_listing, 14)
        self.play_subtitle("We calculate the angle in Radians.")
        
        # Arrow connection: PI -> acos(-1)
        # Accessing code text via index 2 (VGroup structure: bg, numbers, text)
        code_text_group = code_listing[2] 
        target_line = code_text_group[13] # Line 14 is index 13
        
        arrow_pi = Arrow(start=formula.get_left(), end=target_line.get_right(), color=BAKLAVA_GOLD)
        pi_label = create_text("acos(-1) is PI", scale=0.5).next_to(arrow_pi, UP)
        
        self.play(GrowArrow(arrow_pi), FadeIn(pi_label))
        self.wait(2)
        self.play(FadeOut(arrow_pi), FadeOut(pi_label))
        
        # Highlight: The Formula (Line 17)
        self.highlight_line(code_listing, 17)
        self.play_subtitle("Then we apply our derived formula directly.")
        
        # Explain the parts
        parts_text = VGroup(
            create_text("1. sin(angle)", scale=0.5),
            create_text("2. sq(...) -> squares it", scale=0.5),
            create_text("3. 1.0 / ... -> Inverts it", scale=0.5),
            create_text("4. * 10000 -> People", scale=0.5)
        ).arrange(DOWN, aligned_edge=LEFT).next_to(code_listing, RIGHT, buff=0.5)
        
        self.play(Write(parts_text))
        self.wait(4)
        self.play(FadeOut(parts_text))
        
        # --- SECTION 4: SIMULATION (N=3) ---
        self.play_subtitle("Let's trace it with N = 3 (Triangle).")
        
        # Create a "Variables" panel
        var_panel = VGroup(
            create_text("Memory:", scale=0.6).set_color(BLUE),
            Line(LEFT, RIGHT, color=BLUE),
            MathTex("n = 3"),
            MathTex("angle = \\pi / 3 \\approx 1.047"),
            MathTex("\\sin(angle) \\approx 0.866"),
            MathTex("sq(...) \\approx 0.75"),
            MathTex("result \\approx 13333.33333")
        ).arrange(DOWN, aligned_edge=LEFT).next_to(code_listing, RIGHT, buff=1.0).shift(UP)
        
        # Step 1: N = 3
        self.highlight_line(code_listing, 11)
        self.play(FadeIn(var_panel[0:3])) # Header + n=3
        self.wait(1)
        
        # Step 2: Angle
        self.highlight_line(code_listing, 14)
        self.play(FadeIn(var_panel[3])) # angle
        self.wait(1)
        
        # Step 3: Result calculation
        self.highlight_line(code_listing, 17)
        self.play(FadeIn(var_panel[4])) # sin
        self.wait(0.5)
        self.play(FadeIn(var_panel[5])) # sq
        self.wait(0.5)
        self.play(FadeIn(var_panel[6])) # result
        self.play(Indicate(var_panel[6], color=BAKLAVA_GOLD))
        self.wait(2)
        
        # Step 4: Output
        self.highlight_line(code_listing, 19)
        
        console_box = Rectangle(width=4, height=1, color=WHITE, fill_color=BLACK, fill_opacity=1)
        console_text = create_text("Output: 13333.33333", scale=0.6)
        console_group = VGroup(console_box, console_text).next_to(var_panel, DOWN, buff=0.5)
        
        self.play(FadeIn(console_group))
        self.wait(2)
        
        self.play_subtitle("And that matches the example output perfectly!")
        self.wait(3)
        
    # Helper to highlight code lines
    def highlight_line(self, code_obj, line_num):
        # Access lines using index 2 (Code Text VGroup)
        code_lines = code_obj[2]
        
        # line_num is 1-indexed, Python list is 0-indexed
        target_line = code_lines[line_num - 1]
        
        rect = SurroundingRectangle(target_line, color=YELLOW, buff=0.02, stroke_width=2)
        # Stretch rectangle to cover full width of code block roughly
        rect.stretch_to_fit_width(code_obj.width * 0.95)
        rect.align_to(code_obj, LEFT).shift(RIGHT * 0.1)
        
        # If there is already a highlight, transform it
        if hasattr(self, 'current_highlight'):
            self.play(Transform(self.current_highlight, rect), run_time=0.3)
        else:
            self.current_highlight = rect
            self.play(Create(rect), run_time=0.3)

    # Helper for subtitles
    def play_subtitle(self, text_str):
        new_sub = create_text(text_str, scale=0.7).to_edge(DR, buff=0.5)
        bg = SurroundingRectangle(new_sub, color=BLACK, fill_color=BLACK, fill_opacity=0.8, buff=0.2)
        bg.set_stroke(width=0)
        sub_group = VGroup(bg, new_sub)
        
        # Fix: Set a high z-index to ensure it renders on top of the code listing
        sub_group.set_z_index(1000)
        
        if len(self.subtitle) > 0:
            # Also update the current subtitle's z-index to match during the transform
            self.subtitle.set_z_index(1000)
            self.play(Transform(self.subtitle, sub_group), run_time=0.5)
        else:
            self.subtitle = sub_group
            self.play(FadeIn(self.subtitle), run_time=0.5)