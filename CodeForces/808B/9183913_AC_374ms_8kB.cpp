#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cstring>
#include<cmath>
#define LL long long 
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    long long s=0;
    int p=n-k+1;
    int t=min(p,k);
    for(int i=0;i<n;i++){
        long long q;
        cin>>q;
        s+=min(min(i+1,n-i),t)*q;
    }
    printf("%.10f",(double)s/(double)p);
    return 0;
}