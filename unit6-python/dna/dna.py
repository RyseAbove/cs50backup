import sys
import csv


def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    information = []
    with open(sys.argv[1], newline="") as file:
        reader = csv.DictReader(file)
        for row in reader:
            information.append(row)
        # print(information)

    # counts[]

    with open(sys.argv[2], "r") as dnaFile:
        dnaReader = dnaFile.read().rstrip()
    # print(dnaReader)

    test = dnaRead(dnaReader)
    print(test)


def dnaRead(dnaReader):
    counter = 1
    string = "AGATC"
    dnaFound = False
    while not dnaFound:
        if string * counter not in dnaReader:
            dnaFound = True
            counter -= 1
    else:
        counter += 1
    return counter


main()
