#include<cstdio>
#include<cstring>
#define lowbit(b) (b)&(-b)
const int maxn = 1e5+1e2;
int ft1[maxn],ft2[maxn],ft3[maxn],a[maxn];
int rsq(int ft[],int b){
	int sum=0;
	while(b){
		sum+=ft[b];
		b-=lowbit(b);
	}
	return sum;
}
void update(int ft[],int k,int v){
	while(k<maxn){
		ft[k]+=v;
		k+=lowbit(k);
	}
}
int n,x;
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(ft1,0,sizeof ft1);
		memset(ft2,0,sizeof ft2);
		memset(ft3,0,sizeof ft3);
		for(int i = 1; i <= n; i++){
			scanf("%d",&a[i]);
			if(a[i]==1) update(ft1,i,1);
			else if(a[i]==2) update(ft2,i,1);
			else update(ft3,i,1);
		}
		long long sum = 0;
		for(int i = 1; i <= n; i++){
			if(a[i]==1){
				sum+=2*(rsq(ft1,n)-rsq(ft1,i));
				sum+=rsq(ft2,n)-rsq(ft2,i)+rsq(ft3,n)-rsq(ft3,i);
			}
			else if(a[i]==2){
				sum+=rsq(ft1,n)-rsq(ft1,i)+rsq(ft2,n)-rsq(ft2,i);
			}
			else{
				sum+=rsq(ft1,n)-rsq(ft1,i);
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}