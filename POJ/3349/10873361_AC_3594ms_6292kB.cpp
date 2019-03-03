#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
const int max_size=100010;
const int prime=99991;
vector<int> hsh[prime];
int arm[max_size][6];
int n;
bool isTheSame(int a,int b){
    for(int i=0;i<6;i++){
        if((//clockwise
            arm[a][0]==arm[b][i]&& arm[a][1]==arm[b][(i+1)%6]&&
            arm[a][2]==arm[b][(i+2)%6]&& arm[a][3]==arm[b][(i+3)%6]&&
            arm[a][4]==arm[b][(i+4)%6]&& arm[a][5]==arm[b][(i+5)%6])
        ||
        //counter clockwise
        (   arm[a][0]==arm[b][i]&& arm[a][1]==arm[b][(i+5)%6]&&
            arm[a][2]==arm[b][(i+4)%6]&& arm[a][3]==arm[b][(i+3)%6]&&
            arm[a][4]==arm[b][(i+2)%6]&& arm[a][5]==arm[b][(i+1)%6]))
        return true;
    }
    return false;  
}
int main(){
    scanf("%d",&n); long long sum,key;
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            scanf("%d",&arm[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=0;j<6;j++){
            sum+=arm[i][j]*2;
        }
        key=sum%prime;
        vector<int>::size_type k;
        for(k=0;k<hsh[key].size();k++){
            if(isTheSame(i,hsh[key][k])){
                printf("Twin snowflakes found.\n");
                exit(0);
            }
             
        }
        hsh[key].push_back(i);
    }
    printf("No two snowflakes are alike.\n");
}//JUST TESTTTT