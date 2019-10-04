#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e7+7;
const ll mod = 998244353;
const int sz = 25;
#define afdafafafdafaf y1;
int n,m;
int ar[maxn];

int main()
{
    int a,b;
    scanf("%d%d%d", &n, &a, &b);
    int l=1, r = n*min(a, b);
    while(l<r){
        int mid = l+r>>1;
        if(mid/a + mid/b >= n){
            r = mid;
        }
        else{
            l = mid+1;
        }
    }
    assert(l==r);
    int a1 = n, a2 = l;
    if(l % a != 0){
        a2 = l/a*a+a;
        a1 = n+1;
    }
    else if(l % b != 0){
        a2 = l/b*b+b;
        a1 = n+1;
    }
    else{
        a1 = l/a + l/b;
        a2 = l;
    }
    printf("%d %d\n", a1, a2);
    return 0;
}
