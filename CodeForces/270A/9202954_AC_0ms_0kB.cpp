#include<iostream>
using namespace std;
int main(){
    int n; cin >> n;
    while(n--){
        int a;
        cin >> a;
        int k;
        for(k = 3; (180-a)*k-360 < 0; k++){;}
        if(((180-a)*k-360) == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}