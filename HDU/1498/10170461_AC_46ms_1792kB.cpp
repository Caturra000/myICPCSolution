#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 110; 
int G[maxn][maxn];
bool check[maxn];
vector<int> ok;
int match[maxn][2];//left0right1
int k,m,n,from,to,cnt;
bool dfs(int u,int d){
    for(int i = 1; i <= n; i++){
        int v = G[u][i];
        if(check[i]||v!=d) continue;
        check[i] = 1;
        if(!match[i][1]||dfs(match[i][1],d)){
            match[u][0] = i;
            match[i][1] = u;
            return true;
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    while(cin>>n>>k&&n){
    	ok.clear();
        for(int i = 1; i <= n; i++){
        	for(int j = 1; j <= n; j++){
        		cin >> G[i][j];
			}
		}
		for(int d = 1; d <= 50; d++){
			memset(match,0,sizeof match);
			cnt = 0;
			for(int i = 1; i <= n; i++){
	            memset(check,0,sizeof check); //NOTE
	            if(!match[i][0]&&dfs(i,d)) cnt++;
	        }
	        if(cnt>k) ok.push_back(d); 
		}
		if(ok.size()==0) cout << -1 << endl;
	    else for(int i = 0; i < ok.size(); i++){
	    	if(i!=ok.size()-1) cout << ok[i] << " ";
	    	else cout << ok[i] << endl;
		}
    } 
    return 0;
} 