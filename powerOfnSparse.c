#include <stdio.h>

// Function to multiply two sparse matrices
void multiply(int A[][3], int B[][3], int C[][3], int k) {
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for(int x = 0; x < k; x++) {
                C[i][j] += A[i][x] * B[x][j];
            }
        }
    }
}

// Function to print a sparse matrix
void printMatrix(int C[][3], int k) {
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int k, n;

    // Input size k and exponent n
    printf("Enter the value of k: ");
    scanf("%d", &k);
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int A[k][3], B[k][3], C[k][3];

    // Input matrix A
    printf("Enter matrix A(%dx3):\n", k);
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Initialize B as identity matrix
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < 3; j++) {
            if(i == j) {
                B[i][j] = 1;
            } else {
                B[i][j] = 0;
            }
        }
    }

    // Perform A^n
    for(int i = 0; i < n; i++) {
        multiply(B, A, B, k);
    }

    // Print the result
    printf("\nResultant matrix (A^%d):\n", n);
    printMatrix(B, k);

    return 0;
}
