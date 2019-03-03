#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
int dp[maxn],n;
string arr;
int main(){
	ios::sync_with_stdio(0);
    int T,kase=0; cin>>T;
    while(T--){
        cin>>n>>arr;
        if(arr[0]=='.')dp[0]=1;else dp[0]=0;
        if(arr[0]=='.'||arr[1]=='.')dp[1]=1;else dp[1]=0;
        if(arr[0]=='.'||arr[1]=='.'||arr[2]=='.')dp[2]=1;else dp[2]=0;
        for(int i = 3; i < n; i++){
            if(arr[i]=='#') dp[i]=dp[i-1];
            else dp[i]=dp[i-3]+1;
        }
        cout<<"Case "<<++kase<<": "<<dp[n-1]<<endl;
    }
    return 0;
}