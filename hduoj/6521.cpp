#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;

int n,m,ar[maxn];

ll s[maxn<<1],mx[maxn<<1],mn[maxn<<1],se[maxn<<1];
ll ins=0;
ll x,y,v;
void maintain(int l,int r,int o){
    s[o] = se[o]*(r-l+1);
    mx[o] = se[o];
    mn[o] = se[o];
}
void pushdown(int l,int r,int o){
    if(se[o]==-1)return ;
    //assert(se[o<<1]<=se[o]);
    //assert(se[o<<1|1]<=se[o]);
    se[o<<1] = se[o];
    se[o<<1|1] = se[o];
    se[o]=-1;
    int mid = l+r>>1;
    maintain(l,mid,o<<1);
    maintain(mid+1,r,o<<1|1);
}
void update(int l,int r,int o){
    //if(s[o] == 1LL*(r-l)*(r-l+1)/2)
    //cout<<l<<" "<<r<<endl;
    if(l>=x && r<=y){
        if(v>=mx[o]){
            se[o] = v;
            ins += se[o]*(r-l+1)-s[o];
            maintain(l,r,o);
            return ;
        }
        else if(v<=mn[o]){
            return ;
        }
    }
    assert(l<r);
    pushdown(l,r,o);
    int mid = l+r>>1;
    if(x<=mid)update(l,mid,o<<1);
    if(y>mid)update(mid+1, r, o<<1|1);
    s[o] = s[o<<1] + s[o<<1|1];
    mn[o] = min(mn[o<<1], mn[o<<1|1]);
    mx[o] = max(mx[o<<1], mx[o<<1|1]);
}
int main()
{
    while(scanf("%d%d",&n,&m)==2){
        for(int i=1;i<=(n<<2);i++){
            s[i]=0;
            mn[i]=n+1;
            mx[i]=0;
            se[i]=-1;
        }
        for(int i=1;i<=n;i++){
            x=y=v=i;
            ins=0;
            update(1,n,1);
            //cout<<"i,ins = "<<i<<" "<<ins<<"\n";
        }
        for(int i=1;i<=m;i++){
            scanf("%lld%lld",&x,&y);
            v=y;
            //cout<<"x,y= "<<x<<" "<<y<<endl;
            ins=0;
            update(1,n,1);
            printf("%lld\n", ins);
        }
    }
    return 0;
}
