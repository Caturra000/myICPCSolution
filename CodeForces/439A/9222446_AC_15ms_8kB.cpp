#include<iostream>
using namespace std;
int song[1000];
int main(){
    int sum = 0;
    int n,min; cin >> n >> min;
    for(int i = 1; i <= n; i++){
        cin >> song[i];
        sum += song[i];
    }
    if(sum+(n-1)*10 > min){
        cout << "-1" << endl;
        return 0;
    }
    else{
        int ans = (min-sum)/5;
        cout << ans << endl;
        return 0;
    }
}