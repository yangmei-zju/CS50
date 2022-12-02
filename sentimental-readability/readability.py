# TODO
text = input("Text: ")
words = 1
sentences = 1
i = 0
while true:
    if text[i] == '\0':
        break
    if text[i] == ' ':
        words = words + 1
    if text[i] == '.' and text[i] == '?'and text[i] == '!':
        sentences = sentences +  1
    i = i + 1

