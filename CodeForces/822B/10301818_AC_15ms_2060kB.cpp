#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
using namespace std;
const int INF = 0X3f3f3f3f;
typedef long long ll;
string str1,str2;
int a,b;
vector<int> vi,vii;

void dfs(int c){
	
}
int main(){
	ios::sync_with_stdio(false);
	while(cin>>a>>b){
		cin>>str1>>str2;
		vii.clear();
		ll ans = INF;
		for(int i = 0; i < str2.length()-str1.length()+1; i++){
			ll t = 0;
			for(int j = 0; j < str1.length(); j++){
				//cout<<"str2"<<str2[i+j]<<" "<<"str1"<<" "<<str1[j]<<endl; 
				if(str2[i+j]!=str1[j]){
					t++;
					vi.push_back(j+1);
				}
			}
			if(t<ans){
				vii=vi;
				ans = t;
			}
			vi.clear();
		}
		cout<<ans<<endl;
		for(int i = 0; i < vii.size(); i++){
			if(i!=vii.size()-1) cout<<vii[i]<<" ";
			else cout<<vii[i]<<endl;
		}
	}
	return 0;
} 