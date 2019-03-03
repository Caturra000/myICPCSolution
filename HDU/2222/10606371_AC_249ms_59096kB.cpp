#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e6+11;
int head,tail,cnt;
struct node{
	node *next[26];
	node *fail;
	int sum;
	node(){
		memset(next,0,sizeof next);
		fail=NULL;sum=0;
	}
}; 
node *root=new node();
node *q[maxn];
void insert(char *s){
	node *p=root;
	for(int i = 0; s[i]; i++){
		int x=s[i]-'a';
		if(p->next[x]==NULL){
			p->next[x]=new node();
		}
		p=p->next[x];
	}
	p->sum++;
}

void build(){
	head=0;tail=1;
	q[head]=root;
	node *p,*temp;
	while(head<tail){
		temp=q[head++];
		for(int i = 0; i < 26; i++){
			if(temp->next[i]){
				if(temp==root) temp->next[i]->fail=root;
				else{
					p=temp->fail;
					while(p){
						if(p->next[i]){
							temp->next[i]->fail=p->next[i];
							break;
						}
						p=p->fail;
					}
					if(p==NULL) temp->next[i]->fail=root;
				}
				q[tail++]=temp->next[i];
			}
		}
	}
}
void ac(char *s){
	node *p=root;
	int len=strlen(s);
	cnt=0;
	for(int i = 0; i < len; i++){
		int x=s[i]-'a';
		while(!p->next[x]&&p!=root) p=p->fail;
		p=p->next[x];
		if(!p) p=root;
		node *temp=p;
		while(temp!=root){
			if(temp->sum>=0){
				cnt+=temp->sum;
				temp->sum=-1;
			}
			else break;
			temp=temp->fail;
		}
	}
}
char str[maxn],word[123];
int main(){
	ios::sync_with_stdio(0);
	int T;cin>>T;
	while(T--){
		memset(root->next,0,sizeof root->next);root->sum=0;root->fail=0;
		int n;cin>>n;
		for(int i = 0; i < n; i++){
			cin>>word;
			insert(word);
		}
		build();
		cin>>str;
		ac(str);
		cout<<cnt<<endl;
	}
	return 0;
}