#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
typedef long long ll;
int n, m, k;

int ar[maxn], in[maxn];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    cin >> n >> m;
    int s = 0;
    for(int i=1;i<=n;i++){
        cin >> ar[i];
        s += ar[i];
    }
    sort(ar + 1, ar + n + 1);
    if(ar[n - m + 1] * 4 * m >= s)cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
