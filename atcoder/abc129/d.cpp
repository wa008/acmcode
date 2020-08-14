#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e3+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;
int n,m,ar[maxn];

char ch[maxn][maxn];
int a[2][maxn][maxn];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s", ch[i]+1);
    for(int i=1;i<=n;i++){
        int j=1;
        while(j<=m){
            while(j<=m && ch[i][j]=='#')j++;
            int pre = j;
            while(j<=m && ch[i][j]=='.'){
                j++;
            }
            for(int k=pre;k<j;k++)a[0][i][k] = j-pre;
        }
    }
    for(int i=1;i<=m;i++){
        int j=1;
        while(j<=n){
            while(j<=n && ch[j][i]=='#')j++;
            int pre = j;
            while(j<=n && ch[j][i]=='.'){
                j++;
            }
            for(int k=pre;k<j;k++)a[1][k][i] = j-pre;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ch[i][j]=='.'){
                int pre = ans;
                ans = max(ans, a[0][i][j]+a[1][i][j]-1);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
