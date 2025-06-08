#include <stdio.h>
#include <stdlib.h>

int *board, n;


int is_safe(int row, int col) {
    for (int prev_row = 0; prev_row < row; prev_row++) {
        int prev_col = board[prev_row];

       
        if (prev_col == col || abs(prev_col - col) == abs(prev_row - row)) {
            return 0; 
        }
    }
    return 1;
}


void print_board() {
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}


void solve(int row) {
    if (row == n) {
        print_board();
        return;
    }

    for (int col = 0; col < n; col++) {
        if (is_safe(row, col)) {
            board[row] = col;
            solve(row + 1);
            
        }
    }
}

int main() {
    printf("Enter board size (n): ");
    scanf("%d", &n);

    board = (int *)malloc(n * sizeof(int));
    solve(0);
    free(board);

    return 0;
}


/*
Enter board size (n): 4

*/
/*
Solution:
. Q . . 
. . . Q 
Q . . . 
. . Q . 

Solution:
. . Q . 
Q . . . 
. . . Q 
. Q . . 


*/