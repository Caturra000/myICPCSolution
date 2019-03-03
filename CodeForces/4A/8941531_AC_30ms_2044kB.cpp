#include<iostream>
using namespace std;
int main(){
    int w;
    cin >> w;
    if(w%2 == 1){
        cout << "NO";
        return 0;
    }
    for(int i = 1; i < w;i++){//可优化至少一半
        if(i%2 == 0 && (w-i)%2 == 0){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}