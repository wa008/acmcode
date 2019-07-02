#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const int sz = 101;
const ll mod = 1e9+7;
int n,m;

int main()
{
    double lg = log10(2);
    int cas=0;
    while(scanf("%d", &n)==1){
        printf("Case #%d: %d\n", ++cas, int(n*lg));
    }
    
    return 0;
}
