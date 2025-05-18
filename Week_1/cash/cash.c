#include <stdio.h>

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

    int quarters = (change) / 25;
    change = change % 25;

    int dimes = change / 10;
    change = change % 10;

    int nickels = change / 5;
    change = change % 5;

    int pennies = change;

    int num_coins = quarters + dimes + nickels + pennies;

    printf("Cost: %i\nChange: %i\n", cost, change);

    printf("Quarters: %i, Dimes: %i, Nickels: %i, Pennies: %i\n", quarters, dimes, nickels, pennies);
    return num_coins;
}


int get_cost(void)
{
    //int cost;
    //do
    //{
    //    int cost = get_int("How much does the item cost? ");
    //}
    //while (cost < 1;)
    
    int cost = 81;
    return cost;
}