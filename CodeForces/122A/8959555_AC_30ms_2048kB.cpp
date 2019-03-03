#include<iostream>
using namespace std;

int main(){
    int table[13] = {
        4,7,
        44,47,74,77,
        444,447,474,477,744,747,777
    };
    int n; cin >> n;
    for(int i = 0; i < 13; i++){
        if(n%table[i] == 0){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}