#include <stdio.h>
#define INF 999

int min(int a, int b) {
    return (a < b) ? a : b;
}

void floyd(int p[][10], int n) {
    int i, j, k;
    for (k = 1; k <= n; k++) {
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (p[i][k] != INF && p[k][j] != INF) {
                    p[i][j] = min(p[i][j], p[i][k] + p[k][j]);
                }
            }
        }
    }
}

int main() {
    int a[10][10], n, i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for no direct edge):\n", INF);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    floyd(a, n);

    printf("\nShortest path matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (a[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*
Enter the number of vertices: 4
Enter the adjacency matrix:
0  5  INF 10
INF 0  3  INF
INF INF 0  1
INF INF INF 0
*/
/*
Shortest path matrix:
  0   5   8   9
INF  0   3   4
INF INF  0   1
INF INF INF  0
*/