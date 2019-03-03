#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<ll> l,r;
ll n,p,x,cnt;
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n){
		cnt=n;
		while(!l.empty())l.pop();while(!r.empty())r.pop();
		while(n--){
			cin>>x>>p;
			if(p==0){
				while(!r.empty()&&r.top()<x)r.pop(),cnt--;
//				l.push(x);
//				while(!l.empty()&&!r.empty()&&l.top()<r.top())l.pop(); //NOTE Wrong Answer
				if(!r.empty()&&r.top()>x) cnt--;
				
			}
			else r.push(x);
		}
		cout<<cnt<<endl;
	}
	return 0;
}