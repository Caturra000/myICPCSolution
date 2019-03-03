#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
ll a,b,c,d,e,f,g,h,i;//aei
int main(){
	ios::sync_with_stdio(false);
	while(cin>>a>>b>>c>>d>>e>>f>>g>>h>>i){
		for(ll ii = 1; ii <= 100000; ii++){
			a = ii; e = a+b+c-g-c; i = a+b+c-c-f;
//			cout<<a<<" "<<e<<" "<<i<<endl;
			if(a+e+i==a+b+c){
				cout<<a<<" "<<b<<" "<<c<<"\n"<<d<<" "<<e<<" "<<f<<"\n"<<g<<" "<<h<<" "<<i<<endl;
				break;
			}
		}
	}
	return 0;
}