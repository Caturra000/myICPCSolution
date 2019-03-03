#include<bits/stdc++.h>
#define rep(i,j,k) for(int i = j; i <= k; i++)
using namespace std;
const int maxn = 1e6+11;
string s,t;
int main(){
	ios::sync_with_stdio(0);
	while(cin>>s>>t){
		int dway=0;
		rep(i,0,s.length()-1) if(s[i]!=t[i]) dway++;
		if(dway%2==1){
			cout<<"impossible\n";
			continue;
		}
		else{
			rep(i,0,s.length()-1){
				if(s[i]==t[i]) cout<<s[i];
				else{
					if(dway%2==1) cout<<t[i];
					else cout<<s[i];
					dway--;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}