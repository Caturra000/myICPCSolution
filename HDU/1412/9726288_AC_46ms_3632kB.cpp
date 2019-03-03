#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set> 
#define f(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
using namespace std;

set<int> a,b;
set<int> x;
int main(){
    int n,m,inp;
    while(scanf("%d %d",&n,&m) == 2){
        a.clear();b.clear();x.clear();
        f(i,0,n){
            scanf("%d",&inp);
            a.insert(inp);
        }
        f(i,0,m){
            scanf("%d",&inp);
            b.insert(inp);
        }
        set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(x,x.begin()));
        int i = 0;
        for(set<int>::iterator ite = x.begin(); ite!=x.end(); ite++){
            if(i++) printf(" ");
			//cout << *ite;
			printf("%d",*ite);
        }
        printf("\n");
    }
    return 0;
}