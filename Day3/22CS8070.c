#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//O(n^4)
bool method0(int n,int *arr){
    for(int a=1;a<=n;a++){
        for(int b=a+1;b<=n ;b++){
            for(int c=b+1;c<=n ;c++){
                for(int l=0;l<n;l++){
                    int i,j,k;
                    if(a==arr[l]){
                        j=l;
                    }
                    else if(b==arr[l]){
                        k=l;
                    }
                    else if(c==arr[l]){
                        i=l;
                    }
                    if(i<j && j<k){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

//O(n^3)
bool method1(int n,int *arr){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int c=arr[i];
                int a=arr[j];
                int b=arr[k];
                if(a<b && b<c){
                    return false;
                }
            }
        }
    }
    return true;
}

//O(n^2)
bool method2(int n,int *arr){
    for(int i=0;i<n;i++){
       int c=arr[i];
       int smallest=c;
       for(int j=i+1;j<n;j++){
            if(arr[j]<smallest){
                smallest=arr[j];
            }
            else if(smallest!=c && arr[j]>smallest && c>arr[j]){
                return false;
            }
       }
    }
    return true;
}

//O(n)
bool method3(int n,int *arr){
    int a=-1;
    int c=arr[0];
    for(int i=1;i<n;i++){
        if(a==-1 && arr[i]<c){
            a=arr[i];
        }
        else if(a!=-1 && arr[i]>a && c>arr[i]){
            return false;
        }
        else if(a!=-1 && arr[i]<a){
            c=a;
            a=arr[i];
        }
    }
    return true;
}
void main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);
    int *s=(int *)malloc(n*sizeof(int));
    printf("Enter the sequence:");
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
    }
    printf("Sequence:");
    for(int i=0;i<n;i++){
        printf("%d ",s[i]);
    }
    printf("\n");
    printf("Method-1:%s \n",method1(n,s)? "Algolicious":"Unalgolicious");
    printf("Method-2:%s \n",method2(n,s)? "Algolicious":"Unalgolicious");
    printf("Method-3:%s \n",method3(n,s)? "Algolicious":"Unalgolicious");
    printf("Method-4:%s \n",method4(n,s)? "Algolicious":"Unalgolicious");
}