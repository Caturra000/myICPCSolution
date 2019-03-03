#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> > pq;
//int temp[1000006];
char a;
int b;
//int query(){
//    memset(temp,0,sizeof temp);
//    int cnt = 0;
//}
int main(){
	
    int n,k; 
	while(cin >> n >> k){
		while(!pq.empty()) pq.pop();
	    for(int i = 0; i < n; i++){
	        cin >> a;
	        if(a == 'I'){
	            cin >> b;
	            if(pq.size() < k) pq.push(b);
	            else if(pq.top() </*=*/ b){//新的数大于第k大  从{1..k-1}大和{b}的二叉堆中调整更新为新的k大
	                pq.push(b);
	                pq.pop(); //原来的k大 
	            }
	        }
	        else if(a == 'Q'){
	            cout << pq.top() << endl;
	        }
	    }
	}
    return 0;
}