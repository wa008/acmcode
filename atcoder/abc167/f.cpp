#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
int inf = 1e9 + 7;

pair<int, int> p[maxn];
bool my_cmp(pair<int, int> x, pair<int, int> y){
    if(x.first < y.first)return true;
    if(x.first > y.first)return false;
    if(x.second > y.second)return true;
    return false;
}
int main() 
{
    int n;
    cin >> n;
    int s1 = 0, s2 = 0;
    vector<pair<int, int>> vl, vr;
    for(int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        int a = 0, b = 0;
        for(int j = 0; j < s.size(); ++j){
            if(s[j] == '('){
                a++;
            }
            else{
                if(a > 0)--a;
                else ++b;
            }
        }
        s1 += a;
        s2 += b;
        if(a > b){
            vl.push_back(make_pair(b, a - b));
        }
        else{
            vr.push_back(make_pair(a, b - a));
        }
    }
    int flag = 1, now = 0;
    sort(vl.begin(), vl.end(), my_cmp);
    now = 0;
    for(int i = 0; i < vl.size(); ++i){
        if(now < vl[i].first){
            flag = 0;
            break;
        }
        now += vl[i].second;
    }
    sort(vr.begin(), vr.end(), my_cmp);
    now = 0;
    for(int i = 0; i < vr.size(); ++i){
        if(now < vr[i].first){
            flag = 0;
            break;
        }
        now += vr[i].second;
    }
    if(s1 == s2 && flag == 1)cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
