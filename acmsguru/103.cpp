#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e4+7;
const ll mod = 1e9 + 9;
#define afdafafafdafaf y1;
int ar[maxn], n, m;

char ch[maxn][2];
vector<pair<int,int> > g[maxn];
int main()
{
    int s, t;
    scanf("%d%d", &s, &t);
    s--;
    t--;
    scanf("%d%d", &n, &m);
    //cout << n << ' ' << m << '\n';
    vector<int> remain(n, 0), am(n, 0), bm(n, 0), vis(n, 0), pre(n, -1), dis(n, -1);
    for(int i=0; i<n; i++){
        scanf("%s", ch[i]);
        scanf("%d%d%d", &remain[i], &am[i], &bm[i]);
        //cout << ch[i] << ' ' << remain[i] << ' ' << am[i] << ' ' << bm[i] << '\n';
    }
    for(int i=0; i<m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        //cout << a << ' ' << b << ' ' << c << '\n';
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    auto next_time = [&] (int i, int time, vector<int> & ans){
        int re = 0;
        ans.resize(0);
        if(ch[i][0] == 'B'){
            re = (am[i] - remain[i] + time) % (am[i] + bm[i]);
        }
        else{
            re = (bm[i] - remain[i] + am[i] + time) % (am[i] + bm[i]);
        }
        int k = 2;
        if(re < am[i]){
            ans.push_back(am[i] - re);
            for(int index = 0; index < k; index++){
                //cout << "index = " << index << '\n';
                ans.push_back(bm[i]);
                ans.push_back(am[i]);
            }
        }
        else{
            ans.push_back(am[i] + bm[i] - re);
            for(int index = 0; index < k; index++){
                //cout << "index = " << index << '\n';
                ans.push_back(am[i]);
                ans.push_back(bm[i]);
            }
        }
        return re < am[i];
    };
    priority_queue<pair<int,int>> qu;
    qu.push(make_pair(0, s));
    int ans_time = 0, ans_flag = 0;
    dis[s] = 0;
    for(; !qu.empty(); ){
        int u = qu.top().second;
        int now_time = -qu.top().first;
        qu.pop();
        if(vis[u])continue;
        vis[u] = 1;
        if(u == t){
            ans_time = now_time;
            ans_flag = 1;
            break;
        }
        //cout << "u = " << u << ' ' << u << ' ' << now_time << '\n';
        for(int in = 0; in < g[u].size(); in++){
            int v = g[u][in].first, time = g[u][in].second;
            if(vis[v])continue;
            //cout << "v = " << v << '\n';
            vector<int> v_u, v_v;
            bool time_u = next_time(u, now_time, v_u);
            bool time_v = next_time(v, now_time, v_v);
            //for(auto x : v_u)cout << x << ' '; cout << '\n';
            //for(auto x : v_v)cout << x << ' '; cout << '\n';
            int ins = time_u == time_v;
            int cost = 0, i = 0, j = 0, x = 0, y = 0, flag = 0;
            for(;;){
                //cout << i << ' ' << j << '\n';
                if(x == 0){
                    if(i < v_u.size()){
                        x = v_u[i++];
                    }
                    else{
                        break;
                    }
                    ins ^= 1;
                }
                if(y == 0){
                    if(j < v_v.size()){
                        y = v_v[j++];
                    }
                    else{
                        break;
                    }
                    ins ^= 1;
                }
                int mn = min(x, y);
                if(ins){
                    cost += time;
                    flag = 1;
                    break;
                }
                x -= mn;
                y -= mn;
                cost += mn;
            }
            //cout << "mid\n";
            if(flag && (dis[v] == -1 || dis[v] > now_time + cost)){
                qu.push(make_pair(-now_time - cost, v));
                dis[v] = now_time + cost;
                pre[v] = u;
            }
        }
    }
    if(!ans_flag){
        printf("0\n");
        return 0;
    }
    vector<int> ans;
    int x = t;
    for(;;){
        ans.push_back(x);
        if(x == s)break;
        x = pre[x];
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", ans_time);
    for(int i = 0; i < ans.size(); i++){
        printf("%d%c", ans[i] + 1, i == ans.size() - 1 ? '\n' : ' ');
    }
    return 0;
}
