#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2+11;
string str;
int t;
int main(){
	while(cin>>str){
		if(str.length()==1){
			if(str[0]=='9'||str[0]<'5')cout<<str<<endl;
			else if(str[0]>='5'){
				t=str[0]-'0';
				t=9-t;
				cout<<t<<endl;
			}
		}
		else{
			if(str[0]=='9'||str[0]<'5');
			else if(str[0]>='5'){
				t=str[0]-'0';t=9-t;
				str[0]=t+'0';
			}
			for(int i = 1; i < str.length(); i++){
				if(str[i]>='5'){
					t=str[i]-'0';t=9-t;
					str[i]=t+'0';
				}
			}
			cout<<str<<endl;
		}
	}
	return 0;
}