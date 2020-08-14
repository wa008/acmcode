#include <bits/stdc++.h>
using namespace std;
#define y1 adfasfafa
const int maxn = 2e5+7;
typedef long long ll;

int n,m;
int ar[maxn];
char ch[maxn];

int ans[maxn][4];
int vis[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++){
        for(int j=0;j<4;j++)ans[i][j]=1;
    }
    for(int i=1;i<=m;i++){
        scanf("%d", ar+i);
    }
    for(int i=m; i>=1; i--){
        vis[ar[i]] = 1;
        for(int j=0;j<3;j++){
            int x=ar[i]+j-1;
            if(x>0 && x<=n && vis[x]){
                ans[ar[i]][j]=0;
            }
        }
    }
    int ins=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            int x=i+j-1;
            if(x>0 && x<=n){
                ins += ans[i][j];
                //if(ans[i][x]>0)cout<<i<<" "<<x<<endl;
            }
        }
    }
    printf("%d\n",ins);

    return 0;
}