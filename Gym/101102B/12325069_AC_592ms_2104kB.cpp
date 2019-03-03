#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
const int maxn = 1e5+11;
const int oo = 0x3f3f3f3f;
int a[]={6,2,5,5,4,5,6,3,7,6};
char str[maxn];
int main(){
    ios::sync_with_stdio(0);
    int N,T; cin>>T;
    while(T--){
        cin>>N>>str;
        int tot=0;
        rep(i,0,N-1) tot+=a[str[i]-'0'];
        int tmp=tot;
        rep(i,1,N){
            rrep(j,9,0){
                int t=tot-a[j];
                if(t>=2*(N-i)&&t<=7*(N-i)){//note
                    cout<<j;
                    tot=t;
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}