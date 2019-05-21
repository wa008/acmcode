#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;

int n,m,k;
int ar[maxn];

int main()
{
    scanf("%d",&n);
    while(n--){
        vector<ll> ans(100, 0);
        ll a,b,m;
        scanf("%lld%lld%lld",&a,&b,&m);
        if(b<a){
            printf("-1");
        }
        else if(a==b){
            printf("1 %lld\n", a);
        }
        else{
            ll x=1;
            int flag=0,len=0;
            for(int i=2;i<=60;i++){
                if(b-x*a < x)break;
                if(b-x*a<=x*m){
                    len=i;
                    break;
                }
                x*=2;
            }
            if(!len){
                printf("-1\n");
                continue;
            }
            x = b*2-2;
            flag=len;
            while(flag>=2){
                ans[flag] = x/2+1;
                x -= ans[flag];
                flag--;
            }
            ans[1] = a;
            ll s=a;
            for(int i=2;i<=len;i++){
                assert(ans[i]-s >=1 && ans[i]-s<=m);
                s += ans[i];
            }
            assert(ans[1]==a);
            assert(ans[len]==b);
            printf("%d ", len);
            for(int i=1;i<=len;i++)printf("%lld%c", ans[i], i==len?'\n':' ');
        }
    }
    return 0;
}