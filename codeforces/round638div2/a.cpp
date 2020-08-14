#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6 + 7;

int n;
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        cin >> n;
        ll a = 0, b = 0;
        a += (1LL << n);
        for(int i = 1; i < n / 2; i ++)a += (1 << i);
        for(int i = n / 2; i < n; i ++)b += (1 << i);
        cout << abs(a - b) << "\n";
    }
    return 0;
}
