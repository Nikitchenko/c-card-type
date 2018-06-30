#include <cs50.h>
#include <stdio.h>
     
    //There are a lot of people with credit cards in this world, so those numbers are pretty long:
    //American Express uses 15-digit numbers, American Express numbers all start with 34 or 37;
    //MasterCard uses 16-digit numbers, MasterCard numbers all start with 51, 52, 53, 54, or 55;
    //and Visa uses 13- and 16-digit numbers. Visa numbers all start with 4
    //(n <= 4000000000000 || n >= 5599999999999999)
    
unsigned long long n;// Global card number variable
int sum(int s);//Function of calculating the sum of Luhn's algorithm.

int main(void)
{
    printf("Number:");
    n = get_long_long();

    if (n<=4000000000000 || (n>4999999999999 && n<340000000000000) || n>=5599999999999999)// Check for number of digits
    {
        printf("INVALID\n");
    }
    else
    {
        if (sum(n) == 0)
        {
            if ((n>=340000000000000 && n <=349999999999999) || (n>=370000000000000 && n<=379999999999999))
            {
                printf("AMEX\n");
            }
            else if (n>=5100000000000000 && n <=5599999999999999)
            {
                printf("MASTERCARD\n");
            }
            else if ((n>=4000000000000 && n <=4999999999999) || (n>=4000000000000000 && n<=4999999999999999))
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}

int sum(int s)
{
    long long a=n, d=n;
    int b, c=0, e, f=0;

    do
    {
        a = a/10;
        b = a%10;
        b = b*2;
        if (b>9)
         {
             b = b-9;
         }
        a = a/10;
        c= b+c;
    }while (a>0);
    
    do
    {
        e = d%10;
        d = d/100;
        f= e+f;
    }while (d>0);
    
    s = c+f;
    //printf("sum= %i\n", s);
     if (s%10 == 0)
        {
            s = 0;
        }
        else
        {
            s = 1;
        }
    return s;
}
