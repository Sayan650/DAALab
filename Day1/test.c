#include <stdio.h>

// print current combination as a pattern
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i]; j++) {
            printf("S");
        }
        if (i < n - 1) {
            printf("|");
        }
    }
    printf("\n");
}

// Recursive function to generate combinations and print them
void generate_a(int arr[], int in, int c, int s, int N, int *count) {
    if (s <= 0) {
        return;
    }
    if (in == N - 1) {
        arr[in] = s;
        print_array(arr, N);
        (*count)++;
        return;
    }
    for (int i = 1; i <= s - c + 1; i++) {
        arr[in] = i;
        generate_a(arr, in + 1, c - 1, s - i, N, count);
    }
}

// combination generation and count
void print_a(int s, int c) {
    int arr[c];
    int count = 0;
    generate_a(arr, 0, c, s, c, &count);
    printf("Number of Combinations: %d\n", count);
}

int main() {
    int m = 0, n = 0;
    printf("Enter the number of sweets :");
    scanf("%d", &m);
     printf("Enter the number of children :");
     scanf("%d" , &n);
    printf("\nPrint pattern:\n");
    print_a(m, n);
    return 0;
}