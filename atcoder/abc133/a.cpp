#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 1e9+7;

int n,m;

int main()
{
    int a,b;
    scanf("%d%d%d", &n, &a, &b);
    printf("%d\n", min(n*a, b));
    return 0;
}
