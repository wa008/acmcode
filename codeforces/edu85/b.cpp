#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    vector<int> v;
    while(t--){
        ll n, m;
        cin >> n >> m;
        v.resize(0);
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        ll s = 0, ins = 0, ans = 0;
        for(int i = v.size() - 1; i >= 0; i--){
            s += v[i];
            ins++;
            if(ins * m <= s){
                ans = ins;
            }
            else{
                break;
            }
        }
        cout << ans << '\n';

    }
    return 0;
}
