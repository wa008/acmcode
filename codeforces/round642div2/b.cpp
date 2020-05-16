#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int ans = 0, now = 0;
        for(int i = 0; i < v.size(); i ++){
            now += 1;
            if(now == v[i]){
                now = 0;
                ++ans;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
