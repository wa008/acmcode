#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const int maxm = 2e5+7;
const ll mod = 998244353;

int n,m,ar[maxn];
struct node{
    ll b,l,r;
    ll cmp;
    bool operator < (const node& n)const{
        return cmp>n.cmp;
    }
    void prin(){
        cout << b << " " << l << " " << r << "\n";
    }
}no[maxn];
bool che(ll x){
    int mark=0;
    ll a = x/m, b = x%m;
    ll all1=0, all2=0;
    for(int i=1;i<=n;i++){
        if(i<=a+1){
            all1 += (m-no[i].b)*no[i].r;
        }
        else{
            all1 -= no[i].b*no[i].l;
        }
        if(i<=a){
            all2 += (m-no[i].b)*no[i].r;
        }
        else{
            all2 -= no[i].b*no[i].l;
        }
    }
    for(int i=1;i<=n;i++){
        if(i<=a+1){
            ll now = all1 - (m-no[i].b)*no[i].r;
            now += max((b-no[i].b)*no[i].l, (b-no[i].b)*no[i].r);
            if(now>=0){
                //if(mark==x)cout<<"makr = "<< i<<" "<<now<<" "<<all1<<endl;
                return 1;
            }
        }
        else{
            ll now = all2 + no[i].b*no[i].l;
            now += max((b-no[i].b)*no[i].l, (b-no[i].b)*no[i].r);
            if(now>=0){
                //if(mark==x)cout<<"mark = "<< i<<" "<<now<<" "<<all1<<endl;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld", &no[i].b, &no[i].l, &no[i].r);
        no[i].cmp = no[i].r*(m-no[i].b) + no[i].l*no[i].b;
    }
    sort(no+1, no+n+1);
    //for(int i=1;i<=n;i++)no[i].prin();
    ll l=0,r=1LL * m * n;
    while(l<r){
        ll mid = l+r>>1;
        if(che(mid))r=mid;
        else l=mid+1;
    }
    printf("%lld\n", l);
    return 0;
}
