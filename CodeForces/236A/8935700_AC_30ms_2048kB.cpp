#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
char s[156];
bool alpha[27];
int counter = 0;
int main(){
    cin >> s;
    for(int i = 0; i < strlen(s); i++){
        alpha[s[i]-'a'+1] = true;
    }
    for(int j = 1; j <= 26; j++){
        if(alpha[j])
            counter++;
    }
    if(counter%2)
        cout <<"IGNORE HIM!";
    else
        cout << "CHAT WITH HER!";
    return 0;
}