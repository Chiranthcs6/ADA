#include <stdio.h>

#define MAX 50

int weight[MAX], profit[MAX];
double x[MAX];  
int n, capacity;
double maxProfit = 0.0;

void greedyKnapsack() {
    double ratio[MAX];
    int i, j;

    
    for (i = 0; i < n; i++) {
        ratio[i] = (double) profit[i] / weight[i];
        x[i] = 0.0;
    }

    
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                
                double tempRatio = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = tempRatio;

                int temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    int currentWeight = 0;
    for (i = 0; i < n; i++) {
        if (currentWeight + weight[i] <= capacity) {
            x[i] = 1.0;
            currentWeight += weight[i];
            maxProfit += profit[i];
        } else {
            x[i] = (double)(capacity - currentWeight) / weight[i];
            maxProfit += x[i] * profit[i];
            break;
        }
    }

  
    printf("\nMax Profit = %.2f\n", maxProfit);
    printf("Item fractions: ");
    for (i = 0; i < n; i++)
        printf("%.2f ", x[i]);
    printf("\n");
}

int main() {
    int i;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights: ");
    for (i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits: ");
    for (i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    greedyKnapsack();

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