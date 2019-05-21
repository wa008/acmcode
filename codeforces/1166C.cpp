#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;

int n,m,k;
int ar[maxn];
char ch[maxn]="aeiou";
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        ar[i] = abs(x);
    }
    sort(ar+1, ar+n+1);
    ll ans=0;
    for(int i=1;i<=n;i++){
        int k = upper_bound(ar+1, ar+n+1, ar[i]*2)-ar;
        ans += k-i-1;
    }
    printf("%lld\n", ans);


    return 0;
}