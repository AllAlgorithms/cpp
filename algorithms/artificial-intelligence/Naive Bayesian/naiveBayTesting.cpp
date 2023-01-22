#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<string>refund;
    vector<string>marital;
    vector<string>income;

    //reading testing file.
    FILE *fptr;
	if ((fptr = fopen("naiveBayTest.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

	char r[100], m[100], in[100];

	while(fscanf(fptr, "%s %s %s", r, m, in)!=EOF){
		string s1="";
		string s2="";
		string s3="";

		for(int i=0; i<strlen(r); i++){
            s1 += r[i] ;
        }
        refund.push_back(s1);

		for(int i=0; i<strlen(m); i++){
            s2 += m[i] ;
        }
        marital.push_back(s2);

		for(int i=0; i<strlen(in); i++){
            s3 += in[i] ;
        }
        income.push_back(s3);
	}   //done storing data of Testing file.
	fclose(fptr);

	//for refund likelihood.
	vector<string>refund1;
	vector<string>evade1;
	vector<string>refhood;

	if ((fptr = fopen("refundhood.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

	char r1[100], e1[100], ref1[100];

	while(fscanf(fptr, "%s %s %s", r1, e1, ref1)!=EOF){
		string s1="";
		string s2="";
		string s3="";

		for(int i=0; i<strlen(r1); i++){
            s1 += r1[i] ;
        }
        refund1.push_back(s1);

		for(int i=0; i<strlen(e1); i++){
            s2 += e1[i] ;
        }
        evade1.push_back(s2);

		for(int i=0; i<strlen(ref1); i++){
            s3 += ref1[i] ;
        }
        refhood.push_back(s3);
	}
	fclose(fptr);
	//done storing data of Refund file.


	//for marital likelihood.
	vector<string>marry;
	vector<string>evade2;
	vector<string>maritalhood;

	if ((fptr = fopen("maritalhood.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

	char m1[100], e2[100], mar[100];

	while(fscanf(fptr, "%s %s %s", m1, e2, mar)!=EOF){
		string s1="";
		string s2="";
		string s3="";

		for(int i=0; i<strlen(m1); i++){
            s1 += m1[i] ;
        }
        marry.push_back(s1);

		for(int i=0; i<strlen(e2); i++){
            s2 += e2[i] ;
        }
        evade2.push_back(s2);

		for(int i=0; i<strlen(mar); i++){
            s3 += mar[i] ;
        }
        maritalhood.push_back(s3);
	}
	fclose(fptr);
	//done storing data of marital file.



	//for tax likelihood.
	vector<string>tax;
	vector<string>evade3;
	vector<string>taxhood;

	if ((fptr = fopen("taxhood.txt", "r")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }

	char t[100], e3[100], taxx[100];

	while(fscanf(fptr, "%s %s %s", t, e3, taxx)!=EOF){
		string s1="";
		string s2="";
		string s3="";

		for(int i=0; i<strlen(t); i++){
            s1 += t[i] ;
        }
        tax.push_back(s1);

		for(int i=0; i<strlen(e3); i++){
            s2 += e3[i] ;
        }
        evade3.push_back(s2);

		for(int i=0; i<strlen(taxx); i++){
            s3 += taxx[i] ;
        }
        taxhood.push_back(s3);
	}   //done storing data of tax file.
	fclose(fptr);


    string P_R_Y, P_R_N, P_M_Y, P_M_N, P_T_Y, P_T_N;
    double pry, prn, pmy, pmn, pty, ptn;

    for(int i=0;i<refund.size();i++){
        for(int j=0;j<refund1.size();j++){
            if(refund[i]==refund1[j]){
                if(evade1[j]=="yes"){
                    P_R_Y = refhood[j];
                    pry = std::stod(P_R_Y);
                }
                else{
                    P_R_N = refhood[j];
                    prn = std::stod(P_R_N);
                }
            }
        }
        break;
    }
    cout<<P_R_Y<<"  "<<P_R_N<<"\n";

    for(int i=0;i<marital.size();i++){
        for(int j=0;j<marry.size();j++){
            if(marital[i]==marry[j]){
                if(evade2[j]=="yes"){
                    P_M_Y = maritalhood[j];
                    pmy = std::stod(P_M_Y);
                }
                else{
                    P_M_N = maritalhood[j];
                    pmn = std::stod(P_M_N);
                }
            }
        }
        break;
    }
    cout<<P_M_Y<<"  "<<P_M_N<<"\n";

    for(int i=0;i<income.size();i++){
        for(int j=0;j<tax.size();j++){
            if(income[i]==tax[j]){
                if(evade3[j]=="yes"){
                    P_T_Y = taxhood[j];
                    pty = std::stod(P_T_Y);
                }
                else{
                    P_T_N = taxhood[j];
                    ptn = std::stod(P_T_N);
                }
            }
        }
        break;
    }
    cout<<P_T_Y<<" "<<P_T_N<<"\n\n";

    double yes = (pry*pmy*pty)*1.00;
    double no =  (prn*pmn*ptn)*1.00;

    if(yes>no)
        cout<<"'YES' Class"<<"\n";
    else
        cout<<"'NO' Class"<<"\n";



	return 0;
}
