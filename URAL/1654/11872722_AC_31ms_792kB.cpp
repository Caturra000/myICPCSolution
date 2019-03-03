#include<bits/stdc++.h>
#define rep(i,j,k) for(int i = j; i <= k; i++)
#define scan(a) scanf("%d",&a)
#define clr(a,b) memset(a,b,sizeof a);
using namespace std;
const int maxn = 2e5+11;
char stk[maxn];
int top;
char str[maxn];
int main(){
    while(scanf("%s",str)!=EOF){
        int len=strlen(str);
        top=-1;
        rep(i,0,len-1){
            if(top==-1) stk[++top]=str[i];
            else{
                if(str[i]==stk[top]) top--;
                else stk[++top]=str[i];
            }
        }
        bool flag=(top==-1?1:0);
        rep(i,0,top) printf("%c",stk[i]);
        printf("\n");
    }
    return 0;
}