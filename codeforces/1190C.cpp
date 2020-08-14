#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const ll mod = 1e9+7;
 
int n,m,k;
 
char ch[maxn];
bool vis[maxn];
int main()
{
    scanf("%d%d", &n, &k);
    scanf("%s", ch+1);
    int ins=1,cnt=0;
    while(ins<=n && ch[ins]==ch[1]){
        vis[ins]=1;
        cnt++;
        ins++;
    }
    bool flag=0;
    if(cnt+k>=n)flag=1;
 
    ins=n,cnt=0;
    while(ins>0 && ch[ins]==ch[n]){
        vis[ins]=1;
        ins--;
        cnt++;
    }
    if(cnt+k>=n)flag=1;
 
    ins=1;
    while(ins<=n && ch[ins]==ch[n]){
        ins++;
        cnt++;
    }
    if(cnt+k>=n)flag=1;
    if(flag){
        printf("tokitsukaze\n");
        return 0;
    }
    flag=0;
    vis[0] = vis[n+1] = 1;
    if(ch[1] != ch[n]){
        for(int i=2;i<n-k+1;i++){
            if(vis[i-1] && vis[i+k] && i-1<=k && n-(i+k-1)<=k);
            else{
                flag=1;
            }
        }
    }
    else{
        flag=1;
    }
    if(k<(n+1)/2)flag=1;
    if(flag)printf("once again\n");
    else printf("quailty\n");
 
 
   return 0;
}