#include<stdio.h>

int print_a(int num, int m){
    if (m == 0 && num > 0)
    {
        return 1;
    }
    if (m >= 0 && num <= m)
    {
        return 0;
    }
    return print_a(num-1, m) + print_a(num-1, m-1);
}

int print_b(int num, int m){
    
}

int main(){
    int print = print_a(5, 3);
    printf("%d\n", print);
}