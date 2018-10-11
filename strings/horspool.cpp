//
// Implementation of Horspool's algorithm is an algorithm for finding substrings in strings
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/strings
// https://github.com/allalgorithms/cpp
//
// Contributed by: Hemant Singh
// Github: @Robcross
#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
using namespace std;

class horspool
{
	private: char p[40],t[40];
	int m,n,s[256];
	public: void shift();int match();
	void read();
};

void horspool:: read ()
{
	cout<<"enter text string\n";
	gets(t);
	cout<<"enter pattern string"<<endl;
	gets(p);
}

void horspool :: shift()
{
	int i;
	m=strlen(p);
	for(i=0;i<=128;i++)
        s[i]=m;
	for(i=0;i<m-1;i++)
	{
        s[p[i]]=m-1-i;
	}
}

int horspool :: match()
{
    int k;
	shift();
	m=strlen(p);
	n=strlen(t);
	int i=m-1;
	while(i<n)
	{
        k=0;
        while(k<m && t[i-k]==p[m-1-k])
        {
            k++;
        }
        if(k==m)
        return(i-m+1);
        i=i+s[t[i]];
    }
    return -1;
}
int  main()
{
    horspool h;
	int pos;
	h.read();
	pos=h.match();
	if(pos==-1)
	cout<<"unsuccessful"<<endl;
	else
	cout<<"successful at "<<pos+1<<"positon"<<endl;
	getch();
	return 0;
}




