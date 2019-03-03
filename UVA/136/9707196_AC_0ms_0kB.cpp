
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<set> 
#include<string>
#include<vector> 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define scan(a) scanf("%d",&(a))
#define scans(a) scanf("%s",(a))
#define print(a) printf("%d",(a))
#define println(a) printf("%d\n",(a))
#define printt(a,b) printf("%d %d\n",(a),(b)) 
#define f(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
#define ff(i,a,b) for((i) = (a); (i) < (b); (i)++)
using namespace std;
const int maxn = 1e6;
const double exp = 1e-9;
//priority_queue<long long> pq;

//queue<long long> q;
//map<int,bool> m;
/* 
int main(){
	int n; //scan(n);
	n = 1500;
	q.push(1);pq.push(1);
	while(1){
		if(pq.size() > n) break;
		long long temp = q.front(); q.pop();
		long long a = 2*temp,b = 3*temp,c = 5*temp;
		if(!m[a])pq.push(a);
		if(!m[b])pq.push(b);
		if(!m[c])pq.push(c);
		q.push(a);
		q.push(b);
		q.push(c);
		m[a] = 1; m[b] = 1; m[c] = 1;
	}
	while(pq.size() > n)
		pq.pop();
	println(pq.top());
	return 0; 
}//太慢了TLE 
*/
priority_queue<long long,vector<long long>,greater<long long> > pq;//top的2倍 3倍 5倍 和top 以外的最小数既是下一个丑数 
set<long long> s;
int main(){
	int n; //scan(n);
	n = 1500;
	s.insert(1); pq.push(1);
	f(i,1,n+1){
		long long temp = pq.top(); pq.pop();
		if(i==n)
			//println(temp);
			cout << "The 1500'th ugly number is " << temp << ".\n";
		if(s.find(2*temp) == s.end()){
			s.insert(2*temp);
			pq.push(2*temp);
		}
		if(s.find(3*temp) == s.end()){
			s.insert(3*temp);
			pq.push(3*temp);
		}
		if(s.find(5*temp) == s.end()){
			s.insert(5*temp);
			pq.push(5*temp);
		}
	
	}
	//println(pq.top()); //Wrong Answer
	return 0;
} 


/* 标答1 
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const int a[3]={2,3,5};
int main()
{
    priority_queue<ll,vector<ll>,greater<ll> >pq; //top的2倍 3倍 5倍 和top 以外的最小数既是下一个丑数 
    set<ll>s;
    pq.push(1);
    s.insert(1);
    for(int i=1;;i++)
    {
        ll x=pq.top();
        pq.pop();
        if(i==1500)
        {
            cout<<"The 1500'th ugly number is "<<x<<"."<<endl;
            break;
        }
        for(int j=0;j<3;j++)
        {
            ll x2=x*a[j];
            if(s.find(x2)==s.end())
            //if(!s.count(x2)) 
            {
                s.insert(x2);
                pq.push(x2);
            }
        }
    }
    return 0;
}
*/ 

//priority_queue<long long,vector<long long>,greater<long long> >
