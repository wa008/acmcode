#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
typedef long long ll;
int n, m, k;


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    cin >> n;
    cout << n / 500 * 1000 + (n % 500) / 5 * 5 << "\n";
    return 0;
}
