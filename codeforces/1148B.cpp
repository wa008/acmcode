#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const ll mod = 1000000000000037;

int n,m,ar[maxn];

int br[maxn];

int main()
{
    int ta,tb,k;
    scanf("%d%d",&n,&m);
    scanf("%d%d%d",&ta,&tb,&k);
    for(int i=1;i<=n;i++)scanf("%d", ar+i);
    for(int i=1;i<=m;i++)scanf("%d", br+i);
    int ans = 0;
    for(int i=0;i<=min(k, n-1);i++){
        int x = lower_bound(br+1, br+m+1, ar[i+1]+ta) - br + (k-i);
        if(x>m){
            ans=-1;
            break;
        }
        else ans = max(ans, br[x]+tb);
        //cout<<i<<" "<<x<<" "<<ans<<endl;
    }
    if(k>=m || k>=n)ans=-1;
    printf("%d\n", ans);

    return 0;
}