#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e7+7;
const int maxm = 5e3+7;
const ll mod = 1e9 + 7;
#define afdafafafdafaf y1;
int ar[1000000], n, m;
bool is[maxn];
int check(int x){
    int pre = x;
    int ins = 0;
    while(x > 0){
        ins += x % 10;
        x /= 10;
    }
    return ins + pre;
}
pair<int, int> p[maxm];
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1;i<=m;i++){
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
    sort(p+1, p+m+1);
    int ins = 1, pre = 0;
    ll ans = 0;
    for(int i=1;i<=n;i++){
        if(i % 10 != 0)pre += 2;
        else pre = check(i);
        if(pre < maxn)is[pre] = 1;
        if(!is[i]){
            ans++;
            while(ins <=m && p[ins].first == ans){
                ar[p[ins].second] = i;
                ins++;
            }
        }
    }
    printf("%lld\n", ans);
    for(int i=1;i<=m;i++){
        printf("%d%c", ar[i], i == m ? '\n' : ' ');
    }
    return 0;
}
