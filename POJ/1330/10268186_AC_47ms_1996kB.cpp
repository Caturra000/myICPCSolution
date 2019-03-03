#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
#define Size 11111  //节点个数

vector<int> node[Size],que[Size];
int n,pare[Size],anse[Size],in[Size],rank[Size];

int vis[Size];
void init()
{
	int i;
	for(i=1;i<=n;i++)
	{
		node[i].clear();
		que[i].clear();
		rank[i]=1;
		pare[i]=i;/// 
	}
	memset(vis,0,sizeof(vis));
	memset(in,0,sizeof(in));
	memset(anse,0,sizeof(anse));
	 
}

int find(int nd)//并查集操作  不解释
{
	return pare[nd]==nd?nd:pare[nd]=find(pare[nd]);
}
int Union(int nd1,int nd2)//并查集操作  不解释
{
	int a=find(nd1);
	int b=find(nd2);
	if(a==b) return 0;
	else if(rank[a]<=rank[b])
	{
		pare[a]=b;
		rank[b]+=rank[a];
	}
	else 
	{
		pare[b]=a;
		rank[a]+=rank[b];
	}
	return 1;

}

void LCA(int root)
{
	int i,sz;
	anse[root]=root;//首先自成一个集合
	sz=node[root].size();
	for(i=0;i<sz;i++)
	{
		   LCA(node[root][i]);//递归子树
		   Union(root,node[root][i]);//将子树和root并到一块 
		 anse[find(node[root][i])]=root;//修改子树的祖先也指向root
	}
	vis[root]=1;
	sz=que[root].size();
	for(i=0;i<sz;i++)
	{
            if(vis[que[root][i]])
			{
				printf("%d\n",anse[find(que[root][i])]);///root和que[root][i]所表示的值的最近公共祖先
				return ;
			}
	}
     return ;
}

int main()
{
	int cas,i;
	scanf("%d",&cas);
	while(cas--)
	{
		int s,e;
		scanf("%d",&n);
		init();
		for(i=0;i<n-1;i++)
		{
			scanf("%d %d",&s,&e);
			if(s!=e)
			{
			    node[s].push_back(e);
			   // node[e].push_back(s);
				in[e]++;
			}
		}
		scanf("%d %d",&s,&e);
		que[s].push_back(e);
		que[e].push_back(s);
		for(i=1;i<=n;i++)  if(in[i]==0) break;//寻找根节点
	//	printf("root=%d\n",i);
		LCA(i);
	}
	return 0;
}
//testtesttesttest