#include<iostream>
using namespace std;
int Matrix[8][8];
int x,y;

int main(){
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            cin >> Matrix[i][j];
            if(Matrix[i][j] == 1){
                x = j; y = i;
            }
        }
    }
    int ans = 0;
    if(y-3 > 0)
        ans += y-3;
    else
        ans += 3-y;
    if(x-3 > 0)
        ans += x-3;
    else
        ans += 3-x;
    cout << ans;
    return 0;
}