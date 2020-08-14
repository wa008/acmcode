#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e2 + 7;

int n, m, k, x;
int arr[maxn][maxn];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        cin >> n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)cin >> arr[i][j];
        }
        int k = 0, r = 0, c = 0;
        for(int i=1;i<=n;i++){
            set<int> s;
            for(int j=1;j<=n;j++){
                if(arr[i][j] >= 1 && arr[i][j] <= n)s.insert(arr[i][j]);
            }
            if(s.size() != n)r++;
            k += arr[i][i];
        }
        for(int i=1;i<=n;i++){
            set<int> s;
            for(int j=1;j<=n;j++){
                if(arr[j][i] >= 1 && arr[j][i] <= n)s.insert(arr[j][i]);
            }
            if(s.size() != n)c++;
        }
        cout << "Case #" << cas << ": " << k << ' ' << r << ' ' << c << '\n';
    }




    return 0;
}
