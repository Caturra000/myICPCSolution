#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,a;
    cin >> n >> m >> a;
    ll len,wid;
    len = n/a;
    wid = m/a;
    if(n%a > 0)
        len++;
    if(m%a > 0)
        wid++;
    cout << len*wid;
    return 0;
}