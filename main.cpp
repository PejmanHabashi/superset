#include <iostream>
#include <vector>
#include <math.h>

class SuperSet {
    public:
        std::vector < std::vector < int > > IterativeSolutionUsingBits ( std::vector<int> nums ) {
            using namespace std;
            unsigned long n = pow ( 2, nums.size() );
            vector<vector<int>> superset;
            for ( unsigned long i=0; i< n; i++ ) {
                auto cpy = i;
                int c = 0;
                vector<int> subset;
                while ( cpy > 0 ) {
                    bool isZeroBitOne = cpy & 1;
                    cpy >>= 1;
                    if ( isZeroBitOne ) {
                        assert( c < nums.size());
                        subset.push_back ( nums[c] );
                    }
                    c++;
                }
                
                superset.push_back( subset );
            }
            return superset;
        }
};

int main( int argc, char* argv[] ) {
    using namespace std;

    SuperSet p;
    auto s = p.IterativeSolutionUsingBits ( vector<int> { 1, 2, 3 } );

    cout << "{ " << endl;
    for (int i=0; i < s.size() ; i++ ) {
        cout << "{ " ;
        for ( int j=0; j < s[i].size(); j++ ) {
            cout << s[i][j];
            if( j != (s[i].size() - 1 ) ) 
                cout << ", ";
        }
        cout << " }" ;
        if ( i != ( s.size() -1 ) )
            cout << ", ";
        cout << endl;
    }
    cout << "}" << endl;
    return 0;
}
