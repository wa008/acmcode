#include<bits/stdc++.h>
using namespace std;
int ar[300000];
int main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",ar+i);
    long long ans=0;
    for(int i=n;i>=1;i--){
        if(i==n || ar[i]<ar[i+1]){
            ans += ar[i];
        }
        else{
            ar[i] = max(min(ar[i], ar[i+1]-1),0);
            ans += ar[i];
        }
    }
    printf("%lld\n",ans);

    return 0;
}
