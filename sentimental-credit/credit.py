# TODO

while True:
    number = input("Number: ")
    if int(number) >= 0:
        break
i = 1
for d in number:
    n = int(d)
    if i // 2 != 0:
        if n < 5:
            sum1 = sum1 + 2 * n
        else:
            sum1 = sum1 + 2 * n // 10 + 2 * n / 10
    else :
        if n < 5:
            sum2 = sum2 + 2 * n
        else :
            sum2 = sum2 + 2 * n // 10 + 2 * n / 10




