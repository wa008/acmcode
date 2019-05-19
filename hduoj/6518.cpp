#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e2+7;

int n,m,ar[maxn];

int g[maxn][maxn][maxn];
int main()
{
    int x,y,z;
    while(scanf("%d%d%d",&x,&y,&z)==3){
        for(int i=1;i<=x;i++)for(int j=1;j<=y;j++)for(int k=1;k<=z;k++)g[i][j][k]=1;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                int val;scanf("%d",&val);
                if(val==0){
                    for(int k=1;k<=z;k++)g[i][j][k]=0;
                }
            }
        }
        for(int i=1;i<=y;i++){
            for(int j=1;j<=z;j++){
                int val;scanf("%d",&val);
                if(val==0){
                    for(int k=1;k<=x;k++)g[k][i][j]=0;
                }
            }
        }
        for(int i=1;i<=z;i++){
            for(int j=1;j<=x;j++){
                int val;scanf("%d",&val);
                if(val==0){
                    for(int k=1;k<=y;k++)g[j][k][i]=0;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=x;i++)for(int j=1;j<=y;j++)for(int k=1;k<=z;k++)ans += g[i][j][k];
        printf("%d\n", ans);
    }
    
    return 0;
}
