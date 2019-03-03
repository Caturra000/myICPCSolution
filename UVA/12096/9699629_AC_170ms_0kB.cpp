#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
set<int> si;
stack<int> s;
map<set<int>,int> msi;
vector<set<int> > vs;
int ID(set<int> si){
    if(msi[si] != 0){
        return msi[si];
    }
    else{
        vs.push_back(si);
        msi[si] = vs.size()-1;
        return msi[si];
    }
}
string inp;
int main(){
    int T; cin >> T;
    while(T--){
        si.clear(); msi.clear(); vs.clear();
        while(!s.empty()) s.pop();
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            cin >> inp;
            if(inp[0] == 'P'){
                s.push(ID(set<int>()));
            }
            else if(inp[0] == 'D'){
                s.push(s.top());
            }
            else{
                set<int> x1 = vs[s.top()]; s.pop();
                set<int> x2 = vs[s.top()]; s.pop();
                set<int> x;
                if(inp[0] == 'U'){
                    set_union(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
                }
                else if(inp[0] == 'I'){
                    set_intersection(x1.begin(),x1.end(),x2.begin(),x2.end(),inserter(x,x.begin()));
                }
                else{
                    x = x2; x.insert(ID(x1));
                }
                s.push(ID(x));
            }
            cout << vs[s.top()].size() << endl;
        }
        cout << "***" << endl;
    }
}