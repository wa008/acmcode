#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6 + 7;

int n, m, k;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;cin>>t;
    while(t--){
        cin >> n;
        //cout << n << '\n';
        int a = 0, b = 0, flag = 1;
        for(int i=0;i<n;i++){
            int x, y;
            cin >> x >> y;
            if(x - a >= y - b && y - b >= 0);
            else {
                flag = 0;
            }
            a = x;
            b = y;
        }
        if(flag == 1)cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
