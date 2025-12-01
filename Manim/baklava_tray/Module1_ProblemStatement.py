from manim import *
from baklava_config import *
import random

class Module1_ProblemStatement(Scene):
    def construct(self):
        # --- SETUP ---
        setup_camera(self)
        self.subtitle = VGroup()
        
        # Define positions (Shifted Tray left to make room for detailed text)
        TRAY_CENTER = LEFT * 3.5 + UP * 0.5
        TEXT_RIGHT = RIGHT * 3.0 
        
        # --- SECTION 1: THE TRAY & LAYERS ---
        self.play_subtitle("Imagine a giant tray of Baklava shaped like a hexagon.")
        
        # 1.1 Layer 1 (Base)
        r1 = 2.5 
        layer1 = get_regular_polygon(6, r1, color=CRUST_COLOR)
        layer1.rotate(PI/6)
        layer1.move_to(TRAY_CENTER)
        layer1.set_fill(NUT_PALETTE[0], opacity=0.6)
        
        label_l1 = create_text("Layer 1: Hazelnuts", scale=0.6).next_to(layer1, UP, buff=0.2)
        
        self.play(DrawBorderThenFill(layer1), FadeIn(label_l1))
        self.wait(2)
        
        self.play_subtitle("First, the whole tray gets a layer of Hazelnuts.")
        self.wait(2)

        # 1.2 Layer 2 (Construction Detail)
        self.play_subtitle("Then, the baker connects the midpoints to create a smaller shape.")
        
        vertices = layer1.get_vertices()
        midpoints = [(vertices[i] + vertices[(i+1)%6])/2 for i in range(6)]
        
        cut_dots = VGroup(*[Dot(point, color=RED, radius=0.08) for point in midpoints])
        self.play(FadeIn(cut_dots, lag_ratio=0.1))
        
        cut_lines = VGroup()
        for i in range(6):
            line = DashedLine(midpoints[i], midpoints[(i+1)%6], color=BAKLAVA_GOLD)
            cut_lines.add(line)
            
        self.play(Create(cut_lines), run_time=1.5)
        self.wait(0.5)
        
        layer2 = Polygon(*midpoints, color=CRUST_COLOR, stroke_width=4)
        layer2.set_fill(NUT_PALETTE[1], opacity=0.7)
        
        label_l2 = create_text("Layer 2: Cashews", scale=0.6).next_to(layer1, UP, buff=0.2)

        self.play(
            FadeOut(cut_dots),
            FadeOut(cut_lines),
            ReplacementTransform(label_l1, label_l2),
            FadeIn(layer2)
        )
        self.wait(1)

        # 1.3 Layer 3 (Recursion)
        self.play_subtitle("He does this again... adding a new type of nut.")
        
        vertices_2 = layer2.get_vertices()
        midpoints_2 = [(vertices_2[i] + vertices_2[(i+1)%6])/2 for i in range(6)]
        layer3 = Polygon(*midpoints_2, color=CRUST_COLOR, stroke_width=4)
        layer3.set_fill(NUT_PALETTE[2], opacity=0.8)
        
        label_l3 = create_text("Layer 3: Pistachios", scale=0.6).next_to(layer1, UP, buff=0.2)

        self.play(
            DrawBorderThenFill(layer3),
            ReplacementTransform(label_l2, label_l3)
        )
        self.wait(1)

        # 1.4 Infinite Recursion
        self.play_subtitle("He repeats this process forever.")
        
        inner_layers = VGroup()
        current_poly = layer3
        for i in range(3, 20):
            verts = current_poly.get_vertices()
            mids = [(verts[j] + verts[(j+1)%6])/2 for j in range(6)]
            new_poly = Polygon(*mids, color=CRUST_COLOR, stroke_width=2)
            new_poly.set_fill(NUT_PALETTE[i % 5], opacity=0.8)
            inner_layers.add(new_poly)
            current_poly = new_poly
            
        self.play(
            ShowIncreasingSubsets(inner_layers), 
            run_time=2.5, 
            rate_func=linear
        )
        self.wait(1)

        # --- SECTION 2: THE FORKS ---
        self.play_subtitle("Now, imagine 10,000 people throw forks at this tray.")
        self.play(FadeOut(label_l3))
        
        forks = VGroup()
        safe_radius = 2.0
        start_height = 6.0
        
        for _ in range(300):
            r = random.uniform(0, safe_radius)
            theta = random.uniform(0, TAU)
            x = r * np.cos(theta)
            y = r * np.sin(theta)
            
            local_x = x + TRAY_CENTER[0]
            local_y = y + TRAY_CENTER[1]
            start_pos = [local_x, local_y + start_height, 0]
            end_pos = [local_x, local_y, 0]
            
            d = Dot(point=start_pos, radius=0.04, color=WHITE)
            d.generate_target()
            d.target.move_to(end_pos)
            forks.add(d)
        
        self.play(
            LaggedStartMap(lambda m: MoveToTarget(m, run_time=0.8, rate_func=linear), forks, lag_ratio=0.01), 
            run_time=4
        )
        self.wait(1)
        self.play(FadeOut(forks))

        # --- SECTION 3: DEFINING DELICIOUSNESS ---
        self.play_subtitle("What is 'Deliciousness'? Let's define the rules carefully.")
        
        def_title = create_text("Deliciousness Factor", scale=0.75).move_to(TEXT_RIGHT + UP * 3)
        def_line = Line(LEFT, RIGHT, color=BAKLAVA_GOLD).next_to(def_title, DOWN).scale(2)
        
        # Detailed Rules
        # Rule 1: Visualizing nesting
        rule_1 = create_text("1. The tray is like nested shells.", scale=0.55)
        # Rule 2: The mechanics of the fork
        rule_2 = create_text("2. A fork pierces straight down.", scale=0.55)
        # Rule 3: The math consequence
        rule_3 = create_text("3. If you hit the i-th inner layer...", scale=0.55)
        rule_4 = create_text("   ...you pierce exactly i nut types.", scale=0.55)
        rule_5 = create_text("   The number of nut types hit...", scale=0.55)
        rule_5.set_color(BAKLAVA_GOLD)
        rule_6 = create_text("   by the person is deliciousness factor", scale=0.55)
        rule_6.set_color(BAKLAVA_GOLD)
        
        def_body = VGroup(rule_1, rule_2, rule_3, rule_4, rule_5, rule_6).arrange(DOWN, aligned_edge=LEFT, buff=0.15)
        def_body.next_to(def_line, DOWN, buff=0.4).align_to(def_line, LEFT).shift(LEFT * 1.0)
        
        self.play(FadeIn(def_title), Create(def_line))
        self.play(Write(rule_1))
        
        self.play(Write(rule_2))
        self.play(Write(rule_3))
        self.play(Write(rule_4))
        self.play(Write(rule_5))
        self.play(Write(rule_6))
        self.wait(3)

        # --- SECTION 4: SCORING LOGIC ---
        self.play_subtitle("Example: Hitting the 3rd inner polygon (Pistachios).")
        
        # Center Hit Animation
        center_hit = Dot(point=TRAY_CENTER + DOWN * 1.6, radius=0.1, color=RED)
        self.play(Create(center_hit), Flash(center_hit, color=RED, flash_radius=0.5))
        
        # Score calculation text positioned relative to rules
        score_label = MathTex("Score = ").next_to(def_body, DOWN, buff=0.8).align_to(def_body, LEFT)
        
        # Score Components with explicit spacing for labels
        # 1 (Pistachio)
        score_1 = MathTex("1", color=NUT_PALETTE[2]).next_to(score_label, RIGHT) 
        text_1 = create_text("(Pistachio)", scale=0.4).next_to(score_1, UP, buff=0.1).set_color(NUT_PALETTE[2])
        
        # + (Gap)
        plus_1 = MathTex("+").next_to(score_1, RIGHT, buff=.4)

        # 1 (Cashew)
        score_2 = MathTex("1", color=NUT_PALETTE[1]).next_to(plus_1, RIGHT, buff=0.4) 
        text_2 = create_text("(Cashew)", scale=0.4).next_to(score_2, UP, buff=0.1).set_color(NUT_PALETTE[1])
        
        # + (Gap)
        plus_2 = MathTex("+").next_to(score_2, RIGHT, buff=.4)
        
        # 1 (Hazelnut)
        score_3 = MathTex("1", color=NUT_PALETTE[0]).next_to(plus_2, RIGHT, buff=0.4)
        text_3 = create_text("(Hazelnut)", scale=0.4).next_to(score_3, UP, buff=0.1).set_color(NUT_PALETTE[0])
        
        # = Sum
        score_sum = MathTex("= 3").next_to(score_3, RIGHT, buff=.4)
        
        self.play(Write(score_label))
        
        # Animate Layer Piercing: Highlight Inner -> Outer
        self.play(
            layer3.animate.set_stroke(RED, width=8),
            Write(score_1), Write(text_1),
            run_time=0.5
        )
        self.play(layer3.animate.set_stroke(CRUST_COLOR, width=4), run_time=0.2)
        self.play(Write(plus_1))

        self.play(
            layer2.animate.set_stroke(RED, width=8),
            Write(score_2), Write(text_2),
            run_time=0.5
        )
        self.play(layer2.animate.set_stroke(CRUST_COLOR, width=4), run_time=0.2)
        self.play(Write(plus_2))
        
        self.play(
            layer1.animate.set_stroke(RED, width=8),
            Write(score_3), Write(text_3),
            run_time=0.5
        )
        self.play(layer1.animate.set_stroke(CRUST_COLOR, width=4), run_time=0.2)
        self.play(Write(score_sum))
        self.wait(2)
        
        # Edge Hit Animation
        self.play_subtitle("If you hit the outer-most polygon, you pierce only 1 layer.")
        
        edge_pos = TRAY_CENTER + UP * 2.0
        edge_hit = Dot(point=edge_pos, radius=0.1, color=RED)
        
        simple_score_group = VGroup(
            MathTex("Score = ", color=WHITE),
            MathTex("1", color=NUT_PALETTE[0]),
            create_text("(Hazelnut)", scale=0.4).set_color(NUT_PALETTE[0])
        ).arrange(RIGHT).next_to(def_body, DOWN, buff=0.8).align_to(def_body, LEFT)
        
        full_score_group = VGroup(score_label, score_1, text_1, plus_1, score_2, text_2, plus_2, score_3, text_3, score_sum)
        
        self.play(
            ReplacementTransform(center_hit, edge_hit),
            ReplacementTransform(full_score_group, simple_score_group),
            Flash(edge_hit, color=RED, flash_radius=0.5)
        )
        self.play(layer1.animate.set_stroke(RED, width=8), run_time=0.5)
        self.play(layer1.animate.set_stroke(CRUST_COLOR, width=4), run_time=0.5)
        self.wait(2)
        
        # --- SECTION 5: DEFINING EXPECTATION ---
        self.play_subtitle("You need to find the Expected Deliciousness.")
        self.play(FadeOut(simple_score_group), FadeOut(edge_hit))

        exp_title = create_text("Expected Deliciousness", scale=0.75).move_to(TEXT_RIGHT + UP * 3)
        # Transform title
        self.play(ReplacementTransform(def_title, exp_title))

        exp_rule_1 = create_text("'Expected' means 'Average'.", scale=0.55)
        exp_rule_2 = create_text("What is the average score per person?", scale=0.55)

        exp_body = VGroup(exp_rule_1, exp_rule_2).arrange(DOWN, aligned_edge=LEFT, buff=0.15)
        exp_body.next_to(def_line, DOWN, buff=0.4).align_to(def_line, LEFT).shift(LEFT * 1.0)

        self.play(ReplacementTransform(def_body, exp_body))
        self.wait(5)

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