#include<bits/stdc++.h>

using namespace std;

//const int maxn = 2e3+7;
class MaxCutFree{
public:
    static const int maxn = 2e3+7;
    int dfs_clock,p[maxn],pre_ar[maxn];
    bool vis[maxn],iscir[maxn];
    set<int> ans;
    vector<int> g[maxn];
    void dfs(int x,int pre){
        p[x] = ++dfs_clock;
        vis[x]=1;
        pre_ar[x]=pre;
        for(int i=0;i<g[x].size();i++){
            if(g[x][i]!=pre){
                if(!vis[g[x][i]])dfs(g[x][i],x);
                if(p[x]>=p[g[x][i]]){
                    p[x]=p[g[x][i]];
                    ans.insert(x);
                }
            }
        }
        //vis[x]=0;
    }
    int ins,ans_n;
    int cnt[maxn],cnt_clock;
    void dfs2(int x,int pre){
        cnt[x]=cnt_clock;
        vis[x]=1;
        for(int i=0;i<g[x].size();i++){
            if(g[x][i]!=pre && !vis[g[x][i]]){
                dfs2(g[x][i],x);
            }
        }
    }
    void dfs3(int x,int pre,int dep){
        vis[x]=1;
        if(!iscir[x] && (dep&1))ins++;
        for(int i=0;i<g[x].size();i++){
            int now = g[x][i];
            if(!vis[now])dfs3(now, x, dep+1-(iscir[now]&&iscir[x]));
        }
        vis[x]=0;
    }
    int cnt_mx[maxn];
    int solve(int n, vector <int> a, vector <int> b){
        for(int i=0;i<n;i++){
            g[i].clear();
            vis[i]=0;
            p[i]=0;
        }
        set<int> g_se[maxn];
        for(int i=0;i<a.size();i++){
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
            g_se[a[i]].insert(b[i]);
            g_se[b[i]].insert(a[i]);
        }
        ans.clear();
        dfs_clock=0;
        cnt_clock=0;
        for(int i=0;i<n;i++)pre_ar[i]=-1;
        for(int i=0;i<n;i++){
            if(!vis[i] && g[i].size()>1)dfs(i,-1);
        }
        for(int i=0;i<n;i++)vis[i]=iscir[i]=0,cnt[i]=-1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs2(i,-1);
                cnt_clock++;
            }
        }
        for(set<int>::iterator it=ans.begin();it!=ans.end();it++){
            iscir[*it]=1;
        }
        ans_n = 0;
        for(int i=0;i<n;i++){
            vis[i]=0;
            cnt_mx[i]=0;
        }
        for(int i=0;i<n;i++){
            ins = 0;
            dfs3(i,-1,1);
            cnt_mx[cnt[i]] = max(cnt_mx[cnt[i]], ins);
        }
        for(int i=0;i<cnt_clock;i++)ans_n += cnt_mx[i];
        return ans.size()+ans_n;
    }
};

int main(){
    MaxCutFree m;
    vector<int> a,b;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(0);
    b.push_back(1);
    b.push_back(2);
    b.push_back(0);
    b.push_back(3);
    cout<<m.solve(4,a,b)<<" \n\n";
    return 0;
}
