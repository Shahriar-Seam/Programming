import random

def randomize_case(s):
    return ''.join(random.choice([c.upper(), c.lower()]) for c in s)

# Items shorter than "kitkat"
short_items = ["alu", "cha", "dal", "dim", "lobon", "muri", "doi", "chips", "toast"]

# Standalone Junk & Bengali Classics
items = [
    "meatbox", "pizza", "burger", "shingara", "samucha", "sandwich", 
    "chanachur", "jilapi", "meat_box", "chicken_fry", "fish_finger",
    "french_fry", "fuchka", "munch", "perk", "alooz", "meridian"
]

# Despair & Funny
despair = ["cgpa_1.5", "backlog", "unpaid_bill", "broken_dream"]

prefixes = ["overpriced_", "spicy_", "cold_", "hot_"]
suffixes = ["_vorta", "_bhaji", "_vuna", "_shake", "_mix"]

target = "kitkat"

with open("input.in", "w") as f:
    t = 10000
    f.write(f"{t}\n")
    for _ in range(t):
        r = random.random()
        
        if r < 0.15: # 15% chance for success
            f.write(randomize_case(target) + "\n")
        elif r < 0.40: # 25% chance for short items
            f.write(randomize_case(random.choice(short_items)) + "\n")
        else:
            # Complex strings
            item = random.choice(items + despair)
            if random.random() < 0.3: item = random.choice(prefixes) + item
            if random.random() < 0.3: item = item + random.choice(suffixes)
            f.write(randomize_case(item[:50]) + "\n")