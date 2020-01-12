#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
typedef long long ll;
int n,m;
int ar[maxn];
ll s[maxn];
int main()
{
    int t;scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=1;i<=n;i++)scanf("%d", ar+i);
        int flag = 1;
        s[0] = 0;
        for(int i=1;i<=n;i++)s[i] = s[i-1] + ar[i];
        ll mn = 0;
        for(int i=1;i<n;i++){
            if(s[i] - mn >= s[n]){
                flag = 0;
                break;
            }
            if(s[n] - s[i] >= s[n]){
                flag = 0;
                break;
            }
            mn = min(mn, s[i]);
        }
        printf("%s\n", flag == 1 ? "YES" : "NO");
    }
    return 0;
}