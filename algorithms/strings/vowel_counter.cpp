#include <iostream>
using namespace std;

int main() {
  string s;
  int cnt;
  cout << "Enter the string: ";
  cin >> s;

  cnt = 0;
  for ( char ch : s ) {
    switch ( ch ) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        cnt++;
        break;
      default:
        break;
    }
  }

  cout << "The string has " << cnt << " vowels.\n";

  return 0;
}
