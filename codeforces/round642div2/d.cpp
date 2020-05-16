#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
typedef long long ll;

int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    
    int n, s;
    cin >> n >> s;
    vector<int> v;
    if(s >= n * 2){
        cout << "YES\n";
        for(int i = 1; i < n; ++i)cout << 2 << ' ';
        cout << s - (n - 1) * 2 << '\n';
        cout << "1\n";
    }
    else{
        cout << "NO\n";
    }
    /*
    int base = 1;
    for(int i = 1; i < n; ++i){
        if(s >= base){
            s -= base;
            v.push_back(base);
        }
        else{
            cout << "NO\n";
            return 0;
        }
        base *= 2;
    }
    //cout << base << ' ' << s << '\n';
    if(s > base){
        v.push_back(s);
        cout << "YES\n";
        for(int i = 0; i < v.size(); ++i){
            cout << v[i];
            if(i == v.size() - 1)cout << '\n';
            else cout << ' ';
        }
        cout << base << '\n';
    }
    else{
        cout << "NO\n";
    }
    */
    return 0;
}
