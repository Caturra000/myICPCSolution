#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls (o<<1)
#define rs (o<<1|1)
#define lson ls, L, M 
#define rson rs, M+1, R
using namespace std;
const int MAXY = (int)1e6 + 5;
const int MAXN = (int)1e5 + 5;

struct Node {
    int state, city;
    int adds, addc; //lazy
    Node() { state = city = adds = addc = 0;}
} node[MAXY * 3];

int n, q;

void build(int o, int L, int R) {
    node[o] = Node();
    if(L == R) return ;
    int M = (L + R)/2;
    build(lson);
    build(rson);
}

void pushDown(int o) {
    if(node[o].addc) {
        node[ls].addc += node[o].addc;
        node[rs].addc += node[o].addc;
        node[ls].city += node[o].addc;
        node[rs].city += node[o].addc;
        node[o].addc = 0;
    }
    if(node[o].adds) {
        node[ls].adds += node[o].adds;
        node[rs].adds += node[o].adds;
        node[ls].state += node[o].adds;
        node[rs].state += node[o].adds;
        node[o].adds = 0;
    }
}

Node query(int o, int L, int R, int pos) {
    if(L == R) return node[o];
    pushDown(o);
    int M = (L + R)/2;
    if(pos <= M) return query(lson, pos);
    else return query(rson, pos);
}

void modify(int o, int L, int R, int ql, int qr, int val, char type) {
    if(ql <= L && R <= qr) {
        if(type == 'c') {
            node[o].city += val;
            node[o].addc += val;
        }else {
            node[o].state += val;
            node[o].adds += val;
        }
        return ;
    }
    pushDown(o);
    int M = (L + R)/2;
    if(ql <= M) modify(lson, ql, qr, val, type);
    if(qr > M) modify(rson, ql, qr, val, type);
}

int fa[MAXN];
int city[MAXN], state[MAXN], low[MAXN], high[MAXN];

void init() {
    int x, y;
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        fa[i] = i;
        city[i] = state[i] = 1;
        low[i] = high[i] = y;
    }
}

int find(int u) {
    return (fa[u] == u) ? fa[u] : fa[u] = find(fa[u]);
}

void Union(int u, int v) {
    int a = find(u), b = find(v);
    if(a == b) return ;
    if(low[a] < high[a]) {
        modify(1, 0, MAXY, low[a]+1, high[a], -city[a], 'c');
        modify(1, 0, MAXY, low[a]+1, high[a], -1, 's');
    }
    if(low[b] < high[b]) {
        modify(1, 0, MAXY, low[b]+1, high[b], -city[b], 'c');
        modify(1, 0, MAXY, low[b]+1, high[b], -1, 's');
    }
    if(a > b) swap(a, b);
    fa[b] = a;
    low[a] = min(low[a], low[b]);
    high[a] = max(high[a], high[b]);
    city[a] += city[b];
    state[a] = 1;
    modify(1, 0, MAXY, low[a]+1, high[a], city[a], 'c');
    modify(1, 0, MAXY, low[a]+1, high[a], state[a], 's');
}

char oper[10];
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);

        init();
        build(1, 0, MAXY);

        scanf("%d", &q);
        int u, v;
        double pos;
        while(q--) {
            scanf("%s", oper);
            if(oper[0] == 'r') {
                scanf("%d%d", &u, &v);
                Union(u, v);
            }else {
                scanf("%lf", &pos);
                Node ret = query(1, 0, MAXY, (int)(pos + 1));
                printf("%d %d\n", ret.state, ret.city);
            }
        }
    }
    return 0;
}
//jusssttttteeesssttt