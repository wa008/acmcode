#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
typedef long long ll;

ll n, k, ar[maxn];
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    cin >> n >> k;
    vector<int> v;
    map<int, int> s;
    for(int i = 1; i <= n; ++i)cin >> ar[i];
    int now = 1, ins = 0;
    for(; ;){
        if(s.count(now))break;
        s[now] = ins++;
        v.push_back(now);
        now = ar[now];
    }
    if(k < v.size())cout << v[k] << "\n";
    else{
        int x = s[now];
        ins = (k - x) % (v.size() - x) + x;
        cout << v[ins] << '\n';
    }
    return 0;
}
