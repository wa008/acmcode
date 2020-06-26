#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 7;
const int maxm = 4e6 + 7;
const int INF = 2e9 + 10;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n, 0), b(n, 0), left(n, 0), right(n, 0);
    for(int &x : a)cin >> x;
    for(int &x : b)cin >> x;
    for(int i = 0; i < n; ++i){
        int larger = (i + 1) % n;
        left[i] = min(a[i], b[i]);
        a[i] -= left[i];
        b[i] -= left[i];
        right[i] = min(b[i], a[larger]);
        b[i] -= right[i];
        a[larger] -= right[i];
    }
    for(int i = 0; i < n; ++i){
        int lower, mn;
        lower = (i + n - 1) % n;
        mn = min(b[lower], a[i]);
        b[lower] -= mn;
        a[i] -= mn;
        right[lower] += mn;
        mn = min(b[lower], left[i]);
        b[lower] -= mn;
        right[lower] += mn;
        left[i] -= mn;
        b[i] += mn;
        if(a[i] > 0){
            cout << "NO\n";
            return ;
        }
    }
    cout << "YES\n";
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
