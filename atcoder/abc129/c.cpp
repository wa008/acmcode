#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;
int n,m,ar[maxn];

int l[maxn],r[maxn];

int main()
{
    set<int> s;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x;scanf("%d", &x);
        s.insert(x);
    }
    ar[0] = 1;
    for(int i=1;i<=n;i++){
        if(s.count(i))continue;
        if(i-1>=0 && s.count(i-1)==0)ar[i] += ar[i-1];
        if(i-2>=0 && s.count(i-2)==0)ar[i] += ar[i-2];
        ar[i] %= mod;
    }
    printf("%d\n", ar[n]);
    return 0;
}
