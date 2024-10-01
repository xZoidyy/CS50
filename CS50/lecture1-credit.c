#include <stdio.h>
#include <cs50.h>

// FOR VISA

int VISAfirst(long n);
int VISAsecond(long n);

int main(void)
{
    long n;
    int count;
    int sum;
    

    // INPUT CARD NUMBER
    do{
        n = get_long("Credit card number: ");
        count = 0;
        long N = n;

        do {
            N /= 10;
            count++;
        } while (N != 0);

        if(count != 16)
        {
            printf("INVALID NUMBER\n");
        }

    } while(count != 16);

    // WEIRD SUM OD NUMBERS TIMES TWO
    sum = VISAfirst(n);
    // SUM OF LEFT NUMBERS
    sum += VISAsecond(n);

    // CHECK FOR VISA CRITERIA
    if(sum%10 == 0)
    {
        printf("VISA");
    }
    else
    {
        printf("INVALID CART");
    }

}

int VISAfirst(long n) // making sum of every second number times two
{
    int r, k;
    int sum = 0;
    int i = 0;

    while (n > 0) 
    {
        r = n % 10;
        k = 2*r;
        
        if(i % 2 == 1)
        {
            if(k < 10)
            {
                sum += k;
            }
            else // for numbers with more digits
            {
                while(k > 0)
                {
                    sum = sum + (k%10);
                    k = k / 10.;
                }
            }
            
        }

        n = n / 10.;
        i++;
    }

    return sum;
}

int VISAsecond(long n) // making sum of left number
{
    int r;
    int sum = 0;
    int i = 0;

    while (n > 0) 
    {
        r = n % 10;
        
        if(i % 2 == 0)
        {
            sum += r;
        }

        n = n / 10.;
        i++;
    }

    return sum;
}