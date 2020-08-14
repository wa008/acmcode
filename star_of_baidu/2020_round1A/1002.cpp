#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e2 + 10;
const int mod = 998244353;

vector<double> v(101, 0);

void func(int x, int y, double val){
    for(int i = x; i <= y; ++i)v[i] = val;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    func(0, 59, 0);
    func(60, 61, 1);
    func(62, 64, 1.7);
    func(65, 66, 2.0);
    func(67, 69, 2.3);
    func(70, 74, 2.7);
    func(75, 79, 3);
    func(80, 84, 3.3);
    func(85, 89, 3.7);
    func(90, 94, 4.0);
    func(95, 100, 4.3);
    for(int i = 0; i < 100; ++i)assert(v[i] <= v[i + 1]);
    int t;
    cin >> t;
    while(t--){
        int n, mn = 60, mx = 100;
        cin >> n;
        double ans = 0;
        for(int i = mn; i <= min(n, mx); ++i){
            ans = max(ans, v[i]);
            for(int j = i; j <= min(mx, n - i); ++j){
                ans = max(ans, v[i] + v[j]);
                for(int k = j; k <= min(mx, n - i - j); ++k){
                    int val = n - i - j - k;
                    val = min(val, mx);
                    ans = max(ans, v[i] + v[j] + v[k] + v[val]);
                }
            }
        }
        printf("%.1f\n", ans);
    }
    return 0;
}
