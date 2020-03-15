#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
typedef long long ll;
int n, m, k;

int main()
{
    scanf("%d%d", &n, &m);
    if(n == 1 || m == 1){
        printf("1\n");
    }
    else{
        printf("%lld\n", (1LL * n * m + 1) / 2);
    }


    return 0;
}
