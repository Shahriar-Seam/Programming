from manim import *

class SquareToCircle(Scene):
    def construct(self):
        # 1. Create the shapes
        square = Square()  # Create a square
        square.set_fill(BLUE, opacity=0.5)  # Set color and opacity

        circle = Circle()  # Create a circle
        circle.set_fill(PINK, opacity=0.5)

        # 2. Add the square to the scene
        self.play(Create(square))
        self.wait(1)

        # 3. Transform square into circle
        self.play(Transform(square, circle))
        self.wait(1)

        # 4. Fade out
        self.play(FadeOut(square))