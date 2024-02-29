#include  <iostream>
#include <string>
using namespace std;

string compress(string str){
    string newStr = " ";
    for(int i = 0; i < str.length(); i++){
        int count = 1;
        while(i < str.length() -1 && str[i] == str[i+1]){
            count++;
            i++;
        }
        newStr += str[i];
        if(count > 1){
            newStr += to_string(count);
        }
    }
    return newStr;
}






int main() {
    string str = "aaabbbcccddd";
    cout<< compress(str);
    return 0;
}