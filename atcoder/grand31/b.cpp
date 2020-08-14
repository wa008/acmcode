#include<bits/stdc++.h>
using namespace std;

int mid[200005], ans[200005];
int n,ar[200005];
int main()
{
    int mod = 1e9 + 7;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",ar+i);
    ar[0]=-1;
    ans[0]=1;
    for(int i=1;i<=n;i++){
        ans[i] += ans[i-1];
        ans[i] %= mod;
        if(ar[i] != ar[i-1]){
            ans[i] += mid[ar[i]];
            ans[i] %= mod;
            mid[ar[i]] += ans[i-1];
            mid[ar[i]] %= mod;
        }
    }
    printf("%d\n",ans[n]);
    return 0;
}
