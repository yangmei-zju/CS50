# TODO
from cs50 import get_string
text = get_string("Text: ")
words = 1
sentences = 0
letters = 0
i = 0
while True:
    if text[i] == '#':
        break
    elif text[i] == ' ':
        words = words + 1
    elif text[i] == '.' or text[i] == '?' or text[i] == '!':
        sentences = sentences +  1
    elif word >= 'a' or word <= 'z':
        letters = letters + 1
    elif word >= 'A' or word <= 'Z':
        letters = letters + 1
    next(word)


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


