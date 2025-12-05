from manim import *
import numpy as np

class VectorProblem(ThreeDScene):
    def construct(self):
        # --- 1. SETUP & CONFIGURATION ---
        # Fix the camera initially to look like a 2D board for the math part
        self.set_camera_orientation(phi=0 * DEGREES, theta=-90 * DEGREES)
        
        # Fonts & Styles
        # Try a handwriting font. "Segoe Print" (Windows), "Chalkboard SE" (Mac), or generic "Fantasy".
        # If the font isn't found, Manim will log a warning and use the default.
        HANDWRITING_FONT = "Segoe Print" 
        
        eq_scale = 0.8
        subtitle_scale = 0.6
        formula_scale = 0.6
        
        # Colors
        COLOR_A = BLUE
        COLOR_B = GREEN
        COLOR_R = RED
        COLOR_FORMULA = YELLOW

        # Helper to create handwriting text
        def HText(text_str, **kwargs):
            return Text(text_str, font=HANDWRITING_FONT, **kwargs)

        # --- 2. PROBLEM STATEMENT ---
        title = HText("Problem: Find Unit Vector Coplanar & Perpendicular", font_size=32)
        title.to_edge(UP)
        self.play(Write(title))
        self.wait(1)
        self.play(FadeOut(title))

        # --- 3. DEFINE VECTORS ---
        # Given vectors
        vec_a_tex = MathTex(r"\vec{a} = \hat{i} + \hat{j} + \hat{k}", color=COLOR_A).scale(eq_scale)
        vec_b_tex = MathTex(r"\vec{b} = \hat{i} - \hat{j} - \hat{k}", color=COLOR_B).scale(eq_scale)
        
        # Target vector (unknown)
        vec_r_tex = MathTex(r"\text{Let } \vec{r} = x\hat{i} + y\hat{j} + z\hat{k}", color=COLOR_R).scale(eq_scale)

        # Position Group: Middle-Left, Slightly Up (Adjusted as requested)
        given_group = VGroup(vec_a_tex, vec_b_tex, vec_r_tex).arrange(DOWN, aligned_edge=LEFT)
        # Move to Upper Left quadrant, but not extreme corner
        given_group.to_corner(UL).shift(RIGHT * 1.5 + DOWN * 1)
        
        subtitle = HText("Define the given vectors and the unknown vector r.", font_size=24, color=WHITE)
        subtitle.to_edge(DOWN)

        self.play(Write(given_group), Write(subtitle))
        self.wait(2)

        # --- 4. CONDITION 1: PERPENDICULAR ---
        # Subtitle update
        self.play(FadeOut(subtitle))
        subtitle = HText("Step 1: Apply perpendicular condition (Dot Product = 0)", font_size=24)
        subtitle.to_edge(DOWN)
        self.play(Write(subtitle))

        # Formula on the Right
        perp_formula = MathTex(r"\vec{u} \perp \vec{v} \iff \vec{u} \cdot \vec{v} = 0", color=COLOR_FORMULA).scale(formula_scale)
        perp_formula.to_edge(RIGHT).shift(UP * 2)
        self.play(Write(perp_formula))

        # Calculation
        dot_calc = MathTex(
            r"\vec{r} \cdot \vec{a} &= 0 \\",
            r"(x)(1) + (y)(1) + (z)(1) &= 0 \\",
            r"x + y + z &= 0 \quad \text{(Eq. 1)}"
        ).scale(eq_scale)
        dot_calc.next_to(given_group, DOWN, buff=0.5, aligned_edge=LEFT)

        self.play(Write(dot_calc))
        self.wait(2)

        # --- 5. CONDITION 2: COPLANAR ---
        self.play(FadeOut(subtitle))
        subtitle = HText("Step 2: Apply coplanar condition (Scalar Triple Product = 0)", font_size=24)
        subtitle.to_edge(DOWN)
        self.play(Write(subtitle))

        # Formula on the Right
        coplanar_formula = MathTex(
            r"\text{Coplanar} \iff \begin{vmatrix} x & y & z \\ a_x & a_y & a_z \\ b_x & b_y & b_z \end{vmatrix} = 0",
            color=COLOR_FORMULA
        ).scale(formula_scale)
        coplanar_formula.next_to(perp_formula, DOWN, buff=1)
        self.play(Write(coplanar_formula))

        # Calculation matrix
        det_setup = MathTex(
            r"\begin{vmatrix} x & y & z \\ 1 & 1 & 1 \\ 1 & -1 & -1 \end{vmatrix} = 0"
        ).scale(eq_scale)
        det_setup.next_to(dot_calc, DOWN, buff=0.5, aligned_edge=LEFT)
        
        self.play(Write(det_setup))
        self.wait(1)

        # Solving Determinant
        det_solved = MathTex(
            r"x(-1 - (-1)) - y(-1 - 1) + z(-1 - 1) &= 0 \\",
            r"x(0) - y(-2) + z(-2) &= 0 \\",
            r"2y - 2z &= 0 \\",
            r"y &= z \quad \text{(Eq. 2)}"
        ).scale(eq_scale)
        det_solved.next_to(det_setup, DOWN, buff=0.2, aligned_edge=LEFT)

        self.play(Write(det_solved))
        self.wait(2)

        # --- 6. SOLVING THE SYSTEM ---
        self.play(FadeOut(subtitle), FadeOut(given_group), FadeOut(dot_calc), FadeOut(det_setup), FadeOut(perp_formula), FadeOut(coplanar_formula))
        
        # Keep the results visible
        eq1_ref = MathTex(r"x + y + z = 0", color=GREY).scale(eq_scale).to_corner(UL).shift(DOWN*1 + RIGHT*1)
        eq2_ref = MathTex(r"y = z", color=GREY).scale(eq_scale).next_to(eq1_ref, DOWN, aligned_edge=LEFT)
        
        # Transform old equations to reference corner
        self.play(Transform(dot_calc.copy(), eq1_ref), Transform(det_solved.copy(), eq2_ref))
        self.remove(dot_calc, det_solved) # Clean up originals
        
        subtitle = HText("Step 3: Solve the system of linear equations", font_size=24)
        subtitle.to_edge(DOWN)
        self.play(Write(subtitle))

        # Substitution logic
        solve_steps = MathTex(
            r"\text{Substitute } y = z \text{ into Eq. 1:}",
            r"x + (z) + z &= 0 \\",
            r"x + 2z &= 0 \\",
            r"x &= -2z"
        ).scale(eq_scale)
        solve_steps.to_edge(LEFT).shift(UP*0.5 + RIGHT*1) 

        self.play(Write(solve_steps))
        self.wait(2)

        # Vector form
        vec_form = MathTex(
            r"\text{So, } \vec{r} &= -2z\hat{i} + z\hat{j} + z\hat{k} \\",
            r"\vec{r} &= z(-2\hat{i} + \hat{j} + \hat{k})"
        ).scale(eq_scale).set_color(COLOR_R)
        vec_form.next_to(solve_steps, DOWN, buff=0.5, aligned_edge=LEFT)
        self.play(Write(vec_form))
        self.wait(2)

        # --- 7. UNIT VECTOR NORMALIZATION ---
        self.play(FadeOut(subtitle))
        subtitle = HText("Step 4: Normalize to find unit vector (Magnitude = 1)", font_size=24)
        subtitle.to_edge(DOWN)
        self.play(Write(subtitle))

        # Magnitude Formula
        mag_formula = MathTex(r"|\vec{u}| = \sqrt{x^2+y^2+z^2}", color=COLOR_FORMULA).scale(formula_scale)
        mag_formula.to_edge(RIGHT).shift(UP)
        self.play(Write(mag_formula))

        # Calculation
        norm_calc = MathTex(
            r"|\vec{r}| &= \sqrt{(-2z)^2 + z^2 + z^2} = 1 \\",
            r"\sqrt{4z^2 + z^2 + z^2} &= 1 \\",
            r"\sqrt{6z^2} &= 1 \\",
            r"z\sqrt{6} &= 1 \implies z = \pm \frac{1}{\sqrt{6}}"
        ).scale(eq_scale)
        norm_calc.next_to(vec_form, DOWN, buff=0.5, aligned_edge=LEFT)

        self.play(Write(norm_calc))
        self.wait(2)

        # Final Result
        final_vec = MathTex(
            r"\text{Final Unit Vector: } \hat{r} = \pm \frac{1}{\sqrt{6}}(-2\hat{i} + \hat{j} + \hat{k})"
        ).scale(0.9).set_color(COLOR_R)
        final_vec.move_to(ORIGIN).to_edge(UP, buff=1.5)
        
        # Clear board for final result - Remove EVERYTHING to prevent overlap
        self.play(
            FadeOut(solve_steps), 
            FadeOut(vec_form), 
            FadeOut(norm_calc), 
            FadeOut(eq1_ref), 
            FadeOut(eq2_ref),
            FadeOut(mag_formula),
            Write(final_vec),
            FadeOut(subtitle)
        )
        self.wait(2)

        # --- 8. 3D VISUALIZATION ---
        
        # Use add_fixed_in_frame_mobjects for the HUD elements (Subtitle & Result)
        # This prevents them from moving/rotating with the 3D camera
        
        subtitle_3d = HText("Visualizing the solution in 3D Space...", font_size=24)
        subtitle_3d.to_edge(DOWN)
        
        # Temporarily remove final_vec to add it back as a fixed element
        self.remove(final_vec)
        
        # Add HUD elements
        self.add_fixed_in_frame_mobjects(subtitle_3d)
        self.add_fixed_in_frame_mobjects(final_vec)
        
        self.play(Write(subtitle_3d))

        # Create 3D objects
        axes = ThreeDAxes()
        
        # Vectors numerical values
        v_a = np.array([1, 1, 1])
        v_b = np.array([1, -1, -1])
        # Solution: (-2, 1, 1) normalized
        v_r = np.array([-2, 1, 1])
        v_r = v_r / np.linalg.norm(v_r) 

        # Arrows
        arrow_a = Arrow3D(start=ORIGIN, end=v_a, color=COLOR_A)
        arrow_b = Arrow3D(start=ORIGIN, end=v_b, color=COLOR_B)
        arrow_r = Arrow3D(start=ORIGIN, end=v_r, color=COLOR_R)

        # Labels
        label_a = MathTex("a", color=COLOR_A).move_to(v_a + np.array([0.1, 0.1, 0.1]))
        label_b = MathTex("b", color=COLOR_B).move_to(v_b + np.array([0.1, 0.1, 0.1]))
        label_r = MathTex("r", color=COLOR_R).move_to(v_r + np.array([0.1, 0.1, 0.1]))

        # Rotate text to face camera in 3D is complex, so we just let them billboard naturally or stay static
        # Note: MathTex in 3D scenes will rotate with the camera unless configured otherwise.
        # Since we want to see the geometry, we let them rotate.

        # Transition to 3D View
        self.move_camera(phi=75 * DEGREES, theta=30 * DEGREES, zoom=1, run_time=2)
        
        self.play(Create(axes))
        self.play(Create(arrow_a), Write(label_a))
        self.play(Create(arrow_b), Write(label_b))
        self.wait(0.5)
        
        # Create a small plane to show coplanarity
        # Plane defined by A and B passes through origin.
        plane = Surface(
            lambda u, v: u * v_a + v * v_b,
            u_range=[-1.5, 1.5],
            v_range=[-1.5, 1.5],
            fill_opacity=0.3,
            checkerboard_colors=[BLUE_D, BLUE_D],
        )
        self.play(Create(plane))
        
        self.play(Create(arrow_r), Write(label_r))
        
        # Rotate camera around to show the orthogonality and coplanarity
        self.begin_ambient_camera_rotation(rate=0.2)
        self.wait(5)
        self.stop_ambient_camera_rotation()
        
        # Final cleanup
        self.play(FadeOut(subtitle_3d), FadeOut(final_vec))
        self.wait(1)