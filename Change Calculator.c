#include <stdio.h>
#include <math.h>

float numBills(float currency, float currentDenom)
{
    return floor(currency / currentDenom);
}

int currencyLeft(float currency, float currentDenom)
{
    if(currentDenom >=1)
        return (int)(100*currency) % (int)(100*currentDenom);

    if(currentDenom <=1)
        return (int)(100*currency) % (int)(100*currentDenom);
}


void main()
{
    int numDenoms;
    float totalCurrency;
    float usd[] = {100,50,20,10,5,1,0.25,0.10,0.050,0.01};
    numDenoms = (int)sizeof(usd)/sizeof(float);

    printf("Enter the total currency: ");
    scanf(" %f", &totalCurrency);

    for(int i = 0; i < numDenoms; i++)
    {
        printf("%.2f's: %.0f\n",usd[i],numBills(totalCurrency,usd[i]));

        totalCurrency = currencyLeft(totalCurrency,usd[i])/100;


    }

}
