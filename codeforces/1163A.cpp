#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3+7;
const ll mod = 1e9+7;
int n,m;
int ar[maxn];

int dp[maxn][maxn];
int main()
{
    scanf("%d%d",&n,&m);
    int ans;
    if(m<=1){
        ans = 1;
    }
    else if(m<=n/2){
        ans = m;
    }
    else{
        ans = n-m;
    }
    printf("%d\n",ans);
    return 0;
}