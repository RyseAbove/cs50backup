#include <cs50.h>
#include <math.h>
#include <stdio.h>

int getQuarter(int changeOwed);
int getDime(int changeOwed);
int getNickel(int changeOwed);
int getPenny(int changeOwed);

int main(void)
{
    int changeOwed;
    do
    {
        changeOwed = round((get_float("How much change is owed? ")) * 100);
    }
    while (changeOwed <= 0);

    int quarter = getQuarter(changeOwed);
    changeOwed = changeOwed - quarter * 25;

    int dime = getDime(changeOwed);
    changeOwed = changeOwed - dime * 10;

    int nickel = getNickel(changeOwed);
    changeOwed = changeOwed - nickel * 5;

    int penny = getPenny(changeOwed);
    changeOwed = changeOwed - penny * 1;

    int minCoin = quarter + dime + nickel + penny;
    printf("%i\n", minCoin);
}

int getQuarter(int changeOwed)
{
    int quarter = 0;
    while (changeOwed >= 25)
    {
        changeOwed = changeOwed - 25;
        quarter++;
    }
    return quarter;
}

int getDime(int changeOwed)
{
    int dime = 0;
    while (changeOwed >= 10)
    {
        changeOwed = changeOwed - 10;
        dime++;
    }
    return dime;
}

int getNickel(int changeOwed)
{
    int nickel = 0;
    while (changeOwed >= 5)
    {
        changeOwed = changeOwed - 5;
        nickel++;
    }
    return nickel;
}

int getPenny(int changeOwed)
{
    int penny = 0;
    while (changeOwed >= 1)
    {
        changeOwed = changeOwed - 1;
        penny++;
    }
    return penny;
}