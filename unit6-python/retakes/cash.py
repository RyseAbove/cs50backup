from cs50 import get_float

changeOwed = 0


def main():
    while True:
        changeOwed = round((get_float("How much change is owed ")) * 100)
        if changeOwed > 0:
            break

    quarter = getQuarter(changeOwed)
    changeOwed = changeOwed - quarter * 25

    dime = getDime(changeOwed)
    changeOwed = changeOwed - dime * 10

    nickel = getNickel(changeOwed)
    changeOwed = changeOwed - nickel * 5

    penny = getPenny(changeOwed)
    changeOwed = changeOwed - penny * 1

    minCoin = quarter + dime + nickel + penny
    print(f"{minCoin}")

    getQuarter(changeOwed)
    getDime(changeOwed)
    getNickel(changeOwed)
    getPenny(changeOwed)


def getQuarter(changeOwed):
    quarter = 0
    while changeOwed >= 25:
        changeOwed = changeOwed - 25
        quarter = quarter + 1
    return quarter


def getDime(changeOwed):
    dime = 0
    while changeOwed >= 10:
        changeOwed = changeOwed - 10
        dime = dime + 1
    return dime


def getNickel(changeOwed):
    nickel = 0
    while changeOwed >= 5:
        changeOwed = changeOwed - 5
        nickel = nickel + 1
    return nickel


def getPenny(changeOwed):
    penny = 0
    while changeOwed >= 1:
        changeOwed = changeOwed - 1
        penny = penny + 1
    return penny


main()
