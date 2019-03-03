#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set> 
#define f(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
using namespace std;
set<int> a;
int main(){
    int n,m,inp;
    while(scanf("%d %d",&n,&m) == 2){
        a.clear();
        f(i,0,m+n){
        	scanf("%d",&inp);
            a.insert(inp);
        }
        int i = 0;
        for(set<int>::iterator ite = a.begin(); ite!=a.end(); ite++){
            if(i++) printf(" ");
			printf("%d",*ite);
        }
        printf("\n");
    }
    return 0;
}