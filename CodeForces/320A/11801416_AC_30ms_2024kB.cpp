#include<bits/stdc++.h>
using namespace std;
string str;
int main(){
	while(cin>>str){
		bool flag=0;
		for(int i = 0; i < str.length(); i++){
			if(str[i]!='1'&&str[i]!='4'){//NOTE
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"NO\n";
			continue;
		}
		for(int i = 0; i < str.length(); i++){
			if(i==0&&str[i]=='4'){flag=1;break;}
			if(i>1&&str[i]=='4'){
				if(str[i-1]=='4'&&str[i-2]=='4'){
					flag=1;
					break;
				}
			}
		}
		if(flag) cout<<"NO"<<endl;
		else cout<<"YES\n";
	}
	return 0;
}