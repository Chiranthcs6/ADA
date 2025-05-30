#include <stdio.h>
#define INF 999

void dijkstra(int c[10][10], int n, int s, int d[10]) {
    int v[10], min, u = -1, i, j;

    for(i = 1; i <= n; i++) {
        d[i] = c[s][i];
        v[i] = 0;
    }

    v[s] = 1;

    for(i = 1; i < n; i++) {
        min = INF;
        u = -1;

        for(j = 1; j <= n; j++) {
            if(v[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }

        if(u == -1) {
            // No more reachable nodes
            break;
        }

        v[u] = 1;

        for(j = 1; j <= n; j++) {
            if(v[j] == 0 && c[u][j] != INF && d[u] != INF && d[u] + c[u][j] < d[j]) {
                d[j] = d[u] + c[u][j];
            }
        }
    }
}

int main() {
    int c[10][10], d[10], i, j, s, n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (999 for no edge):\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("Enter the source node (1 to %d): ", n);
    scanf("%d", &s);

    if(s < 1 || s > n) {
        printf("Invalid source node!\n");
        return 1;
    }

    dijkstra(c, n, s, d);

    printf("\nShortest distances from node %d:\n", s);
    for(i = 1; i <= n; i++) {
        if(d[i] == INF)
            printf("To node %d: No path\n", i);
        else
            printf("To node %d: %d\n", i, d[i]);
    }

    return 0;
}
/*Enter the number of nodes: 4
Enter the adjacency matrix:
0 3 999 7
8 0 2 999
5 999 0 1
2 999 999 0
Enter the source node (1 to 4): 1
*/
/*Shortest distances from node 1:
To node 1: 0
To node 2: 3
To node 3: 5
To node 4: 6
*/