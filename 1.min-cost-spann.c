#include <stdio.h>
#include <stdlib.h>

#define MAX 9
#define INF 999

int i, j, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[MAX][MAX], parent[MAX];


int find(int i) {   
    while (parent[i])
        i = parent[i];
    return i;
}


int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    printf("\n\tImplementation of    Kruskal's Algorithm\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = INF; 
        }
    }

    printf("\nThe edges of Minimum Cost Spanning Tree are:\n");
    while (ne < n) {
        min = INF;

       
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

       
        if (uni(u, v)) {
            printf("Edge %d: (%d, %d) cost: %d\n", ne++, a, b, min);
            mincost += min;
        }

       
        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nMinimum cost = %d\n", mincost);
    return 0;
}

/*
Enter the number of vertices: 4
Enter the cost adjacency matrix:
0 2 0 6
2 0 3 8
0 3 0 0
6 8 0 0

*/

/*
The edges of Minimum Cost Spanning Tree are:
Edge 1: (1, 2) cost: 2
Edge 2: (2, 3) cost: 3
Edge 3: (1, 4) cost: 6

Minimum cost = 11


*/
