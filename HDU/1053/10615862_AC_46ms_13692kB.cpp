#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<queue> 
using namespace std;
const int maxn = 5e5 + 11;
struct treenode {
	char ch;
	int weight;
	int lc, rc, p;
	int id;
	bool operator < (const treenode& b)const {
		return weight>b.weight;
	}
};
struct node {
	int n;
	char ch;
}b[100];
bool cmp(node a, node b) {
	return a.n>b.n;
}
vector<treenode> s;
string str;
priority_queue<treenode> pq;
queue<treenode> q;
string biao[maxn];
string yingshe[100];
int main() {
//	ios::sync_with_stdio(0);
	while (cin >> str) {
		if(str=="END") break; 
		while (!pq.empty()) pq.pop();
		s.clear(); memset(b, 0, sizeof b);
		for (int i = 0; i < 99; i++) b[i].ch = i + 'A';
		for (int i = 0; i < str.length(); i++) {
			b[str[i] - 'A'].n++;
		}
		sort(b, b + 100, cmp);
		int cnt = 0;
		for (int i = 0; i < 100; i++) {
			if (b[i].n>0) {
				cnt++;
			}
			else break;
		}
		for (int i = 0; i < cnt; i++) {
			treenode t;
			t.ch = b[i].ch; t.weight = b[i].n; t.lc = -1; t.rc = -1; t.p = -1; t.id = i;
			s.push_back(t);
			pq.push(t);
		}

		if (pq.size() == 1) {
			cout<<pq.top().weight*8<<" "<<pq.top().weight<<" 8.0\n"; 
//			cout << "8 1 8.0" << endl;
			continue;
		}
		treenode last;
		while (!pq.empty()) {
			treenode x = pq.top();
			last = x; pq.pop();
			if (pq.empty()) break;
			treenode y = pq.top(); pq.pop();
			treenode t;
			t.p = -1; t.lc = x.id; t.rc = y.id;
			t.id = s.size(); t.ch = '['; t.weight = x.weight + y.weight;
			s.push_back(t); s[x.id].p = t.id; s[y.id].p = t.id;
			pq.push(t);
		}
		while (!q.empty()) q.pop();
		q.push(last);
		memset(biao, 0, sizeof biao);
		bool flag = 0;
		while (!q.empty()) {
			treenode t = q.front(); q.pop();
			if (t.lc != -1) {
				q.push(s[t.lc]);
			}
			if (t.rc != -1) {
				q.push(s[t.rc]);
			}
			if (/*t.id==last.id||*/flag == 0) {
				biao[t.id] = "";//root
				flag = 1;
			}
			else {
				biao[t.id] = biao[t.p];
				if (t.id == s[t.p].lc) biao[t.id] += "0";
				else biao[t.id] += "1";
			}
		}
		memset(yingshe, 0, sizeof yingshe);
		for (int i = 0; i < s.size(); i++) {
			if (s[i].ch != '[') {
				yingshe[s[i].ch - 'A'] = biao[i];
			}
		}
		int sum = 0;
		for (int i = 0; i <str.length(); i++) {
			sum += yingshe[str[i] - 'A'].length();
		}
		cout << 8 * str.length() << " " << sum << " " ; printf("%.1lf\n",(double)8 * str.length() / sum);
	}
	return 0;
}