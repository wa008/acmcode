#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;
int n,m;
int ar[maxn];
int main()
{ 
    scanf("%d", &n);
    for(int i=0;i<n;i++)scanf("%d", ar+i);
    sort(ar, ar+n);
    int ans=0;
    ans = ar[n/2] - ar[n/2-1];
    printf("%d\n", ans);


    return 0;
}
