#include<iostream>
#include<cstring> 
using namespace std;
char s[1005];
bool flag = false;
int main(){
    cin >> s;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9' )
            flag = true;
    }
    if(flag)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
