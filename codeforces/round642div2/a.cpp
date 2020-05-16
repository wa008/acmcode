#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6 + 7;

int n;
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    string s1, s2;
    cin >> s1;
    cin >> s2;
    if(s1.size() + 1 == s2.size() && s1 == s2.substr(0, s1.size()))cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
