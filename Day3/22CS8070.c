#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Method 0: Brute force - O(n^4)
bool method0(int *S, int n) {
    for (int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            for (int c = b + 1; c <= n; c++) {
                int i, j, k;
                for (i = 0; i < n && S[i] != c; i++);
                for (j = i + 1; j < n && S[j] != a; j++);
                for (k = j + 1; k < n && S[k] != b; k++);
                if (k < n) return false;
            }
        }
    }
    return true;
}

// Method 1: Brute force, but better - O(n^3)
bool method1(int *S, int n) {
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (S[j] < S[k] && S[k] < S[i]) return false;
            }
        }
    }
    return true;
}

// Method 2: Brute force, more refinement - O(n^2)
bool method2(int *S, int n) {
    for (int i = 0; i < n; i++) {
        int c = S[i];
        for (int j = i + 1; j < n; j++) {
            if (S[j] < c) {
                for (int k = j + 1; k < n; k++) {
                    if (S[j] < S[k] && S[k] < c) return false;
                }
            }
        }
    }
    return true;
}

// Method 3: Good bye brute force - O(n)
bool method3(int *S, int n) {
    int a = -1;
    int c= S[0];
    for (int i = 1; i < n; i++) {
        if (a == -1 && S[i] < c) 
        {
            a = S[i];
        }else if (a!=-1 && S[i] < a && c > S[i])
        {
            return false;
        }else if (a!=-1 && S[i]<a)
        {
            c = a;
            a=S[i];
        }
    }
    return true;
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int *S = (int *)malloc(n * sizeof(int));
    printf("Enter the sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    printf("Sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", S[i]);
    }
    printf("\n");

    printf("Method 0: %s\n", method0(S, n) ? "Algolicious" : "Unalgolicious");
    printf("Method 1: %s\n", method1(S, n) ? "Algolicious" : "Unalgolicious");
    printf("Method 2: %s\n", method2(S, n) ? "Algolicious" : "Unalgolicious");
    printf("Method 3: %s\n", method3(S, n) ? "Algolicious" : "Unalgolicious");

    free(S);
    return 0;
}