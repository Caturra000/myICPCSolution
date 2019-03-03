#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 211;
bool d[maxn][maxn];
int n,m,id,od,ans,from,to,cnt,flag;
void floyd(){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) 
				d[i][j] = d[i][j] || (d[i][k]&&d[k][j]); 
}
int main(){
	ios::sync_with_stdio(false);//cin.tie(0);
	while(cin>>n>>m){
		memset(d,0,sizeof d);
		for(int i = 0; i < m; i++){
			cin>>from>>to;
			d[from][to]=1;
		}
		floyd();ans=0;
		for(int i = 1; i <= n; i++){
			id=0;od=0;cnt=0;flag=1;
			for(int j = 1; j <= n; j++){
				if(i==j) continue;
				if(d[i][j]) od++;
				if(d[j][i]) id++; 
//				if(d[i][j]||d[j][i]) cnt++;
//				if(!d[i][j]&&!d[j][i]) flag=0;
			}
			if(id+od==n-1) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}