# TODO
def space_print(n):
    for i in range(n):
        print(" ",end = "")

def hash_print(n):
    for i in range(n):
        print("#",end = "")

while true:
    try:
        height = int(input("Height:"))
    except ValueError:
        continue
    if height > 0 and height < 9:
        break

for i in range(1,height,1):
    space_print(height - i)
    hash_print(i)
    print("  ",end = "")
    hash_print(i)
print()





