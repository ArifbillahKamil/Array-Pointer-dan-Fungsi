#include <stdio.h>

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
  
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            *(chessBoard + x*size + y) = 0;
        }
    }

    int moves[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};

    for (int k = 0; k < 8; k++) {
        int new_i = i + moves[k][0];
        int new_j = j + moves[k][1];
        
        if (new_i >= 0 && new_i < size && new_j >= 0 && new_j < size) {
            *(chessBoard + new_i*size + new_j) = 1;
        }
    }
}

int main() {
    int i, j;
    int chessBoard[8][8];

    printf("Masukkan nilai i dan j (0 <= i, j < 8): ");
    scanf("%d %d", &i, &j);

    koboImaginaryChess(i, j, 8, &chessBoard[0][0]);

    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            printf("%d ", chessBoard[x][y]);
        }
        printf("\n");
    }

    return 0;
}