#include<bits/stdc++.h>
using namespace std;
char a[103],b[103];
int main(){
    cin >> a >> b;
    for(int i = 0; i < strlen(a); i++){
        if(a[i] == b[i]) cout << 0;
        else cout << 1;
    }
    cout << endl;
    return 0;
}