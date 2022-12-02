# TODO
from cs50 import get_string
text = get_string("Text: ")
words = 1
sentences = 0
letters = 0
i = 0
for text[i] in text:
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
index = round(index)
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")


