from manim import *
from baklava_config import *

class Module2_LinearityLogic(Scene):
    def construct(self):
        # --- SETUP ---
        setup_camera(self)
        self.subtitle = VGroup()
        
        # Position constants (Shifted UP to avoid subtitle overlap)
        CENTER_POS = LEFT * 3.5 + UP * 0.5 
        MATH_POS = RIGHT * 2.5
        
        # --- SECTION 1: THE "HARD WAY" (NESTED) ---
        self.play_subtitle("Counting overlaps directly is a nightmare.")
        
        # Create nested layers (Standard View)
        layers = VGroup()
        # Correct geometric ratio for connecting midpoints: sqrt(3)/2
        midpoint_ratio = np.sqrt(3) / 2
        
        for i in range(4):
            color = NUT_PALETTE[i % len(NUT_PALETTE)]
            # Exact radius
            radius = 2.5 * (midpoint_ratio ** i)
            poly = get_regular_polygon(6, radius, color=CRUST_COLOR)
            
            # Rotation logic (Alternating 30 degrees)
            rotation_angle = PI/6 + (i * PI/6)
            poly.rotate(rotation_angle)
            
            poly.set_fill(color, opacity=0.5)
            layers.add(poly)
            
        layers.move_to(CENTER_POS)
        
        self.play(DrawBorderThenFill(layers))
        self.wait(2) # Increased pause
        
        # Visualize the confusion
        complex_text = create_text("Region A: 1 layer\nRegion B: 2 layers...", scale=0.5)
        complex_text.next_to(layers, UP)
        self.play(FadeIn(complex_text))
        
        # Flash rings to show difficulty
        self.play(layers[0].animate.set_stroke(RED, 6), run_time=0.5)
        self.play(layers[0].animate.set_stroke(CRUST_COLOR, 4), layers[1].animate.set_stroke(RED, 6), run_time=0.5)
        self.play(layers[1].animate.set_stroke(CRUST_COLOR, 4), layers[2].animate.set_stroke(RED, 6), run_time=0.5)
        self.play(layers[2].animate.set_stroke(CRUST_COLOR, 4), FadeOut(complex_text))
        
        # --- DETAILED EXPLANATION: SUBTRACTION ---
        self.play_subtitle("To get the area of just the 2nd ring (Region B)...")
        self.wait(2.5)
        
        math_diff = MathTex("\\text{Ring Area} = \\text{Area}_1 - \\text{Area}_2").next_to(layers, UP)
        self.play(Write(math_diff))
        self.wait(3) # Give time to read equation
        
        self.play_subtitle("We have to subtract the inner area from the outer area.")
        self.wait(3)
        self.play(FadeOut(math_diff))
        
        self.play_subtitle("Doing this subtraction for infinite rings is messy and unnecessary.")
        self.wait(3)

        self.play_subtitle("So, let's use 'Linearity of Expectation'.")
        self.wait(2.5)

        # --- SECTION 2: THE "EXPLOSION" (SHEETS) ---
        self.play_subtitle("Imagine the layers are separate, transparent sheets.")
        
        # 2.5D Transformation
        perspective_angle = 60 * DEGREES
        
        # Move slightly down for perspective, but keep higher than before
        EXPLODE_BASE = CENTER_POS + DOWN * 1.0 
        
        self.play(
            layers.animate.rotate(perspective_angle, axis=RIGHT).move_to(EXPLODE_BASE),
            run_time=2
        )
        
        # Explode Layers Vertically (Compacted Spacing)
        separations = [0, 1.2, 2.4, 3.6] # Reduced spacing to keep it compact
        anims = []
        labels = VGroup()
        
        for i, layer in enumerate(layers):
            target_pos = EXPLODE_BASE + UP * separations[i]
            anims.append(layer.animate.move_to(target_pos))
            
            label_text = f"Sheet {i+1}"
            label = create_text(label_text, scale=0.4).next_to(target_pos, LEFT, buff=0.6)
            labels.add(label)
        
        self.play(*anims, FadeIn(labels, lag_ratio=0.1), run_time=2)
        self.wait(2)
        
        # --- DETAILED EXPLANATION: INDEPENDENCE ---
        self.play_subtitle("Linearity lets us count each layer independently.")
        self.wait(3)
        self.play_subtitle("We don't care about the overlaps anymore.")
        self.wait(3)
        self.play_subtitle("We simply ask: 'Did the fork hit THIS sheet?'")
        self.wait(3)

        # --- SECTION 3: DERIVING "R" (SELF-SIMILARITY) ---
        self.play_subtitle("Why does the area shrink? It's Self-Similarity.")
        
        # Highlight Sheet 1 and 2
        self.play(
            layers[0].animate.set_stroke(BAKLAVA_GOLD, 6).set_opacity(0.8),
            layers[1].animate.set_stroke(BAKLAVA_GOLD, 6).set_opacity(0.8)
        )
        
        # Math for R
        r_def_title = create_text("Self-Similarity Ratio (R)", scale=0.6).move_to(MATH_POS + UP * 3)
        r_def_eq = MathTex("R = \\frac{\\text{Area}_{new}}{\\text{Area}_{old}}").next_to(r_def_title, DOWN)
        
        self.play(Write(r_def_title), Write(r_def_eq))
        self.wait(3)
        
        # --- DETAILED EXPLANATION: CONSTANT R ---
        self.play_subtitle("The baker repeats the exact same cut every time.")
        self.wait(3)
        self.play_subtitle("So the reduction ratio 'R' stays exactly the same forever.")
        self.wait(3)
        
        r_example = MathTex("\\text{Area}_2 = \\text{Area}_1 \\times R").next_to(r_def_eq, DOWN, buff=0.5)
        self.play(Write(r_example))
        self.wait(3)
        
        # Reset highlights
        self.play(
            layers[0].animate.set_stroke(CRUST_COLOR, 4).set_opacity(0.5),
            layers[1].animate.set_stroke(CRUST_COLOR, 4).set_opacity(0.5),
            FadeOut(r_def_title), FadeOut(r_def_eq), FadeOut(r_example)
        )

        # --- SECTION 4: PROBABILITY & RECURSION ---
        self.play_subtitle("The Probability of hitting a sheet is its Area.")
        
        prob_title = create_text("Probability = Area", scale=0.8).move_to(MATH_POS + UP * 3)
        self.play(Write(prob_title))
        self.wait(2)
        
        # --- DETAILED EXPLANATION: GEOMETRIC PROBABILITY ---
        prob_formula = MathTex("P = \\frac{\\text{Target Area}}{\\text{Total Area}}").next_to(prob_title, DOWN)
        self.play(Write(prob_formula))
        self.wait(3)
        self.play_subtitle("Since our Total Area is 1, Probability equals the Target Area.")
        self.wait(3)
        self.play(FadeOut(prob_formula))

        # --- Term 1 ---
        self.play_subtitle("Sheet 1 covers 100%. Probability = 1.")
        self.play(layers[0].animate.set_stroke(RED, 8).set_opacity(1))
        
        term1 = MathTex("P_1 = 1", color=NUT_PALETTE[0]).next_to(prob_title, DOWN, buff=0.5)
        self.play(Write(term1))
        self.play(layers[0].animate.set_stroke(CRUST_COLOR, 4).set_opacity(0.5))
        self.wait(1.5)
        
        # --- Term 2 ---
        self.play_subtitle("Sheet 2 is shrunk by R. Probability = R.")
        self.play(layers[1].animate.set_stroke(RED, 8).set_opacity(1))
        
        term2 = MathTex("P_2 = 1 \\times R = R", color=NUT_PALETTE[1]).next_to(term1, DOWN, buff=0.3)
        self.play(Write(term2))
        self.play(layers[1].animate.set_stroke(CRUST_COLOR, 4).set_opacity(0.5))
        self.wait(1.5)
        
        # --- Term 3 (Recursive) ---
        self.play_subtitle("Sheet 3 is shrunk by R *again*.")
        self.play(layers[2].animate.set_stroke(RED, 8).set_opacity(1))
        
        # Show algebraic substitution
        term3_step1 = MathTex("P_3 = P_2 \\times R", color=NUT_PALETTE[2]).next_to(term2, DOWN, buff=0.3)
        self.play(Write(term3_step1))
        self.wait(2)
        
        term3_step2 = MathTex("P_3 = (R) \\times R = R^2", color=NUT_PALETTE[2]).move_to(term3_step1)
        self.play(Transform(term3_step1, term3_step2))
        self.play(layers[2].animate.set_stroke(CRUST_COLOR, 4).set_opacity(0.5))
        self.wait(2.5)
        
        # --- Term 4 ---
        term4 = MathTex("P_4 = R^3", color=NUT_PALETTE[3]).next_to(term3_step1, DOWN, buff=0.3)
        self.play(Write(term4))
        self.wait(2)

        # --- SECTION 5: GEOMETRIC SERIES ---
        self.play_subtitle("To get the Expected Value, we sum these probabilities.")
        
        # Clear specific terms to make room for sum
        self.play(
            FadeOut(term1), FadeOut(term2), FadeOut(term3_step1), FadeOut(term4),
            FadeOut(prob_title)
        )
        
        sum_title = create_text("Total Expected Value (E)", scale=0.8).move_to(MATH_POS + UP * 2.5)
        sum_eq = MathTex("E = 1 + R + R^2 + R^3 + \\dots").next_to(sum_title, DOWN)
        
        self.play(Write(sum_title), Write(sum_eq))
        self.wait(3)
        
        self.play_subtitle("This is an Infinite Geometric Series.")
        
        # --- DETAILED EXPLANATION: SERIES FORMULA ---
        formula_box = SurroundingRectangle(sum_eq, color=BAKLAVA_GOLD, buff=0.2)
        self.play(Create(formula_box))
        
        self.play_subtitle("The formula for a Geometric Sum is: First Term / (1 - Ratio).")
        series_rule = MathTex("S = \\frac{a}{1 - r}").next_to(sum_eq, DOWN, buff=0.5).set_color(BAKLAVA_GOLD)
        self.play(Write(series_rule))
        self.wait(3)
        
        self.play_subtitle("Here, First Term 'a' is 1, and Ratio 'r' is R.")
        self.wait(3)
        self.play(FadeOut(series_rule))
        
        self.play_subtitle("Since R < 1, the sum converges nicely.")
        
        final_formula = MathTex("E = \\frac{1}{1 - R}").scale(1.5).next_to(sum_title, DOWN, buff=1.0)
        final_formula.set_color(BAKLAVA_GOLD)
        
        self.play(
            ReplacementTransform(sum_eq, final_formula),
            FadeOut(formula_box)
        )
        self.play(Indicate(final_formula, color=WHITE))
        self.wait(4)
        
        self.play_subtitle("Now, we just need to find the value of R.")
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