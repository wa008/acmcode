#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 1e6 + 7;
int n, m, k;

bool is_prime(int x){
    for(int i=2;i<x;i++){
        if(x % i == 0)return 0;
    }
    return 1;
}
int ar[maxn], nx[maxn];
int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        string ns;
        cin >> ns >> m;
        for(int i=0;i<m;i++){
            cin >> ar[i];
        }
        set<int> s;
        for(int i=0;i<m-1;i++){
            if(ar[i] != ar[i+1]){
                int gcd = __gcd(ar[i], ar[i+1]);
                nx[i] = ar[i] / gcd;
                s.insert(nx[i]);
                for(int j = i + 1; j <= m; j++){
                    nx[j] = ar[j - 1] / nx[j - 1];
                    //cout << j << ' ' << nx[j] << '\n';
                    s.insert(nx[j]);
                }
                for(int j = i - 1; j >= 0; j--){
                    nx[j] = ar[j + 1] / nx[j + 1];
                    s.insert(nx[j]);
                }
                /*
                for(int i=0;i<m;i++)cout << nx[i] << ' '; cout << '\n';
                */
                for(int x : s) cout << x << ' '; cout << '\n';
                cout << "s.size() = " << s.size() << '\n';
                assert(int(s.size() == 26));
                map<int, char> mp;
                char c = 'A';
                // cout << "debug\n";
                for(int x : s){
                    mp[x] = c;
                    c++;
                }
                cout << "Case #" << cas << ": ";
                for(int i=0;i<=m;i++)cout << mp[nx[i]];
                cout << '\n';
                break;
            }
        }
    }
    return 0;
}
