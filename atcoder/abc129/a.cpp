#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6+7;
const int maxm = 2e6+7;
const ll mod = 998244353 ;
int n,m,ar[maxn];


int main()
{
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    int sum = a+b+c;
    printf("%d\n", sum - max(a, max(b,c)));




    return 0;
}
