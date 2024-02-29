#include <iostream>
#include <string>

using namespace std;


string merge(string word1, string word2){
    string merged;
    int i = 0;
    int j = 0;

    while(i < word1.length() && j < word2.length()){
        merged.push_back(word1[i++]);
        merged.push_back(word2[j++]);
    }
    while( i < word1.length()){
        merged.push_back(word1[i++]);
    }
    while(j < word2.length()){
        merged.push_back(word2[j++]);

    }
}



int main(){
    string word1 = "abc";
    string word2 = "pqr";

    cout<<merge(word1, word2);
    return 0;
}