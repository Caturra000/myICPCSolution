#include<iostream>
#include<algorithm>
using namespace std;
int a[1000];
int main(){
    int n; cin >> n;
    int trea = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        trea = max(trea,a[i]);
    }
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (trea > a[i]) ? (trea-a[i]) : 0;
    }
    cout << sum << endl;
    return 0;
}