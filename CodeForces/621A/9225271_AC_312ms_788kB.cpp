#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
__int64 odd[100007];
//vector<int> even;

int main(){
    __int64 n; cin >> n;
    __int64 inp,sum = 0;
    __int64 cur = 0;
    for(__int64 i = 0; i < n; i++){
        cin >> inp;
        if(inp%2 == 0){
            //even.push_back(inp);
            sum += inp;
        }
        else{
            odd[cur++] = inp;
        }
    }
    sort(odd,odd+cur);
    for(__int64 i = cur-1; i > 0; i--){
        sum += odd[i];
    }
    if(cur%2 == 0)
        sum += odd[0];
    cout << sum << endl;
    return 0;
}