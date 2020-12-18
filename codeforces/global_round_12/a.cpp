//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include <iostream>
#include <utility>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
const int maxn = 3e5+7;

int s[maxn << 2];
int l[maxn], r[maxn];

void update(int x, int y){
    while(x > 0){
        s[x] += y;
        x -= x & (-x);
    }
}
int que(int x){
    int ans = 0;
    while(x < (maxn << 2)){
        ans += s[x];
        x += x & (-x);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> ar(n + 1, 0);
        for(int i = 0; i < n; ++i){
            cin >> ar[i + 1];
        }
        vector< pair<int, int> > vp;
        for(int i = n; i >= 1; --i){
            int k = upper_bound(vp.begin(), vp.end(), make_pair(ar[i], 0)) - vp.begin();
            r[i] = vp[k].second;
            while(vp.size() > 0 && vp.back().first > ar[i])vp.pop_back();
            vp.push_back(make_pair(ar[i], i));
        }
        while(vp.size() > 0)vp.pop_back();
        for(int i = 1; i <= n; ++i){
            int k = upper_bound(vp.begin(), vp.end(), make_pair(ar[i], 0)) - vp.begin();
            l[i] = vp[k].second;
            while(vp.size() > 0 && vp.back().first > ar[i])vp.pop_back();
            vp.push_back(make_pair(ar[i], i));
        }
        set<int> is;
        for(int i = 1; i <= n; ++i){
            if(is.count(ar[i]) > 0){
                continue;
            }
            is.insert(ar[i]);
            int len = r[i] - l[i] + 1;
            if(l[i] != i && r[i] != i){
                update(len, 1);
            }
            else{
                update(len, 1);
                update(len - 1, -1);
            }
        }
        for(int i = 1; i <= n; ++i){
            int iq = que(i);
            if(iq + i - 1 == n)cout << '1';
            else cout << '0';
        }
        cout << '\n';
        for(int i = 0; i < (n << 2); ++i)s[i] = 0;
        for(int i = 0; i <= n; ++i)l[i] = r[i] = 0;
    }
    return 0;
}
