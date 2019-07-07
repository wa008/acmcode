#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+7;
const int mod = 1e9+7;
typedef long long ll;

int n,m;
ll a[maxn], b[maxn];

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)scanf("%lld", a+i);
    ll sum=0;
    for(int i=1;i<=n;i++){
        if(i&1)sum += a[i];
        else sum -= a[i];
    }
    sum /= 2;
    b[1] = sum;
    for(int i=2;i<=n;i++){
        sum = a[i-1]-sum;
        b[i] = sum;
    }
    for(int i=1;i<=n;i++){
        printf("%lld%c", b[i]*2, i==n?'\n':' ');
    }
    return 0;
}
