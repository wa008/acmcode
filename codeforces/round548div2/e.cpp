#include<bits/stdc++.h>
using namespace std;

const int maxn = 15010;
const int maxm = 1e6+7;

//Dinic
struct Edge{
    int from,to,cap,flow;
    Edge(){
        
    }
    Edge(int a,int b,int c,int d){
        from=a;
        to=b;
        cap=c;
        flow=d;
    }
}edges[maxm*2];
int n,m,s,t,sz;
vector<int> ve[maxn];
int dis[maxn],cur[maxn];
bool vis[maxn];
void addEdge(int a,int b,int c)
{
    edges[sz++]=Edge(a,b,c,0);
    edges[sz++]=Edge(b,a,0,0);
    ve[a].push_back(sz-2);
    ve[b].push_back(sz-1);
}
bool BFS(){
    memset(vis,0,sizeof(vis));
    queue<int> qu;
    qu.push(s);
    dis[s]=0;
    vis[s]=1;
    while(qu.size()){
        int u=qu.front();qu.pop();
        for(int i=0;i<ve[u].size();i++){
            Edge& e=edges[ve[u][i]];
            if(!vis[e.to] && e.flow<e.cap){
                vis[e.to]=1;
                qu.push(e.to);
                dis[e.to]=dis[u]+1;
            }
        }
    }
    return vis[t];
}
int DFS(int x,int a)
{
    if(x==t || a==0)return a;
    int flow=0,f;
    for(int& i=cur[x];i<ve[x].size();i++){
        Edge e=edges[ve[x][i]];
        if(dis[x]+1==dis[e.to] && (f=DFS(e.to,min(a,e.cap-e.flow)))>0){
            flow+=f;
            a-=f;
            edges[ve[x][i]].flow+=f;
            edges[ve[x][i]^1].flow-=f;
            if(a==0)break;
        }
    }
    return flow;
}
int flow;
int dinic()
{
    while(BFS()){
        memset(cur,0,sizeof(cur));
        flow += DFS(s,600000);
    }
    return flow;
}
bool vis_a[maxn];
int a1[maxn],a2[maxn],a3[maxn],ans_a[maxn];
int mx = 5e3;
int main()
{
    flow=sz=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",a1+i),assert(a1[i]<mx);
    for(int i=1;i<=n;i++)scanf("%d",a2+i);
    int d;
    scanf("%d",&d);
    memset(vis_a,0,sizeof(vis_a));
    for(int i=1;i<=d;i++)scanf("%d",a3+i),vis_a[a3[i]]=1;
    //for(int i=1;i<=d;i++)cout<<a3[i]<<" ";cout<<endl;
    s=0,t=mx*3+2;
    for(int i=1;i<=m;i++){
        addEdge(s,i,1);
    }
    for(int i=1;i<=mx;i++){
        addEdge(i+mx,i+mx*2,1);
    }
    addEdge(2*mx+1, t, n+10);
    int pre = 0;
    for(int i=1;i<=n;i++){
        if(!vis_a[i]){
            addEdge(a2[i],mx+1+a1[i],1);
        }
    }
    for(int i=d;i>=1;i--){
        dinic();
        while(flow>pre){
            addEdge(2*mx+1+flow,2*mx+1+flow-1,n+10);
            dinic();
            pre++;
        }
        ans_a[i]=flow;
        addEdge(a2[a3[i]],mx+1+a1[a3[i]],1);
    }
    for(int i=1;i<=d;i++)printf("%d\n",ans_a[i]);
    return 0;
}
