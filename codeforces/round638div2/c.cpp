#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 1e6 + 7;
const ll f = 1e6;
int n, m, k;
int ar[maxn];


int main() 
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> n >> k;
        cin >> s;
        sort(s.begin(), s.end());
        string ans;
        int flag = 1;
        for(int i = 0; i < n / k; i++){
            int same = 1;
            for(int j = 1; j < k; ++j){
                if(s[i * k + j] != s[i * k + j - 1]){
                    same = 0;
                    break;
                }
            }
            ans += s[i * k + k - 1];
            if(same == 0){
                flag = 0;
                break;
            }
        }
        if(flag == 1 && n % k > 0){
            ans += s[s.size() - 1];
        }
        ans = min(ans, s.substr(k - 1));
        cout << ans << "\n";
    }   

    return 0;
}
