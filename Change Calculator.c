#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
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

    char money;
    float cur[14];

    printf("Please enter the letter of the desired currency");
    printf("\nA:[USD]\nB:[GBP]\nC:[EUR]\nD:[YEN]\nE:[CNY]\n");

    scanf(" %c", &money);
    money = toupper(money);
    switch(money)
    {
        case ('A'):
            printf("[USD] has been selected");
            float USD[] = {100,50,20,10,5,1,0.25,0.10,0.05,0.01};
            for(int i = 0; i< sizeof(USD); i++)
            {
                cur[i] = USD[i];
            }
            numDenoms = (int)sizeof(USD)/sizeof(float);
            break;

        case ('B'):
            printf("[GBP] has been selected");
            float GBP[] = {50,20,10,5,2,1,0.50,0.20,0.10,0.05,0.02,0.01};
            for(int i = 0; i< sizeof(GBP); i++)
            {
                cur[i] = GBP[i];
            }
            numDenoms = (int)sizeof(GBP)/sizeof(float);
            break;

        case ('C'):
            printf("[EUR] has been selected");
            float EUR[] = {200,100,50,20,10,5,2,1,0.50,0.20,0.10,0.05,0.02,0.01};
            for(int i = 0; i< sizeof(EUR); i++)
            {
                cur[i] = EUR[i];
            }
            numDenoms = (int)sizeof(EUR)/sizeof(float);
            break;

        case ('D'):
            printf("[YEN] has been selected");
            float YEN[] = {10000,5000,1000,500,100,50,10,5,1};
            for(int i = 0; i< sizeof(YEN); i++)
            {
                cur[i] = YEN[i];
            }
            numDenoms = (int)sizeof(YEN)/sizeof(float);
            break;

        case ('E'):
            printf("[CNY] has been selected");
            float CNY[] = {100,50,20,10,5,1,0.5,0.1};
            for(int i = 0; i< sizeof(CNY); i++)
            {
                cur[i] = CNY[i];
            }
            numDenoms = (int)sizeof(CNY)/sizeof(float);
            break;

        default:
            printf("Error, invalid currency entered");
            break;

    }

    printf("\n\nEnter the total currency: ");
    scanf(" %f", &totalCurrency);

    for(int i = 0; i < numDenoms; i++)
    {

        printf("%.2f's: %.0f\n",cur[i],numBills(totalCurrency,cur[i]));

        totalCurrency = currencyLeft(totalCurrency,cur[i]);


    }

}
