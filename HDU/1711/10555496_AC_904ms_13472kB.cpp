#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 1e6+100;
int nxt[maxn],n,m;
int P[maxn],T[maxn];
void buildNext(int *P){
    int len = m, j = 0;
    memset(nxt,0,sizeof nxt); nxt[0]=-1;
    int t = nxt[0];
    while(j<len-1){
        if(t==-1||P[j]==P[t])
            nxt[++j]=++t;
        else
            t=nxt[t]; 
    } 
} 
int match(int *T,int *P){
    buildNext(P);
    int i = 0;
    int j = 0;
    while(j<m&&i<n){
        if(j==-1||T[i]==P[j]){
            i++;j++;
        } 
        else
            j=nxt[j];
    }
    return i-j;
}
int main(){
	ios::sync_with_stdio(false);
    int t; cin>>t;
    while(t--){
    	memset(T,0,sizeof T);
    	memset(P,0,sizeof P);
    	cin>>n>>m;
    	for(int i = 0; i < n; i++) cin>>T[i];
    	for(int i = 0; i < m; i++) cin>>P[i];
    	int ans=match(T,P);
    	if(ans>n-m) cout<<"-1\n";
    	else cout<<ans+1<<endl;
	}
    return 0; 
}