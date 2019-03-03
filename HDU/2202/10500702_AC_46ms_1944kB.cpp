#include<iostream>
#include<algorithm>
#include<cstdio> 
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 1e5;
struct point{
	int x,y;
}p[maxn];
int dis(point a,point b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int cross(point p0,point p1,point p2){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
bool cmp1(point p1,point p2){
	return p1.x<p2.x||(p1.x==p2.x&&p1.y<p2.y);
}
bool cmp2(point p1,point p2){
	int c = cross(p[0],p1,p2);
	if(c==0) return dis(p[0],p1)<dis(p[0],p2);
	return c>0;
}
point sta[maxn];
int top,n;
void convex(int n){
	top=0;
	sort(p,p+n,cmp1);
	sort(p+1,p+n,cmp2);
	sta[top++]=p[0];
	sta[top++]=p[1];
	for(int i = 2; i < n; i++){
		if(cross(sta[top-2],sta[top-1],p[i])>0) sta[top++]=p[i];
		else{
			top--;
			while(top>=2&&cross(sta[top-2],sta[top-1],p[i])<=0) top--;
			sta[top++]=p[i];
		}
	}
}
int rotating(){
	int q=1,ans=0;
	sta[top]=sta[0];
	for(int i = 0; i < top; i++){
		while(cross(sta[i],sta[i+1],sta[q+1])>cross(sta[i],sta[i+1],sta[q]))
			q=(q+1)%top;
		ans = max(ans,max(dis(sta[i],sta[q]),dis(sta[i+1],sta[q+1])));
	}
	return ans;
}
double rotating(int n)
{
    int j=1,k=0;
    double ans=0;
    for(int i=0;i<n;i++)
    {
        j=(i+1)%n;
        k=(j+1)%n;
        while(fabs(cross(sta[i],sta[j],sta[k]))<fabs(cross(sta[i],sta[j],sta[(k+1)%n])))
             k=(k+1)%n;
        while(j!=i&&k!=i)
        {
            ans=max(ans,fabs(cross(sta[i],sta[j],sta[k])));
            while(fabs(cross(sta[i],sta[j],sta[k]))<fabs(cross(sta[i],sta[j],sta[(k+1)%n])))
                 k=(k+1)%n;
            j=(j+1)%n;
        }
    }
    return ans*0.5;
}

int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i = 0; i < n; i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		convex(n);
		double ans = rotating(top);
		printf("%.2lf\n",ans);
	}
	return 0;
}