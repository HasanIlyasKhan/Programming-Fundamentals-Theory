
#include <stdio.h>

int main()
{
    int row, col;
    int i, j, h, k;
    int count, start;
    int middle;
    int currentrow;
    int found = 0;
    int total = 0;
    printf("Enter the number of rows : ");
    scanf("%d", &row);
    printf("Enter the number of seats per row : ");
    scanf("%d", &col);
    int arr[row][col];
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("Enter seat status (0/1) : ");
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nSeating Arrangement\n\n");
    printf("   ");
    for(j=0; j<col; j++)
    {
        printf("%d ", j);
    }
    printf("\n");
    for(i=0; i<row; i++)
    {
        printf("%d  ", i);
        for(j=0; j<col; j++)
        {
            if(arr[i][j]==0)
            {
                printf("_ ");
            }
            else
            {
                printf("X ");
            }
        }
        printf("\n");
    }
    printf("\nSeat Availability Report\n");
    total = 0;
    for(i=0; i<row; i++)
    {
        count = 0;
        for(j=0; j<col; j++)
        {
            if(arr[i][j]==0)
            {
                count++;
            }
        }
        printf("Row %d : %d seats available\n", i, count);
        total = total + count;
    }
    printf("Total available seats = %d\n", total);
    printf("\nEnter the number of customers : ");
    scanf("%d", &k);
    if(k<=0 || k>col)
    {
        printf("Invalid group size.");
        return 0;
    }
    middle = row/2;
    for(i=0; i<row && found==0; i++)
    {
        if(i==0)
        {
            currentrow = middle;
        }
        else if(i%2==1)
        {
            currentrow = middle - (i+1)/2;
        }
        else
        {
            currentrow = middle + i/2;
        }
        if(currentrow<0 || currentrow>=row)
        {
            continue;
        }
        for(j=0; j<=col-k; j++)
        {
            count = 0;
            for(h=j; h<j+k; h++)
            {
                if(arr[currentrow][h]==0)
                {
                    count++;
                }
            }
            if(count==k)
            {
                for(start=j; start<j+k; start++)
                {
                    arr[currentrow][start]=1;
                }
                printf("\nBooking Successful\n");
                printf("Allocated Row : %d\n", currentrow);
                printf("Allocated Seats : ");
                for(start=j; start<j+k; start++)
                {
                    printf("%d ", start);
                }
                found = 1;
                break;
            }
        }
    }
    if(found==1)
    {
        total = 0;
        printf("\nUpdated Seating Arrangement\n\n");
        printf("   ");
        for(j=0; j<col; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
        for(i=0; i<row; i++)
        {
            printf("%d  ", i);
            for(j=0; j<col; j++)
            {
                if(arr[i][j]==0)
                {
                    printf("_ ");
                    total++;
                }
                else
                {
                    printf("X ");
                }
            }
            printf("\n");
        }
        printf("\nRemaining Available Seats = %d\n", total);
    }
    else
    {
        printf("\nNo suitable block of consecutive seats found.\n");
    }
    return 0;
}
