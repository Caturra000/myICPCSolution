#include<iostream>
using namespace std;
int k2,k3,k5,k6;
int sum = 0;
int main(){
    cin >> k2 >> k3 >> k5 >> k6;
    bool flag = true;
    while(flag){
        if(k2 && k5 && k6){
            k2--;k5--;k6--;
            sum += 256;
            continue;
        }
        if(k3 && k2){
            k2--;k3--;
            sum += 32;
            continue;
        }
        flag = false;
    }
    cout << sum << endl;
    return 0;
}