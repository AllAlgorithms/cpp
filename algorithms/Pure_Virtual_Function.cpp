#include<iostream>
using namespace std;
class B
{
    public:
        virtual void show()
        {
            cout<<"This Is class B"<<endl;
        }
};
class D1:public B
{
    public:
        void show()
        {
            cout<<"This Class D1"<<endl;
        }
};
class D2:public B
{
    public:
        void show()
        {
            cout<<"This Is Class D2";
        }
};

int main()
{
    B *p;
    D1 obj1;
    D2 obj2;
    B objbase;
    p=&objbase;
    p->show();
    p=&obj2;
    p->show();    
    return 0;
}
