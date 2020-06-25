#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 7;
const int maxm = 4e6 + 7;
const int INF = 2e9 + 10;

//Dinic
//maxn 点的数量 maxm 边的数量
struct node
{
    int cap,from,to,flow,nex;
};
struct Dinic //maxn 点的数量 maxm 边的数量
{
    int n,s,t,node_len;
    node mo[maxm*2];
    int head[maxn],d[maxn],mark[maxn],cur[maxn];
    void init(int n)
    {
        this->n=n;
        node_len=0;
        memset(head,-1,sizeof(head));
    }
    void addnode(int from,int to,int cap){
        int k=node_len;
        mo[k].from=from;mo[k].to=to;mo[k].cap=cap;mo[k].flow=0;mo[k].nex=head[from];
        head[from]=k++;
        mo[k].from=to;mo[k].to=from;mo[k].cap=0;mo[k].flow=0;mo[k].nex=head[to];
        head[to]=k++;
        node_len=k;
    }
    bool BFS(){
        memset(mark,0,sizeof(mark));
        queue<int>qn;
        qn.push(s);
        d[s]=0;
        mark[s]=1;
        while(qn.size()){
            int u=qn.front();qn.pop();
            for(int i=head[u];i!=-1;i=mo[i].nex){
                node& e=mo[i];
                if(mark[e.to]==0&&e.cap>e.flow){
                    mark[e.to]=1;
                    d[e.to]=d[u]+1;
                    qn.push(e.to);
                }
            }
        }
        return mark[t];
    }
    int DFS(int u,int a){
        if(u==t||a==0)return a;
        int flow=0,f;
        for(int& i=cur[u];i!=-1;i=mo[i].nex){
            node& e=mo[i];
            if(d[e.to]==d[u]+1&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0){
                mo[i].flow+=f;
                mo[i^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0)break;
            }
        }
        return flow;
    }
    int Maxflow(int s,int t){
        this->s=s;this->t=t;
        int flow=0;
        while(BFS()){
            for(int i=0;i<=n;i++)cur[i]=head[i];
            flow+=DFS(s,INF);
        }
        return flow;
    }
}dinic;

int main() 
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a, b;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            a.push_back(x);
        }
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            b.push_back(x);
        }
        dinic.init(n * 2 + 2);
        int s = n * 2, t = n * 2 + 1;
        for(int i = 0; i < n; ++i){
            dinic.addnode(i + n, i, a[i]);
            dinic.addnode(i + n, (i + 1) % n, a[(i + 1) % n]);
            dinic.addnode(s, i + n, b[i]);
            dinic.addnode(i, t, a[i]);
        }
        int flow = dinic.Maxflow(s, t), ans = 0;
        for(int x : a)ans += x;
        if(flow == ans)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
