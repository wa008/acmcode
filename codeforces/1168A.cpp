#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;

int n,m;
int ar[maxn];
char ch[maxn];

bool che(int x){
    int pre=0;
    for(int i=1;i<=n;i++){
        int now = ar[i];
        int ne = (now+x)%m;
        bool ff=1;
        if(now+x>=m){
            if(pre>=now || pre<=ne);
            else pre = now;
        }
        else{
            if(pre>=now && pre<=now+x);
            else if(pre>now+x){
                return 0;
            }
            else{
                pre = now;
            }
        }
    }
    return 1;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d", ar+i);
    int l=0,r=m;
    while(l<r){
        int mid = l+r>>1;
        if(che(mid))r=mid;
        else l=mid+1;
    }
    printf("%d\n", l);


    return 0;
}