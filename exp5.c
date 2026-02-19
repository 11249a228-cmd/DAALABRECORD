#include <stdio.h>

int matrix[25][25], visited_cities[25];
int limit, cost = 0;

// Function to find nearest unvisited city
int tsp(int city)
{
    int i;
    int nearest_city = -1;
    int min = 999;

    for(i = 0; i < limit; i++)
    {
        if(matrix[city][i] != 0 && visited_cities[i] == 0)
        {
            if(matrix[city][i] < min)
            {
                min = matrix[city][i];
                nearest_city = i;
            }
        }
    }

    if(nearest_city != -1)
    {
        cost += min;
    }

    return nearest_city;
}

void minimum_cost(int city)
{
    int nearest_city;

    visited_cities[city] = 1;
    printf("%d ", city + 1);

    nearest_city = tsp(city);

    if(nearest_city == -1)
    {
        nearest_city = 0;
        printf("%d", nearest_city + 1);
        cost += matrix[city][nearest_city];
        return;
    }

    minimum_cost(nearest_city);
}

int main()
{
    int i, j;

    printf("Enter Total Number of Cities: ");
    scanf("%d", &limit);

    printf("\nEnter Cost Matrix:\n");

    for(i = 0; i < limit; i++)
    {
        for(j = 0; j < limit; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
        visited_cities[i] = 0;
    }

    printf("\nPath: ");
    minimum_cost(0);

    printf("\nMinimum Cost: %d\n", cost);

    return 0;
}
