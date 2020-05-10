#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long ll;

int ar[maxn];
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min(a, d) + -1 * (max(0, min(c, d - a - b))) << "\n";

    return 0;
}
