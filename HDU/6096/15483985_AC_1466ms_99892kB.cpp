#include<bits/stdc++.h>
#define rep(i,j,k) for(register int i=j;i<=k;i++)
#define rrep(i,j,k) for(register int i=j;i>=k;i--)
#define println(a) printf("%lld\n",(ll)a)
using namespace std;
const int MAXN = 2e5 + 11;
const int MOD = 1e9+7;
typedef long long ll;
const ll INF = 1ll<<62;
ll read(){
    ll x = 0, f = 1; register char ch = getchar();
    while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0'&&ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x*f;
}
string str[MAXN];
bool cmp(const string &a,const string &b){
    return a.length()<b.length();
}
struct Q{
    string pre,suf;
    int id,len;
    Q(){};
    Q(string a,string b,int _id){
        pre=a;
        suf=b;
        id=_id;
        len=pre.length();
        len+=suf.length();
        if(pre.length()<suf.length()){
            for(int i=pre.length();i<suf.length();i++){
                pre.push_back('@');
            }
        }else if(suf.length()<pre.length()){
            string t((int)pre.length()-suf.length(),'#');
            suf=t+suf;
        }
    }
    bool operator < (const Q &QAQ) const{
        return len<QAQ.len;
    }
}q[MAXN];
int ans[MAXN];
const int MAXV = 3e6+11;
struct Trie{
    int son[MAXV][26];
    int size[MAXV];
    int tot,root;
    void init(){
        root=tot=1;
        size[root]=0;
        rep(i,0,25) son[root][i]=0;
    }
    int node(){
        ++tot;
        size[tot]=0;
        rep(i,0,25) son[tot][i]=0;
        return tot;
    }
    void insert(const string &str){
        int o=root,t;
        int cur1=0,cur2=str.length();
        int len=2*str.length();
        for(int i=0;i<len;i++){
            if(i&1) t=--cur2;
            else t=cur1++;
            size[o]++;
            int wh=str[t]-'a';
            if(son[o][wh]==0) son[o][wh]=node();
            o=son[o][wh];
        }
        size[o]++;
    }
    int ans;
    void query(int o,int dep,const string &s){
        if(o==0) return;
        if(dep==s.length()){
            ans+=size[o];
            return;
        }
        if(s[dep]=='#'||s[dep]=='@'){
            for(int j=0;j<26;j++) query(son[o][j],dep+1,s);
        }else{
            query(son[o][s[dep]-'a'],dep+1,s);
        }
    }
}trie;
int main(){
    ios::sync_with_stdio(false);
    int T; cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        rep(i,1,n) cin>>str[i];
        sort(str+1,str+1+n,cmp);
        string a,b;
        rep(i,1,m){
            cin>>a>>b;
            q[i]=Q(a,b,i);
        }
        sort(q+1,q+1+m);
        trie.init();
        int cur=n;
        string s;
        rrep(i,m,1){
            while(cur>0&&str[cur].length()>=q[i].len){
                trie.insert(str[cur]);
                cur--;
            }
            s.clear();
            int len=2*q[i].pre.length();
            int cur1=0,cur2=len>>1;
            for(int j=0;j<len;j++){
                char ch;
                if(j&1) ch=q[i].suf[--cur2];
                else ch=q[i].pre[cur1++];
                s.push_back(ch);
            }
            trie.ans=0; trie.query(1,0,s);
            ans[q[i].id]=trie.ans;
        }
        rep(i,1,m){
            cout<<ans[i]<<endl;
        }
    }
    return 0;
}