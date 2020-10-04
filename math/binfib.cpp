#include <stdio.h>
void bin(long long int arr[][2],long long int brr[][2], long long int n);
void mul(long long int arr1[][2],long long int arr2[][2],long long int brr[][2]);
using namespace std;
int main(void)
{
    long long int b;
    long long int mat[2][2]={{0,1},{1,1}},brr[2][2];
    scanf("%lld", &b);
    bin(mat,brr,b);
     long long int res=brr[1][0];
    printf("%lld\n", res);
}

void bin(long long int arr[][2],long long int brr[][2],long long int b){
    long long int id[2][2]={{0,1},{1,1}};
    if(b==0){
        brr[0][0]=1;
        brr[0][1]=0;
        brr[1][0]=0;
        brr[1][1]=1;
        return;
    } 
    bin(arr,brr,b/2);
    mul(brr,brr,brr);
    if(b%2)  mul(id,brr,brr);
}

void mul(long long int arr1[][2],long long int arr2[][2],long long int brr[][2]){
    long long int sum=0;
    long long int trr[2][2];
    for(long long int i=0;i<2;i++){
        for(long long int j=0;j<2;j++){
            sum=0;
            for(long long int k=0;k<2;k++){
                sum+=(arr1[i][k]*arr2[k][j]);
            }
            trr[i][j]=sum;
        }
    }
    for(long long int i=0;i<2;i++){
        for(long long int j=0;j<2;j++){
            brr[i][j]=trr[i][j];
        }
    }
}