import itertools

def solve_cryptarithm(equation):
    # Clean up the input string by converting to uppercase and removing spaces
    equation = equation.upper().replace(" ", "")
    
    # Validate and split into left and right sides of the equation
    if "=" not in equation or "+" not in equation:
        return "Please provide an equation in the format 'WORD1 + WORD2 = WORD3'."
    
    left_str, right_str = equation.split("=")
    addends = left_str.split("+")
    
    # Group all words involved to find unique letters
    words = addends + [right_str]
    unique_letters = list(set("".join(words)))
    
    if len(unique_letters) > 10:
        return "Invalid puzzle: More than 10 unique letters. Not solvable in base-10."
    
    # Words in cryptarithms cannot start with the digit 0
    first_letters = set(word[0] for word in words)
    
    solutions = []
    
    # Generate all possible permutations of digits 0-9 for the unique letters
    for perm in itertools.permutations(range(10), len(unique_letters)):
        # Create a dictionary mapping letters to the current permutation of digits
        mapping = dict(zip(unique_letters, perm))
        
        # Skip this permutation if any starting letter is mapped to 0
        if any(mapping[letter] == 0 for letter in first_letters):
            continue
            
        # Helper function to convert a word to its numeric value based on the mapping
        def word_to_number(word):
            return int("".join(str(mapping[char]) for char in word))
        
        # Calculate the sums
        left_sum = sum(word_to_number(word) for word in addends)
        right_sum = word_to_number(right_str)
        
        # Check if the equation holds true
        if left_sum == right_sum:
            sol_str = " + ".join(str(word_to_number(w)) for w in addends) + " = " + str(right_sum)
            solutions.append((mapping, sol_str))
            
    return solutions

def display_results(equation):
    print(f"Solving: {equation.upper()}")
    print("-" * 30)
    
    solutions = solve_cryptarithm(equation)
    
    if isinstance(solutions, str):
        # This handles our error strings
        print(solutions)
    elif not solutions:
        print("No solution found.")
    else:
        for mapping, math_str in solutions:
            print(math_str)
            # Format the dictionary into a neat string like (A=1, B=2)
            details = ", ".join(f"{k}={v}" for k, v in sorted(mapping.items()))
            print(f"({details})\n")

# --- Test the code with your inputs ---
if __name__ == "__main__":
    display_results(input())