#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>

#define inf FLT_MAX
#define pline printf("\n");

int tChar=0;

struct strg{
	char *x;
};

int wordcnt(char *str){
	int i=0;int flag=0; int wc=1;
	while(str[i]!='\0'){
		i++;
		if(flag==0 && str[i]==' '){
			wc++;
			flag=1;
		}
		else if(str[i]!=' '){
			flag=0;
		}
	}
return wc;
}

int* wlen(char *str, int wc){
	int* wl = malloc(sizeof(int)*wc);
	int i=0, flag=0, wordlen,j=0;
	while(str[i]!='\0'){
		if(flag==0 && str[i]==' '){
			wl[j]=wordlen;j++;
			tChar += wordlen;
			wordlen=0;
			flag=1;
		}
		else if(str[i]!=' '){
			flag=0;
			wordlen++;	printf("%c",str[i]);
		}
		i++;
	}wl[j]=wordlen-1;tChar += wordlen-1;
//	for(i=0;i<wc;i++)
//		printf("%d ",wl[i]);
//	pline
return wl;
}

void badness(int **mat, int *p, int dim, int line){
	int i,j,k,temp,flag;
	for(i=0;i<dim;i++)
		printf("%d ",p[i]);
	pline

	for(i=0; i<dim; i++){
		for(j=i; j<dim; j++){
			temp=0;flag=0;
			for(k=i;k<j+1;k++){
				if(flag==0){
					temp = temp + p[k];
					flag=1;
				}
				else{
					temp = temp + p[k] + 1;
				}
			}
//			printf("temp-%d ",temp);pline
			if(line-temp>=0)
				mat[i][j] = (line-temp)*(line-temp);
			else
				mat[i][j]=50000;
		}
	}
}

int* justify(int **mat, int dim){
	int minCost[dim];
	int* result = malloc(sizeof(int)*dim);
	int i;
	for(i=0;i<dim;i++){minCost[i]=0;result[i]=0;}
	for(i = dim-1; i >= 0 ; i--){
		minCost[i] = mat[i][dim-1];
		result[i] = dim;
		int j;
		for(j=dim-1; j > i; j--){
			if(mat[i][j-1] == 50000){
				continue;
			}
			if(minCost[i] > (minCost[j] + mat[i][j-1])){
				minCost[i] = minCost[j] + mat[i][j-1];
				result[i] = j;
			}
		}
	}
	printf("Min cost %d\n",minCost[0]);
	for(i=0;i<dim;i++){printf("%d ",result[i]);}pline
	return result;
}
char* clearText(char *strg, int length){
    int i,cnt=0; char tem[50];

	char *str = (char *) malloc(sizeof(char) * length+1);
    for (i = 0; strg[i]; i++){
        if (isupper(strg[i])){
			str[cnt++] = strg[i];
			tem[i]=strg[i];
		}
		else if(islower(strg[i])){
			str[cnt++] = strg[i];
			tem[i]=strg[i];
		}
		else{
			
		}
	}str[cnt]='\0';
return str;
}

void pretty(char *str, int *p, int *q, int dim){
	int i=0,j,k,temp=0,max;
	int n[dim],m[dim];
	max=0;
	for(j=0;j<dim;j++){
		if(q[j]>max){
			max=q[j];
			n[k]=max;k++;
		}
	}
	for(i=0;i<k;i++)
		printf("%d ",n[i]);

	pline

	int can=0,tan=0,r;i=0;
	pline
	printf("----------------------------------------------------");
	pline
	while(i!=k){
		for(j=can;j<n[i];j++){
			for(r=tan;r<tan+p[j];r++){
				printf("%c", str[r]);
			}printf(" ");
			tan = tan+p[j];
		}pline
		can=n[i];i++;
	}
	printf("----------------------------------------------------");
	pline
}

int main(){

int i=0,j,k,**mat,dim;

FILE *fp; char ch; char str[1000];// = (char *)malloc(sizeof(char));
fp = fopen("plaintext.txt","r");
while((ch = fgetc(fp))!=EOF){
	str[i]=ch;
	i++;
}str[i] = '\0';
fclose(fp);

dim = wordcnt(str);
int *p=wlen(str, dim);
printf("total words: %d\n",dim);

//mat = (int**)calloc(dim,sizeof(int*));
mat = calloc(dim,sizeof(int*));
for(i=dim-1; i>-1; i--)
    mat[i]=(int*)calloc(i+1,sizeof(int));

badness(mat,p,dim,10);

printf("Badness Matrix: \n");
for(i=0; i<dim; i++)
    for(j=0; j<dim; j++)
        printf("%d%c",j>=i?mat[i][j]:0,j!=dim-1?' ':'\n');

int *q = justify(mat,dim);
printf("tchar %d\n",tChar);
char *pstr = clearText(str, tChar);
pretty(pstr,p,q,dim);

return 0;
}
