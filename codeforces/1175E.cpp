#include<bits/stdc++.h>
#include<ctime>
using namespace std;
typedef long long ll;
const int maxn = 5e5+7;
const int maxm = 2e6+7;
const ll mod = (1LL<<62);
int n,m,ar[maxn];
set<int> se;
set<int>::iterator it;

map<int,int> ma;
int ans[maxn];
int rmq[maxn][30],nex[maxn];
int che(int x,int mid){
    int ins=0;
    while(mid>0){
        if(mid&1)x = rmq[x][ins];
        mid/=2;
        ins++;
    }
    return x;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int a,b;scanf("%d%d", &a,&b);
        ma[a] = max(ma[a], b);
    }
    int mx=0;
    for(int i=0;i<=int(5e5+1);i++){
        nex[i]=max(i,mx);
        if(ma.count(i)==0)continue;
        int x = ma[i];
        if(mx<i){
            for(int j=mx;j<i;j++)se.insert(j);
        }
        if(x<=mx)continue;
        nex[i]=max(nex[i], x);
        mx=x;
    }
    for(int i=0;i<maxn;i++){
        rmq[i][0] = nex[i];
    }
    for(int j=1;j<30;j++){
        for(int i=0;i<maxn;i++){
            rmq[i][j] = max(rmq[i][j], rmq[rmq[i][j-1]][j-1]);
        }
    }
    /*
    for(int i=0;i<10;i++)cout<<nex[i]<<" ";cout<<"\n";
    for(int i=0;i<10;i++){
        cout<<i<<" "<<rmq[i][0]<<" "<<rmq[i][1]<<"\n";
    }*/
    for(int i=0;i<m;i++){
        int a,b;scanf("%d%d",&a,&b);
        int l=1,r=n,flag=1;
        while(l<r){
            int mid = l+r>>1;
            if(che(a,mid)>=b)r=mid;
            else l=mid+1;
        }
        if(che(a,l)<b)l=-1;
        printf("%d\n",l);
    }
    return 0;
}