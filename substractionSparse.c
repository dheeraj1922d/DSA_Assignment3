#include <stdio.h>

void subtractSparseMatrices(int A[][3], int B[][3], int k) {
    int result[k][3]; // To store the result matrix
    int i = 0, j = 0, r = 0;

    while (i < k && j < k) {
        // If A[i] and B[j] have the same row and column
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            // Subtract the values and store in result
            result[r][0] = A[i][0];
            result[r][1] = A[i][1];
            result[r][2] = A[i][2] - B[j][2];
            i++;
            j++;
            r++;
        } else if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            // If A[i] comes before B[j] in the order, copy A[i] to result
            result[r][0] = A[i][0];
            result[r][1] = A[i][1];
            result[r][2] = A[i][2];
            i++;
            r++;
        } else {
            // If B[j] comes before A[i] in the order, copy -B[j] to result
            result[r][0] = B[j][0];
            result[r][1] = B[j][1];
            result[r][2] = -B[j][2];
            j++;
            r++;
        }
    }

    // Copy remaining elements from A (if any)
    while (i < k) {
        result[r][0] = A[i][0];
        result[r][1] = A[i][1];
        result[r][2] = A[i][2];
        i++;
        r++;
    }

    // Copy remaining elements from B (if any)
    while (j < k) {
        result[r][0] = B[j][0];
        result[r][1] = B[j][1];
        result[r][2] = -B[j][2];
        j++;
        r++;
    }

    // Print the result matrix
    printf("Result Matrix:\n");
    for (int i = 0; i < r; i++) {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
    }
}

int main() {
    int k; // Assuming both matrices have k non-zero elements
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int A[k][3], B[k][3];

    printf("Enter elements of matrix A (row col value):\n");
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }

    printf("Enter elements of matrix B (row col value):\n");
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);
    }

    subtractSparseMatrices(A, B, k);

    return 0;
}
