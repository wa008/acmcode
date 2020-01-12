#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
typedef long long ll;
int n,m;
char ch[maxn][30];
string s[maxn];
int dfs(int x, int l, int r){
    if(x == 29){
        if(s[l][x] == s[r][x])return 0;
        else return 1;
    }
    if(s[l][x] == s[r][x]){
        return dfs(x + 1, l, r);
    }
    int xx = l, yy = r;
    while(xx < yy){
        int mid = xx + yy >> 1;
        if(s[mid][x] == '0')xx = mid + 1;
        else yy = mid;
    }
    int a = dfs(x + 1, l, xx - 1);
    int b = dfs(x + 1, xx, r);
    return min(a, b) + (1 << (29 - x));
}
int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d", &x);
        int ins = 29;
        while(ins >= 0){
            if(x & 1)ch[i][ins] = '1';
            else ch[i][ins] = '0';
            ins--;
            x /= 2;
        }
        s[i] = string(ch[i]);
    }
    sort(s, s + n);
    int ans = dfs(0, 0, n-1);
    printf("%d\n", ans);
    return 0;
}