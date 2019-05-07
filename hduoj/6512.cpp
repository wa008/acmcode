#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e6+7;
const ll mod = 1e9+7;
int n,m;
int ar[maxn];

int main()
{
    int mx = INT_MAX;
    ll a=1,b=1,ins=0;
    while(b<mx){
        ll mid = b;
        b = a+b;
        a = mid;
        ins++;
    }
    //cout<<"ins = "<<ins<<endl;
    while(scanf("%d",&n)==1){
        
        for(int i=1;i<=n;i++)scanf("%d",ar+i);
        if(n>=55){
            printf("YES\n");
            continue;
        }
        sort(ar+1, ar+n+1);
        int flag=0;
        for(int i=3; i<=n; i++){
            if(ll(ar[i-2]) + ar[i-1] > ar[i]){
                printf("YES\n");
                flag=1;
                break;
            }
        }
        if(!flag)printf("NO\n");


    }
    return 0;
}
