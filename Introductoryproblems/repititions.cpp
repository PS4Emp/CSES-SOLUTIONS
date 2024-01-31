#include <iostream>
using namespace std; 

int main() {
    string  s;
    cin >> s;

    char x = s[0];
    int c = 1;
    int count = 1;
    
    for( int i = 1; i <  s.size(); i++ )
    {
        if( s[i] != x )
        {
            c = 0;
            x=s[i];
        }
        c++;
        count = max(count, c);

    }   
    
    cout << count << endl;

    return 0;

}