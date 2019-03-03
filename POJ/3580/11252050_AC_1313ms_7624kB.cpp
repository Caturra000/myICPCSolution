#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{
    node *lc,*rc;
    int val,fix,size,wgt,mn,add,rev;
    node(int v){
    	lc=rc=0;//NOTE 
        val=v;
        fix=rand();
        size=wgt=1;
        mn=v;
        add=rev=0;
    }
    int ls(){
        if(lc)return lc->size;
        else return 0;
    }
    int rs(){
        if(rc)return rc->size;
        else return 0;
    }
    void pu(){
        mn=val;
        if(lc) mn=min(mn,lc->mn+lc->add);//
        if(rc) mn=min(mn,rc->mn+rc->add);
    }
    void pd(){
        node *tmp;
        if(add){
            mn+=add;
            val+=add;
            if(lc) lc->add+=add;
            if(rc) rc->add+=add;
            add=0;
        }
        if(rev%2){
            if(lc==0||rc==0){
                if(!lc){
                    lc=rc;
                    rc=0;
                }
                else{
                    rc=lc;
                    lc=0;
                }
            }
            else{
                tmp=lc;
                lc=rc;
                rc=tmp;
            }
            if(lc) lc->rev+=rev;
            if(rc) rc->rev+=rev;
            rev=0;
        }
        pu();
    }
    void maintain(){
        size=wgt;
        size+=ls()+rs();
    }
}*root;
typedef pair<node*,node*> droot;
node *merge(node *a,node *b){
    if(!a) return b;
    if(!b) return a;
    a->pd();b->pd();
    a->pu();b->pu();
    if(a->fix<b->fix){
        a->rc=merge(a->rc,b);
        a->pu();a->maintain();
        return a;
    }
    else{
        b->lc=merge(a,b->lc);
        b->pu();b->maintain();
        return b;
    }
}
droot split(node *a,int k){
    if(!a) return droot(0,0);
    droot y;
    a->pd();a->pu();
    if(a->ls()>=k){
        y=split(a->lc,k);
        a->lc=y.second;
        a->pu();a->maintain();
        y.second=a;
    }
    else{
        y=split(a->rc,k-a->ls()-1);
        a->rc=y.first;
        a->pu();
        a->maintain();
        y.first=a;
    }
    return y;
}
void insert(int k,int v){
    node *tmp;
    droot y=split(root,k);
    tmp=new node(v);
    root=merge(merge(y.first,tmp),y.second);
}
void del(int k){
    droot x,y;
    x=split(root,k-1);
    y=split(x.second,1);
    root=merge(x.first,y.second);
}
char str[199];
int n,m;
droot ai,bi,ci;
node *tmp;
int x,y,a,L,t;
int main(){
    while(scanf("%d",&n)!=EOF){
        root=0;
        for(int i = 1; i <= n; i++){
            scanf("%d",&x);
            insert(i,x);
        }
        scanf("%d",&m);
        for(int i = 1; i <= m; i++){
            scanf("%s",str);
            if(str[0]=='A'){
                scanf("%d%d%d",&x,&y,&a);
                ai=split(root,x-1);
                bi=split(ai.second,y-x+1);
                bi.first->add+=a;
                ai.second=merge(bi.first,bi.second);
                root=merge(ai.first,ai.second);
            }
            else if(str[0]=='I'){
                scanf("%d%d",&x,&a);
                insert(x,a);
            }
            else if(str[0]=='D'){
                scanf("%d",&x);
                del(x);
            }
            else if(str[0]=='R'){
                if(str[3]=='E'){
                    scanf("%d%d",&x,&y);
                    ai=split(root,x-1);
                    bi=split(ai.second,y-x+1);
                    bi.first->rev++;
                    ai.second=merge(bi.first,bi.second);
                    root=merge(ai.first,ai.second);
                }
                else{//
                    scanf("%d%d%d",&x,&y,&a);
                    L=y-x+1;
                    a=(a%L+L)%L;
                    ai=split(root,x-1);
                    bi=split(ai.second,L);
                    ci=split(bi.first,L-a);
                    bi.first=merge(ci.second,ci.first);
                    ai.second=merge(bi.first,bi.second);
                    root=merge(ai.first,ai.second);
                }
            }
            else if(str[0]=='M'){
                scanf("%d%d",&x,&y);
                ai=split(root,x-1);
                bi=split(ai.second,y-x+1);
                t=bi.first->mn;
                ai.second=merge(bi.first,bi.second);
                root=merge(ai.first,ai.second);
                printf("%d\n",t);
            }
        }
    }
}