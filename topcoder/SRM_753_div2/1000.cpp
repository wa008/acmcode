#include<bits/stdc++.h>
using namespace std;


const int maxn = 2e3+7;
class MaxCutFree{
public:
    vector<int> g[maxn],h[maxn];
    int low[maxn],dep[maxn],vis[maxn],cnt,dp[2][maxn];
    void dfs(int u,int pre){
        dep[u]=low[u]=++cnt;
        vis[u]=1;
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(v==pre)continue;
            if(vis[v]){
                if(v!=pre)low[u]=min(low[u], low[v]);
            }
            else{
                dfs(v,u);
                low[u]=min(low[u], low[v]);
                if(low[v]>dep[u]){
                    h[u].push_back(v);
                    h[v].push_back(u);
                }
            }
        }
    }
    void take(int u){
        vis[u]=1;
        dp[1][u]=1;
        dp[0][u]=0;
        for(int i=0;i<h[u].size();i++){
            int v=h[u][i];
            if(!vis[v]){
                take(v);
                dp[0][u] += max(dp[0][v], dp[1][v]);
                dp[1][u] += dp[0][v];
            }
        }
    }
    int solve(int n, vector <int> a, vector <int> b){
        cnt=0;
        for(int i=0;i<a.size();i++){
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
        }
        for(int i=0;i<=n;i++){
            vis[i]=dep[i]=low[i]=0;
        }
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i,-1);
        }
        for(int i=0;i<n;i++)dp[0][i]=dp[1][i]=vis[i]=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                take(i);
                ans += max(dp[0][i], dp[1][i]);
            }
        }
        //cout<<"ans = "<<ans<<endl;
        return ans;
    }
};

int main(){
    MaxCutFree m;
    vector<int> a,b;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(4);
    a.push_back(4);
    a.push_back(5);

    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    b.push_back(0);
    b.push_back(0);
    b.push_back(5);
    b.push_back(6);
    b.push_back(6);
    cout<<m.solve(7,a,b)<<" \n\n";
    return 0;
}
