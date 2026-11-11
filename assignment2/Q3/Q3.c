#include <stdio.h>

void input(int temperature[][50], int num_sensor, int hourly_readings);
void analysis(int temperature[][50], int num_sensor, int hourly_readings, float average[]);
int highestAverage(float average[], int num_sensor);

int main()
{
    int num_sensor, hourly_readings;
    printf("Enter the number of sensors : ");
    scanf("%d", &num_sensor);
    printf("Enter the number of hourly readings : ");
    scanf("%d", &hourly_readings);
    int temperature[50][50];
    float average[50];
    input(temperature, num_sensor, hourly_readings);
    analysis(temperature, num_sensor, hourly_readings, average);
    int sensor;
    sensor = highestAverage(average, num_sensor);
    printf("\n==============================");
    printf("\nFinal Report");
    printf("\n==============================");
    printf("\nSensor with Highest Average Temperature : %d", sensor);
    printf("\nAverage Temperature : %.2f\n", average[sensor]);
    return 0;
}

void input(int temperature[][50], int num_sensor, int hourly_readings)
{
    int i, j;
    for(i=0; i<num_sensor; i++)
    {
        printf("\nSensor %d\n", i+1);
        for(j=0; j<hourly_readings; j++)
        {
            printf("Enter reading for hour %d : ", j);
            scanf("%d", &temperature[i][j]);
        }
    }
}

void analysis(int temperature[][50], int num_sensor, int hourly_readings, float average[])
{
    int i, j;
    int total;
    int max;
    int min;
    int count_crit;
    int count_warn;
    int streak;
    int longest;
    for(i=0; i<num_sensor; i++)
    {
        total = 0;
        count_crit = 0;
        count_warn = 0;
        streak = 0;
        longest = 0;
        max = temperature[i][0];
        min = temperature[i][0];
        for(j=0; j<hourly_readings; j++)
        {
            total = total + temperature[i][j];
            if(temperature[i][j] > max)
            {
                max = temperature[i][j];
            }
            if(temperature[i][j] < min)
            {
                min = temperature[i][j];
            }
            if(temperature[i][j] >= 40)
            {
                count_crit++;
            }
            else if(temperature[i][j] >= 35 && temperature[i][j] <= 39)
            {
                count_warn++;
            }
            if(temperature[i][j] >= 35)
            {
                streak++;
                if(streak > longest)
                {
                    longest = streak;
                }
            }
            else
            {
                streak = 0;
            }
        }
        average[i] = (float)total / hourly_readings;
        printf("\n==============================");
        printf("\nSensor %d Report", i);
        printf("\n==============================");
        printf("\nTotal Temperature = %d", total);
        printf("\nAverage Temperature = %.2f", average[i]);
        printf("\nHighest Temperature = %d", max);
        printf("\nLowest Temperature = %d", min);
        printf("\nCritical Readings = %d", count_crit);
        printf("\nWarning Readings = %d", count_warn);
        printf("\nLongest Streak = %d\n", longest);
    }
}

int highestAverage(float average[], int num_sensor)
{
    int i;
    int index = 0;
    for(i=1; i<num_sensor; i++)
    {
        if(average[i] > average[index])
        {
            index = i;
        }
    }
    return index;
}

