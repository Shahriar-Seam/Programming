from manim import *
from baklava_config import *
import textwrap

class Module5_SolutionCode_alt(Scene):
    def construct(self):
        # --- SETUP ---
        setup_camera(self)
        self.subtitle = VGroup()
        
        # --- SECTION 1: THE FORMULA RECAP ---
        self.play_subtitle("We have the math. Now let's build the code piece by piece.")
        
        # Bring back the formula
        formula = MathTex("E = \\frac{10000}{\\sin^2(\\pi / N)}").scale(1.5).to_edge(UP)
        formula.set_color(BAKLAVA_GOLD)
        
        self.play(Write(formula))
        self.wait(2)
        
        # Move formula to corner to be a reference
        self.play(
            formula.animate.scale(0.7).to_corner(UR).set_opacity(0.8)
        )
        
        # --- SECTION 2: LIVE CODING ---
        
        # The full C++ code string
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
    // Fast I/O & Precision
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
        
        # Create the full Code object but initially hide text
        # Using correct keyword arguments for Manim Community Code class
        code_listing = Code(
            code_string=code_str,
            tab_width=4,
            language="cpp",
            formatter_style="monokai",
            background="window",
            add_line_numbers=True,
            background_config={"fill_opacity": 0.9, "fill_color": "#1e1e1e", "stroke_width": 0}
        ).scale(0.6).to_edge(LEFT).shift(DOWN*0.1)
        
        # Access components: [0]=bg, [1]=line_nums, [2]=code_text
        code_bg = code_listing[0]
        line_nums = code_listing[1]
        code_text = code_listing[2]
        
        # Initially hide content (opacity 0)
        line_nums.set_opacity(0)
        code_text.set_opacity(0)
        
        # Show empty editor window first
        self.play(FadeIn(code_bg))
        self.wait(1)
        
        # --- BLOCK 1: HEADERS ---
        self.play_subtitle("Start with the standard headers.")
        
        # Lines 1-2 (Indices 0-1)
        self.reveal_code_block(code_listing, 0, 1)
        self.wait(2)
        
        # --- BLOCK 2: MAIN FUNCTION ---
        self.play_subtitle("Write main() first to handle Fast I/O and Test Cases.")
        
        # Lines 22-33 (Indices 21-32) - The Main Function
        self.reveal_code_block(code_listing, 21, 33)
        self.wait(3)
        
        # --- BLOCK 3: SOLVE INPUT & ANGLE ---
        self.play_subtitle("Now we define solve(). First step: Input and Angle.")
        
        # Lines 9-14 (Indices 8-13) - solve header through angle calc
        self.reveal_code_block(code_listing, 8, 13)
        
        # Visual Link for PI
        target_line = code_text[13] # Line 14 corresponding to angle calc
        arrow_pi = Arrow(start=formula.get_left(), end=target_line.get_right(), color=BAKLAVA_GOLD)
        self.play(GrowArrow(arrow_pi))
        self.wait(2)
        self.play(FadeOut(arrow_pi))
        
        # --- BLOCK 4: HELPER FUNCTION ---
        self.play_subtitle("Before calculating the result, let's make a square helper.")
        
        # Lines 4-7 (Indices 3-6) - The sq function above solve
        self.reveal_code_block(code_listing, 3, 6)
        self.wait(3)
        
        # --- BLOCK 5: SOLVE RESULT & OUTPUT ---
        self.play_subtitle("Now we can use sq() to calculate and print the result.")
        
        # Lines 16-20 (Indices 15-19) - Result calc and closing brace of solve
        self.reveal_code_block(code_listing, 15, 19)
        self.wait(3)
        
        self.reveal_code_block(code_listing, 0, 33)
        
        # --- SECTION 3: SIMULATION ---
        self.play_subtitle("Now, let's watch it run for N=3.")
        
        # Variables Panel
        var_panel = VGroup(
            create_text("Memory:", scale=0.6).set_color(BLUE),
            Line(LEFT, RIGHT, color=BLUE),
            MathTex("n = 3"),
            MathTex("angle \\approx 1.047"),
            MathTex("result \\approx 13333.33")
        ).arrange(DOWN, aligned_edge=LEFT).next_to(code_listing, RIGHT, buff=1.0).shift(UP)
        
        # Trace Lines
        self.highlight_line(code_listing, 11) # cin >> n
        self.play(FadeIn(var_panel[0:3]))
        self.wait(1)
        
        self.highlight_line(code_listing, 14) # angle
        self.play(FadeIn(var_panel[3]))
        self.wait(1)
        
        self.highlight_line(code_listing, 17) # result
        self.play(FadeIn(var_panel[4]))
        self.play(Indicate(var_panel[4], color=BAKLAVA_GOLD))
        self.wait(1)
        
        self.highlight_line(code_listing, 19) # cout
        
        console_box = Rectangle(width=4, height=1, color=WHITE, fill_color=BLACK, fill_opacity=1)
        console_text = create_text("Output: 13333.33333", scale=0.6)
        console_group = VGroup(console_box, console_text).next_to(var_panel, DOWN, buff=0.5)
        
        self.play(FadeIn(console_group))
        self.wait(3)
        
        self.play_subtitle("Code complete. Problem solved!")
        self.wait(3)

    # Helper to reveal lines (start_idx and end_idx are 0-indexed inclusive)
    def reveal_code_block(self, code_obj, start_idx, end_idx):
        line_nums = code_obj[1]
        code_text = code_obj[2]
        
        # Collect objects to fade in
        anims = []
        for i in range(start_idx, end_idx + 1):
            # Check bounds to be safe
            if i < len(line_nums):
                anims.append(line_nums[i].animate.set_opacity(0.5)) # Dimmed line nums
            if i < len(code_text):
                anims.append(code_text[i].animate.set_opacity(1))   # Full text
        
        if anims:
            self.play(*anims, run_time=1.0)

    # Helper to highlight code lines
    def highlight_line(self, code_obj, line_num):
        code_lines = code_obj[2]
        target_line = code_lines[line_num - 1]
        
        rect = SurroundingRectangle(target_line, color=YELLOW, buff=0.02, stroke_width=2)
        rect.stretch_to_fit_width(code_obj.width * 0.95)
        rect.align_to(code_obj, LEFT).shift(RIGHT * 0.1)
        
        if hasattr(self, 'current_highlight'):
            self.play(Transform(self.current_highlight, rect), run_time=0.3)
        else:
            self.current_highlight = rect
            self.play(Create(rect), run_time=0.3)

    # Helper for subtitles
    def play_subtitle(self, text_str):
        # Automatically wrap text to ~50 characters
        wrapped_text = textwrap.fill(text_str, width=30)
        
        # Use Text directly to support multiline
        new_sub = Text(wrapped_text, font="Arial", line_spacing=1.0).scale(0.7).to_edge(DR, buff=0.5)
        
        bg = SurroundingRectangle(new_sub, color=BLACK, fill_color=BLACK, fill_opacity=0.8, buff=0.2)
        bg.set_stroke(width=0)
        sub_group = VGroup(bg, new_sub)
        sub_group.set_z_index(1000)
        
        if len(self.subtitle) > 0:
            self.subtitle.set_z_index(1000)
            self.play(Transform(self.subtitle, sub_group), run_time=0.5)
        else:
            self.subtitle = sub_group
            self.play(FadeIn(self.subtitle), run_time=0.5)