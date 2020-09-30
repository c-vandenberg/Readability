from cs50 import get_string


def main():
    text = get_string("Text: ")
    cole_liau(text)


def cole_liau(t):
    # Number of Letters
    letters = 0
    for c in t:
        if c.isalpha():
            letters += 1
    # Number of words 
    words = 0 
    for w in t:
        if w == " ":
            words += 1
    words += 1
    # Number of sentences
    sentences = 0
    for s in t:
        if s == "." or s == "?" or s == "!":
            sentences += 1
    # Coleman-Liau Index calculation
    L = (letters/words) * 100
    S = (sentences/words) * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)
    if index > 1 and index < 16:
        return print(f"Grade {index}")
    elif index < 1:
        return print("Before Grade 1")
    else:
        return print("Grade 16+")
    

main()
        