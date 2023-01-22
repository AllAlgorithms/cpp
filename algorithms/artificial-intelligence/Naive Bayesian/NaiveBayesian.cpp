#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<vector>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<string>Rvalue;
vector<string>Mvalue;
vector<string>Tvalue;
vector<string>Evade;
vector<int>tax;

int numberofobject = 0;
double priorY=0, priorN=0;

int findOccurance(string att, string cl)
{
    FILE *fptr;
    char r[100], m[100], t[100], e[100];
    int count = 0 ;
    if ((fptr = fopen("NaiveBay.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    while (fscanf(fptr, "%s %s %s %s", r, m, t, e)!= EOF){
        string s1 = "" ;
        string s2 = "" ;
        string s3 = "" ;
        string s4 = "" ;

        for(int i = 0 ; i < strlen(r) ; i++){
            s1 += r[i] ;
         }
         for(int i = 0 ; i < strlen(m) ; i++){
            s2 += m[i] ;
         }

         for(int i = 0 ; i < strlen(t) ; i++){
            s3 += t[i] ;
         }
         //n = std::stoi(s3);

         for(int i = 0 ; i < strlen(e) ; i++){
            s4 += e[i] ;
         }
         if(s1 == att && s4 == cl) count++ ;
         if(s2 == att && s4 == cl) count++ ;
    }
    fclose(fptr);
    return count ;
}

int main() {
    char r[100], m[100], t[100], e[100];
    FILE *fptr;
    if ((fptr = fopen("NaiveBay.txt", "r")) == NULL){
        printf("Error! opening file");
        exit(1);
    }
    string s = "" ;

    int yes=0, no=0;

    while (fscanf(fptr, "%s %s %s %s", r, m, t, e)!= EOF){
        //printf("%s %s", a, c);
        //printf("\n") ;
        numberofobject++ ;

        bool flag = false ; //Refund
        string s = "" ;
        for(int i = 0 ; i < strlen(r) ; i++)
        {
            s += r[i] ;
        }
        for(int i = 0 ; i < Rvalue.size() ; i++)
        {
            if(s == Rvalue[i])
            {
                flag = true ;
            }
        }
        if(!flag)
            Rvalue.push_back(s);


        flag = false ; //Marital status
        s = "" ;
        for(int i = 0 ; i < strlen(m) ; i++)
        {
            s += m[i] ;
        }
        for(int i = 0 ; i < Mvalue.size() ; i++)
        {
            if(s == Mvalue[i])
            {
                flag = true ;
            }
        }
        if(!flag)
            Mvalue.push_back(s);

        s = "";
        for(int i=0; i<strlen(t); i++){
            s+=t[i];
        }
        int n = std::stoi(s);
        tax.push_back(n); //storing 'taxable income' in a vector.


        flag = false ; //Evade
        s = "" ;
        for(int i = 0 ; i < strlen(e) ; i++)
        {
            s += e[i] ;
        }
        for(int i = 0 ; i < Evade.size() ; i++)
        {
            if(s == Evade[i])
            {
                flag = true ;
            }
        }
        if(!flag)
            Evade.push_back(s);

        //counting number of yes and no's.
        if(s=="yes")
        {
            yes++;
        }
        if(s=="no")
        {
            no++;
        }
    }

    printf("%d\n\n", numberofobject) ;
    for(int i = 0 ; i < Rvalue.size() ; i++){
        cout<< Rvalue[i] << endl ;
    }
    cout<<endl;
    for(int i = 0 ; i < Mvalue.size() ; i++){
        cout<< Mvalue[i] << endl ;
    }
    cout<<endl;
    for(int i = 0 ; i < Evade.size() ; i++){
        cout<< Evade[i] << endl ;
    }
    cout<<endl;


    ofstream myfile("refundhood.txt"); //likelihood for refund.
    cout<<"Refundhood\n"<<"-----------\n";
    for(int i = 0 ; i < Evade.size() ; i++){
        for(int j = 0 ; j < Rvalue.size() ; j++){
            int n = findOccurance(Rvalue[j], Evade[i]);

            cout<< Rvalue[j] <<"|"<< Evade[i] << " = "<< n << "\t\t";

            //calculating likelihood for refund
            double likeR=0, likeE=0;
            if(Evade[i]=="yes"){
                likeR = (n*1.00)/yes;

                myfile<<Rvalue[j]<<"\t\t"<<Evade[i]<<"\t"<<likeR<<"\n";
                cout<<likeR<<endl;
            }
            else{
                likeE = (n*1.00)/no;

                myfile<<Rvalue[j]<<"\t\t"<<Evade[i]<<"\t"<<likeE<<"\n";
                cout<<likeE<<endl;
            }
        }
    }
    cout<<"\n\n";


    cout<<"Maritalhood\n"<<"-----------\n";
    ofstream myfileM("maritalhood.txt");
    for(int i = 0 ; i < Evade.size() ; i++){
        for(int j = 0 ; j < Mvalue.size() ; j++){
            int n = findOccurance(Mvalue[j], Evade[i]);

            cout << Mvalue[j] <<"|"<< Evade[i] << "= "<< n <<"\t\t";

            //calculating likelihood for marital status
            double likeR=0, likeE=0;
            if(Evade[i]=="yes"){
                likeR = (n*1.00)/yes;

                myfileM<<Mvalue[j]<<"\t\t"<<Evade[i]<<"\t\t"<<likeR<<"\n";
                cout<<likeR<<endl;
            }
            else{
                likeE = (n*1.00)/no;

                myfileM<<Mvalue[j]<<"\t\t"<<Evade[i]<<"\t\t"<<likeE<<"\n";
                cout<<likeE<<endl;
            }
        }
    }
    cout<<"\n\n";


    ofstream myfiletax("taxhood.txt");
    cout<<"Taxhood\n"<<"----------\n";
    double sum = 0;
    for(int i=0; i<tax.size(); i++)
    {
        sum +=tax[i];
    }
    double likeT = 0;
    for(int i=0;i<Evade.size();i++){
        for(int j=0;j<tax.size();j++){
            //int n = findOccurance(Tvalue[j], Evade[i]);
            cout << tax[j] <<"|"<< Evade[i] << "="<<"\t\t";

            double likeR=0, likeE=0;
            if(Evade[i]=="yes"){
                likeR = (tax[j]*1.00)/(sum*yes);
                myfiletax<<tax[j]<<"\t\t"<<Evade[i]<<"\t\t"<<likeR<<"\n";
                cout<<likeR<<"\n";
            }
            else{
                likeE = (tax[j]*1.00)/(sum*no);
                myfiletax<<tax[j]<<"\t\t"<<Evade[i]<<"\t\t"<<likeE<<"\n";
                cout<<likeE<<"\n";
            }
        }
    }
    cout<<"\n\n";

    /*
    for(int i=0; i<tax.size(); i++)
    {
        likeT = (tax[i]/sum)*1.00;
        cout<<tax[i]<<"\t"<<likeT<<"\n";
        myfiletax<<tax[i]<<"\t"<<likeT<<"\n";
    }
    //cout<<"\n"<<"Sum: "<<sum<<"\n";
    cout<<"\n\n";*/


    ofstream myfilePrior("priorhood.txt");
    priorY = (yes*1.00)/numberofobject;
    priorN = (no*1.00)/numberofobject;
    myfilePrior<<"Yes "<<priorY<<"\n";
    myfilePrior<<"No  "<<priorN<<"\n";
    cout<<"Prior(Yes): "<<priorY<<"\n"<<"Prior(No) : "<<priorN<<"\n\n";



    fclose(fptr);

    /*string myText;
    ifstream readFile("refundhood.txt");

    while (getline (readFile, myText)){
        cout << myText<<"\n";
    }
    readFile.close();*/

    return 0;
}


