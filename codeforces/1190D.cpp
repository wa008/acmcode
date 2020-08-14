#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const ll mod = 1e9+7;
 
int n,m,k;
int ar[maxn];
map<int,int> m1,m2;
int s1[maxn<<2],s2[maxn<<2];
int len1=0;
void add1(int x,int v){
    while(x<=len1){
        s1[x] += v;
        x += x&(-x);
    }
}
void add2(int x,int v){
    while(x>0){
        s2[x] += v;
        x -= x&(-x);
    }
}
ll que1(int x){
    ll ans=0;
    while(x>0){
        ans += s1[x];
        x -= x&(-x);
    }
    return ans;
}
ll que2(int x){
    ll ans=0;
    while(x<=len1){
        ans += s2[x];
        x += x&(-x);
    }
    return ans;
}
int xx[maxn];
pair<int,int> p[maxn];
set<int> s;
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d%d", &p[i].second, &p[i].first);
        xx[i] = p[i].second;
    }
    sort(p+1, p+n+1);
    sort(xx+1, xx+n+1);
    for(int i=1;i<=n;i++){
        if(m1.count(xx[i]));
        else{
            m1[xx[i]] = ++len1;
        }
    }
    ll ans=0;
    for(int i=n;i>=1;i--){
        int x = m1[p[i].second];
        //cout<<i<<" "<<x<<"\n";
        if(s.count(x)==0){
            add1(x, 1);
            add2(x, 1);
            s.insert(x);
        }
        if(i==1 || p[i].first!=p[i-1].first){
            ll x1=que1(x);
            ll x2=que2(x);
            ans += x1*x2;
            //cout<<i<<" "<<x1<<" "<<x2<<"\n";
        }
        else{
            int x1 = m1[p[i-1].second];
            ll a = que2(x);
            ll b = que1(x);
            ll c = que1(x1);
            ans += a*(b-c);
            //cout<<i<<" "<<a<<" "<<b<<" "<<c<<"\n";
        }
        //cout<<ans<<"\n\n";;
    }
    printf("%lld\n", ans);
 
    return 0;
}
