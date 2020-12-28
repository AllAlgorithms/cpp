#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdint>

/*
ever 8 bit packed into uint8_t then writed to file.
uint8_t = 0000 0000 first if bool array member 1 then manipulate 8bit number else do nothing
since its already zero
write to file
*/

using namespace std;
ofstream outfile;

void get_unary(int N, vector  <bool> *v_bool_1_bit )
{
    for (int i = 0; i < N; i++)
    {
        bool b =false;
        (*v_bool_1_bit).push_back(false);
    }
}

string get_biN(int N,unsigned x, vector  <bool> *v_bool_1_bit)
{

    string s ;
    do
    {
        s.push_back('0'+(x&1));
    }
    while(x >>= 1);
        reverse(s.begin(),s.end());

    for (int i = 0; i < N ;i++)
    {

        if( s[i] == '0' )
        {
            (*v_bool_1_bit).push_back( false ) ;
        }
        else
        {
        (*v_bool_1_bit).push_back(true) ;
        }
    }
    return s;
}
void procces(string line)
{
    stringstream ss(line);

    string token;
    while (std::getline(ss, token,'\t'))
    {
        uint8_t num= 0x00;
        stringstream stream(token);
        int x = 0;
        stream >> x;
        vector<bool> ar;
        int N = int(log2(x));
        get_unary(N,&ar);
        get_biN(N+1, x, &ar);

        //write the factor of 8
        int int_part = (N+N+1)/8;
        int i=0;
        for (;i<int_part;i++)
        {
            if( i!=0 && i%8 ==0 )
            {
                    outfile.write( (char*) &num ,sizeof num );
                    num=0x00;
            }
            if(ar[i] == 1) num |= 1 << i;

        }// moving on remainder part of 8ths.

        num=0x00;
        for(int a=0;a<(N+N+1)%8;i++,a++)
        {
            if( ar[i])
            {
                num |= 1 << i;
            }
        }
        outfile.write( (char*) &num ,sizeof num );
    }
}

int main()
{
    string line;
    // file format: tab seperated ints.
    cout<< "please enter the  tab file name you want  to compress.\n";
    string inputfile;
    cin >> inputfile;

    ifstream myfile(inputfile);
    //output file name for example myout.bin
    cout << "please enter the file name yo want to output\n Example: output.bin" << endl;
    string out;
    cin >> out;
    outfile.open(out, ios::binary | ios::out);
    if (myfile.is_open())
    {
        while ( getline(myfile, line,'\r'))
        {
            procces(line);
        }
        myfile.close();
        outfile.close();
    }

    return 0;
}
