#include<bits/stdc++.h>
using namespace std;
map<int,int> m;
int arr[1000003];
bool vis[1000003];
int main(){
    int n,inp; 
    while(cin >> n){
        memset(arr,0,sizeof arr);
        m.clear();
        memset(vis,0,sizeof vis);
        int j = 0;
        for(int i = 0; i < n; i++){
            scanf("%d",&inp);
            m[inp]++;
            if(!vis[inp]) arr[j++] = inp;
            vis[inp] = true;
        }
        for(int i = 0; i < n; i++){
        if(m[arr[i]] >= (n+1)/2)
            cout << arr[i] << endl;
        if(arr[i] == 0)
            break;
    	}
    }
    
    return 0;
}