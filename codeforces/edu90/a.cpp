#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6 + 7;
const ll inf = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    while(t--){
        ll a, b, c;
        cin >> a >> b >> c;
        ll na, nb;
        if(a < c)na = 1;
        else na = -1;
        if(c < a * b)nb = b;
        else nb = -1;
        cout << na << ' ' << nb << "\n";
    }
    return 0;
}
