# TODO
def main():
    height = int(input(Height:))
    while height < 0 or height > 9:
        height = int(input(Height:))
    for i in range(1,height,1):
        space_print()

   #  #
  ##  ##
 ###  ###
####  ####
def space_print(n):
    for i in range(n):
        print(" ",end = "")

def hash_print(n):
    for i in range(n):
        print("#",end = "")
