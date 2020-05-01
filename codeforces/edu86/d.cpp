#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
typedef long long ll;
typedef long double ld;
const ld eps = 1e-30;

int n, k;
int in[maxn], c[maxn];
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        ++in[x];
    }
    for(int i = 1; i <= k; i++)cin >> c[i];
    int cnt = 0, ans_size = 0;
    for(int i = k; i >= 1; --i){
        cnt += in[i];
        ans_size = max(ans_size, (cnt + c[i] - 1) / c[i]);
    }
    vector<int> ans[ans_size];
    int ins = k, index = 0, plus = 0;
    for(; ins >= 1;){
        while(in[ins] > 0 && plus < ans_size){
            if(ans[index].size() < c[ins]){
                ans[index].push_back(ins);
                in[ins]--;
                plus = 0;
            }
            else{
                index = (index + 1) % ans_size;
                ++plus;
            }
        }
        assert(plus != ans_size);
        if(plus == ans_size);
        if(in[ins] == 0)ins--;
    }
    cout << ans_size << "\n";
    for(int j = 0; j < ans_size; ++j){
        vector<int> con = ans[j];
        cout << con.size() << " ";
        for(int i = 0 ; i < con.size(); ++ i){
            cout << con[i];
            if(i == con.size() - 1)cout << '\n';
            else cout << ' ';
        }
    }
    return 0;
}
