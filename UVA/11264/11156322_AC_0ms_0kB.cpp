#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+11;
int a[maxn],n,tot;
long long sum;
int main(){
    int T; cin>>T;
    while(T--){
        cin>>n;
        for(int i = 0; i < n; i++)cin>>a[i];
        if(n<=2){
            cout<<n<<endl;
            continue;
        }
        sort(a,a+n);
        sum=1;tot=2;
        for(int i = 1; i < n-1; i++){
            if(sum<a[i]&&sum+a[i]<a[i+1]){
                sum+=a[i];
                tot++;
            }
        }
        cout<<tot<<endl;
    }
    return 0;
}