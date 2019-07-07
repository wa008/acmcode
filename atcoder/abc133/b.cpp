#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e2+7;
const ll mod = 1e9+7;
int n,m;

int arr[maxn][maxn];
int main()
{
    scanf("%d%d", &n, &m);
    int ans=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d", arr[i]+j);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ll ins=0;
            for(int k=1;k<=m;k++){
                ins += (arr[i][k] - arr[j][k])*(arr[i][k] - arr[j][k]);
            }
            ll nn = sqrt(ins);
            ans += (nn*nn==ins);
        }
    }
    printf("%d\n", ans);
    return 0;
}
