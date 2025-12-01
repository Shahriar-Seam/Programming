from manim import *
from baklava_config import *

class Module4_CombinedDerivation(Scene):
    def construct(self):
        # --- SETUP ---
        setup_camera(self)
        self.subtitle = VGroup()
        
        # --- LAYOUT CONSTANTS ---
        ANCHOR_LEFT = LEFT * 4.5 + UP * 2.5
        TRANSFORM_CENTER = ORIGIN + DOWN * 0.5 # Slightly down to center vertically with subtitles
        FORMULA_RIGHT = RIGHT * 3.5 + UP * 2.0
        
        # --- PHASE 1: SETUP THE ANCHORS ---
        self.play_subtitle("Let's bring back our two key findings.")
        
        # 1. Linearity of Expectation (The Goal)
        eq_expect = MathTex("E = \\frac{1}{1 - R}", color=WHITE).scale(0.9)
        lbl_expect = create_text("Linearity of Expectation", scale=0.4).next_to(eq_expect, UP, buff=0.1).set_color(GRAY)
        group_expect = VGroup(lbl_expect, eq_expect).move_to(ANCHOR_LEFT)
        
        # 2. Shrinkage Factor (The Variable)
        eq_shrink = MathTex("R = \\frac{1 - \\cos(\\alpha)}{2}", color=WHITE).scale(0.9)
        lbl_shrink = create_text("Shrinkage Factor", scale=0.4).next_to(eq_shrink, UP, buff=0.1).set_color(GRAY)
        group_shrink = VGroup(lbl_shrink, eq_shrink).next_to(group_expect, RIGHT, buff=0.8)
        
        self.play(FadeIn(group_expect), FadeIn(group_shrink))
        self.wait(2)
        
        self.play_subtitle("Our goal: Simplify 'R' first, then solve for 'E'.")
        
        # Copy R to the Center Workspace
        workspace_eq = eq_shrink.copy().scale(1.5).move_to(TRANSFORM_CENTER)
        self.play(TransformFromCopy(eq_shrink, workspace_eq))
        self.wait(2)
        
        # --- PHASE 2: SIMPLIFYING R ---
        
        # --- Step 2.1: Half-Angle Identity ---
        self.play_subtitle("Step 1: Convert this fraction using a Trig Identity.")
        
        # Show Formula on Right
        id_half_angle = MathTex("\\frac{1 - \\cos(x)}{2} = \\sin^2\\left(\\frac{x}{2}\\right)", color=BAKLAVA_GOLD).scale(0.7)
        lbl_id_1 = create_text("Half-Angle Identity", scale=0.4).next_to(id_half_angle, UP, buff=0.1).set_color(BAKLAVA_GOLD)
        group_id_1 = VGroup(lbl_id_1, id_half_angle).move_to(FORMULA_RIGHT)
        
        self.play(FadeIn(group_id_1))
        self.wait(2)
        
        # Perform Transformation
        # R = sin^2(alpha / 2)
        step_2_1 = MathTex("R = \\sin^2\\left(\\frac{\\alpha}{2}\\right)").scale(1.5).move_to(TRANSFORM_CENTER)
        self.play(TransformMatchingTex(workspace_eq, step_2_1))
        self.wait(2)
        
        self.play(FadeOut(group_id_1)) # Clear formula
        
        # --- Step 2.2: Substitute Alpha ---
        self.play_subtitle("Step 2: Substitute the definition of Angle Alpha.")
        
        # Show Alpha definition
        alpha_val = MathTex("\\alpha = 180^\\circ - \\frac{360^\\circ}{N}", color=BAKLAVA_GOLD).scale(0.7)
        lbl_alpha = create_text("Interior Angle", scale=0.4).next_to(alpha_val, UP, buff=0.1).set_color(BAKLAVA_GOLD)
        group_alpha = VGroup(lbl_alpha, alpha_val).move_to(FORMULA_RIGHT)
        
        self.play(FadeIn(group_alpha))
        self.wait(2)
        
        # Perform Substitution
        # R = sin^2( (180 - 360/N) / 2 )
        step_2_2 = MathTex("R = \\sin^2\\left( \\frac{180^\\circ - \\frac{360^\\circ}{N}}{2} \\right)").scale(1.5).move_to(TRANSFORM_CENTER)
        self.play(TransformMatchingTex(step_2_1, step_2_2))
        self.wait(2)
        
        self.play_subtitle("Distribute the division by 2.")
        
        # Simplify fraction: 180/2 = 90, 360/2 = 180
        step_2_3 = MathTex("R = \\sin^2\\left( 90^\\circ - \\frac{180^\\circ}{N} \\right)").scale(1.5).move_to(TRANSFORM_CENTER)
        self.play(TransformMatchingTex(step_2_2, step_2_3))
        self.wait(2)
        
        self.play(FadeOut(group_alpha))
        
        # --- Step 2.3: Complementary Angle ---
        self.play_subtitle("Step 3: Simplify using the Complementary Angle Identity.")
        
        # Show Formula
        id_comp = MathTex("\\sin(90^\\circ - x) = \\cos(x)", color=BAKLAVA_GOLD).scale(0.7)
        lbl_id_2 = create_text("Complementary Identity", scale=0.4).next_to(id_comp, UP, buff=0.1).set_color(BAKLAVA_GOLD)
        group_id_2 = VGroup(lbl_id_2, id_comp).move_to(FORMULA_RIGHT)
        
        self.play(FadeIn(group_id_2))
        self.wait(2)
        
        # Perform Transformation
        # R = cos^2(180/N)
        r_simplified = MathTex("R = \\cos^2\\left(\\frac{180^\\circ}{N}\\right)").scale(1.5).move_to(TRANSFORM_CENTER)
        
        self.play(TransformMatchingTex(step_2_3, r_simplified))
        self.play(Indicate(r_simplified, color=BAKLAVA_GOLD))
        self.wait(2)
        
        self.play(FadeOut(group_id_2))
        
        # Update the Anchor R with the new simple version
        self.play_subtitle("We have a clean formula for R. Let's update our reference.")
        
        new_anchor_r = r_simplified.copy().scale(0.9/1.5).move_to(eq_shrink)
        self.play(
            FadeOut(r_simplified), # Clear workspace
            Transform(eq_shrink, new_anchor_r) # Update anchor
        )
        self.wait(2)
        
        # --- PHASE 3: SOLVING FOR E ---
        
        self.play_subtitle("Now, plug this new 'R' into our Expected Value formula.")
        
        # Copy E to Workspace
        workspace_e = eq_expect.copy().scale(1.5).move_to(TRANSFORM_CENTER)
        self.play(TransformFromCopy(eq_expect, workspace_e))
        self.wait(2)
        
        # Substitute R
        # E = 1 / (1 - cos^2(180/N))
        step_3_1 = MathTex("E = \\frac{1}{1 - \\cos^2\\left(\\frac{180^\\circ}{N}\\right)}").scale(1.5).move_to(TRANSFORM_CENTER)
        
        # Emphasize the R being replaced
        self.play(
            eq_shrink.animate.set_color(YELLOW),
            run_time=0.5
        )
        self.play(TransformMatchingTex(workspace_e, step_3_1))
        self.play(eq_shrink.animate.set_color(WHITE))
        self.wait(2)
        
        # --- Step 3.2: Pythagorean Identity ---
        self.play_subtitle("Look at the denominator. We can simplify it.")
        
        # Show Formula
        id_pythag = MathTex("1 - \\cos^2(x) = \\sin^2(x)", color=BAKLAVA_GOLD).scale(0.7)
        lbl_id_3 = create_text("Pythagorean Identity", scale=0.4).next_to(id_pythag, UP, buff=0.1).set_color(BAKLAVA_GOLD)
        group_id_3 = VGroup(lbl_id_3, id_pythag).move_to(FORMULA_RIGHT)
        
        self.play(FadeIn(group_id_3))
        self.wait(2)
        
        # Perform Transformation
        final_eq = MathTex("E = \\frac{1}{\\sin^2\\left(\\frac{180^\\circ}{N}\\right)}").scale(2.0).move_to(TRANSFORM_CENTER)
        final_eq.set_color(BAKLAVA_GOLD)
        
        self.play(TransformMatchingTex(step_3_1, final_eq))
        self.play(Flash(final_eq, color=WHITE, flash_radius=1.0))
        self.wait(3)
        
        # --- RADIAN TRANSFORMATION ---
        self.play_subtitle("One last step: Computers use Radians.")
        
        final_rad = MathTex("E = \\frac{1}{\\sin^2\\left(\\frac{\\pi}{N}\\right)}").scale(2.0).move_to(TRANSFORM_CENTER)
        final_rad.set_color(BAKLAVA_GOLD)
        
        self.play(TransformMatchingTex(final_eq, final_rad))
        self.play(Flash(final_rad, color=WHITE, flash_radius=1.0))
        self.wait(3)
        
        # --- CONCLUSION ---
        self.play_subtitle("And we are done! This is the formula we code.")
        self.wait(4)

    # Helper for subtitles
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