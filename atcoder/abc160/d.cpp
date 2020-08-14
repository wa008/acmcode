#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 7;
const int mod = 1e9 + 7;
typedef long long ll;
int n, m, k;

int ar[maxn];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int x, y;
    cin >> n >> x >> y;
    for(int i=1;i<=n;i++){
        ar[i] = n - i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int ins = min(j - i, abs(i - x) + abs(j - y) + 1);
            if(ins < j - i){
                ar[j - i]--;
                ar[ins]++;
                //cout << i << ' ' << j << ' ' << ins << '\n';
            }
        }
    }
    for(int i=1;i<n;i++)cout << ar[i] << '\n';
    return 0;
}
