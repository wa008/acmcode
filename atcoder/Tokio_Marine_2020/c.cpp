#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int maxm = 2e3 + 10;
const int inf = 1e9 + 9;

int f[maxn << 2], n, k;
void add(int x, int val){
    while(x > 0){
        f[x] += val;
        x -= x & (-x);
    }
}
int que(int x){
    int s = 0;
    while(x <= n){
        s += f[x];
        x += x & (-x);
    }
    return s;
}
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    cin >> n >> k;
    vector<vector<int> > v(2, vector<int>(n + 1, 0));
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        v[0][i + 1] = x;
    }
    int ins = 0;
    while(k--){
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= n; ++i){
            add(min(n, i + v[ins][i]), 1);
            add(max(0, i - v[ins][i] - 1), -1);
        }
        for(int i = 1; i <= n; ++i){
            v[ins ^ 1][i] = que(i);
        }
        int flag = 1;
        ins ^= 1;
        for(int i = 1; i <= n; ++i){
            if(v[ins][i] != n){
                flag = 0;
                break;
            }
        }
        if(flag == 1)break;
    }
    for(int i = 1; i <= n; ++i){
        cout << v[ins][i];
        if(i == n)cout << '\n';
        else cout << ' ';
    }

    return 0;
}
