
#include <stdio.h>

int sumOfDivisor(int num)
{
    int i;
    int sum = 0;
    for(i=1; i<num; i++)
    {
        if(num%i==0)
        {
            sum = sum + i;
        }
    }
    return sum;
}

int main()
{
    int n,total;
    int num1, num2;
    int sum1, sum2;
    total = 0;
    printf("Enter a number till which you wanted to check amicable pairs : ");
    scanf("%d",&n);
    printf("\nAmicable Pairs are :\n");
    for(num1=1; num1<=n; num1++)
    {
        sum1 = sumOfDivisor(num1);
        num2 = sum1;
        if(num2<=n)
        {
            sum2 = sumOfDivisor(num2);
            if(sum2==num1 && num1!=num2)
            {
                if(num1<num2)
                {
                    printf("(%d , %d)\n",num1,num2);
                }
                total = total + 1;
            }
        }
    }
    total = total / 2;
    printf("Total pairs are :%d",total);
    return 0;
}
