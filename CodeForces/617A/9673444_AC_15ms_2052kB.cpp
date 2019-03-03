#include<bits/stdc++.h>
using namespace std;
int main(){
    int x; scanf("%d",&x);
    cout << x/5+(x%5)/4+((x%5)%4)/3+(((x%5)%4)%3)/2+((((x%5)%4)%3)%2)/1 << endl;
    return 0;
}