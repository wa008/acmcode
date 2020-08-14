#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
typedef long long ll;
int n, m, k;

int ar[maxn], in[maxn];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++){
        string s;
        cin >> s;
        string ans;
        int res = 0;
        for(int i=0; i<s.size(); i++){
            while(res < int(s[i] - '0')){
                res += 1;
                ans += '(';
            }
            while(res > int(s[i] - '0')){
                res -= 1;
                ans += ')';
            }
            ans += s[i];
        }
        while(res > 0){
            res--;
            ans += ')';
        }
        cout << "Case #" << cas << ": " << ans << '\n';
    }

    return 0;
}
