#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
#define root 0
const int N = 100001, K = 256;

int sz;
struct tree {
    int nx[K], suff;
    bool flag;
} t[N];
int q[N], endq, stq;
short tmp;
int n, i, j, tmp_pos, x;
string s;
int main()
{
    freopen("console2.in", "r", stdin);
    freopen("console2.out", "w", stdout);
    ios_base :: sync_with_stdio(0);
    cin >> n;
    getline (cin, s);
    for (i = 1; i <= n; ++i) {
        getline (cin, s);
        tmp_pos = 0;
        for (j = 0; j < (int)s.size(); ++j) {
            tmp = int(s[j]) - 32;
            if (t[tmp_pos].nx[tmp] == 0)
                t[tmp_pos].nx[tmp] = ++sz;
            tmp_pos = t[tmp_pos].nx[tmp];
        }
        t[tmp_pos].flag = 1;
    }
    q[endq++] = 0;
    t[0].suff = 0;
    while (stq != endq) {
        x = q[stq++];
        if (x != 0) {
            for (i = 0; i < K; ++i) {
                if (t[x].nx[i] == 0) {
                    t[x].nx[i] = t[t[x].suff].nx[i];
                } else {
                    t[t[x].nx[i]].suff = t[t[x].suff].nx[i];
                    q[endq++] = t[x].nx[i];
                    if(t[t[t[x].nx[i]].suff].flag == 1)
                        t[t[x].nx[i]].flag = 1;
                }
            }
        } else {
            for (i = 0; i < K; ++i) {
                if (t[x].nx[i] == 0) {
                    t[x].nx[i] = 0;
                } else {
                    t[t[x].nx[i]].suff = 0;
                    q[endq++] = t[x].nx[i];
                    if (t[t[t[x].nx[i]].suff].flag == 1)
                        t[t[x].nx[i]].flag = 1;
                }
            }
        }
    }
    while (getline (cin, s)) {
        tmp_pos = 0;
        bool flag = 0;
        for (i = 0; i < (int)s.size(); ++i) {
            tmp = int(s[i]) - 32;
            tmp_pos = t[tmp_pos].nx[tmp];
            if (t[tmp_pos].flag) {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << s << "\n";
    }
    return 0;

}
