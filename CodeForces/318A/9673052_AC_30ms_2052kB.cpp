#include<bits/stdc++.h>
using namespace std;
int main(){
    __int64 n,k,m; cin >> n >> k;
    if(n%2)
        m = n/2+1;
    else
        m = n/2;
    if(k > m)
        cout << 2*(k-m);
    else
        cout << 2*k-1;
    cout << endl;
    return 0;
}