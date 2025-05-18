#include <stdio.h>
//#include </home/pmd/CS-50x/CS50x/Week_1/cash/cs50.h>
#include <cs50.h>

int get_cost(void);
int calc_change(int cost);

int main(void)
{
    int cost = get_cost();
    int num_coins = calc_change(cost);

    printf("Total number of coins returned: %i\n", num_coins);
}


int calc_change(int cost)
{
    int change = 100 - cost;

    printf("Cost: %i\nChange owed: %i\n", cost, change);

    int quarters = (change) / 25;
    change = change % 25;

    int dimes = change / 10;
    change = change % 10;

    int nickels = change / 5;
    change = change % 5;

    int pennies = change;

    int num_coins = quarters + dimes + nickels + pennies;

    printf("Quarters: %i, Dimes: %i, Nickels: %i, Pennies: %i\n", quarters, dimes, nickels, pennies);
    return num_coins;
}


int get_cost(void)
{
    int cost;
    do
    {
        cost = get_int("How much does the item cost (0 to 100 cents)? ");
    }
    while (cost < 0 || cost > 100);

    //next line sets cost to a fixed number, for testing purposes only
    //int cost = 47;
    return cost;
}