#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
int n,a[maxn];
bool used[maxn];
bool ok[maxn];
int main(){
	ios::sync_with_stdio(0);
	while(cin>>n){
		for(int i = 1; i <= n; i++) cin>>a[i];
		memset(used,0,sizeof used);memset(ok,0,sizeof ok);
		sort(a+1,a+n+1,greater<int>());
		for(int i = 1; i <= n; i++){
			if(!used[a[i]]) used[a[i]]=1,ok[i]=1;
		}
		int sum=0;
		for(int i = 1; i <= n; i++){
			if(!ok[i]){
				for(int j = 1; j <= n; j++){
//					if(a[i]-j>=1&&!used[a[i]-j]){
//						used[a[i]-j]=1;
//						ok[i]=1;
//						sum+=j;
//						break;
//					}
					if(a[i]+j<=maxn&&!used[a[i]+j]){
						used[a[i]+j]=1;
						ok[i]=1;
						sum+=j;
						break;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}