#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 1e6 + 7;
int n, m, k;


int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        cin >> n;
        vector<pair<pair<int, int>, int> > v;
        for(int i=0;i<n;i++){
            int a, b;
            cin >> a >> b;
            v.push_back(make_pair(make_pair(a, b), i));
        }
        sort(v.begin(), v.end());
        string ans(n, 'C');
        int e1 = 0, e2 = 0;
        for(int i=0;i<n;i++){
            if(v[i].first.first >= e1){
                ans[v[i].second] = 'C';
                e1 = v[i].first.second;
            }
            else if(v[i].first.first >= e2){
                ans[v[i].second] = 'J';
                e2 = v[i].first.second;
            }
            else{
                ans = string("IMPOSSIBLE");
                break;
            }
        }
        cout << "Case #" << cas << ": " << ans << '\n';
    }
    return 0;
}
