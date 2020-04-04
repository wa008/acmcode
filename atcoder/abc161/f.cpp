#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    long long n;
    cin >> n;
    set<ll> s;
    for(ll i=2;i<=sqrt(n);i++){
        if(n % i == 0){
            ll nx = n;
            while(nx % i == 0)nx /= i;
            if(nx % i == 1)s.insert(i);
        }
    }
    n--;
    for(ll i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            s.insert(i);
            s.insert(n / i);
        }
    }
    s.insert(n);
    s.insert(n + 1);
    if(n == 1)cout << "1\n";
    else cout << s.size() << '\n';

    return 0;
}
