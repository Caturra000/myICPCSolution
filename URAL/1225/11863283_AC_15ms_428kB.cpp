#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3;
long long F[maxn],n; 
int main(){
	F[1]=F[2]=2;
	for(int i = 3; i <= 45; i++) F[i]=F[i-1]+F[i-2];
	while(cin>>n) cout<<F[n]<<endl;
	return 0;
}