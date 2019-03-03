//#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;
//priority_queue<int> pq[2];
//map<int,bool> vis;
//map<int,int> client;
//int p,k;    
//int main(){
//    int query;
//    while(cin >> query){
//        if(query == 0)
//            break;
//        else if(query == 1){
//            cin >> k >> p;
//            client[p] = k;
//            pq[0].push(p);
//            pq[1].push(-p);
//            //vis[p] = true;
//        }
//        else if(query == 2){
//            if(pq[1].empty() || pq[0].empty())
//                cout << 0 << endl;
//            else{
//                while(!pq[0].empty() && vis[pq[0].top()])
//                    pq[0].pop();
//                if(pq[1].empty() || pq[0].empty()){
//                	cout << 0 << endl;
//                	continue;
//                }
//                cout << client[pq[0].top()] << endl;
//                vis[pq[0].top()] = true;
//                pq[0].pop();
//            }
//        }
//        else if(query == 3){
//            if(pq[0].empty() ||pq[1].empty())
//                cout << 0 << endl;
//            else{
//                while(!pq[1].empty() && vis[(-1)*pq[1].top()])
//                    pq[1].pop();
//                if(pq[0].empty() || pq[1].empty()){
//                	cout << 0 << endl;
//                	continue;
//                }
//                cout << client[(-1)*pq[1].top()] << endl;
//                vis[(-1)*pq[1].top()] = true;
//                pq[1].pop();
//            }
//        }
//    }
//    return 0;
//} //TLE
deque<int> dq;
int client[10000057];
int main(){
	int k,p,query;
	while(scanf("%d",&query)==1){
		if(query == 0)
			break;
		else if(query == 1){
			//cin >> k >> p;
			scanf("%d %d",&k,&p);
			client[p] = k;
			deque<int>::iterator ite = lower_bound(dq.begin(),dq.end(),p);
			dq.insert(ite,p);
		}
		else if(query == 2){
			if(dq.empty())
				//cout << 0 << endl;
				printf("0\n");
			else{
				//cout << client[dq.back()] << endl;
				printf("%d\n",client[dq.back()]);
				dq.pop_back(); 
			}
		} 
		else if(query == 3){
			if(dq.empty())
				//cout << 0 << endl;
				printf("0\n");
			else{
				//cout << client[dq.front()] << endl;
				printf("%d\n",client[dq.front()]);
				dq.pop_front();
			}
		}
	}
	return 0; 
} //TLE