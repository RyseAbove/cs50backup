from cs50 import get_int

while True:
    height = get_int("How tall is the tower ")
    if height > 0 and height < 9:
        break

for i in range(0, height, 1):
    for f in range(0, height, 1):
        if i + f < height - 1:
            print(f" ", end="")
        else:
            print(f"#", end="")
    print(f"")
