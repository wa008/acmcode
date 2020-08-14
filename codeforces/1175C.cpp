#include<bits/stdc++.h>
#include<ctime>
using namespace std;
typedef long long ll;
const int maxn = 3e5+7;
const int maxm = 2e6+7;
const ll mod = (1LL<<62);
int n,m,ar[maxn];


int main()
{
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%d", ar+i);
        int l=0,r=m,mn=ar[n], ans=0;
        while(r<n){
            l++;
            r++;
            if(ar[r]-(ar[l]+ar[r])/2<mn){
                mn = ar[r]-(ar[l]+ar[r])/2;
                ans = (ar[l]+ar[r])/2;
            }
        }
        //cout<<"mx = "<<mn<<" "<<ans<<endl;
        printf("%d\n", ans);
    }
    return 0;
}