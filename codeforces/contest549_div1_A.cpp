#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,k,a,b;
    long long x,y;
    scanf("%lld%lld",&n,&k);
    scanf("%lld%lld",&a,&b);
    x=y=-1;
    for(int i=0;i<n;i++){
        long long now = i*k+b-a;
        if(now<0)now += n*k;
        long long ans = n*k/__gcd(n*k,now);
        if(x==-1)x=ans;
        else x=min(x,ans);
        if(y==-1)y=ans;
        else y=max(y,ans);

        now = i*k+(k-b)-a;
        if(now<0)now += n*k;
        ans = n*k/__gcd(n*k,now);
        if(x==-1)x=ans;
        else x=min(x,ans);
        if(y==-1)y=ans;
        else y=max(y,ans);
    }
    printf("%lld %lld\n",x,y);
    return 0;
}
