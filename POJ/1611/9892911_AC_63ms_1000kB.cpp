#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 30002;
int p[maxn],rank[maxn];
void init(){
	for(int i = 0; i < maxn; i++){
		p[i] = i;
	}
	memset(rank,0,sizeof rank);
}

int find(int i){
    return p[i] == i ? i : p[i]=find(p[i]);
}
void link(int i,int j){
	int p1 = find(i),p2 = find(j);
	if(p1==p2){
		return ;
	}
	rank[p1]+=rank[p2];
	p[p2]=p[p1]; 
}
//void link(int i,int j){
//    if(p[i]==p[j])  return ;
//    if(rank[i] < rank[j]){
//        p[i] = j;
//    }
//    else{
//        p[j] = i;
//        if(rank[i] == rank[j])
//            rank[i]++;
//    }
//    cout << "p[" << i << "] = " << p[i] << " p[" << j << "] = " << p[j] << endl;
//}

bool same(int i,int j){
    return find(i) == find(j);
}

int arr[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n,m;
	while(cin>>n>>m){
		if(n==0) break;
		init();
		int mmm,fir;
		for(int mm = 0; mm < m; mm++){
			cin >> mmm;
			
			if(mmm>0) cin >> fir;
			for(int i = 0; i < mmm-1; i++){
				cin >> arr[i];
				link(fir,arr[i]);
			}
		}
		//int f = find(0);
		int ans = 0;
		for(int i = 0; i < n; i++){
			if(same(i,0)) ans++;
		}
		cout << ans << endl;
	}
	return 0;
}