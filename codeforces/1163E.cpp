#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;

int n,m;
int ar[maxn], ans[maxn];
vector<int> vs;

void solve(int x,int y,int index, int ins){
    if(x==y)return ;
    int mid = x+y>>1;
    solve(x, mid, index+1, 0);
    solve(mid+1, y ,index+1, 1);
    if(ins==0){
        for(int i=x;i<=mid;i++){
            ans[i] ^= vs[index];
        }
    }
    else{
        for(int i=mid+1;i<=y;i++){
            ans[i] ^= vs[index];
        }
    }
    //cout<<x<<" "<<y<<endl;
    //for(int i=x;i<=y;i++)cout<<ans[i]<<" ";cout<<"\n"<<endl;
}
bool vis[maxn];
set<int> s1,s2,se;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d", ar+i);
    vis[0]=1;
    int ins=20;
    while(ins>0){
        s1.clear();
        s2.clear();
        for(int i=1;i<=n;i++){
            if(s2.count(ar[i]) || ar[i]>=(1<<ins))continue;
            vs.clear();
            s1.insert(ar[i]);
            for(auto x : s2){
                vs.push_back(x^ar[i]);
            }
            vs.push_back(ar[i]);
            for(auto x : vs)s2.insert(x);
        }
        if(s2.size()==(1<<ins)-1)break;
        ins--;
    }
    if(ins<=0){
        printf("0\n0\n");
        return 0;
    }
    for(auto x : s1){
        if(x<(1<<ins))se.insert(x);
    }
    assert(se.size()==ins);
    vs.clear();
    for(auto x : se){
        vs.emplace_back(x);
    }
    //for(auto x : vs)cout<<x<<" ";cout<<endl;
    solve(0,(1<<ins)-1, 0, 0);
    printf("%d\n",ins);
    for(int i=0;i<(1<<ins);i++){
        printf("%d%c",ans[i], i==(1<<ins)-1?'\n':' ');
    }
    memset(vis,0,sizeof(vis));
    for(int i=0;i<(1<<ins);i++){
        assert(vis[ans[i]]==0);
        vis[ans[i]]=1;
    }
    for(int i=0;i<(1<<ins)-1;i++){
        assert(se.count(ans[i]^ans[i+1])==1);
    }
    return 0;
}