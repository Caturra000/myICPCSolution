#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define clr(a) memset((a),0,sizeof (a))
using namespace std;
const int maxn =  3e5+11;
struct Splay{
    int root,sz,n;
    int f[maxn],ch[maxn][2],key[maxn],cnt[maxn],size[maxn];
    void init(){
        sz=0;root=0;
        clr(f);clr(ch);clr(key);clr(cnt);clr(size);
    }
    void clear(int x){
        f[x]=0;
        ch[x][0]=ch[x][1]=0;
        key[x]=size[x]=cnt[x]=0;
    } 
    int get(int x){
        return ch[f[x]][1]==x;
    }
    void update(int x){
        size[x]=cnt[x]+size[ch[x][0]]+size[ch[x][1]];
    }
    void rotate(int x){
        int old=f[x],oldf=f[old],wh=get(x);
        ch[old][wh]=ch[x][wh^1];
        if(ch[old][wh]) f[ch[old][wh]]=old;
        ch[x][wh^1]=old;
        f[old]=x;
        if(oldf) ch[oldf][ch[oldf][1]==old]=x;
        f[x]=oldf;
        update(old);
        update(x);
    }
    void splay(int x){
        for(int fa;fa=f[x];rotate(x))
            if(f[fa]) rotate(get(x)==get(fa)?fa:x);
        root=x;
    }
    void insert(int x){
        if(!root){
            root=++sz;
            cnt[sz]=size[sz]=1;key[sz]=x;
            return ;
        }
        int now=root,fa=0;
        while(1){
            if(x==key[now]){
                cnt[now]++;
                update(now);
                splay(now);
                break;
            }
            fa=now;
            now=ch[now][x>key[now]];
            if(!now){
                ++sz;
                f[sz]=fa;ch[fa][x>key[fa]]=sz;
                size[sz]=cnt[sz]=1;
                key[sz]=x;
                update(fa);
                splay(sz);
                break;
            }
        }
    }
    int find(int x){
        int now=root,ans=0;
        while(1){
            if(x<key[now]) now=ch[now][0];
            else{
                ans+=size[ch[now][0]];
                if(x==key[now]){
                    splay(now);
                    return ans+1;
                }
                ans+=cnt[now];
                now=ch[now][1];
            }
        }
    }
    int findx(int x){
        int now=root;
        while(1){
            if(x<=size[ch[now][0]]) now=ch[now][0];
            else{
                x-=size[ch[now][0]];
                if(x<=cnt[now]){
                    splay(now);
                    return key[now];
                }
                x-=cnt[now];
                now=ch[now][1];
            }
        }
    }
    int pre(){
        int now=ch[root][0];
        while(ch[now][1]) now=ch[now][1];
        return now;
    }
    int nxt(){
        int now=ch[root][1];
        while(ch[now][0]) now=ch[now][0];
        return now;
    }
    void del(int x){
        int wh=find(x);
        if(cnt[root]>1){
            --cnt[root];
            update(root);
            return;
        }
        if(!ch[root][0]&&!ch[root][1]){
            clear(root);
            root=0;
            return;
        }
        if(!ch[root][0]){
            int oldroot=root;
            root=ch[oldroot][1];
            f[root]=0;
            clear(oldroot);
            return;
        }
        if(!ch[root][1]){
            int oldroot=root;
            root=ch[oldroot][0];
            f[root]=0;
            clear(oldroot);
            return;
        }
        int oldroot=root;
        int leftbig=pre();splay(leftbig);
        ch[root][1]=ch[oldroot][1];
        f[ch[root][1]]=root;
        clear(oldroot);
        update(root);
        return; 
    }
}splay;
int n; 
int main(){
    while(scanf("%d",&n)!=EOF){
        splay.init();
        int op,t;
        for(int i = 0; i < n; i++){
            scanf("%d%d",&op,&t);
            switch(op){
                case 1: splay.insert(t);break;
                case 2: splay.del(t);break;
                case 3: printf("%d\n",splay.find(t));break;
                case 4: printf("%d\n",splay.findx(t));break;
                case 5: splay.insert(t);printf("%d\n",splay.key[splay.pre()]);splay.del(t);break;
                case 6: splay.insert(t);printf("%d\n",splay.key[splay.nxt()]);splay.del(t);break;
            }
        }
    }
    return 0;
}