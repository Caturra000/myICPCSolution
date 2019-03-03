#include<iostream>
#include<algorithm>
using namespace std;
typedef struct CARD{int num,ID;}CARD;
bool cmp(CARD a,CARD b){return a.num < b.num;}
CARD card[123];
//bool hasM[123];int Matched = 0;
int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> card[i].num;
        card[i].ID = i;
    }
    sort(card+1,card+1+n,cmp);
    for(int i = 1; i <= n/2; i++){
        cout << card[i].ID << " " <<card[n-i+1].ID << endl;
    }
    return 0;
}