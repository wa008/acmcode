#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e2 + 7;

int n, m, k;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    string s;
    cin >> s;
    if(s[2] == s[3] && s[4] == s[5])cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
