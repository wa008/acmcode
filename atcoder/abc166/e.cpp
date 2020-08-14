#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 7;
const ll mod = 998244353;

map<int, int> mp;
int main() 
{
    ll ans = 0, n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        if(mp.count(i - x) > 0)ans += mp[i - x];
        if(mp.count(x + i))
            mp[x + i] += 1;
        else{
            mp[x + i] = 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
