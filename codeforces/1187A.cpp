#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const int sz = 101;
const ll mod = 1e9+7;
int n,m;

int main()
{
    int t;scanf("%d", &t);
    while(t--){
        int a,b;
        scanf("%d%d%d", &n, &a, &b);
        printf("%d\n", max(n-a+1, n-b+1));
    }
    
    return 0;
}
