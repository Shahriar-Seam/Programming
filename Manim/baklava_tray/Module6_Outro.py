from manim import *
from baklava_config import *

class Module6_Outro(Scene):
    def construct(self):
        # --- SETUP ---
        setup_camera(self)
        
        # --- BACKGROUND ---
        # Reuse the intro aesthetic for visual consistency
        bg_hex = get_regular_polygon(6, 3.5, color=BAKLAVA_GOLD, stroke_width=2)
        bg_hex.set_stroke(opacity=0.3)
        bg_hex.add_updater(lambda m, dt: m.rotate(-dt * 0.15)) # Reverse rotation for ending
        self.add(bg_hex)
        
        # --- TEXT ELEMENTS ---
        
        # 1. The Lead-in
        line1 = Text("This Tutorial Was", font="Arial", weight=NORMAL).scale(0.8)
        line2 = Text("Created By", font="Arial", weight=NORMAL).scale(0.8)
        
        lead_group = VGroup(line1, line2).arrange(DOWN, buff=0.2)
        lead_group.set_color(GRAY_A)
        lead_group.move_to(UP * 1.5)
        
        # 2. The Star
        name = Text("Gemini 3.0", font="Arial", weight=BOLD).scale(2.5)
        name.set_color(BAKLAVA_GOLD)
        name.move_to(DOWN * 0.5)
        
        # 3. Sub-credit
        sub = Text("AI-Powered Problem Solving & Visualization", font="Arial").scale(0.5)
        sub.next_to(name, DOWN, buff=0.5).set_color(WHITE)
        
        # --- ANIMATION SEQUENCE ---
        
        # Appear
        self.play(
            FadeIn(lead_group, shift=DOWN),
            run_time=2.0 # Increased run_time
        )
        self.wait(1.5) # Longer pause
        
        # Reveal Name
        self.play(
            Write(name),
            run_time=2.5 # Increased run_time
        )
        
        # Flash/Glow effect
        self.play(
            Flash(name, color=BAKLAVA_GOLD, line_length=0.3, num_lines=12),
            name.animate.scale(1.1).set_color(YELLOW),
            run_time=1.0 # Increased run_time
        )
        self.play(
            name.animate.scale(1/1.1).set_color(BAKLAVA_GOLD),
            FadeIn(sub, shift=UP),
            run_time=1.0 # Increased run_time
        )
        
        self.wait(4) # Longer final hold
        
        # Fade Out
        self.play(
            FadeOut(lead_group),
            FadeOut(name),
            FadeOut(sub),
            FadeOut(bg_hex),
            run_time=2.5 # Increased run_time
        )
        self.wait(1)