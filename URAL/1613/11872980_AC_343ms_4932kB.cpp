#include<bits/stdc++.h>
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define scan(a) scanf("%d",&a)
#define clr(a,b) memset(a,b,sizeof a);
using namespace std;
const int maxn = 1e5+11;
vector<int> vec[maxn];
map<int,int> ID;
int x,n,m,l,r,cnt;
int main(){
    while(scan(n)!=EOF){
        rep(i,0,maxn-1) vec[i].clear();
        ID.clear(); cnt=0;
        rep(i,1,n){
            scan(x);
            if(ID[x]==0) ID[x]=++cnt;
            vec[ID[x]].push_back(i);
        }
        scan(m);
        rep(i,1,m){
            scan(l);scan(r);
            scan(x);int id=ID[x];
            vector<int>::iterator it=lower_bound(vec[id].begin(),vec[id].end(),l);
            if(it==vec[id].end()||(*it)>r) printf("0");
            else printf("1");
        }
        printf("\n");
    }
    return 0;
}