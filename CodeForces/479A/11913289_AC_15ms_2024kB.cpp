#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int a,b,c;
vector<int> vec;
int main(){
	while(cin>>a>>b>>c){
		vec.clear();
		vec.pb(a+b+c);
		vec.pb(a*b+c);
		vec.pb(a+b*c);
		vec.pb(a*b*c);
		vec.pb(a*(b+c));
		vec.pb((a+b)*c);
		int mx=-300;
		for(auto t:vec){
			mx=max(mx,t);
		}
		cout<<mx<<endl;
	}
}