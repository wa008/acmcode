#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6 + 7;

int n, m, k;
int ar[maxn], pos[maxn];
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    vector<int> v;
    for(int cas = 1; cas <= t; cas++){
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i){
            cin >> ar[i];
            pos[ar[i]] = i;
        }
        int mx = n, shou = 0, flag = 1, mx_pre = n + 1;
        for(int i = 1; i <= n; ++i){
            if(shou == 0){
                if(pos[i] == mx){
                    mx_pre = mx;
                    mx--;
                }
                else if(pos[i] < mx){
                    mx_pre = mx + 1;
                    mx = pos[i] - 1;
                    shou = pos[i] + 1;
                }
                else{
                    //cout << "error " << i << ' ' << pos[i] << ' ' << mx << ' ' << shou << ' ' << mx_pre << '\n';
                    assert(1 == 2);
                }
            }
            else{
                if(shou == pos[i]){
                    ++shou;
                    if(shou == mx_pre){
                        shou = 0;
                    }
                }
                else{
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 1)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
