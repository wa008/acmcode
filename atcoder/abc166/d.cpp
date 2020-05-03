#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
typedef long long ll;

int n, k;
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    ll x;
    cin >> x;
    for(ll i = -1000; i <= 1000; ++i){
        for(ll j = -1000; j <= 1000; ++j){
            if(i * i * i * i * i - j * j * j * j * j == x){
                cout << i << ' ' << j << '\n';
                return 0;
            }
        }
    }   

    return 0;
}
