#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e2 + 7;

int n, m, k;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    // scanf("%d", &t);
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        string s;
        cin >> s;
        n = s.size();
        string a, b;
        for(int i = 0; i < n; i++){
            int x = s[i] - '0';
            if(x == 4){
                a += string("2");
                b += string("2");
            }
            else{
                if(int(a.size()) > 0)a += string("0");
                if(int(b.size()) > 0 || x > 0)b += char('0' + x);
            }
        }
        cout << "Case #" << cas << ": " << a << " " << b << "\n";
    }
    return 0;
}
