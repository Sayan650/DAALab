#include <stdio.h>
#include <stdlib.h>

// Function to compute d'(r) in O(n^2) time
int dist1(int* r, int n) {
    int count = 0;
    // Check all pairs (i,j) where i < j
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Increment count if ri > 2rj
            if (r[i] > 2 * r[j]) {
                count++;
            }
        }
    }
    return count;
}

// Helper function for mergesort and counting inversions
int mergeAndCount(int* arr, int left, int mid, int right) {
    int i, j, k;
    int count = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= 2 * R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            // Count inversions
            count += n1 - i;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free temporary arrays
    free(L);
    free(R);

    return count;
}

// Recursive function for mergesort and counting inversions
int sortAndCount(int* arr, int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        // Sort first and second halves
        count += sortAndCount(arr, left, mid);
        count += sortAndCount(arr, mid + 1, right);
        // Merge the sorted halves and count inversions
        count += mergeAndCount(arr, left, mid, right);
    }
    return count;
}

// Function to compute d'(r) in O(n log n) time
int dist2(int* r, int n) {
    // Create a copy of the array to avoid modifying the original
    int* temp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp[i] = r[i];
    }
    int result = sortAndCount(temp, 0, n - 1);
    free(temp);
    return result;
}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);

    int* r = (int*)malloc(n * sizeof(int));
    printf("Ranking: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &r[i]);
    }

    int distance1 = dist1(r, n);
    int distance2 = dist2(r, n);

    printf("Distance by Method 1: %d\n", distance1);
    printf("Distance by Method 2: %d\n", distance2);

    free(r);
    return 0;
}