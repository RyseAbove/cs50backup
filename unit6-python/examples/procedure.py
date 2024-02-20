# procedure that says hello as many times as i tell it to
from cs50 import get_int

def main():
    # n = input("Number: ")
    count = get_int("Number: ")
    hello(count)


def hello(count):

    for i in range(count):
        print(f"Hello")

main()