def print_words(words):
    for word in words:
        print(word)

def count_vowels(words):
    for word in words:
        vowel_count = sum(1 for char in word.lower() if char in 'aeiou')
        print(f"{word}, vowel count = {vowel_count}")

def count_distinct(words):
    distinct_words = set(words)
    for word in distinct_words:
        count = words.count(word)
        print(f"{word.rjust(20)}: {'*' * count}")

def main():
    input_line = input("Enter a line of text: ")
    words = [word.strip() for word in input_line.split() if word.isalpha()]

    print("\nAll the words:")
    print("-----------------------------")
    print_words(words)
    print("-----------------------------")

    print("\nVowel Count:")
    print("-----------------------------")
    count_vowels(words)
    print("-----------------------------")

    print("\nDistinct Words:")
    print("-----------------------------")
    count_distinct(words)
    print("-----------------------------")

if __name__ == "__main__":
    main()
