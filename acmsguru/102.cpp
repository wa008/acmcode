#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+7;
const ll mod = 1e9 + 9;
#define afdafafafdafaf y1;
int ar[maxn], n;
 
int main()
{
    scanf("%d", &n);
    int ins = 0;
    for(int i=1; i<=n; i++){
        if(__gcd(i, n) == 1)ins++;
    }
    printf("%d\n", ins);
    return 0;
}
