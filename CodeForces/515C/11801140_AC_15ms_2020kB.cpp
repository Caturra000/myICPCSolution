#include<bits/stdc++.h>
using namespace std;
//string _4="322";
//string _6="53";
//string _8="7222";
//string _9="7332";
string s[]={"0","1","2","3","322","5","53","7","7222","7332"};
string str;
int n;
int main(){
	while(cin>>n>>str){
//		sort(str.begin(),str.end(),greater<char>());
//		cout<<str<<endl;
		string ans("");
		for(int i = 1; i <= n; i++){
			if(str[i-1]=='0'||str[i-1]=='1')continue;
			ans+=s[str[i-1]-'0'];
		}
		sort(ans.begin(),ans.end(),greater<char>());
		cout<<ans<<endl; 
	}
	return 0;
}
