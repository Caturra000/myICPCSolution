#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+11;
int A[maxn],TT[maxn],C[maxn],G[maxn];
string str;
int main(){
	ios::sync_with_stdio(0);
	int T; cin>>T;
	while(T--){
		int n,m; cin>>n>>m;
		memset(A,0,sizeof A);memset(TT,0,sizeof TT);memset(C,0,sizeof C);memset(G,0,sizeof G);
		for(int i = 0; i < n; i++){
			cin>>str;
			for(int j = 0; j < m; j++){
				if(str[j]=='A') A[j]++;
				if(str[j]=='T') TT[j]++;
				if(str[j]=='C') C[j]++;
				if(str[j]=='G') G[j]++;
			}
		}
		int ans=0;
		string res;res.clear();
		for(int i = 0; i < m; i++){
			int ans1=C[i]+G[i]+TT[i];
			int ans2=A[i]+G[i]+TT[i];
			int ans3=A[i]+C[i]+TT[i];
			int ans4=A[i]+C[i]+G[i];
			if(ans1<=min(ans2,min(ans3,ans4))){
				res+="A";ans+=ans1;continue;
			}
			if(ans2<=min(ans1,min(ans3,ans4))){
				res+="C";ans+=ans2;continue;
			}
			if(ans3<=min(ans1,min(ans2,ans4))){
				res+="G";ans+=ans3;continue;
			}
			res+="T";ans+=ans4;
		}
		cout<<res<<endl<<ans<<endl;
	}
	return 0;
}