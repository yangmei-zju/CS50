# TODO

while True:
    number = input("Number: ")
    if int(number) >= 0:
        break
length = 1
for d in number:
    n = int(d)
    if length // 2 != 0:
        if n < 5:
            sum1 = sum1 + 2 * n
        else:
            sum1 = sum1 + 2 * n // 10 + 2 * n / 10
    else :
        sum2 = sum2 + 2 * n

length = length - 1
sum = sum1 + sum2
if sum // 10 == 0:
    while b > 100:
        b = b / 10


