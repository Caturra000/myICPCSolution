#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+11;
typedef unsigned long long ll;
ll phi[maxn];
void euler(int n){
    for(int i = 1; i <= n; i++){
        phi[i]=i;
    }
    for(int i = 2; i <= n; i++){
        if(phi[i]==i){
            for(int j = i; j <= n; j+=i){
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}
vector<int> P;
void chai(int n){
	P.clear();
	for(ll i = 1; i*i <= n; i++){
		if(n%i==0){
			P.push_back(i);
			if(n/i!=i) P.push_back(n/i);
		}
	}
}
int a[maxn],n;
int main(){
	euler(maxn-1);
	while(scanf("%d",&n)!=EOF){
		ll ans=0;
		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
		for(int i = 1; i <= n; i++){
			chai(a[i]);
			for(int j = 0; j < P.size(); j++){
				ans+=phi[a[i]/P[j]]*P[j];
			}
			ans-=a[i];
		}
		printf("%llu\n",ans);
	}
	return 0;
}