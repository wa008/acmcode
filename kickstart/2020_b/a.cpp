#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6 + 7;

int n, m, k;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    vector<int> v;
    for(int cas = 1; cas <= t; cas++){
        cin >> n;
        v.resize(0);
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        int ans = 0;
        for(int i=1;i<v.size() - 1; i++){
            if(v[i] > v[i - 1] && v[i] > v[i + 1])ans++;
        }
        cout << "Case #" << cas << ": " << ans << '\n';
    }

    return 0;
}
