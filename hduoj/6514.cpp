#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e6+7;
const ll mod = 1e9+7;
int n,m;
int ar[maxn];

int main()
{
    while(scanf("%d%d",&n,&m)==2){
        int p;scanf("%d",&p);
        vector<vector<int>> g(n+2, vector<int>(m+2,0));
        for(; p--; ){
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            g[x1][y1]++;
            g[x2+1][y2+1]++;
            g[x2+1][y1]--;
            g[x1][y2+1]--;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                g[i][j] += g[i-1][j] + g[i][j-1] - g[i-1][j-1];
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                g[i][j] = g[i][j]>0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                g[i][j] += g[i-1][j] + g[i][j-1] - g[i-1][j-1];
            }
        }
        int q;scanf("%d",&q);
        for(; q--; ){
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            int ans = g[x2][y2] + g[x1-1][y1-1] - g[x1-1][y2] - g[x2][y1-1];
            ans = (ans == (y2-y1+1)*(x2-x1+1));
            printf("%s\n", ans?"YES":"NO");
        }
    }

    return 0;
}
