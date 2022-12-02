# TODO
import get_string() from CS50
text = get_string("Text: ")
text = text + '#'
words = 1
sentences = 1
letters = 0
i = 0
while True:
    if text[i] == '#':
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

l = letters / words * 100
s = sentences / words * 100
index = 0.0588 * l - 0.296 * s - 15.8
if index < 1.5:
    print("Before Grade 1")
elif index >= 15.5:
    print("Grade 16+")
else:
    index = round(index)
    print(f"Grade {index}")


