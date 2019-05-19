#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
typedef long long ll;

int n,m;
int ar[maxn],num[maxn],mx[maxn],mn[maxn];
int ss[maxn<<1];

void update(int x){
    int v=x;
    while(x>0){
        ss[x] = min(ss[x], v);
        x -= x&(-x);
    }
}
int que(int x){
    int ans = m+1;
    while(x<=m){
        ans = min(ans, ss[x]);
        x += x&(-x);
    }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d", ar+i);
    for(int i=0;i<=m;i++)ss[i] = m+1;
    for(int i=0;i<=max(n,m);i++)mn[i] = m+1;
    int x=0;
    for(int i=1;i<=n;i++){
        if(x>ar[i]){
            mx[ar[i]] = max(mx[ar[i]], x);
        }
        x = max(x, ar[i]);
        mn[ar[i]] = min(mn[ar[i]], que(ar[i]+1));
        update(ar[i]);
        //for(int i=1;i<=m;i++)cout<<que(i)<<" ";cout<<endl;
    }
    ll ans=0;
    x=0;//max
    int y=m+1;//min
    for(int i=1;i<=m;i++){
        if(mx[i]>i){
            x = max(x, i);
        }
    }
    for(int i=1;i<=m;i++){
        if(y<i){
            break;
        }
        x = max(x, i);
        ans += max(0, m+1-x);
        //cout<<"i,x = "<<i<<" "<<x<<endl;
        x = max(x, mx[i]);
        if(y==-1 || y>mn[i])y = mn[i];
    }
    printf("%lld\n",ans);
    return 0;
}