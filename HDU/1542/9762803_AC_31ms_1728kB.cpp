#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector> 
using namespace std;
double x1[123],y1[123],x2[123],y2[123];
vector<double> x,y;
int main(){
    int n,kase=0; 
    while(scanf("%d",&n)==1){
        x.clear(); y.clear();
        if(n==0)
            break;
        for(int i = 0; i < n; i++){
            scanf("%lf %lf %lf %lf",&x1[i],&y1[i],&x2[i],&y2[i]);
            x.push_back(x1[i]); x.push_back(x2[i]);
            y.push_back(y1[i]); y.push_back(y2[i]);
        }
        sort(x.begin(),x.end()); sort(y.begin(),y.end());
        double s = 0;
        for(int i = 0; i < 2*n-1; i++){ //NOTE: 注意离散方块是2n 
            for(int j = 0 ; j < 2*n-1; j++){
                double sz = (x[i+1]-x[i])*(y[j+1]-y[j]);
                for(int k = 0; k < n; k++){
                    if(x[i] >= x1[k] && y[j] >= y1[k] && x[i+1] <= x2[k] && y[j+1] <= y2[k]){
                        s+=sz;
                        //cout << s << endl;
                        break;
                    }
                }
            }
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n",++kase,s);
    }
    return 0;
}