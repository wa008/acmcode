#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
typedef long long ll;

int n,m;

int f[maxn],num[maxn],ar[maxn];
int findx(int x){
    return f[x]==x? x:f[x]=findx(f[x]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        f[i]=i;
        num[i]=1;
    }
    for(int i=1;i<=m;i++){
        int x;scanf("%d",&x);
        if(x==0)continue;
        x--;
        int pre;
        scanf("%d",&pre);
        for(int j=1;j<=x;j++){
            int now;scanf("%d",&now);
            pre = findx(pre);
            now = findx(now);
            if(pre!=now){
                f[pre] = now;
                num[now] += num[pre];
            }
            pre = now;
        }
    }
    for(int i=1;i<=n;i++){
        int x=i;
        x = findx(x);
        printf("%d%c", num[x], i==n?'\n':' ');
    }


    return 0;
}