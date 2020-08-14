#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6+7;

vector<int> ve[maxn];
int n,m,f[maxn];
int dfs(int u,int x=0){
    if(ve[u].size()==0)return 1;
    int ans;
    if(f[u]==1){
        ans = n;
        for(int i=0;i<ve[u].size();i++){
            ans=min(ans, dfs(ve[u][i]));
        }
    }
    else{
        ans = 0;
        for(int i=0;i<ve[u].size();i++){
            ans += dfs(ve[u][i]);
        }
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",f+i);
    for(int i=2;i<=n;i++){
        int x;scanf("%d",&x);
        ve[x].push_back(i);
    }
    m=0;
    for(int i=1;i<=n;i++)if(ve[i].size()==0)m++;
    int ans = dfs(1,1);
    printf("%d\n",m-ans+1);

    return 0;
}
