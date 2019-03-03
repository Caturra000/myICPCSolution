#include <iostream>
#include <cstdio>
using namespace std;

const int N = 50000;

int n;
int pre[3*N+1];
int rank[3*N+1];

void init()
{
    for (int i = 1; i <= 3*n; i ++) {
        pre[i] = i;
        rank[i] = 0;
    }
}

int find(int a)
{
    while (a != pre[a])
        a = pre[a];
    return a;
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (rank[a] < rank[b]) {
        pre[a] = b;
    } else {
        pre[b] = a;
        if (rank[a] == rank[b])
            rank[a] ++;
    }
}

bool same(int a, int b)
{
    return find(a) == find(b);
}

int main(void)
{
    int k;
    int d, a, b;
    int res = 0;

    cin >> n >> k;
    init();
    while ( k-- ) {
        scanf("%d%d%d", &d, &a, &b);
        if ( a > n || b > n ) {
            res ++;
        }
        else if ( d == 1 ) {
            if ( same(a, b+n) || same(a, b+2*n) ) {
                res ++;
            } else {
                unite(a, b);
                unite(a+n, b+n);
                unite(a+2*n, b+2*n);
            }
        }
        else {
            if ( same(a, b) || same(a, b+2*n) ) {
                res ++;
            } else {
                unite(a, b+n);
                unite(a+n, b+2*n);
                unite(a+2*n, b);
            }
        }
    }
    printf("%d\n", res);

    return 0;
}
//test