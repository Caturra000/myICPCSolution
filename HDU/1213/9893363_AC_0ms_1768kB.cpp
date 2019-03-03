#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set> 
#include<cstring>
using namespace std;
const int maxn = 1002;
int p[maxn],R[maxn];
bool used[maxn];
void init(){
	for(int i = 0; i < maxn; i++){
		p[i] = i;
	}
	memset(R,0,sizeof R);
	memset(used,0,sizeof used);
}

int find(int i){
    return p[i] == i ? i : p[i]=find(p[i]);
}

void link(int i,int j){
	i = find(i); j = find(j); 
    if(i==j)  return ;
    if(R[i] < R[j]){
        p[i] = j;
    }
    else{
        p[j] = i;
        if(R[i] == R[j])
            R[i]++;
    }
}

bool same(int i,int j){
    return find(i) == find(j);
}
int main(){
	ios::sync_with_stdio(false);
	int T,n,m; cin >> T;
	while(T--){
		cin >> n >> m;
		init(); 
		int a,b;
		for(int i = 0; i < m; i++){
			cin >> a >> b;
			link(a,b);
			used[a] = 1;used[b] = 1;
		}
		set<int> s;int unknow=0;
		for(int i = 1;i <= n; i++){
			if(used[i]) s.insert(find(i));
			else unknow++;
		}
		cout << s.size()+unknow << endl;
	}
	return 0;
}
