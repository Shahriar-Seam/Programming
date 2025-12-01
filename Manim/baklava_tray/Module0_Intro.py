from manim import *
from baklava_config import *

class Module0_Intro(Scene):
    def construct(self):
        # --- SETUP ---
        setup_camera(self)
        
        # --- DECORATION ---
        # A slow spinning hexagon in the background to set the theme
        bg_hex = get_regular_polygon(6, 3.5, color=BAKLAVA_GOLD, stroke_width=2)
        bg_hex.set_stroke(opacity=0.3)
        
        # Continuous rotation animation
        bg_hex.add_updater(lambda m, dt: m.rotate(dt * 0.15))
        self.add(bg_hex)
        
        # --- TEXT ELEMENTS ---
        
        # 1. Problem Title
        # Using raw Text for specific weight control
        title = Text("The Baklava Tray", font="Arial", weight=BOLD).scale(1.5)
        title.set_color(BAKLAVA_GOLD)
        title.move_to(UP * 1.5)
        
        # 2. Source
        source = Text("ACPC 2018", font="Arial").scale(0.6).set_color(GRAY)
        source.next_to(title, DOWN, buff=0.3)
        
        # 3. Tags
        tags_str = "Geometry  •  Expectation  •  Infinite Series"
        tags = Text(tags_str, font="Arial").scale(0.6).set_color(WHITE)
        tags.move_to(DOWN * 0.5)
        
        # 4. Rating
        # Codeforces 1900 is typically Purple (Candidate Master)
        rating_group = VGroup()
        rating_label = Text("Estimated Rating:", font="Arial").scale(0.6).set_color(WHITE)
        rating_val = Text("1900", font="Arial", weight=BOLD).scale(0.8).set_color(PURPLE_B) # Manim's PURPLE_B is nice
        rating_group.add(rating_label, rating_val).arrange(RIGHT, buff=0.2)
        
        # Add a box around rating for emphasis
        rating_box = SurroundingRectangle(rating_group, color=PURPLE_B, buff=0.2, corner_radius=0.2)
        full_rating = VGroup(rating_box, rating_group).next_to(tags, DOWN, buff=1.0)
        
        # --- ANIMATION ---
        
        # 1. Title Slide in
        self.play(
            FadeIn(title, shift=DOWN),
            FadeIn(source, shift=DOWN)
        )
        self.wait(1)
        
        # 2. Tags Write out
        self.play(
            Write(tags),
            run_time=1.5
        )
        self.wait(1)
        
        # 3. Rating Stamp
        self.play(
            GrowFromCenter(rating_box),
            FadeIn(rating_group),
            run_time=1
        )
        self.play(Flash(rating_val, color=PURPLE_B, line_length=0.2))
        
        # Hold for final image
        self.wait(4)