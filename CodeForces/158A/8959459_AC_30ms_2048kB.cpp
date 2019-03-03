#include<iostream>
using namespace std;
int par[123];

int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> par[i];
    }
    int ans = k;
    if(par[k] > 0){
        for(int i = k+1;i <= n;i++){
            if(par[i] < par[k])
                break;
            ans++;
        }
    }
    else{
        ans--;
        for(int i = k-1;i >= 1; i--){
            if(par[i] > 0)
                break;
            ans--;
        }
    }
    cout << ans;
    return 0;
}