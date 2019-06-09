#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6+7;
const int maxm = 2e6+7;
const ll mod = 998244353 ;
int n,m,ar[maxn];

int l[maxn],r[maxn];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d", ar+i);
    for(int i=1;i<=n;i++){
        l[i] = l[i-1]+ar[i];
    }
    for(int i=n;i>0;i--){
        r[i] = r[i+1]+ar[i];
    }
    int ans = 1000000;
    for(int i=1;i<n;i++){
        ans = min(ans, abs(l[i] - r[i+1]));
    }
    printf("%d\n", ans);





    return 0;
}
