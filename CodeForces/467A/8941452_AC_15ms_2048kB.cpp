#include<iostream>
using namespace std;

int ans = 0;
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int p,q;
        cin >> p >> q;
        if(q-p >= 2)
            ans++;
    }
    cout << ans;
    return 0;
}