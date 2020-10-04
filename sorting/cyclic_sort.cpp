#include <time.h>
#include <iostream>
#include <vector>
 
using namespace std;
 
class cSort
{
public:
    void doIt( vector<unsigned> s )
    {
	sq = s; display(); c_sort();
	cout << "writes: " << wr << endl; display(); 
    }
private:
    void display()
    {
	copy( sq.begin(), sq.end(), ostream_iterator<unsigned>( std::cout, " " ) );
	cout << endl;
    }
    void c_sort()
    {
	wr = 0;
	unsigned it, p, vlen = static_cast<unsigned>( sq.size() ); 
	for( unsigned c = 0; c < vlen - 1; c++ )
	{
	    it = sq[c];
	    p = c;
	    for( unsigned d = c + 1; d < vlen; d++ )
		if( sq[d] < it ) p++;
 
	    if( c == p ) continue;
 
	    doSwap( p, it );
 
	    while( c != p )
	    {
		p = c;
		for( unsigned e = c + 1; e < vlen; e++ )
		    if( sq[e] < it ) p++;
 
		doSwap( p, it );
	    }
	}
    }
    void doSwap( unsigned& p, unsigned& it )
    {
	while( sq[p] == it ) p++;
	swap( it, sq[p] );
	wr++;
    }
    vector<unsigned> sq;
    unsigned wr;
};
 
int main(int argc, char ** argv)
{
    srand( static_cast<unsigned>( time( NULL ) ) );
    vector<unsigned> s;
    for( int x = 0; x < 20; x++ )
	s.push_back( rand() % 100 + 21 );
 
    cSort c; c.doIt( s );
    return 0;
}
