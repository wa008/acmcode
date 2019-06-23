#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;

int n,m,ar[maxn];
int a1[maxn], a2[maxn];
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++)scanf("%d", ar+i);
    int ins=n;
    for(int i=1;i<n;i++){
        a1[i] = ar[0];
        a2[i] = ar[i];
        ar[ins++] = min(ar[0], ar[i]);
        ar[0] = max(ar[0], ar[i]);
    }
    while(m--){
        ll x;scanf("%lld", &x);
        if(x>n-1){
            printf("%d %d\n", ar[0], ar[(x-1)%(n-1)+n]);
        }
        else{
            printf("%d %d\n", a1[x], a2[x]);
        }
    }

    return 0;
}