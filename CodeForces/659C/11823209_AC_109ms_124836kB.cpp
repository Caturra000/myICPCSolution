#include<bits/stdc++.h>
using namespace std;
bitset<1000000001> a;
int n,m,x,cnt;
vector<int> vec;
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		a.reset();vec.clear();
		for(int i = 1; i <= n; i++){
			scanf("%d",&x);
			a[x]=1;
		}
		cnt=0;
		for(int i = 1; i <= 1e9; i++){
			bool flag=a[i];
			if(flag) continue;
			if(m<i) break;
			vec.push_back(i);m-=i;cnt++;
		}
		printf("%d\n",cnt);
		for(int i = 0; i < vec.size(); i++){
			if(i==vec.size()-1) printf("%d\n",vec[i]);
			else printf("%d ",vec[i]);
		}
	}
	return 0;
}