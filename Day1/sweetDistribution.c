#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int print_a(int num, int m, char *result, int i, int j){
    if (i+j == num+m){
        if (i==num && j == m-1){
            print_result(result, num+m-1);
            return 1;
        }
        return 0;
    }
    int total = 0;
    if (i < num)
    {
        result[i+j] = 's';
        total += print_a(num, m, result, i+1, j);
    }
    if (j < m-1)
    {
        if (i > 0)
        {
            result[i+j] = '|';
            total += print_a(num, m, result, i, j+1);
        }
        
    }
    return total;
}

int print_b(int num, int m, char *result, int i, int j, int lastWasSeparator){
    if (i+j == num+m){
        if (i==num && j == m-1){
            print_result(result, num+m-1);
            return 1;
        }
        return 0;
    }
    int total = 0;
    if (i < num)
    {
        result[i+j] = 's';
        total += print_b(num, m, result, i+1, j, 0);
    }
    if (j < m-1 && !lastWasSeparator)
    {
        if (i > 0)
        {
            result[i+j] = '|';
            total += print_b(num, m, result, i, j+1, 1);
        }
        
    }
    return total;
}
void print_result(char *result, int length){
    for (int i=0; i<length; i++){
        printf("%c", result[i]);
    }
}

int main(){
    int n=5, m=4;
    char *result = (char *)malloc((n+m) * sizeof(char));
    int total_a = print_a(n, m, result, 0, 0);
    printf("\nTotal ways to form the pattern A: %d\n", total_a);
    free(result);
}