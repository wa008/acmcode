#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 998244353;
const int sz = 25;
#define afdafafafdafaf y1;
int n,m;
int ar[maxn];
map<string, int> mp;
int ins=0;
map<vector<int>, int> ms;
int decode(string s){
    if(mp.count(s) == 0){
        mp[s] = ins++;
    }
    return mp[s];
}
vector<int> res, in;
void dfs(int x){
    if(x==in.size()){
        if(res.size() == 0)return ;
        vector<int> mid = res;
        sort(res.begin(), res.end());
        ms[res]++;
        res = mid;
    }
    else{
        dfs(x+1);
        res.push_back(in[x]);
        dfs(x+1);
        res.pop_back();
    }
}
char ch[maxn];
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int k;scanf("%d", &k);
        in.resize(0);
        while(k--){
            scanf("%s", ch);
            in.push_back(decode(string(ch)));
        }
        dfs(0);
        assert(res.size() == 0);
    }
    scanf("%d", &m);
    for(int i=1; i<=m; i++){
        int k;scanf("%d", &k);
        in.resize(0);
        while(k--){
            scanf("%s", ch);
            in.push_back(decode(string(ch)));
        }
        sort(in.begin(), in.end());
        printf("%d\n", ms[in]);
    }
    return 0;
}
