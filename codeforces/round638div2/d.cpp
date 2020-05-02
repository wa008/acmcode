#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
typedef long long ll;
typedef long double ld;
const ld eps = 1e-30;

int n, k;
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    vector<int> ans;
    while(t--){
        ans.resize(0);
        cin >> n;
        int x = n, cnt = 0;
        while(x > 0){
            x >>= 1;
            cnt ++;
        }
        cnt--;
        x = n;
        x -= cnt + 1;
        int cell = 1;
        for(int i = 0; i < cnt; ++i){
            int num = min(cell, x / (cnt - i));
            x -= num * (cnt - i);
            cell += num;
            ans.push_back(num);
            //cout << i << ' ' << x << "\n";
        }
        cout << cnt << "\n";
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i];
            if(i == ans.size() - 1)cout << '\n';
            else cout << ' ';
        }
    }
    return 0;
}
