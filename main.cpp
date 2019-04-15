#include <iostream>
#include <vector>
#include <math.h>
#include <set>

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

        std::set < std::set < int > > RecursiveSolution ( std::set<int> set ) {
            if ( set.size() == 0 ) return {};

            std::set < std::set < int > > results;
            for ( auto item : set ) {
                auto setCopy = set;
                setCopy.erase ( item );
                auto temp = RecursiveSolution ( setCopy );
                for ( auto subset : temp ) {
                    // add this item to the results set
                    results.insert ( subset );
                    // add item to the set
                    subset.insert(item);
                    // add augmented set to the resutls
                    results.insert ( subset );
                }
                results.insert( { item } ) ;
            }

        return  results;
        }

};

int main( int argc, char* argv[] ) {
    using namespace std;

    SuperSet p;
    auto s = p.IterativeSolutionUsingBits ( { 1, 2, 3, 4, 5 } );

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

    auto s2 = p.RecursiveSolution           ( { 1, 2, 3, 4, 5 } );
    cout << "{ " << endl;
    int i = 0;
    for (auto subset : s2 ) {
        cout << "{ " ;
        int j=0;
        for ( auto item : subset ) {
            cout << item;
            if ( j != (subset.size() - 1 ) ) 
                cout << ", ";

            j++;
        }
        cout << " }" ;
        if ( i != ( s.size() -1 ) )
            cout << ", ";
        cout << endl;

        i++;
    }
    cout << "}" << endl;
    return 0;
}
