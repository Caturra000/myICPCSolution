#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b; cin >> a >> b;
    int a1=0,a2=0,a3=0;
    for(int i = 1; i <= 6; i++){
        if(abs(a-i) < abs(b-i)) a1++;
        else if(abs(a-i) == abs(b-i)) a2++;
        else a3++;
    }
    cout << a1 << " " << a2 << " " << a3 << endl;
    return 0;
}