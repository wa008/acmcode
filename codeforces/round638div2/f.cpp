#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 7;
const int inf = 1e9 + 7;

vector<pair<int, int>> points[maxn];
int index[maxn << 2], mn[maxn << 2], a[maxn], b[maxn], n, ans[maxn], where[maxn];
void build(int l, int r, int o){
    if(l == r){
        mn[o] = a[where[l]];
        index[o] = l;
    }
    else{
        int mid = l + r >> 1;
        build(l, mid, o << 1);
        build(mid + 1, r, o << 1 | 1);
        if(mn[o << 1] <= mn[o << 1 | 1]){
            mn[o] = mn[o << 1];
            index[o] = index[o << 1];
        }
        else{
            mn[o] = mn[o << 1 | 1];
            index[o] = index[o << 1 | 1];
        }
    }
}
int min_val, min_index, x, y;
void que(int l, int r, int o){
    //cout << l << ' ' << r << ' ' << o << '\n';
    if(x <= l && r <= y){
        if(mn[o] < min_val){
            min_val = mn[o];
            min_index = index[o];
        }
    }
    else{
        int mid = l + r >> 1;
        if(x <= mid)que(l, mid, o << 1);
        if(y > mid)que(mid + 1, r, o << 1 | 1);
    }
}
void show(){
    for(int i = 1; i <= n; ++ i){
        cout << ans[i];
        if(i == n)cout << '\n';
        else cout << ' ';
    }
}

int main() 
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
        points[a[i]].push_back(make_pair(b[i], i));
    }
    set<pair<int, int> > smin;
    for(int i = 1; i <= n; i++){
        smin.insert(points[i].begin(), points[i].end());
        assert(smin.size() > 0);
        ans[smin.begin() -> second] =  i;
        where[i] = smin.begin() -> second;
        smin.erase(smin.begin());
    }
    build(1, n, 1);
    for(int i = 1; i <= n; i++){
        min_val = inf, min_index = inf;
        x = i + 1, y = b[where[i]];
        que(1, n, 1);
        if(min_val <= i){
            cout << "NO\n";
            //cout << i << ' '  << min_index << ' ' << min_val << '\n';
            show();
            swap(ans[where[i]], ans[where[min_index]]);
            show();
            return 0;
        }
    }
    cout << "YES\n";
    show();
    return 0;
}
