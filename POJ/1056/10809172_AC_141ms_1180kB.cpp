#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e4+11;
string str[maxn];
int main(){
	ios::sync_with_stdio(0);
	int n=0,kase=0;
	while(cin>>str[n]){
		if(str[n][0]=='9'){
			sort(str,str+n);
			int flag=0,cnt=0;
			for(int i = 1; i < n; i++){
				for(int j = 0; j < str[i-1].length(); j++){
					if(str[i][j]==str[i-1][j]&&str[i][j]&&str[i-1][j]) cnt++;
				}
				if(cnt==str[i-1].length()) {
					flag=1;break;
				}
				cnt=0;
			}
			if(!flag) cout<<"Set "<<++kase<<" is immediately decodable"<<endl;
			else cout<<"Set "<<++kase<<" is not immediately decodable"<<endl;
			n=0;continue;
		}
		n++;
	}
	return 0;
}
