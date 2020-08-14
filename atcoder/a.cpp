#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6 + 7;

int n;
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int k, a, b;
    cin >> k >> a >> b;
    if(a % k == 0 || b % k == 0 || b / k > a / k)cout << "OK\n";
    else cout << "NG\n";
    return 0;
}
