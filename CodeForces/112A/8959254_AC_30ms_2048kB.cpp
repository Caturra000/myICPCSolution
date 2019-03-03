#include<cctype>
#include<string>
#include<iostream>
using namespace std;
string s1,s2;
int counter = 0;


int main(){
    cin >> s1 >> s2;
    for(int i = 0; i < s1.length(); i++){
        s1[i] = tolower(s1[i]);
        s2[i] = tolower(s2[i]);
    }
    if(s1 > s2)
        cout << "1";
    else if(s1 < s2)
        cout << "-1";
    else
        cout << "0";
    return 0;
}