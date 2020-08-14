#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
typedef long long ll;
int n, m, k;


int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        cin >> n;
        string s;
        cin >> s;
        string ans;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'S')ans += 'E';
            else ans += 'S';
        }
        cout << "Case #" << cas << ": " << ans << '\n';
    }


    return 0;
}
