#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1011;
typedef unsigned long long ll;
const ll base1 = 10016957;
const ll base2 = 10016957;
const int mod = 99999997;
ll hash[maxn][maxn],hash2[maxn][maxn];
ll pow1[maxn],pow2[maxn];
char h1[maxn][maxn];
bool set[mod+3];
int n,m,q,nn,mm;
ll get(){
    for(int i = 1; i <= mm; i++){
        for(int j = 1; j <= nn; j++){
            hash2[i][j]+=hash2[i-1][j]*base1;
        }
    }
    for(int i = 1; i <= mm; i++){
        for(int j = 1; j <= nn; j++){
            hash2[i][j]+=hash2[i][j-1]*base2;//矩阵前缀和 
        }
    }
    return hash2[mm][nn];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    pow1[0]=pow2[0]=1;
    for(int i = 1; i <= 100; i++){
        pow1[i]=pow1[i-1]*base1;
        pow2[i]=pow2[i-1]*base2;
//        cout<<i<<" "<<pow1[i]<<" "<<pow2[i]<<endl;
    }
    while(cin>>m>>n>>mm>>nn){
    	memset(set,0,sizeof set); 
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                cin>>h1[i][j];hash[i][j]=h1[i][j]-'0';
            }
        }
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                hash[i][j]+=hash[i-1][j]*base1;
            }
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                hash[i][j]+=hash[i][j-1]*base2;
            }
        }
        for(int i = mm; i <= m; i++){
            for(int j = nn; j <= n; j++){
                ll h = hash[i][j];
                h-=hash[i-mm][j]*pow1[mm];
                h-=hash[i][j-nn]*pow2[nn];
                h+=hash[i-mm][j-nn]*pow1[mm]*pow2[nn];
                set[h%mod]=1;
            }
        }
        cin>>q;
        while(q--){
            for(int i = 1; i <= mm; i++){
                for(int j = 1; j <= nn; j++){
                    cin>>h1[i][j];hash2[i][j]=h1[i][j]-'0';
                }
            }
            cout<<(set[get()%mod]?1:0)<<endl;
        }
    }
    return 0;
}