#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string>test;
    vector<string>feature;
    vector<string>cls;
    vector<string>like;
    vector<string>mapc;

	string str;
	ifstream read("cat.txt");

	while(getline (read,str))
    {
		test.push_back(str);
	}
	read.close();

	/*for(int i=0;i<test.size();i++){
		cout<<test[i]<<"\n";
	}*/
	FILE *fptr;
	if ((fptr = fopen("likelihood.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

	char f[100], c[100], l[100], m[100];
	string c1,c2,m1,m2;
	while(fscanf(fptr, "%s %s %s %s", f, c, l, m)!=EOF){
		string s1="";
		string s2="";
		string s3="";
		string s4="";

		for(int i=0; i<strlen(f); i++){
            s1 += f[i] ;
        }
        feature.push_back(s1);

		for(int i=0; i<strlen(c); i++){
            s2 += c[i] ;
        }
        cls.push_back(s2);

		for(int i=0; i<strlen(l); i++){
            s3 += l[i] ;
        }
        like.push_back(s3);

		for(int i=0; i<strlen(m); i++){
            s4 += m[i] ;
        }
        mapc.push_back(s4);
	}

	for(int i=0;i<test.size();i++){
		for(int j=0;j<feature.size();j++){
		    if(test[i]==feature[j])
		    {
			if(cls[j]=="dog")
			{
			    c1 = cls[j];
			    m1 = mapc[j];
			}
			else
			{
			    c2 = cls[j];
			    m2 = mapc[j];
			}
		    }
		}
		if(m1>m2){
		    cout<<test[i]<<"\t--> "<<"dog"<<"\n";
		}
		else{
		    cout<<test[i]<<"\t--> "<<"cat"<<"\n";
		}
	}

	return 0;

}
