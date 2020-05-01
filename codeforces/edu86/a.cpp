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
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if(b < a * 2){
            cout << a * 1LL * abs(x - y) + b * 1LL * min(x, y) << '\n';
        }
        else{
            cout << 1LL * a * (x + y) << '\n';
        }
    }
    return 0;
}
