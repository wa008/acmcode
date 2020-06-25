#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e2 + 10;
const int mod = 998244353;
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        //cout << "s = " << s << "\n";
        vector<int> v;
        int res = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '+')++res;
            else --res;
            v.push_back(res);
        }
        int ins = 0;
        ll ans = 0;
        for (int i = 0; i <= n && ins < n; ++i){
            while(ins < n && i + v[ins] >= 0){
                ++ins;
            }
            ans += min(n, ins + 1);
            if(ins == n)break;
            //cout << i << ' ' << ins << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}
