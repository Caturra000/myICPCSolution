#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
const int M = 35;
const int INF = 0x3f3f3f3f;

int n, q;
int v[4 * N];
int A[N];
int s[M], num[M];

int Query (int o, int l, int r, int ql, int qr) {

    int m = l + (r - l)/ 2;
    int ans = INF; 

    if (ql <= l && r <= qr)
        return v[o];

    if (ql <= m)
        ans = min (ans, Query (2 * o, l, m, ql, qr)); 
    if (qr > m)
        ans = min (ans, Query (2 * o + 1, m + 1, r, ql, qr));
    return ans;
}

void Update (int o, int l, int r, int p, int val) {

    int m = l + (r - l) / 2;
    if (l == r)
        v[o] = val;
    else {

        if (p <= m)
            Update (2 * o, l, m, p, val);
        else
            Update (2 * o + 1, m + 1, r, p, val);
        v[o] = min (v[2 * o] , v[2 * o + 1]);
    }
}

int get_number (char* str) {

    int dex = 0;
    int len = strlen (str);
    s[dex] = 0;
    bool flag = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            s[dex] = s[dex] * 10 + str[i] - '0';    
            flag = 1;
        } else if (flag)
            s[++dex] = 0;
    }
    return dex;
}

void solve () {

    char str[N]; 
    int x, y;
    while (q--) {

        scanf ("%s", str);
        int dex = get_number(str);
        if (str[0] == 'q') {

            //memcpy (str, str + 6, sizeof (str));
            //sscanf (str, "%d,%d", &x, &y);
            printf ("%d\n", Query (1, 1, n, s[0], s[1]));
        } else {

        /*    memcpy (str, str + 6, sizeof (str));
            sscanf (str, "%d%s", &s[dex], str);
            num[dex++] = A[s[dex]];
            while (sscanf (str, ",%d%s", &s[dex], str)) {
                num[dex++] = A[s[dex]];    
            }*/

            for (int i = 0; i < dex; i++)
                num[i] = A[s[i]];

            for (int i = 0; i < dex; i++) {

                if (i + 1 < dex)
                    A[s[i]] = num[i + 1];
                else
                    A[s[i]] = num[0];
                Update (1, 1, n, s[i], A[s[i]]);
            }
        }
    }
}

int main () {

    while (scanf ("%d%d", &n, &q) != EOF) {

        memset (v, 0, sizeof (v));
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &A[i]);
            Update (1, 1, n, i, A[i]);
        }

        solve();
    }
    return 0;
}//just test