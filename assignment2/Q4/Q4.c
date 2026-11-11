#include <stdio.h>

int getValidDays();
float calculateDailySales(int dayNumber);
int findHighestSalesDay(float dailySales[], int numberOfDays);
void displayBarChart(float dailySales[], int numberOfDays);

int main()
{
    int numberOfDays;
    int i;
    int highestDay;
    float totalFestivalSales;
    float dailySales[7];
    numberOfDays = getValidDays();
    totalFestivalSales = 0;
    for(i=0; i<numberOfDays; i++)
    {
        dailySales[i] = calculateDailySales(i + 1);
        totalFestivalSales = totalFestivalSales + dailySales[i];
    }
    highestDay = findHighestSalesDay(dailySales, numberOfDays);
    printf("\n==============================");
    printf("\nFestival Sales Summary");
    printf("\n==============================");
    printf("\nTotal Festival Sales = %.2f", totalFestivalSales);
    printf("\nHighest Sales Day = Day %d\n", highestDay);
    displayBarChart(dailySales, numberOfDays);
    return 0;
}

int getValidDays()
{
    int n;
    printf("Enter number of festival days (1-7): ");
    scanf("%d",&n);
    while(n<1 || n>7)
    {
        printf("Invalid input.\n");
        printf("Enter number of festival days (1-7): ");
        scanf("%d",&n);
    }
    return n;
}

float calculateDailySales(int dayNumber)
{
    int num_order;
    int amount;
    int total;
    int max;
    int i;
    float avg;
    total = 0;
    max = 0;
    printf("\nDay %d\n",dayNumber);
    printf("Enter number of orders : ");
    scanf("%d",&num_order);
    for(i=0; i<num_order; i++)
    {
        printf("Enter amount for order %d : ",i+1);
        scanf("%d",&amount);
        while(amount<=0)
        {
            printf("Invalid amount.\n");
            printf("Enter amount for order %d : ",i+1);
            scanf("%d",&amount);
        }
        total = total + amount;
        if(amount>max)
        {
            max = amount;
        }
    }
    avg = (float)total/num_order;
    printf("\nDay %d Report\n",dayNumber);
    printf("Total Sales = %d\n",total);
    printf("Average Order Amount = %.2f\n",avg);
    printf("Highest Order Amount = %d\n",max);
    return (float)total;
}

int findHighestSalesDay(float dailySales[], int numberOfDays)
{
    int i;
    int index;
    float max_sales;
    index = 0;
    max_sales = dailySales[0];
    for(i=1; i<numberOfDays; i++)
    {
        if(dailySales[i]>max_sales)
        {
            max_sales = dailySales[i];
            index = i;
        }
    }
    return index + 1;
}

void displayBarChart(float dailySales[], int numberOfDays)
{
    int i;
    int j;
    printf("\n==============================");
    printf("\nDaily Sales Bar Chart");
    printf("\n==============================\n");
    for(i=0; i<numberOfDays; i++)
    {
        printf("Day %d : ",i+1);
        for(j=0; j<(int)(dailySales[i]/100); j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
