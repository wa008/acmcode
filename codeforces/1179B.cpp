#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;

int n,m,ar[maxn];
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n/2;i++){
        for(int j=1;j<=m;j++){
            printf("%d %d\n", i, j);
            printf("%d %d\n", n-i+1, m-j+1);
        }
    }
    if(n&1){
        n = n/2+1;
        for(int j=1;j<=m/2;j++){
            printf("%d %d\n", n, j);
            printf("%d %d\n", n, m-j+1);
        }
        if(m&1)printf("%d %d\n", n, m/2+1);
    }
    return 0;
}