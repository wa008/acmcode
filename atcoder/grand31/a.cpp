#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;scanf("%d",&n);
    char ch[100007];
    scanf("%s",ch);
    int mod=1e9+7;
    long long ans=1;
    int ar[30];
    memset(ar,0,sizeof(ar));
    for(int i=0;i<n;i++){
        ar[ch[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        ans = ans * (ar[i] + 1) % mod;
    }
    ans = (ans - 1 + mod) % mod;
    printf("%lld\n",ans);

    return 0;
}
