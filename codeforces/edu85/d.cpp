#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 7;
const int mod = 1e9 + 7;
typedef long long ll;


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    vector<ll> ans;
    while(t--){
        ll n, l, r;
        ans.resize(0);
        cin >> n >> l >> r;
        //cout << n << ' ' << l << ' ' << r << '\n';
        ll in = 1, res = n - 1;
        for(int i = 1; i < n; i++){
            ll num = (n - i) * 2;
            ll base = i;
            if(r >= in && l < in + num){
                for(int j = base + 1; j <= n; j++){
                    if(in >= l && in <= r)ans.push_back(base);
                    in++;
                    if(in >= l && in <= r)ans.push_back(j);
                    in++;
                }
            }
            else{
                in += num;
            }
            if(r < in)break;
        }
        if(in == r && in == n *(n - 1) + 1)ans.push_back(1);
        for(int i=0;i<ans.size(); i++){
            cout << ans[i];
            if(i == int(ans.size() - 1))cout << '\n';
            else cout << ' ';
        }
    }


    return 0;
}
