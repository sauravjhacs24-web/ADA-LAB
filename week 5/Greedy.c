#include<stdio.h>

struct item
{
    int weight, profit;
    float ratio;
};

void main()
{
    int i, j, n, capacity;
    float total_profit = 0;

    struct item it[10], temp;

    printf("Enter number of items:\n");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter profit and weight of item %d:\n", i+1);
        scanf("%d%d", &it[i].profit, &it[i].weight);
        it[i].ratio = (float)it[i].profit / it[i].weight;
    }

    printf("Enter knapsack capacity:\n");
    scanf("%d", &capacity);

    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(it[i].ratio < it[j].ratio)
            {
                temp = it[i];
                it[i] = it[j];
                it[j] = temp;
            }
        }
    }

    printf("\nItems selected:\n");

    for(i = 0; i < n; i++)
    {
        if(capacity >= it[i].weight)
        {
            capacity -= it[i].weight;
            total_profit += it[i].profit;
            printf("Item %d taken fully\n", i+1);
        }
        else
        {
            float fraction = (float)capacity / it[i].weight;
            total_profit += it[i].profit * fraction;
            printf("Item %d taken %.2f fraction\n", i+1, fraction);
            break;
        }
    }

    printf("\nMaximum profit = %.2f\n", total_profit);
}
