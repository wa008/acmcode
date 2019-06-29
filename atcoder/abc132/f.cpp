#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 8e4+7;
const int sz = 101;
const ll mod = 1e9+7;
int n,m;

int dp[maxn][sz], pre[maxn][sz];
vector<int> v;
map<int,int> ma;
int main()
{
    scanf("%d%d", &n, &m);
    v.push_back(0);
    for(int i=1;i*i<=n;i++){
        v.push_back(i);
        if(i*i < n)v.push_back(n/i);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++)ma[v[i]] = i;
    for(int i=1;i<v.size();i++)dp[i][1] = 1;
    for(int i=1;i<v.size();i++)pre[i][1] = v[i];
    for(int in=2;in<=m;in++){
        for(int i=1;i<v.size();i++){
            int index = ma[n/v[i]];
            dp[i][in] = 1LL*(v[i]-v[i-1])*pre[index][in-1] % mod;
            pre[i][in] = (pre[i-1][in] + dp[i][in])%mod;
        }
    }
    printf("%d\n", pre[v.size()-1][m]);


    return 0;
}
