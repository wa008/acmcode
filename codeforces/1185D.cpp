#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;

int n,m;
int ar[maxn];
pair<int,int> p[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d", ar+i);
        p[i].first=ar[i];
        p[i].second=i;
    }
    sort(p+1, p+n+1);
    for(int i=1;i<=n;i++)ar[i] = p[i].first;
    if(n<=3){
        printf("1\n");
        return 0;
    }
    int ans=-1;
    int flag=-1,now=0;
    int be=2,dis=ar[2]-ar[1],pre=ar[1];
    for(; be<=n; be++){
        if(ar[be]-pre != dis && flag==-1){
            flag=be;
        }
        else if(ar[be]-pre == dis){
            pre = ar[be];
        }
        else{
            flag=-2;
            break;
        }
    }
    if(flag==-1)ans=1;
    else if(flag>-1)ans=flag;

    flag=1;
    be=3;
    dis=ar[3]-ar[2];
    pre = ar[2];
    for(; be<=n; be++){
        if(ar[be]-pre == dis){
            pre = ar[be];
        }
        else{
            flag=0;
            break;
        }
    }
    if(flag==1)ans=1;

    flag=1;
    be=3;
    dis=ar[3]-ar[1];
    pre = ar[1];
    for(; be<=n; be++){
        if(ar[be]-pre == dis){
            pre = ar[be];
        }
        else{
            flag=-2;
            break;
        }
    }
    if(flag==1)ans=2;

    if(ans!=-1)ans = p[ans].second;
    printf("%d\n", ans);
    return 0;
}