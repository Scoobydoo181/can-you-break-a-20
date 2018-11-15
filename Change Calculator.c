#include <stdio.h>
#include <math.h>

float numBills(float currency, float currentDenom)
{
    return floor(currency / currentDenom);
}

float currencyLeft(float currency, float currentDenom)
{
    return currency - numBills(currency,currentDenom)*currentDenom;
}


void main()
{
    int numDenoms;
    float totalCurrency;
    float usd[] = {100,50,20,10,5,1,0.25,0.10,0.05,0.01};
    numDenoms = (int)sizeof(usd)/sizeof(float);

    printf("Enter the total currency: ");
    scanf(" %f", &totalCurrency);

    for(int i = 0; i < numDenoms; i++)
    {

        printf("%.2f's: %.0f\n",usd[i],numBills(totalCurrency,usd[i]));

        totalCurrency = currencyLeft(totalCurrency,usd[i]);


    }

}
