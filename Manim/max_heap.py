from manim import *
import numpy as np

class MaxHeapConstruction(Scene):
    def construct(self):
        # --- CONFIGURATION ---
        data = [10, 30, 20, 5, 40, 60, 35, 2, 15, 50, 55, 25]
        
        ROOT_POS = UP * 3
        V_SPACING = 1.2
        
        # --- DATA STRUCTURES ---
        heap = []
        heap_mobjects = []
        edge_mobjects = {} 

        # --- SETUP VISUALS ---
        # Using Text instead of MathTex to avoid LaTeX errors
        title = Text("Max Heap Construction", font_size=36).to_corner(UL)
        self.add(title)

        array_label = Text("Array Storage:", font_size=24).to_corner(DL).shift(UP*1.5)
        self.add(array_label)
        
        array_boxes = VGroup()
        array_nums = VGroup()
        box_size = 0.6
        
        for i in range(15): 
            box = Square(side_length=box_size, color=WHITE)
            box.move_to(LEFT * 6 + RIGHT * (i * box_size) + DOWN * 3)
            array_boxes.add(box)
        
        self.play(Create(array_boxes), FadeIn(array_label))

        # --- HELPER FUNCTIONS ---

        def get_node_pos(index):
            if index == 0:
                return ROOT_POS
            
            level = int(np.floor(np.log2(index + 1)))
            max_nodes_level = 2**level
            pos_in_level = (index + 1) - max_nodes_level
            
            total_width = 12
            spread = total_width / (max_nodes_level + 1)
            
            x = - (total_width / 2) + (pos_in_level + 1) * spread
            y = ROOT_POS[1] - level * V_SPACING
            return np.array([x, y, 0])

        def update_array_visuals():
            new_nums = VGroup()
            for i, val in enumerate(heap):
                # Changed MathTex to Text
                num = Text(str(val), font_size=20)
                num.move_to(array_boxes[i].get_center())
                new_nums.add(num)
            return new_nums

        # --- MAIN ALGORITHM LOOP ---

        for i, val in enumerate(data):
            # 1. VISUALIZE INSERTION
            new_node_circle = Circle(radius=0.35, color=BLUE, fill_opacity=0.7)
            
            # Changed MathTex to Text
            new_node_text = Text(str(val), font_size=24).set_z_index(10)
            new_node_group = VGroup(new_node_circle, new_node_text)
            
            target_pos = get_node_pos(len(heap))
            new_node_group.move_to(target_pos)

            heap.append(val)
            heap_mobjects.append(new_node_group)
            current_idx = len(heap) - 1

            if current_idx > 0:
                parent_idx = (current_idx - 1) // 2
                parent_pos = heap_mobjects[parent_idx].get_center()
                edge = Line(parent_pos, target_pos, color=GRAY).set_z_index(-1)
                edge_mobjects[(parent_idx, current_idx)] = edge
                self.play(Create(edge), run_time=0.3)

            new_array_nums = update_array_visuals()
            self.play(
                FadeIn(new_node_group, shift=DOWN * 0.5),
                Transform(array_nums, new_array_nums),
                run_time=0.6
            )

            # 2. HEAPIFY UP
            while current_idx > 0:
                parent_idx = (current_idx - 1) // 2
                
                curr_mob = heap_mobjects[current_idx]
                parent_mob = heap_mobjects[parent_idx]
                
                curr_mob[0].set_color(YELLOW)
                parent_mob[0].set_color(YELLOW)
                self.wait(0.3)

                if heap[current_idx] > heap[parent_idx]:
                    heap[current_idx], heap[parent_idx] = heap[parent_idx], heap[current_idx]
                    heap_mobjects[current_idx], heap_mobjects[parent_idx] = heap_mobjects[parent_idx], heap_mobjects[current_idx]
                    
                    pos_child = get_node_pos(current_idx)
                    pos_parent = get_node_pos(parent_idx)
                    
                    self.play(
                        curr_mob.animate.move_to(pos_parent),
                        parent_mob.animate.move_to(pos_child),
                        Transform(array_nums, update_array_visuals()),
                        run_time=0.8
                    )
                    
                    curr_mob[0].set_color(BLUE)
                    parent_mob[0].set_color(BLUE)
                    current_idx = parent_idx
                else:
                    curr_mob[0].set_color(BLUE)
                    parent_mob[0].set_color(BLUE)
                    break
            
            self.wait(0.4)

        final_text = Text("Max Heap Built!", color=GREEN, font_size=30).next_to(title, RIGHT)
        self.play(Write(final_text))
        self.wait(2)