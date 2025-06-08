#include <stdio.h>
#define MAX 10

int s[MAX], x[MAX], d, n;

void sumofsub(int p, int k, int r) {
    int i;
    x[k] = 1;

    
    if ((p + s[k]) == d) {
        printf("Subset: ");
        for (i = 1; i <= k; i++)
            if (x[i] == 1)
                printf("%d ", s[i]);
        printf("\n");
    }

    
    if (k + 1 <= n && (p + s[k] + s[k + 1]) <= d)
        sumofsub(p + s[k], k + 1, r - s[k]);


    if (k + 1 <= n && (p + r - s[k] >= d) && (p + s[k + 1] <= d)) {
        x[k] = 0;
        sumofsub(p, k + 1, r - s[k]);
    }
}

int main() {
    int i, sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in increasing order: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        sum += s[i];
    }

    printf("Enter the target sum: ");
    scanf("%d", &d);

    if (sum < d || s[1] > d) {
        printf("No subset possible.\n");
    } else {
        printf("Subsets of sum %d are:\n", d);
        sumofsub(0, 1, sum);
    }

    return 0;
}
/*Enter the number of elements: 4
Enter the elements in increasing order: 2 4 6 8
Enter the target sum: 10
*/
/*Subsets of sum 10 are:
Subset: 2 4 4 
Subset: 2 8 
*/