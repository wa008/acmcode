#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+7;
const ll mod = 1e9 + 9;
#define afdafafafdafaf y1;
int ar[maxn], n;

vector<int> ans1, ans2;
int b[maxn], to[maxn], c[maxn], index[maxn];
int head[maxn], cnt;
void add(int u, int v, int index_int, int val){
    b[cnt] = v;
    c[cnt] = val;
    index[cnt] = index_int;
    to[cnt] = head[u];
    head[u] = cnt++;
}
int vis[maxn], in[maxn], vis_edge[maxn], flag = -1, ans_flag = 0, ins = 0;
void dfs(int u,int pre){
    vis[u] = 1;
    for(int i = head[u]; i != -1; i = to[i]){
        if(vis_edge[i])continue;
        int v = b[i];
        vis_edge[i] = vis_edge[i ^ 1] = 1;
        dfs(v, u);
        ans1.push_back(index[i]);
        ans2.push_back(c[i]);
    }
}
int inx[maxn], iny[maxn];
int main()
{
    cnt = 0;
    scanf("%d", &n);
    for(int i=0;i<=6;i++)head[i] = -1;
    for(int i=0;i<n;i++){
        int x,y;scanf("%d%d", &x, &y);
        add(x, y, i+1, 1);
        add(y, x, i+1, 0);
        in[x]++;
        in[y]++;
        inx[i+1] = x;
        iny[i+1] = y;
    }
    for(int i=0;i<7;i++){
        if(in[i] % 2 == 1){
            flag = i;
            break;
        }
    }
    if(flag == -1){
        for(int i=0;i<=6;i++){
            if(in[i]){
                flag = i;
                break;
            }
        }
    }
    dfs(flag, 0);
    if(ans1.size() != n){
        printf("No solution\n");
        return 0;
    }
    int pre = -1;
    for(int i=0;i<ans1.size();i++){
        int a = inx[ans1[i]], b = iny[ans1[i]];
        if(ans2[i] == 1)swap(a, b);
        if(i > 0 && a != pre){
            printf("No solution\n");
            return 0;
        }
        pre = b;
    }
    for(int i=ans1.size() - 1;i >= 0;i--){
        int a = ans1[i], b = ans2[i];
        printf("%d %c\n", a, b == 1 ? '+' : '-');
    }
    return 0;
}
