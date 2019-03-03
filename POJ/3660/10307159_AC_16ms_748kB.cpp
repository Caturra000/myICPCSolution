#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define LL long long
#define INF 0x7fffffff
using namespace std;

int mp[105][105];

int n, m;

int main() {
    while(scanf("%d %d", &n, &m) != EOF) {
        int u, v;
        memset(mp, 0, sizeof(mp));
        for(int i = 0; i < m; i ++) {
            scanf("%d %d", &u, &v);
            mp[u][v] = 1;
        }

        for(int k = 1; k <= n; k ++) {
            for(int i = 1; i <= n; i ++) {
                for(int j = 1; j <= n; j ++) {
                    mp[i][j] = (mp[i][j] | (mp[i][k] & mp[k][j]) );
                }
            }
        }

        for(int i = 1; i <= n; i ++) mp[i][i] = 0;

        int ans = 0;
        for(int i = 1; i <= n; i ++) {
            int cnt = 0;
            for(int j = 1; j <= n; j ++) {
                cnt += mp[i][j];
                cnt += mp[j][i];
            }
            if(cnt == n-1) ans ++;
        }

        printf("%d\n", ans);
    }
    return 0;
}
//just test