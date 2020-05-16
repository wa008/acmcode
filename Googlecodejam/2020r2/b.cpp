#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e2 + 10;
const int maxm = 2e3 + 10;
const int inf = 1e9 + 9;

int head[maxn], ans[maxm], tag[maxn], time_x[maxn], ar[maxn];
int to[maxm], nex[maxm], inde[maxm];
int sz;
void add(int u, int v, int in){
    to[sz] = v;
    inde[sz] = in;
    nex[sz] = head[u];
    head[u] = sz++;
}
vector<pair<int, int>> p, py;
void solve(){
    sz = 0;
    int n, m;
    cin >> n >> m;
    memset(head, -1, sizeof(head));
    memset(tag, 0, sizeof(tag));
    memset(ans, -1, sizeof(ans));
    for(int i = 1; i <= n; ++i){
        time_x[i] = inf;
    }
    for(int i = 2; i <= n; ++i)cin >> ar[i];
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> a >> b;
        add(a, b, i);
        add(b, a, i);
    }
    /*
       for(int i = head[2]; i != -1; i = nex[i]){
       cout << to[i] << '\n';
       }
       */
    p.resize(0);
    for(int i = 2; i <= n; ++i){
        if(ar[i] < 0){
            p.push_back(make_pair(-ar[i], i));
        }
        else{
            tag[i] = 1;
            time_x[i] = ar[i];
            py.push_back(make_pair(ar[i], i));
        }
    }
    if(p.size() == n - 1){
        sort(p.begin(), p.end());
        int pre_val = 0, pre_time_max = 0, below_cnt = 1;
        tag[1] = 1;
        time_x[1] = 0;
        for(int index_p = 0; index_p < p.size(); ++index_p){
            int val = p[index_p].first, u = p[index_p].second;
            //cout << "u = " << u << '\n';
            int time_min = inf, index_ans = 0;
            for(int i = head[u]; i != -1; i = nex[i]){
                if(tag[to[i]] == 1 && time_x[to[i]] < time_min){
                    //cout << "u, v = " << u << ' ' << to[i] << '\n';
                    time_min = time_x[to[i]];
                    index_ans = inde[i];
                }
            }
            if(val > pre_val){
                time_x[u] = pre_time_max + 1;
                assert(below_cnt == val);
            }
            else{
                time_x[u] = pre_time_max;
            }
            ans[index_ans] = time_x[u] - time_min;
            /*
               if(time_x[u] < time_min){
               cout << u << ' ' << index_ans << ' ' << time_min << '\n';
               }
               */
            assert(time_x[u] > time_min);
            pre_time_max = time_x[u];
            tag[u] = 1;
            pre_val = val;
            below_cnt++;
        }
        for(int i = 1; i <= m; ++i){
            if(ans[i] == -1)ans[i] = 2000;
        }
        for(int i = 1; i <= m; ++i){
            cout << ans[i];
            if(i == m)cout << '\n';
            else cout << ' ';
        }

    }
    else{


        sort(p.begin(), p.end());
        int pre_val = 0, pre_time_max = 0, below_cnt = 1;
        tag[1] = 1;
        time_x[1] = 0;
        for(int index_p = 0; index_p < p.size(); ++index_p){
            int val = p[index_p].first, u = p[index_p].second;
            //cout << "u = " << u << '\n';
            int time_min = inf, index_ans = 0;
            for(int i = head[u]; i != -1; i = nex[i]){
                if(tag[to[i]] == 1 && time_x[to[i]] < time_min){
                    //cout << "u, v = " << u << ' ' << to[i] << '\n';
                    time_min = time_x[to[i]];
                    index_ans = inde[i];
                }
            }
            vector<int> times;
            for(int i = 1; i <= n; ++i){
                if(tag[i] == 1)times.push_back(time_x[i]);
            }
            sort(times.begin(), times.end());
            if(val > pre_val){
                if(times.size() == val){
                    time_x[u] = times[val - 1] + 1;
                }
                else if(times.size() > val && times[val] > times[val - 1]){
                    time_x[u] = times[val - 1] + 1;
                }
                else{
                    assert(1 == 2);
                }
            }
            else{
                time_x[u] = pre_time_max;
            }
            ans[index_ans] = time_x[u] - time_min;
            //assert(time_x[u] > time_min);
            pre_time_max = time_x[u];
            tag[u] = 1;
            pre_val = val;
        }
        sort(py.begin(), py.end());
        for(int index_p = 0; index_p < py.size(); ++index_p){
            int val = py[index_p].first, u = py[index_p].second;
            //cout << "u = " << u << '\n';
            int time_min = inf, index_ans = 0;
            for(int i = head[u]; i != -1; i = nex[i]){
                if(tag[to[i]] == 1 && time_x[to[i]] < time_min){
                    //cout << "u, v = " << u << ' ' << to[i] << '\n';
                    time_min = time_x[to[i]];
                    index_ans = inde[i];
                }
            }
            ans[index_ans] = time_x[u] - time_min;
            //assert(time_x[u] > time_min);
        }
        for(int i = 1; i <= m; ++i){
            if(ans[i] == -1)ans[i] = 1000000;
        }
        for(int i = 1; i <= m; ++i){
            cout << ans[i];
            if(i == m)cout << '\n';
            else cout << ' ';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; ++ cas){
        cout << "Case #" << cas << ": ";
        solve();
    }
    return 0;
}
