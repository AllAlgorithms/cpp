/*

Author: Krishan singh karki
Algorithm name: Trie tree for seaching a string in n number of string.
This is trie tree data structure implementation in c++. 
We want to search a string an array of string if string is present or 
not with trie data structure.
Trie data structure has lower time complexity as compared to linear search for large
value of n.
*/

/*
HACKTOBERFEST
*/

#include <iostream>
using namespace std;

struct Trie			//creating structure name trie
{
	Trie*  m[26];	//creating mapping for the 26 small latters alphabet
	bool end= false;//0 means not a leaf node  and 1 means it is a leaf node.
};

Trie* BuildtrieTree(Trie* root, const string& s, int start, int size) {
	if(start==size && root==NULL) {	//cheking if this is last char of string and that node does not exist already
		Trie* temp;
		temp=(Trie*)malloc(sizeof(Trie));	//dynamically allocating memory
		temp->end=1;
		root=temp;
	}
	else if(start==size) {	//cheking if this is last char of string but node exist already 

	}
	else if(root!=NULL) {	//cheking for this is not last char in string and node for that char does not exist
		//cout<<s;
		root->end=0;
		root->m[s[start]-'a'] = BuildtrieTree(root->m[s[start]-'a'], s, start+1, size);//recursivly calling child node
	}
	else {	// Finally cheking for this is not last char but that char node exists already.
		Trie* temp;
		temp=(Trie*)malloc(sizeof(Trie));
		temp->end=0;
		root=temp;
		root->m[s[start]-'a']=BuildtrieTree( root->m[s[start]-'a'], s, start+1, size );
	}	
	return root;
}

void checkString(Trie *root, const string& s, int start, int size) {
	if(start==size && root->end==1) {
		// if the start pointer has reached to the end and this is a leaf node.
		cout << "YES, this string exists in the array of strings.";
	}
	else if(root->m[s[start]-'a']!=NULL){
		//start pointer has not reached to the end and there are more 
		//char left in  string to be searched
		checkString(root->m[s[start]-'a'],s,start+1,size);//recursivly calling there child node
	}
	else {	
		//start pointer has not reached to the end and no strings from all the string has meached to this string
		cout << "SORRY, this string does not exist in the array of strings.";
	}
}

int main() {
	Trie *root = NULL;

	//dynamcally alocating the first root node
	root = (Trie*)malloc(sizeof(Trie));
	root->end = 1;

	int num;
	cout << "Enter the number of strings you want to insert : ";
	cin >> num;

	string s[num];
	cout << endl << "Enter your  strings : ";
	for(int i=0; i<num; i++) {
		cin >> s[i];
		BuildtrieTree(root,s[i],0,s[i].length());
	}

	cout << endl << "Enter string you want to search : ";
	string s2;
	cin>>s2;

	checkString(root, s2, 0, s2.length());
}
