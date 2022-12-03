# get credit number that is positive
while True:
    number = input("Number: ")
    if int(number) >= 0:
        break

# the length of the number and sum of its digits
length = 1
sum = 0
for d in number:
    n = int(d)
    if length % 2 == 0:
        sum = sum + 2 * n % 10 + 2 * n // 10
    else:
        sum = sum + n
    length = length + 1
    
print(sum)
length = length - 1
if sum % 10 == 0:
    b = int(number)
    while True:
        b = b // 10
        if b < 100:
            break
    print(b)
    if (b == 34 or b == 37) and length == 15:
        print("AMEX")
    elif b >= 51 and b <= 55 and length == 16:
        print("MASTERCARD")
    elif (b >= 40 and b <= 49) and (length == 13 or length == 16):
        print("VISA")
    else:
        print("INVALID")

else:
    print("INVALID")

