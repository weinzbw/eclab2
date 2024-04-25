#include <stdio.h>

const char *months[12] = {"January","February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void monthlySales(double nums[])
{
    int i;

    printf("\nMonthly sales report for 2022:\n");
    printf("Month\t\tSales\n");

    for (i = 0; i < 12; i++)
    {
        printf("%s\t\t$%.2f\n", months[i], nums[i]);
    }
}

void salesSummary(double nums[])
{
    int i, minMonth, maxMonth;
    double avg;
    double min = 9999999;
    double max = 0;

    for (i = 0; i < 12; i++)
    {
        if (nums[i] < min) {
            min = nums[i];
            minMonth = i;
        }

        if (nums[i] > max) {
            max = nums[i];
            maxMonth = i;
        }
    }

    for (i = 0; i < 12; i++)
    {
        avg += nums[i]/12;
    }
    
    printf("\nSales summary:\nMinimum sales:\t$%.2f\t(%s)\nMaximum sales:\t$%.2f\t(%s)\nAverage sales:\t$%.2f\n\n", min, months[minMonth], max, months[maxMonth], avg);
}

void sixMonth(double nums[])
{
    int i, j;
    double avg = 0;

    for (i = 0; i < 7; i++)
    {
        printf("%s\t-\t", months[i]);

        for (j = i; j < i + 6; j++)
        {
            avg += nums[j]/6;
        }

        printf("%s\t\t$%.2f\n", months[j-1], avg);
        avg = 0;
    }
}

void highToLow(double nums[])
{
    int i, k, l, o, maxMonth;
    int j = 0;
    int highs[12] = {13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13};
    double max = 0;
    int flag = 0;

    printf("\nSales Report (Highest to Lowest):\nMonth\tSales\n");

    for (l = 0; l < 12; l++)
    {
        for (i = 0; i < 12; i++)
        {
            if (nums[i] > max) {
                for (k = 0; k < 12; k++)
                {
                    if (i == highs[k]) {
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    max = nums[i];
                    maxMonth = i; 
                }
            }
        
            flag = 0;
        } 
        printf("%s\t$%.2f\n", months[maxMonth], max);

        highs[j] = maxMonth;
        j++;
        max = 0;
    }



}

int main(void)
{
    FILE *report;
    report = fopen("test.txt", "r");

    double monthlyRev[12];
    int i;

    for (i = 0; i < 12; i++)
    {
        fscanf(report, "%lf\n", &monthlyRev[i]);
    }

    monthlySales(monthlyRev);
    salesSummary(monthlyRev);
    sixMonth(monthlyRev);
    highToLow(monthlyRev);

    return 0;
}