#include <stdio.h>
#define INF 999

int prim(int c[10][10], int n, int s)
{
    int v[10], ver[10], d[10];
    int i, j, sum = 0, min, u;

    // Initialization
    for(i = 1; i <= n; i++) {
        ver[i] = s;
        d[i] = c[s][i];
        v[i] = 0;
    }
    v[s] = 1;

    // Prim's algorithm main loop
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
            printf("\nGraph is disconnected. MST cannot be formed completely.");
            return -1;
        }

        v[u] = 1;
        sum += d[u];
        printf("\n%d -> %d  cost=%d", ver[u], u, sum);

        for(j = 1; j <= n; j++) {
            if(v[j] == 0 && c[u][j] < d[j]) {
                d[j] = c[u][j];
                ver[j] = u;
            }
        }
    }

    return sum;
}

int main()
{
    int c[10][10], i, j, res, s, n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 999 for no edge):\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("Enter the source node (1 to %d): ", n);
    scanf("%d", &s);

    res = prim(c, n, s);

    if(res != -1)
        printf("\nTotal cost of MST = %d\n", res);

    return 0;
}


/*
Enter number of nodes: 4
Enter the adjacency matrix:
999  1   3   999
1   999  1   4
3   1   999  2
999 4   2   999
Enter the source node (1 to 4): 1
*/

/*
1 -> 2  cost=1
2 -> 3  cost=2
3 -> 4  cost=4
Total cost of MST = 4
*/