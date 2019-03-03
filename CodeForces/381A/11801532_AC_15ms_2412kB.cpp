#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+11;
int a[maxn],n;
int main(){
	while(cin>>n){
		for(int i = 1; i <= n; i++) cin>>a[i];
		int le=1,ri=n;
		int sa=0,sb=0;
		while(1){
			if(le>ri)break;
			if(a[le]>a[ri]){sa+=a[le];le++;}
			else{sa+=a[ri];ri--;}
			if(le>ri)break;
			if(a[le]>a[ri]){sb+=a[le];le++;}
			else{sb+=a[ri];ri--;}
		}
		cout<<sa<<" "<<sb<<endl;
	}
	return 0;
}