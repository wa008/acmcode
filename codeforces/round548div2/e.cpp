#include<bits/stdc++.h>
using namespace std;

const int maxn = 15010;
const int maxm = 1e6+7;

int n,m;
bool vis_a[maxn];
int a1[maxn],a2[maxn],a3[maxn],ans_a[maxn],ans[maxn];
int mx = 5e3;
int f[maxn],mat[maxn];

int cnt;
vector<int> g[maxn];
bool match(int x){
    f[x]=cnt;
    for(int i=0;i<g[x].size();i++){
        int v=g[x][i];
        //cout<<"x,v1 = "<<x<<" "<<v<<" "<<f[v]<<' '<<cnt<<endl;
        if(mat[v]!=-1 && f[mat[v]]==cnt)continue;
        //cout<<"x,v2 = "<<x<<" "<<v<<endl;
        if(mat[v]==-1 || match(mat[v])){
            ///cout<<"x,vyes = "<<x<<" "<<v<<"\n";
            mat[v]=x;
            return 1;
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a1+i),assert(a1[i]<mx);
    for(int i=1;i<=n;i++)scanf("%d",a2+i);
    int d;
    scanf("%d",&d);
    memset(vis_a,0,sizeof(vis_a));
    memset(mat,-1,sizeof(mat));
    memset(f,0,sizeof(f));
    for(int i=1;i<=d;i++)scanf("%d",a3+i),vis_a[a3[i]]=1;
    //for(int i=1;i<=d;i++)cout<<a3[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++){
        if(!vis_a[i]){
            //cout<<"a[i],a2[i] = "<<a1[i]<<" "<<a2[i]<<"\n";
            g[a1[i]].push_back(a2[i]);
        }
    }
    cnt=0;
    ans_a[d+1]=0;
    for(int i=d;i>=1;i--){
        //cout<<"\ni = "<<i<<"\n";
        cnt++;
        ans_a[i]=ans_a[i+1];
        while(match(ans_a[i])){
            //cout<<"yes = "<<ans_a[i]<<endl;
            cnt++;
            ans_a[i]++;
        }
        //cout<<"a[i],a2[i] = "<<a1[a3[i]]<<" "<<a2[a3[i]]<<"\n";
        g[a1[a3[i]]].push_back(a2[a3[i]]);
    }
    for(int i=1;i<=d;i++)printf("%d\n",ans_a[i]);
    return 0;
}
