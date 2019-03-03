#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string s[]={"0","1","2","3","322","5","53","7","7222","7332"};
string str;
int n;
int main(){
	while(cin>>n>>str){
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
