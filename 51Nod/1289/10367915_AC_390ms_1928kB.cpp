#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
stack<ll> l,r;
ll n,p,x,cnt;
int main(){
	while(cin>>n){
		cnt=n;
		while(!l.empty())l.pop();while(!r.empty())r.pop();
		while(n--){
			cin>>x>>p;
			if(p==0){
//				while(!r.empty()&&r.top()<x)r.pop();
//				l.push(x);
//				while(!l.empty()&&!r.empty()&&l.top()<r.top())l.pop();
				while(!r.empty())
					if(x>r.top()){
						r.pop();cnt--;
					}
					else{
						cnt--;break;
					}
			}
			else r.push(x);
		}
		cout<<cnt<<endl;
	}
	return 0;
}