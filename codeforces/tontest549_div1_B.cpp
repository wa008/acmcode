#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;
int n,m,k;
int ar[maxn],nex[maxn],mid[maxn];
int rr[maxn],tn[maxn][30];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++){
        int x;scanf("%d",&x);
        mid[x]=i;
    }
    for(int i=1;i<=m;i++){
        int x;scanf("%d",&x);
        ar[i]=mid[x];
    }
    if(n==1){
        for(int i=1;i<=k;i++)printf("1");printf("\n");
        return 0;
    }
    memset(mid,0,sizeof(mid));
    memset(nex,0,sizeof(nex));
    memset(tn,0,sizeof(tn));
    for(int i=m;i>=1;i--){
        if(mid[(ar[i]+1)%n]!=0)nex[i]=mid[(ar[i]+1)%n];
        mid[ar[i]]=i;
    }
    for(int i=1;i<=m;i++){
        tn[i][0]=nex[i];
    }
    for(int i=1;i<30;i++){
        for(int j=1;j<=m;j++){
            tn[j][i] = tn[tn[j][i-1]][i-1];
        }
    }
    for(int i=1;i<=m;i++){
        int x = n-1,j=0,now=i;
        while(x){
            if(x&1)now = tn[now][j];
            j += 1;
            x >>= 1;
        }
        rr[i]=now;
    }
    int mn = m+1;
    for(int i=m;i>=1;i--){
        if(rr[i]==0)rr[i]=m+1;
        rr[i] = min(rr[i],mn);
        mn = min(mn,rr[i]);
    }
    while(k--){
        int l,r;scanf("%d%d",&l,&r);
        printf("%c",rr[l]<=r?'1':'0');
    }
    printf("\n");
    return 0;
}
