#include <bits/stdc++.h>
using namespace std;

const int NMAX = 100000;
bool used[ NMAX + 1 ];
int v[ NMAX + 1 ];

ifstream fin( "permutari1.in" );
ofstream fout( "permutari1.out" );

void make_perm( int pos, int n ) {
  int i;
  if ( pos == n + 1 ) {
    for ( i = 1; i <= n; i++ )
      cout << v[ i ] << ' ';
    cout << '\n';
    return;
  }

  for ( i = 1; i <= n; i++ ) {
    if ( !used[ i ] ) {
      used[ i ] = true;
      v[ pos ] = i;
      make_perm( pos + 1, n );
      used[ i ] = false;
    }
  }
}

int main() {
  int n;

  cout << "Input an integer: ";
  cin >> n;

  cout << "These are the permutations of the array [ 1, 2, 3, ..., n ]:\n";
  make_perm( 1, n );
  
  return 0;  
}
