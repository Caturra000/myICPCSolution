#include<cstdio>
#include<cstring>
char a[] = "++X";
char b[] = "X++";
char c[] = "--X";
char d[] = "X--";
char inp[5];
int main(){
    int n;
    int ans = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%s",inp);
        if(strcmp(inp,a) == 0 || strcmp(inp,b) == 0)
            ans++;
        if(strcmp(inp,c) == 0 || strcmp(inp,d) == 0)
            ans--;
    }
    printf("%d",ans);
    return 0;
}