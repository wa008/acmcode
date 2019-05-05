#include <bits/stdc++.h>
using namespace std;
#define y1 adfasfafa
const int maxn = 2e2+7;
typedef long long ll;

int n,m;
int ar[maxn];
char ch[maxn];

int a[2][maxn][maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d", &a[0][i][j]);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d", &a[1][i][j]);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        int x=a[0][i][j];
        int y=a[1][i][j];
        a[0][i][j] = min(x,y);
        a[1][i][j] = max(x,y);
    }
    int flag=1;
    for(int k=0;k<2;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<m;j++){
                if(a[k][i][j]>=a[k][i][j+1]){
                    flag=0;
                }
            }
        }
        for(int j=1;j<=m;j++){
            for(int i=1;i<n;i++){
                if(a[k][i][j]>=a[k][i+1][j]){
                    flag=0;
                }
            }
        }
    }
    printf("%s\n",flag==0?"Impossible":"Possible");

    return 0;
}