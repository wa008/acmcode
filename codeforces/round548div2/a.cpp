#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;scanf("%d",&n);
    char ch[100000];
    scanf("%s",ch+1);
    long long ans=0;
    for(int i=1;i<=n;i++){
        if((ch[i]-'0')%2==0)ans += i;
    }
    printf("%lld\n",ans);

    return 0;
}
