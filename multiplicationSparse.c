#include <stdio.h>

void multiplySparseMatrices(int A[][3], int B[][3], int k) {
    int C[k][3];
    
    // Initialize result matrix C with all elements as 0
    for(int i = 0; i < k; i++) {
        C[i][0] = A[i][0];
        C[i][1] = A[i][1];
        C[i][2] = 0;
    }
    
    // Multiply A and B
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            if(A[i][1] == B[j][0]) {
                C[i][2] += A[i][2] * B[j][2];
            }
        }
    }
    
    // Print the resulting matrix C
    printf("Resulting Matrix C:\n");
    for(int i = 0; i < k; i++) {
        printf("%d %d %d\n", C[i][0], C[i][1], C[i][2]);
    }
}

int main() {
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int A[k][3], B[k][3];

    // Input matrix A
    printf("Enter elements of matrix A:\n");
    for(int i = 0; i < k; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }

    // Input matrix B
    printf("Enter elements of matrix B:\n");
    for(int i = 0; i < k; i++) {
        scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);
    }

    // Multiply A and B
    multiplySparseMatrices(A, B, k);

    return 0;
}
