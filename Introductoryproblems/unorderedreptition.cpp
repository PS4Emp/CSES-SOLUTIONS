#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s;
    cin >> s;

    const int MAX_CHAR = 256;
    int charCount[MAX_CHAR] = {0};

    for( char ch : s){
        charCount[ch]++;
    }

    char mostRepeat;
    int maxCount = 0;

    for( int i = 0; i < MAX_CHAR; i++)
    {
        if (charCount[i] > maxCount){
            mostRepeat = static_cast<char>(i);
            maxCount = charCount[i];
        }
    }

    cout << "Most repeated character: " << mostRepeat << endl;
    cout << "Total count: " << maxCount << endl;

    return 0; 
}