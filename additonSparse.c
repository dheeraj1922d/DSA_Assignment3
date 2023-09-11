#include <stdio.h>

#define MAX_SIZE 100

void addSparseMatrices(int A[][3], int B[][3], int k) {
    int result[MAX_SIZE][3];
    int i, j, a_idx = 0, b_idx = 0, r_idx = 0;

    while (a_idx < k && b_idx < k) {
        if (A[a_idx][0] < B[b_idx][0] || (A[a_idx][0] == B[b_idx][0] && A[a_idx][1] < B[b_idx][1])) {
            result[r_idx][0] = A[a_idx][0];
            result[r_idx][1] = A[a_idx][1];
            result[r_idx][2] = A[a_idx][2];
            a_idx++;
        } else if (A[a_idx][0] > B[b_idx][0] || (A[a_idx][0] == B[b_idx][0] && A[a_idx][1] > B[b_idx][1])) {
            result[r_idx][0] = B[b_idx][0];
            result[r_idx][1] = B[b_idx][1];
            result[r_idx][2] = B[b_idx][2];
            b_idx++;
        } else {
            result[r_idx][0] = A[a_idx][0];
            result[r_idx][1] = A[a_idx][1];
            result[r_idx][2] = A[a_idx][2] + B[b_idx][2];
            a_idx++;
            b_idx++;
        }
        r_idx++;
    }

    while (a_idx < k) {
        result[r_idx][0] = A[a_idx][0];
        result[r_idx][1] = A[a_idx][1];
        result[r_idx][2] = A[a_idx][2];
        a_idx++;
        r_idx++;
    }

    while (b_idx < k) {
        result[r_idx][0] = B[b_idx][0];
        result[r_idx][1] = B[b_idx][1];
        result[r_idx][2] = B[b_idx][2];
        b_idx++;
        r_idx++;
    }

    printf("Resultant matrix:\n");
    for (i = 0; i < r_idx; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int A[MAX_SIZE][3], B[MAX_SIZE][3];

    printf("Enter elements of matrix A (row col value):\n");
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }

    printf("Enter elements of matrix B (row col value):\n");
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);
    }

    addSparseMatrices(A, B, k);

    return 0;
}
