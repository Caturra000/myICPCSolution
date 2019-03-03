#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn = 1e5+100;
int nnext[maxn];
string P,T;
void buildNext(string &P){
	int len = P.length(), j = 0;
	memset(nnext,0,sizeof nnext); nnext[0]=-1;
	int t = nnext[0];
	while(j<len-1){
		if(t==-1||P[j]==P[t])
			nnext[++j]=++t;
		else
			t=nnext[t]; 
	} 
} 
int match(string &T,string &P){
	buildNext(P);
	int m = P.length(), j = 0;
	int n = T.length(), i = n-m<0?0:n-m;//0
	while(i<n/*&&j<m*/){
		if(j==-1||T[i]==P[j]){
			i++;j++;
		} 
		else
			j=nnext[j];
	}
	return j;//shi
}
string str1,str2,str3,str4;
int main(){
	ios::sync_with_stdio(false);
	while(cin>>str1>>str2){
		int cnt=match(str1,str2);
//		cout<<cnt<<endl;
//		cout<<str2.substr(cnt,str2.length())<<endl;
		str3=str1;str3+=str2.substr(cnt,str2.length());
		cnt = match(str2,str1);
		str4=str2;str4+=str1.substr(cnt,str1.length());
		if(str3.length()<str4.length()){
			cout<<str3<<endl;
		}
		else if(str3.length()>str4.length()){
			cout<<str4<<endl;
		}
		else if(str3<str4){
			cout<<str3<<endl;
		}
		else{
			cout<<str4<<endl;
		}
	}
	return 0; 
}