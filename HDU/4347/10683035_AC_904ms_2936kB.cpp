#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
const int Maxn = 100005;
int n,K,Q,m,D,i,root;
int son[Maxn][2];
struct Point
{
  int x[5];
  void read()
  {
    for (int i=0;i<K;i++)
      scanf("%d",&x[i]);
  }
  void print()
  {
    for (int i=0;i<K-1;i++)
      printf("%d ",x[i]);
    printf("%d\n",x[K-1]);
  }
  bool operator <(const Point &a)const
  {
    return x[D] < a.x[D];
  }
} dot[Maxn], P;

typedef pair<int,int> PR;
#define di first
#define id second
priority_queue <PR> heap;
vector <int> ans;

int build(int l,int r,int now){
  if (l>r) return 0;
  D = now;
  int mid = (l+r)>>1;
  nth_element(dot+l,dot+mid,dot+r+1);
  //L[mid] = l; R[mid] = r;
  son[mid][0] = build(l,mid-1,(now+1)%K);
  son[mid][1] = build(mid+1,r,(now+1)%K);
  return mid;
}
#define sqr(x) ((x)*(x))
int Distance(Point P1,Point P2){
  int ret = 0;
  for (int i=0;i<K;i++)
    ret += sqr(P1.x[i]-P2.x[i]);
  return ret;
}

void query(int cur,int now){
  if (cur==0) return;
  PR nd(Distance(dot[cur],P), cur);
  int x = son[cur][0], y = son[cur][1];
  if (dot[cur].x[now]<P.x[now]) swap(x,y);
  query(x,(now+1)%K);
  if (heap.size()<m) heap.push(nd);
  else
  {
    if (nd.di<heap.top().di) heap.pop(), heap.push(nd);
  }
  if ( sqr(dot[cur].x[now]-P.x[now]) <= heap.top().di )
    query(y,(now+1)%K);
}

int main(){
  while (~scanf("%d%d",&n,&K)){
    for (i=1;i<=n;i++)
      dot[i].read();
    root = build(1,n,0);
    scanf("%d",&Q);
    while (Q--){
      P.read(); scanf("%d",&m);
      printf("the closest %d points are:\n",m);
      query(root, 0);
      while (!heap.empty())
      {
        ans.push_back(heap.top().id);
        heap.pop();
      }
      while (!ans.empty())
      {
        dot[ans.back()].print();
        ans.pop_back();
      }
    }
  }
  return 0;
}
//just test