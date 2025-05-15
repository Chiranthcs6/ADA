#include <stdio.h>

int w[10], p[10], n;


int max(int a, int b) {
    return a > b ? a : b;
}


int knap(int i, int m) {
    if (i > n)
        return 0;
    
    if (w[i] > m)
        return knap(i + 1, m);
    
  
    return max(knap(i + 1, m), p[i] + knap(i + 1, m - w[i]));
}

int main() {
    int m, i, max_pr;

    printf("Enter the number of objects:\n");
    scanf("%d", &n);

    printf("Enter the knapsack capacity:\n");
    scanf("%d", &m);

    printf("Enter the profit followed by weight for each object:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d %d", &p[i], &w[i]);
    }

    max_pr = knap(1, m);
    printf("\nMax profit = %d\n", max_pr);

    return 0;
}
