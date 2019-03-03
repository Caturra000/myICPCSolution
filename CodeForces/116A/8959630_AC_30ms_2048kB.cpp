/*
#include<iostream>
#include<algorithm>
using namespace std;

int n;
int main(){
    int T,cur = 0;
    cin >> T;
    for(int i = 0; i < T; i++){
        int a,b;
        cin >> a >> b;
        n = max(n,n-a+b);
        cout << cur << cur-a+b << endl;
        cur = cur-a+b;
    }
    cout << n;
    return 0;
}
*/


#include <iostream>  
#include <algorithm>  
using namespace std;  

int main()  
{  
    int maxv=0,a=0,b=0,now=0,n=0;   cin>>n;  
    for(int i=0;i<n;i++)  
    {  
        cin>>a>>b;  
        now=now-a+b;  
        maxv=max(maxv,now);  
    }  
    cout<<maxv;  
    return 0;  
}   