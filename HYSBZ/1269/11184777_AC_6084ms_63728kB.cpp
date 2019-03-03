#include<bits/stdc++.h>
using namespace std;
struct node{
    node *lc,*rc;
    int fix,wgt,size,rev;
    char val;
    node(char v){
        lc=rc=0;
        fix=rand();
        wgt=size=1;
        rev=0;
        val=v;
    }
    int ls(){
        if(lc)return lc->size;
        return 0;
    }
    int rs(){
        if(rc)return rc->size;
        return 0;
    }
    void pd(){
        if(rev&1){
            swap(lc,rc);
            if(lc) lc->rev+=rev;
            if(rc) rc->rev+=rev;
            
        }
		rev=0;
    }
    void maintain(){
        size=wgt;
        size+=ls()+rs();
    }
}*root;
typedef pair<node*,node*> droot;
void print(node *p){
    p->pd();
    if(p->lc)print(p->lc);
    printf("%c",p->val);
    if(p->rc)print(p->rc);
}
node *merge(node *a,node *b){
    if(!a) return b;
    if(!b) return a;
    a->pd();b->pd();
    //a->pu();b->pu();
    if(a->fix<b->fix){
        a->rc=merge(a->rc,b);
        //a->pu();
        a->maintain();
        return a;
    }
    else{
        b->lc=merge(a,b->lc);
        //b->pu();
        b->maintain();
        return b;
    }
}
droot split(node *a,int k){
    if(!a) return droot(0,0);
    droot y;
    a->pd();//a->pu();
    if(a->ls()>=k){
        y=split(a->lc,k);
        a->lc=y.second;
        // a->pu();
        a->maintain();
        y.second=a;
    }
    else{
        y=split(a->rc,k-a->ls()-1);
        a->rc=y.first;
        // a->pu();
        a->maintain();
        y.first=a;
    }
    return y;
}
void insert(int k,int len){
    char c;
    node *tmp;
    droot y=split(root,k);scanf("%c",&c);
    for(int i = 1; i <= len; i++){
//        while(c<32||c>126)
			scanf("%c",&c);
        tmp=new node(c);
        y.first=merge(y.first,tmp);
    }
    root=merge(y.first,y.second);
}
void del(int k,int len){
    droot x,y;
    x=split(root,k);
    y=split(x.second,len);
    root=merge(x.first,y.second);
}
int main(){
    droot x,y;
    int n,now,num;char str[111];
    now=0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        scanf("%s",str);
        if(str[0]=='M'){
            scanf("%d",&now);
        }
        if(str[0]=='I'){
            scanf("%d",&num);
            insert(now,num);
        }
        if(str[0]=='D'){
            scanf("%d",&num);
            del(now,num);
        }
        if(str[0]=='R'){
            scanf("%d",&num);
            x=split(root,now);
            y=split(x.second,num);
            y.first->rev++;
            x.second=merge(y.first,y.second);
            root=merge(x.first,x.second);
        }
        if(str[0]=='G'){
            x=split(root,now);
            y=split(x.second,1);
            print(y.first);printf("\n");
            x.second=merge(y.first,y.second);
            root=merge(x.first,x.second);
        }
        if(str[0]=='P'){
            now--;
        }
        if(str[0]=='N'){
            now++;
        }
    }
}