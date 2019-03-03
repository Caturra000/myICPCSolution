#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+11;
struct Line{
    int x,y1,y2,c;
    bool operator<(const Line& rhs)const{
        return x<rhs.x;
    }
}line[maxn];
struct ST{
    int cover[maxn<<2],lines[maxn<<2];
    bool lx[maxn<<2],rx[maxn<<2];//是否覆盖
    int length[maxn<<2],coverlen[maxn<<2];
    void merge(int o){
        cover[o]=0;
        lines[o]=lines[o<<1]+lines[o<<1|1]-(rx[o<<1]&&lx[o<<1|1]);
        coverlen[o]=coverlen[o<<1]+coverlen[o<<1|1];
        lx[o]=lx[o<<1];rx[o]=rx[o<<1|1];
        length[o]=length[o<<1]+length[o<<1|1];
    }
    void pu(int o){
        if(cover[o]){
            coverlen[o]=length[o];
            lx[o]=rx[o]=lines[o]=1;
        }
        else{//合并连续区间
            merge(o);
        }
    }
    void build(int o,int l,int r){
        if(l==r){
            lx[o]=rx[o]=cover[o]=lines[o]=coverlen[o]=0;
            length[o]=1;
            return;
        }
        int m=l+r>>1;
        build(o<<1,l,m);
        build(o<<1|1,m+1,r);
        pu(o);
    }
    void cov(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            if(!cover[o]){
                lx[o]=rx[o]=1;
                lines[o]=1;
                coverlen[o]=length[o];
            }
            cover[o]++;
            return;
        }
        int m=l+r>>1;
        if(L<=m) cov(o<<1,l,m,L,R);
        if(R>m) cov(o<<1|1,m+1,r,L,R);
        pu(o);
    }
    void uncov(int o,int l,int r,int L,int R){
        if(L<=l&&r<=R){
            --cover[o];
            if(!cover[o]){
                if(l==r){
                    lx[o]=rx[o]=cover[o]=lines[o]=coverlen[o]=0;
                }
                else merge(o);
            }
            return;
        }
        int m=l+r>>1;
        if(L<=m) uncov(o<<1,l,m,L,R);
        if(R>m) uncov(o<<1|1,m+1,r,L,R);
        pu(o);
    }
}st;
int main(){
	int n,x1,x2,y1,y2; 
    while(~scanf("%d",&n)){
        if(n==0) break;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            line[i<<1]=(Line){x1,y1+10001,y2+10001,1};
            line[i<<1|1]=(Line){x2,y1+10001,y2+10001,0};
        }
        int t=n<<1;
        sort(line,line+t);
        int prex=line[0].x;
        int ans=0;
        int prelen=0;
        int preline=0;
        st.build(1,1,20001);
        for(int i = 0; i < t; i++){
            if(line[i].c) st.cov(1,1,20001,line[i].y1,line[i].y2-1);
            else st.uncov(1,1,20001,line[i].y1,line[i].y2-1);
            ans+=2*preline*(line[i].x-prex);
            preline=st.lines[1];
            prex=line[i].x;
            ans+=abs(st.coverlen[1]-prelen);
            prelen=st.coverlen[1];
        }
        printf("%d\n",ans);
    }
    return 0;
}