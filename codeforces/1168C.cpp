#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+7;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;

int n,m,q;
int ar[maxn];
vector<int> g[maxn];
set<pair<int,int>> se;

int mn[maxn][21];
int pre[maxn];
int main()
{
    scanf("%d%d",&n, &q);
    for(int i=1;i<=n;i++)for(int j=0;j<=20;j++)mn[i][j] = n+1;
    for(int i=1;i<=n;i++)scanf("%d", ar+i);
    for(int i=n;i>=1;i--){
        int x=ar[i];
        for(int j=0;j<=20;j++){
            if(x & (1<<j)){
                if(pre[j]!=0){
                    mn[i][j] = pre[j];
                    int a=i,b=pre[j];
                    for(int k=0;k<=20;k++){
                        mn[a][k] = min(mn[a][k], mn[b][k]);
                    }
                }
                pre[j] = i;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=20;j++){
            //if(mn[i][j]!=n+1)cout<<i<<" "<<j<<" "<<mn[i][j]<<"\n";
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        scanf("%d%d", &x, &y);
        bool ok = false;
        for(int j=0; !ok && j<=20;j++){
            if((ar[y]>>j) & 1){
                //cout<<x<<" "<<y<<" "<<j<<endl;
                if(mn[x][j]<=y){
                    ok=true;
                }
            }
        }
        printf("%s\n", ok==true?"Shi":"Fou");
    }
    return 0;
}