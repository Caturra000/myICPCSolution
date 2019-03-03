/****************************>>>>HEADFILES<<<<****************************/
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
/****************************>>>>>DEFINE<<<<<*****************************/
#define fst             first
#define snd             second
#define root            1,N,1
#define lson            l,mid,rt<<1
#define rson            mid+1,r,rt<<1|1
#define PB(a)           push_back(a)
#define MP(a,b)         make_pair(a,b)
#define CASE(T)         for(scanf("%d",&T);T--;)
#define FIN             freopen("input.txt","r",stdin)
#define FOUT            freopen("output.txt","w",stdout)
//#pragma comment(linker, "/STACK:1024000000,1024000000")
typedef __int64         LL;
typedef pair<int,int>   PII;
const int INF = 0x3f3f3f3f;
const int maxn = 100000 + 5;
/****************************>>>>SEPARATOR<<<<****************************/
struct Node { int fir,las; }nodes[maxn];
vector<vector<int> > G;
bool vis[maxn];
int C[maxn],S[maxn];
int G_Mark, N, M, u, v;
void init()
{
    G.resize(N+2);
    G_Mark = 0;
    G.clear();
    memset(C,0,sizeof(C));
    memset(vis, false, sizeof(vis));
}
void DFS(int x)
{
    vis[x] = true;
    nodes[x].fir = ++G_Mark;
    for(int i = 0; i < G[x].size(); i++)
    {
        if(vis[G[x][i]]) continue;
        DFS(G[x][i]);
    }
    nodes[x].las = G_Mark;
}
inline int lowbit(int x) { return x&(x^(x-1)); }
void Add(int pos,int val)
{
    while(pos <= N)
    {
        C[pos] += val;
        pos += lowbit(pos);
    }
}
int Sum(int pos)
{
    int ret = 0;
    while(pos > 0)
    {
        ret += C[pos];
        pos -= lowbit(pos);
    }
    return ret;
}
int main()
{
   // FIN;
    while(~scanf("%d", &N))
    {
        init();
        for(int i = 0; i < N - 1; i++)
        {
            scanf("%d %d", &u, &v);
            G[u].PB(v);
            G[v].PB(u);
        }
        DFS(1);
        scanf("%d", &M);
        char Op[5];
        int x, pos, L, R, ans;
        for(int i = 1;i <= N;i++) Add(i,1),S[i] = 1;
        for(int i = 0; i < M; i++)
        {
            scanf("%s %d", Op, &x);
            if(Op[0] == 'C')
            {
                pos = nodes[x].fir;
                S[pos] ^= 1;
                int add = S[pos] == 1 ? 1 : -1;
                Add(pos,add);
            }
            else
            {
                L = nodes[x].fir, R = nodes[x].las;
                if(L == 1) ans = Sum(R);
                else ans = Sum(R) - Sum(L-1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
//just test