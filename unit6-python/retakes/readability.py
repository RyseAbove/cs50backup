from cs50 import get_string


def main():
    # get input from the user
    sample = get_string("Input: ")

    letter = 0
    word = 1
    sentence = 0

    # test each character
    for char in sample:
        if str.isalpha(char):
            letter += 1
        if str.isspace(char):
            word += 1
        if char == "!" or char == "?" or char == ".":
            sentence += 1

    # calculate averages

    # determine grade level
    gradeLevel = round(
        0.0588 * (letter * (100 / word)) - (0.296 * (sentence * (100 / word))) - 15.8
    )

    # print grade level
    if gradeLevel < 1:
        print(f"Before Grade 1")

    elif gradeLevel > 16:
        print(f"Grade 16+")

    else:
        print(f"Grade {gradeLevel}")


main()
