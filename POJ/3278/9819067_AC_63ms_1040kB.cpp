#include<cstdio>
#include<queue>
#define min(a,b) (a)>(b)?(b):(a)
using namespace std;
int N,K,t,DP[100005];
queue<int> qi;
int main(){
    for(int i = 0; i < 100005; i++)
        DP[i] = 123456;
    scanf("%d %d",&N,&K);
    DP[N] = 0;
    qi.push(N);
    while(!qi.empty()){
        t = qi.front(); qi.pop();
        if(t-1>=0 && DP[t-1]==123456){
            qi.push(t-1);
            DP[t-1] = min(DP[t]+1,DP[t-1]);
        }
        if(t+1<=100000 && DP[t+1]==123456){
            qi.push(t+1);
            DP[t+1] = min(DP[t]+1,DP[t+1]);
        }
        if(t*2<=100000 && DP[2*t]==123456){
            qi.push(2*t);
            DP[t*2] = min(DP[t]+1,DP[t*2]);
        }
    }
    printf("%d\n",DP[K]);
    return 0;
}