#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;
int n,m;
int ar[maxn];
int main()
{ 
    scanf("%d", &n);
    for(int i=0;i<n;i++)scanf("%d", ar+i);
    int ans=0;
    for(int i=1;i<n-1;i++){
        if((ar[i]>ar[i-1] && ar[i]<ar[i+1]) || (ar[i]<ar[i-1] && ar[i]>ar[i+1]))ans++;
    }
    printf("%d\n", ans);
    return 0;
}
