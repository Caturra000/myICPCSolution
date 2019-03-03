#include<bits/stdc++.h>
using namespace std;
string S,T;
int main(){
	ios::sync_with_stdio(0);
	while(cin>>S>>T){
		int ans=0;
		for(int i = 0; i < S.length();){
			if(T==S.substr(i,T.length())){
				ans++; 
				S[i+T.length()-1]='#';
				i=i+T.length();
			}
			else i++;
//			cout<<S<<endl;
		}
		cout<<ans<<endl;
	}
}