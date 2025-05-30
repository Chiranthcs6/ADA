#include <stdio.h>
#define MAX 50

int p[MAX], w[MAX];
double x[MAX];
double maxprofit;
int n, m;

void greedyKnapsack(int n, int w[], int p[], int m)
{
    double ratio[MAX];
    int i, j;

    // Calculate the ratio of profit to weight for each item
    for (i = 0; i < n; i++) {
        ratio[i] = (double)p[i] / w[i];
        x[i] = 0.0; // Initialize solution vector
    }

    // Sort items by decreasing profit/weight ratio
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratio
                double temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // Swap weights
                int temp2 = w[i];
                w[i] = w[j];
                w[j] = temp2;

                // Swap profits
                temp2 = p[i];
                p[i] = p[j];
                p[j] = temp2;
            }
        }
    }

    int currentWeight = 0;
    maxprofit = 0.0;

    for (i = 0; i < n; i++) {
        if (currentWeight + w[i] <= m) {
            x[i] = 1.0;
            currentWeight += w[i];
            maxprofit += p[i];
        } else {
            x[i] = (double)(m - currentWeight) / w[i];
            maxprofit += x[i] * p[i];
            break;
        }
    }

    printf("Optimal solution for greedy method: %.2f\n", maxprofit);
    printf("Solution vector for greedy method: ");
    for (i = 0; i < n; i++) {
        printf("%.2f\t", x[i]);
    }
    printf("\n");
}

int main()
{
    int i;

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the objects' weights: ");
    for (i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter the objects' profits: ");
    for (i = 0; i < n; i++)
        scanf("%d", &p[i]);

    printf("Enter the maximum capacity: ");
    scanf("%d", &m);

    greedyKnapsack(n, w, p, m);

    return 0;
}
/*Enter the number of objects: 3
Enter the objects' weights: 10 20 30
Enter the objects' profits: 60 100 120
Enter the maximum capacity: 50
*/
/*Optimal solution for greedy method: 240.00
Solution vector for greedy method: 1.00	1.00	0.33
*/