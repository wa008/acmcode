#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
typedef long long ll;
int n, m;
int v, p;
int ar[maxn];
bool check(int index){
    int x = ar[index] + m;
    if(ar[index] + m < ar[n - p + 1])return false;
    ll last = 1LL * (v - p + 1) * m;
    for(int i = 1; i <= n - p + 1; i++){
        last -= min(m, max(0, x - ar[i]));
    }
    return last <= 0;
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &v, &p);
    for(int i = 1; i <= n; i++)scanf("%d", ar + i);
    sort(ar + 1, ar + n + 1);
    //for(int i = 1; i <= n; i++)cout << ar[i] << " ";
    //cout << "\n";
    int l = 1, r = n - p + 1;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid))r = mid;
        else l = mid + 1;
    }
    printf("%d\n", n - l + 1);
    return 0;
}
