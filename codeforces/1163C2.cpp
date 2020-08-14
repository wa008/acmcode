#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 1e9+7;
int n,m;
int ar[maxn];
ll xl[maxn],yl[maxn];
map<pair<ll,ll>, ll> ma;
set<pair<ll,ll>> se[maxn];

void add(int in, ll x, ll y, ll a,ll b){
    int flag=0;
    for(auto it : se[in]){
        ll xx = it.first, yy = it.second;
        if((yy-y)*a == (xx-x)*b){
            flag=1;
            break;
        }
    }
    if(!flag){
        se[in].insert(make_pair(x,y));
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld%lld", xl+i, yl+i);
    int index = 1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ll x=xl[j]-xl[i], y=yl[j]-yl[i];
            ll a=abs(x), b=abs(y);
            ll gg = __gcd(a,b);
            a/=gg;
            b/=gg;
            x/=gg;
            y/=gg;
            if(x*y==0){
                if(x==0){
                    a=0;b=1;
                }
                else{
                    a=1;b=0;
                }
                if(ma.count(make_pair(a,b))==0)ma[make_pair(a,b)]=index++;
                int in = ma[make_pair(a,b)];
                add(in, xl[i], yl[i], a, b);
            }
            else if(x*y>0){
                if(ma.count(make_pair(a,b))==0)ma[make_pair(a,b)]=index++;
                int in = ma[make_pair(a,b)];
                add(in, xl[i], yl[i], a, b);
            }
            else{
                b = -b;
                if(ma.count(make_pair(a,b))==0)ma[make_pair(a,b)]=index++;
                int in = ma[make_pair(a,b)];
                add(in, xl[i], yl[i], a, b);
            }
        }
    }
    ll s = 0;
    for(int i=1;i<index;i++){
        s += se[i].size();
    }
    ll ans=0;
    for(int i=1;i<index;i++){
        ans += 1LL*se[i].size()*(s-se[i].size());
    }
    //for(int i=1;i<index;i++)cout<<se[i].size()<<" ";cout<<"\n";
    printf("%lld\n",ans/2);
    return 0;
}