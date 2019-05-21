#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4+7;
const int maxm = 2e1+7;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;

int n,m,k;
int ar[maxn];

int arr[60][maxn];
bool vis[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d", ar+i);
        for(int j=1;j<=ar[i];j++)scanf("%d", arr[i]+j);
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=ar[i];j++)cout<<arr[i][j]<<" ";
        cout<<"\n";
    }*/
    bool flag=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            memset(vis,0,sizeof(vis));
            for(int k=1;k<=ar[i];k++)vis[arr[i][k]]=1;
            int ff=0;
            for(int k=1;k<=ar[j];k++)if(vis[arr[j][k]]){
                ff=1;
                break;
            }
            if(!ff)flag=0;
            if(!flag)break;
        }
        if(!flag)break;
    }
    printf("%s\n", flag==1?"possible":"impossible");
    return 0;
}