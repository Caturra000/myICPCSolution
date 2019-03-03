#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 1e5+11;
int p[maxn],k[maxn];
vector<int> vec;
int main(){
    int T,P,L,kase=0; scanf("%d",&T);
    while(T--){
        vec.clear();
        scanf("%d%d",&P,&L);P-=L;
        for(long long i = 1; i*i <= P; i++){
            if(P%i==0){
                if(i>L) vec.push_back(i);
                if(P/i>L&&P/i!=i) vec.push_back(P/i);
            }
        }
        printf("Case %d: ",++kase);
        if(vec.size()){
            sort(vec.begin(),vec.end());
            for(int i = 0; i < vec.size(); i++){
                if(i==vec.size()-1) printf("%d\n",vec[i]);
                else printf("%d ",vec[i]);
            }
        }
        else printf("impossible\n");
    }
    return 0;
}