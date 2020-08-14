#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
const ll mod = 998244353;

int main() 
{
    int n, k;
    cin >> n >> k;
    if(n % 2 == 1){
        int l = 1, r = n;
        while(k -- ){
            cout << l << ' ' << r << '\n';
            l++;
            r--;
        }
    }
    else{
        int b = k / 2, a = k - b;
        int l = 1, r = (n + 1) / 2;
        while(a--){
            cout << l << ' ' << r << '\n';
            l++;
            r--;
        }
        l = (n + 1) / 2 + 1, r = n - 1;
        while(b--){
            cout << l << ' ' << r << '\n';
            l++, r--;
        }
    }

    return 0;
}
