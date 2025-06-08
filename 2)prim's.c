#include <stdio.h>

#define INF 999
#define MAX 10

int main() {
    int cost[MAX][MAX];    // Cost/weight matrix
    int visited[MAX] = {0}; // Visited nodes
    int distance[MAX];     // Minimum cost to connect to MST
    int from[MAX];         // Parent node for each vertex
    int n, i, j, min, totalCost = 0, u;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use 999 for no edge):\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int start;
    printf("Enter the starting node (1 to %d): ", n);
    scanf("%d", &start);

    // Initialize distance[] and from[]
    for(i = 1; i <= n; i++) {
        distance[i] = cost[start][i];
        from[i] = start;
    }
    visited[start] = 1;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    for(i = 1; i < n; i++) {
        min = INF;
        u = -1;

        // Find the closest unvisited node
        for(j = 1; j <= n; j++) {
            if(!visited[j] && distance[j] < min) {
                min = distance[j];
                u = j;
            }
        }

        if(u == -1) {
            printf("Graph is disconnected.\n");
            return -1;
        }

        // Include the selected node in MST
        visited[u] = 1;
        totalCost += distance[u];
        printf("%d -> %d   cost = %d\n", from[u], u, distance[u]);

        // Update distance[] and from[] based on the new node u
        for(j = 1; j <= n; j++) {
            if(!visited[j] && cost[u][j] < distance[j]) {
                distance[j] = cost[u][j];
                from[j] = u;
            }
        }
    }

    printf("\nTotal cost of MST = %d\n", totalCost);
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