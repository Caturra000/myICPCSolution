#include<iostream>
#include<cstring> 
using namespace std;

int num[5];
int ans;
int n;
int solve;bool solved;//solved多余

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        memset(num,0,sizeof(num));
        solve = 0 ; solved = false;
        for(int j = 0; j < 3; j++){
        	cin >> num[j];
            if(num[j] == 1 && !solved)
                solve++;
            if(solve == 2)
                solved = true;
        }
        if(solved)
            ans++;
    }
    cout << ans;
    return 0;
}