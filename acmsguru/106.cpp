#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+7;
const ll mod = 1e9 + 9;
#define afdafafafdafaf y1;
int ar[maxn], n;


void exgcd(ll a,ll b,ll& d,ll &x,ll &y)
{
    if(!b){
        d=a,x=1,y=0;
    }
    else
    {
        exgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
int main()
{
    int aa,bb,cc,xx1,xx2,yy1,yy2;
    scanf("%d%d%d", &aa, &bb, &cc);
    scanf("%d%d", &xx1, &xx2);
    scanf("%d%d", &yy1, &yy2);
    double a = aa,b = bb, c = cc, x1 = xx1, x2 = xx2, y1 = yy1, y2 = yy2;
    double xy1, xy2;
    assert(xx1 <= xx2);
    assert(xx1 <= xx2);
    ll ans = 0;
    if(aa == 0 && bb == 0){
        if(cc == 0){
            ans = 1LL * (yy2 - yy1 + 1) * (xx2 - xx1 + 1);
        }
        else{
            ans = 0;
        }
    }
    else if(aa == 0){
        if(cc % bb == 0 && - cc / bb <= y2 && - cc / bb >= y1)ans = x2 - x1 + 1;
        else ans = 0;
    }
    else if(b == 0){
        if(cc % aa == 0 && - cc / aa <= x2 && - cc / aa >= x1)ans = y2 - y1 + 1;
        else ans = 0;
    }
    else{
        ll dd, xx, yy;
        exgcd(aa, bb, dd, xx, yy);
        dd = abs(dd);
        if(cc % dd == 0){
            if(aa < 0)dd *= -1;
            aa /= dd;
            bb /= dd;
            cc /= dd;
            a = aa;
            b = bb;
            c = cc;
            xx *= -cc;
            yy *= -cc;
            //cout << aa << ' ' << bb << ' ' << cc << '\n';
            //cout << xx << ' ' << yy << '\n';
            assert(aa * xx + bb * yy + cc == 0);
            xy1 = (-c - a * x1) / b;
            xy2 = (-c - a * x2) / b;
            y1 = max(y1, min(xy1, xy2));
            y2 = min(y2, max(xy1, xy2));
            //cout<<y1<<" "<<y2<<"\n";
            y1 = ceil((y1 - yy) / aa);
            y2 = floor((y2 - yy) / aa);
            ans = y2 - y1 + 1;
            ans = max(ans, 0LL);
        }
        else{
            ans = 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
