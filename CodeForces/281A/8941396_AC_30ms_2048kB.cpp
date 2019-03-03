#include<iostream>
#include<cctype>
using namespace std;
char s[1005];
int main(){
    cin >> s;
    s[0] = toupper(s[0]);
    cout << s;
    return 0;
}