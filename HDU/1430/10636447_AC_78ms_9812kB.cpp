#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
const int maxn = 1e5+11;
bool vis[maxn];
string ans[maxn],s,e;
struct node{
    string str,now;
};
int f[10];
char change[10];
int fac(int i){
    return f[i]=i?i*fac(i-1):1;
} 
int cantor(string &str){
    int sum=0;
    for(int i = 0; i < 8; i++){
        int cnt=0;
        for(int j = i+1; j < 8; j++){
            if(str[j]<str[i]) cnt++;
        }
        sum+=cnt*f[7-i];
    }
    return sum;
} 
inline void trya(string &str){
    reverse(str.begin(),str.end());
}
inline void tryb(string &str){
    string tstr(str);
    str[0]=tstr[3];
    str[1]=tstr[0];
    str[2]=tstr[1];
    str[3]=tstr[2];
    str[4]=tstr[5];
    str[5]=tstr[6];
    str[6]=tstr[7];
    str[7]=tstr[4];
    
}
inline void tryc(string &str){
    string tstr(str);
    str[0]=tstr[0];
    str[1]=tstr[6];
    str[2]=tstr[1];
    str[3]=tstr[3];
    str[4]=tstr[4];
    str[5]=tstr[2];
    str[6]=tstr[5];
}
void bfs(){
    memset(vis,0,sizeof vis);
    queue<node> q;
    node a,b,nxt; int k; string t;
    a.str="12345678"; a.now=""; q.push(a); k=cantor(a.str); vis[k]=1;
    while(!q.empty()){
        b = q.front(); q.pop();
        t=b.str;trya(t);k=cantor(t);
        if(!vis[k]){
            nxt.str=t;
            nxt.now=b.now;nxt.now+="A";
            vis[k]=1;q.push(nxt);ans[k]=nxt.now;
        }
        t=b.str;tryb(t);k=cantor(t);
        if(!vis[k]){
            nxt.str=t;
            nxt.now=b.now;nxt.now+="B";
            vis[k]=1;;q.push(nxt);ans[k]=nxt.now;
        }
        t=b.str;tryc(t);k=cantor(t);
        if(!vis[k]){
            nxt.str=t;
            nxt.now=b.now;nxt.now+="C";
            vis[k]=1;;q.push(nxt);ans[k]=nxt.now;
        }
    }
} 
int main(){
    ios::sync_with_stdio(0);
    fac(9); bfs();
    while(cin>>s>>e){
        for(int i = 0; i < 8; i++){
            change[s[i]-'1']=i+'1';
        }
        for(int i = 0; i < 8; i++){
        	e[i]=change[e[i]-'1'];
		}
        cout<<ans[cantor(e)]<<endl;
    }
    return 0;
}
