#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<iterator>
using namespace std;
const int maxn = 1e5+11;
typedef pair<int,int> P;
vector<P> vec[maxn];
vector<int> F;
// int F[maxn],P[maxn];
int n,m,x,y;
int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(vec,0,sizeof vec); F.clear();
        for(int i = 1; i <= n; i++){
            scanf("%d",&m);
            for(int j = 1; j <= m; j++){
                scanf("%d%d",&x,&y);
                vec[i].push_back(P(x,y));
                F.push_back(x);
            }
        }
        sort(F.begin(),F.end());
        vector<int>::iterator it = unique(F.begin(),F.end());
        F.erase(it,F.end());
        double ans=-1;
        long long tmp=0;
        // for(auto lowf:F){//enum the lb of F
        for(int k = 0; k < F.size(); k++){
            int lowf=F[k];
            tmp=0;
            bool flag=0;
            for(int i = 1; i <= n; i++){
                int mn=0x7fffffff;
                // for(auto t:vec[i]){
                for(int tt = 0; tt < vec[i].size(); tt++){
                    P t=vec[i][tt];
                    if(t.first>=lowf){
                        mn=min(mn,t.second);
                    }
                }
                if(mn==0x7fffffff)flag=1;
                tmp+=mn;
            }
            if(flag==1) continue;
            ans=max(ans,(double)lowf/tmp);
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}