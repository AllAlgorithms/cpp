#include<bits/stdc++.h>
using namespace std ;

vector<string>avalue ; //attribute value
vector<string>cvalue ; //class value

int numberofobject = 0;
double priorD=0, priorC=0;

int findOccurance(string att, string cl)
{
    FILE *fptr;
    char a[100], c[100] ; //a-attribute, c-class
    int count = 0 ;
    if ((fptr = fopen("data.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    while (fscanf(fptr, "%s %s", a, c)!= EOF){
        string s = "" ;
        string s2 = "" ;

        for(int i = 0 ; i < strlen(a) ; i++){ //converting char array into string
            s += a[i] ;
         }
         for(int i = 0 ; i < strlen(c) ; i++){
            s2 += c[i] ;
         }
         if(s == att && s2 == cl) count++ ;
    }
    fclose(fptr);
    return count ;
}

int main() {
    char a[100], c[100];
    FILE *fptr;
    if ((fptr = fopen("data.txt", "r")) == NULL){
        printf("Error! opening file");
        exit(1);
    }
    string s = "" ;

    int dogc=0, catc=0;

    while (fscanf(fptr, "%s %s", a, c)!= EOF){
         //printf("%s %s", a, c);
         //printf("\n") ;
         numberofobject++ ; //counting total objects.

         bool flag = false ;
         string s = "" ;
         for(int i = 0 ; i < strlen(a) ; i++){
            s += a[i] ;
         }

         for(int i = 0 ; i < avalue.size() ; i++){
            if(s == avalue[i]) {
                flag = true ;
            }
         }
         if(!flag)
            avalue.push_back(s) ;


         flag = false ;
         s = "" ;
         for(int i = 0 ; i < strlen(c) ; i++){
            s += c[i] ;
         }

         for(int i = 0 ; i < cvalue.size() ; i++){
            if(s == cvalue[i]) {
                flag = true ;
            }
         }
         if(!flag)
            cvalue.push_back(s) ;

         if(s=="dog"){ //counting number of dogs and cats.
            dogc++;
         }
         if(s=="cat"){
            catc++;
         }
    }

    printf("%d\n\n", numberofobject) ;
    for(int i = 0 ; i < avalue.size() ; i++){

        cout<< avalue[i] << endl ;
    }

    for(int i = 0 ; i < cvalue.size() ; i++){
        cout<< cvalue[i] << endl ;
    }

    //calculating likelihood and writing in a file
    ofstream myfile("likelihood.txt");
    myfile<<"Feature"<<"\t"<<"Class"<<"\t"<<"Likelihood"<<"\t"<<"Classifier"<<"\n";
    myfile<<"-------"<<"\t"<<"-----"<<"\t"<<"-----------"<<"\t"<<"----------"<<"\n";

    for(int i = 0 ; i < cvalue.size() ; i++){
        for(int j = 0 ; j < avalue.size() ; j++){
            int n = findOccurance(avalue[j], cvalue[i]) ; //finding occurences of big-dog, small-cat, medium-dog etc.

            cout << avalue[j] << "|" << cvalue[i] << " = "<< n << endl;

            //calculating likelihood
            double liked=0, likec=0;
            if(cvalue[i]=="dog"){
                liked = (n*1.00)/dogc;
                priorD = (dogc*1.00)/numberofobject;

                myfile<<avalue[j]<<"\t"<<cvalue[i]<<"\t"<<liked<<"\t\t"<<priorD*liked<<"\n";
                cout<<liked<<endl;
            }
            else{
                likec = (n*1.00)/catc;
                priorC = (catc*1.00)/numberofobject;

                myfile<<avalue[j]<<"\t"<<cvalue[i]<<"\t"<<likec<<"\t"<<priorC*likec<<"\n";
                cout<<likec<<endl;
            }
        }
    }
    fclose(fptr);

    //priorD = (dogc*1.00)/numberofobject;
    //priorC = (catc*1.00)/numberofobject;

    myfile<<"\n\n"<<"Prior\n-----\n"<<"P(Dog) = "<<priorD<<"\n";
    myfile<<"\n"<<"P(Cat) = "<<priorC<<"\n";
    myfile.close();

    cout<<"\n"<<"Dog count: "<<dogc<<"\n"<<"Cat count: "<<catc<<"\n\n";

    //cout<<priorC<<" "<<priorD<<"\n\n\n";


    string myText;
    ifstream readFile("likelihood.txt");

    while (getline (readFile, myText)){
        cout << myText<<"\n";
    }
    readFile.close();


    return 0;
}

