from manim import *

# --- VISUAL THEME ---

# Background
BG_COLOR = "#2F4F4F"  # Dark Slate Grey (as requested)

# Baklava Colors
BAKLAVA_GOLD = "#FFD700"  # Gold
BAKLAVA_HONEY = "#FF8C00" # Dark Orange
CRUST_COLOR = WHITE       # Distinct outline

# Nut Colors (for layers)
NUT_HAZELNUT = "#C4A484"  # Light Brown
NUT_CASHEW = "#F5DEB3"    # Wheat
NUT_PISTACHIO = "#93C572" # Pistachio Green

# Palette Array for easy iteration
NUT_PALETTE = [NUT_HAZELNUT, NUT_CASHEW, NUT_PISTACHIO, "#F0E68C", "#E6E6FA"]

# --- TEXT STYLES ---

# Standard Text
def create_text(text_str, scale=0.8):
    return Text(text_str, font="Arial", color=WHITE).scale(scale)

# Math/LaTeX
def create_math(tex_str, scale=1.0):
    return MathTex(tex_str, color=BAKLAVA_GOLD).scale(scale)

# --- GEOMETRY HELPERS ---

def get_regular_polygon(n_sides, radius, color=CRUST_COLOR, stroke_width=4):
    return RegularPolygon(n=n_sides, color=color, stroke_width=stroke_width).scale(radius)

# Config Helper
def setup_camera(scene):
    scene.camera.background_color = BG_COLOR