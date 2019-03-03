#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue> 
using namespace std;
int N,K;
int DP[100005];
queue<int> qi;
int main(){
    for(int i = 0; i < 100005; i++)
        DP[i] = 123456;
    scanf("%d %d",&N,&K);
    DP[N] = 0;
    qi.push(N);
    while(!qi.empty()){
        int temp = qi.front(); qi.pop();
        if(temp-1>=0 && DP[temp-1]==123456){
            qi.push(temp-1);
            DP[temp-1] = min(DP[temp]+1,DP[temp-1]);
        }
        if(temp+1<=100000 && DP[temp+1]==123456){
            qi.push(temp+1);
            DP[temp+1] = min(DP[temp]+1,DP[temp+1]);
        }
        if(temp*2<=100000 && DP[2*temp]==123456){
            qi.push(2*temp);
            DP[temp*2] = min(DP[temp]+1,DP[temp*2]);
        }
    }
    cout << DP[K] << endl;
    return 0;
}