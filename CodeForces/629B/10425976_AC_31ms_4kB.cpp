#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+1e2; 
typedef long long ll;
int F[400];
int M[400];
int n,from,to;
char str[20];
int main(){
	ios::sync_with_stdio(false); 
	while(cin>>n){
		memset(F,0,sizeof F);memset(M,0,sizeof M);
		for(int i = 0; i < n; i++){
			cin>>str>>from>>to;
			if(str[0]=='M'){
				for(int j = from; j <= to; j++){
					M[j]++;
				}
			}
			else{
				for(int j = from; j <= to; j++){
					F[j]++;
				}
			}
		}
		int mmax = 0;
		for(int i = 1; i <= 366; i++){
			mmax = max(mmax,min(F[i],M[i]));
		}
		cout<<2*mmax<<endl;
	}
	return 0;
}