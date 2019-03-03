#include<bits/stdc++.h>
using namespace std;
string str;
int main(){
	int n,a,b;
	while(cin>>n>>str){
		a=b=0;
		for(int i = 0; i < n; i++){
			if(str[i]=='1') a++;
			else b++;
		}
		cout<<abs(a-b)<<endl; 
	}
	return 0;
}