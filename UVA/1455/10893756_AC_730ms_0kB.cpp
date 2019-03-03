#include<cstdio>  
#include<cstring>  
#include<cmath>  
#include<cstdlib>  
#include<iostream>  
#include<algorithm>  
#include<vector>  
#include<map>  
#include<queue>  
#include<stack> 
#include<string>
#include<map> 
#include<set>
#define eps 1e-6 
#define LL long long  
using namespace std;  

const int maxn = 100000 + 100;
const int maxl = 1000000 + 10;
const int INF = 0x3f3f3f3f;
int pa[maxn], low[maxn], high[maxn], pos[maxn], node[maxn];
int sumv1[2*maxl], addv1[2*maxl];  //有多少州
int sumv2[2*maxl], addv2[2*maxl]; 
int n, m;
//pa保存父亲结点，low，high保存该连通分量的上下边界，node保存连通分量中的结点个数 
int find(int x) {
	if(x != pa[x]) return pa[x] = find(pa[x]);
	return x;
}
 
void maintain1(int o, int L, int R) {
	int lc = o*2, rc = o*2+1;
	sumv1[o] = 0;
	if(R > L) {   //考虑左右子树 
		sumv1[o] = sumv1[lc] + sumv1[rc];
	}
	sumv1[o] += addv1[o] * (R-L+1);//考虑add操作 
} 
void update1(int o, int L, int R, int v, int yl, int yr) {
	int lc = o*2, rc = o*2+1;
	if(yl <= L && yr >= R) {   //递归边界 
		addv1[o] += v;		//累加边界的add值 
	} else {
		int M = L + (R-L)/2;
		if(yl <= M) update1(lc, L, M, v, yl, yr);
		if(yr > M) update1(rc, M+1, R, v, yl, yr);
	}
	maintain1(o, L, R);		//递归结束前重新计算本节点的附加信息 
} 
int query1(int o, int L, int R, int add, int yl, int yr) {
	if(yl <= L && yr >= R) {
		return sumv1[o] + add*(R-L+1);
	} else {
		int ans = 0;
		int M = L + (R-L)/2;
		if(yl <= M) ans += query1(o*2, L, M, add + addv1[o], yl, yr);
		if(yr > M)  ans += query1(o*2+1, M+1, R, add + addv1[o], yl, yr);
		return ans;
	}
} 

void maintain2(int o, int L, int R) {
	int lc = o*2, rc = o*2+1;
	sumv2[o] = 0;
	if(R > L) {   //考虑左右子树 
		sumv2[o] = sumv2[lc] + sumv2[rc];
	}
	sumv2[o] += addv2[o] * (R-L+1);//考虑add操作 
} 
void update2(int o, int L, int R, int v, int yl, int yr) {
	int lc = o*2, rc = o*2+1;
	if(yl <= L && yr >= R) {   //递归边界 
		addv2[o] += v;		//累加边界的add值 
	} else {
		int M = L + (R-L)/2;
		if(yl <= M) update2(lc, L, M, v, yl, yr);
		if(yr > M) update2(rc, M+1, R, v, yl, yr);
	}
	maintain2(o, L, R);		//递归结束前重新计算本节点的附加信息 
} 
int query2(int o, int L, int R, int add, int yl, int yr) {
	if(yl <= L && yr >= R) {
		return sumv2[o] + add*(R-L+1);
	} else {
		int ans = 0;
		int M = L + (R-L)/2;
		if(yl <= M) ans += query2(o*2, L, M, add + addv2[o], yl, yr);
		if(yr > M)  ans += query2(o*2+1, M+1, R, add + addv2[o], yl, yr);
		return ans;
	}
} 

void init() {
	memset(addv1, 0 ,sizeof(addv1)); memset(addv2, 0, sizeof(addv2));
	memset(sumv1, 0, sizeof(sumv1)); memset(sumv2, 0, sizeof(sumv2));
	cin >> n; 
	for(int i = 0; i < n; i++) {
		int tmp; cin >> tmp >> pos[i];
	}
	for(int i = 0; i < n; i++) {
		pa[i] = i;
		node[i] = 1;
		high[i] = low[i] = pos[i];
	}
	cin >> m;
}

void solve() {
	char cmd[5];
	int a, b;
	float c;
	while(m--) {
		cin >> cmd;
		if(cmd[0] == 'r') {
			cin >> a >> b;
			if(find(a) != find(b)) {
				if(high[pa[a]] != low[pa[a]]) {
					update1(1, 1, 1000000, -1, low[pa[a]]+1, high[pa[a]]);
					update2(1, 1, 1000000, -node[pa[a]], low[pa[a]]+1, high[pa[a]]);
				}
				if(high[pa[b]] != low[pa[b]]) {
					update1(1, 1, 1000000, -1, low[pa[b]]+1, high[pa[b]]);
					update2(1, 1, 1000000, -node[pa[b]], low[pa[b]]+1, high[pa[b]]);
				}
				node[pa[a]] += node[pa[b]]; 
				low[pa[a]] = min(low[pa[a]], low[pa[b]]);
				high[pa[a]] = max(high[pa[a]], high[pa[b]]);
				pa[pa[b]] = pa[a];
				if(high[pa[a]] != low[pa[a]]) {
					update1(1, 1, 1000000, 1, low[pa[a]]+1, high[pa[a]]);
					update2(1, 1, 1000000, node[pa[a]], low[pa[a]]+1, high[pa[a]]);
				}
			} 
		} else {
			cin >> c;
			cout << query1(1, 1, 1000000, 0, (int)(c+1), (int)(c+1)) << " ";
			cout << query2(1, 1, 1000000, 0, (int)(c+1), (int)(c+1)) << endl;
		//	cout << (int)(c+1) << endl;
		}
	}
}

int main() {
//	freopen("input.txt", "r", stdin);	
	int t; cin >> t;
	while(t--) {
		init();
		solve();
	}
	return 0;
}

//just test