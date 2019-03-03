#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll maxn = 1e6+100,mmod=1e9+7;
ll quick_pow(ll a,ll n,ll mmod){
    ll ans = 1;
    while(n){
        if(n&1) ans = ans*a%mmod; 
        a = a*a%mmod;
        n >>= 1;
    }
    return ans;
}
string str;
ll cnt,sum;
int main(){
	ios::sync_with_stdio(false);
	while(cin>>str){
		sum=0;cnt=0;
		for(int i = 0; i < str.length(); i++){
			if(str[i]=='a') cnt++;
			else sum = (sum+quick_pow(2,cnt,mmod)-1/*-1*/)%mmod;
		}
		cout<<sum<<endl;
	}
	return 0;
} 