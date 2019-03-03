#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
int main(){
    int n,j=0;
    string inp,ans = "girigiriAi123";
    m[ans] = -111;
    while(cin >> n){
        if(n == 0) break;
        m.clear();
        for(int i = 0; i < n; i++){
            cin >> inp;
            if(m[ans] < ++m[inp]) ans = inp;
        }
        cout << ans << endl;
    }
    return 0;
}