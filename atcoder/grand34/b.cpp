#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const int maxm = 2e5+7;
const ll mod = 998244353;

int n,m,ar[maxn];
char ch[maxn];
int main()
{
    scanf("%s",ch);
    n=strlen(ch);
    ll ans=0, a=0, b=0;
    for(int i=0;i<n;i++){
        if(ch[i]=='A'){
            a++;
        }
        else if(ch[i]=='B' && ch[i+1]=='C'){
            ans += a;
            i++;
        }
        else{
            a=0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
