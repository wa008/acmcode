#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long ll;

int ar[maxn];
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    ll x;
    cin >> x;
    ll cnt = 0;
    ll base = 100;
    while(base < x){
        base = base * 1.01;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
