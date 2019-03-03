#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define lowbit(b) (b)&(-b)
using namespace std;
const int maxn = 1e2+1e5;
int ft[maxn];
int rsq(int b){
	int sum = 0;
	while(b){
		sum+=ft[b];
		b-=lowbit(b);
	}
	return sum;
}
void update(int k,int v){
	while(k<maxn){
		ft[k]+=v;
		k+=lowbit(k);
	}
}
int findk(int k){
	int now = 0;
	for(int i = (int)log2(maxn-1); i >= 0; i--){
		now |= (1<<i);
		if(now >= maxn || ft[now] >= k){
			now ^= (1<<i);
		} 
		else k -= ft[now];
	}
	return now+1;
}
int main(){
	int n,op,x,k;
	ios::sync_with_stdio(false); 
	while(cin>>n){
		memset(ft,0,sizeof ft);
		while(n--){
			//scanf("%d%d",&op,&x);
			cin>>op>>x; x++;
			if(op==0){
				update(x,1); 
			}
			else if(op==1){
				if(rsq(x)-rsq(x-1)==0) printf("No Elment!\n");
				else update(x,-1);
			}
			else{
				//scanf("%d",&k);
				cin>>k;
				if(rsq(maxn-1)-rsq(x)<k) printf("Not Find!\n");
				else printf("%d\n",findk(k+rsq(x))-1);
			}
		} 
	}
	return 0;
}
//test