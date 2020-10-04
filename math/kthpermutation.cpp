#include<stdio.h>
#include<algorithm>
void shift(int arr[],int p[]);
void bin(int arr[],int res[],int b);
using namespace std;
int main(void){
    char arr[5]={'a','b','c','d','e'},rres[5];
    int p[5]={4,3,2,1,0},res[5],b=4;
    bin(p,res,b);
    for(int i=0;i<5;i++) rres[i]=arr[res[i]];
    for(int i=0;i<5;i++) printf("%c ",rres[i]);
    printf("\n");
}

void bin(int arr[],int res[],int b){
    if(b==0) {
        for(int i=0;i<5;i++) res[i]=arr[i];
        sort(res,res+5);
        return;
    }
    bin(arr,res,b/2);
    shift(res,res);
    if(b%2) shift(arr,res);
}

void shift(int arr[],int p[]){
    int brr[5];
    for(int i=0;i<5;i++) brr[i]=arr[p[i]];
    for(int i=0;i<5;i++) p[i]=brr[i];
}