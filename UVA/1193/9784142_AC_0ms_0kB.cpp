#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
struct isl{
	double l,r;
};
bool cmp(isl a,isl b){
	if(a.r!=b.r) return a.r < b.r;
	return a.l > b.l;
}//d相同 不存在完全重复/包含的区间 
int isl1,isl2;
bool flag;
isl is[1234];
int main(){
	int n,d,kase=0;
	while(scanf("%d %d",&n,&d) == 2){
		if(n==0&&d==0)
			break;
		for(int i = 0; i < n; i++){
			scanf("%d %d",&isl1,&isl2);
			if(isl2 > d || isl2 <= 0){
				flag = 1;
				break;
			}
			is[i].l = (double)isl1-(double)sqrt(d*d-isl2*isl2);
			is[i].r = (double)isl1+(double)sqrt(d*d-isl2*isl2);
			//cout << "pos" << i << ":" << is[i].l <<" " << is[i].r << endl;
		}
		sort(is,is+n,cmp);
		int cnt = 1;
		double point = is[0].r;
		//cout << point << "afas"; 
		for(int i = 0; i < n; i++){
			if(is[i].l<=point){
				continue;
			}
			else{
				cnt++;
				point = is[i].r;
			}
		}
		if(flag){
			printf("Case %d: -1\n",++kase);
			flag = 0;
		}
		else{
			printf("Case %d: %d\n",++kase,cnt);
		}
	}
	return 0;
} 