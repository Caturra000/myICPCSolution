#include<iostream>
#include<algorithm>
using namespace std;
long long ctime[123][123];
int main(){
    int n,inp1,inp2; cin >> n;
    long long mmax = 0;
    for(int i = 0; i < n; i++){
        cin >> inp1 >> inp2;
        ctime[inp1][inp2]++;
        mmax = max(mmax,ctime[inp1][inp2]);
    }
    cout << mmax << endl;
    return 0;
}