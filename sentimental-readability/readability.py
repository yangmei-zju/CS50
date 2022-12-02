# TODO
import
text = input("Text: ")
words = 1
sentences = 1
letters = 0
i = 0
while true:
    if text[i] == '\0':
        break
    elif text[i] == ' ':
        words = words + 1
    elif text[i] == '.' and text[i] == '?'and text[i] == '!':
        sentences = sentences +  1
    elif text[i] >= 'a' and text[i] <= 'z':
        letters = letters + 1
    elif text[i] >= 'A' and text[i] <= 'Z':
        letters = letters + 1
    i = i + 1

index = 0.0588 * l - 0.296 * s - 15.8
if index < 1.5:
    print("Before Grade 1")
elif index >= 15.5:
    print("Grade 16+")
elif:
    index = index // 1
    print(f"Grade {index}")



