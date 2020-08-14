#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
typedef long long ll;
typedef long double ld;
const ld eps = 1e-30;

int n, k;
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    ll a, b, n;
    cin >> a >> b >> n;
    cout << a * min(b - 1, n) / b << "\n";
    return 0;
}
