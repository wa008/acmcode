#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+7;
const ll mod = 1e9 + 9;
#define afdafafafdafaf y1;
int ar[maxn], n;

ll k;
int main()
{
    scanf("%d%lld", &n, &k);
    multiset<ll> s;
    for(int i = 1; i <= n; i++){
        scanf("%d", ar + i);
        s.insert(ar[i]);
    }
    ll be = * s.begin();
    auto it = s.end();
    it--;
    ll en = *it;
    ll be_ins = s.count(be), en_ins = s.count(en);
    ll ans = 0;
    s.erase(be);
    s.erase(en);
    while(be < en){
        if(s.size() == 0){
            be = min(en, be + k / min(be_ins, en_ins));
            break;
        }
        it = s.begin();
        ll new_be = *it;
        it = s.end();
        it--;
        ll new_en = *it;
        if(be_ins < en_ins){
            if(k > be_ins * (new_be - be)){
                k -= be_ins * (new_be - be);
                be = new_be;
                be_ins += s.count(be);
                s.erase(be);
            }
            else{
                be = min(en, be + k / be_ins);
                break;
            }
        }
        else{
            if(k > en_ins * (en - new_en)){
                k -= en_ins * (en - new_en);
                en = new_en;
                en_ins += s.count(en);
                s.erase(en);
            }
            else{
                en = max(be, en - k / en_ins);
                break;
            }
        }
    }
    ans = en - be;
    printf("%lld\n", max(0LL, ans));
    return 0;
}
