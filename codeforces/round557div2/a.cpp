#include <bits/stdc++.h>
using namespace std;
#define y1 adfasfafa
const int maxn = 2e5+7;
typedef long long ll;

int n,m;
int ar[maxn];
char ch[maxn];


int main()
{
    int h;
    scanf("%d%d%d",&n,&h,&m);
    for(int i=1;i<=n;i++)ar[i] = h;
    for(int i=1;i<=m;i++){
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        for(int i=a;i<=b;i++){
            ar[i] = min(ar[i], c);
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans += ar[i]*ar[i];
    }
    printf("%lld\n",ans);

    return 0;
}