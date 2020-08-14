#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;
typedef long long ll;
int n,m;

pair<int, int> p[maxn];
int main()
{
    int t;scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=0;i<n;i++)scanf("%d%d", &p[i].first, &p[i].second);
        sort(p, p+n);
        int flag = 1;
        for(int i=1;i<n;i++){
            if(p[i].first <= p[i-1].second){
                flag = 0;
                break;
            }
        }
        if(flag){
            printf("%d\n", n-1);
            continue;
        }
        int pre = - 1e9 - 1, fa = - 1e9 - 1, ins = 0, fb = - 1e9 - 1;
        //cout << pre << " " << fa << '\n';
        int max_tail = -1e9-1, base = 0, ans = 0;
        for(int i=0;i<n;i++){
            //cout << fa << ' ' << fb << '\n';
            if(pre >= fa && pre < p[i].first && p[i].first <= fb)ins++;
            ans = max(ans, ins);
            if(fb > p[i].second){
                //pre = p[i].second;
                pre = max(pre, p[i].second);
            }
            else{
                pre = max(pre, fb);
                //pre = fb;
                fa = p[i].first;
                fb = p[i].second;
                ins = 0;
            }
            if(p[i].first > max_tail)base++;
            max_tail = max(max_tail, p[i].second);
            //cout << i << ' ' << p[i].first << ' ' << p[i].second << ' ' << ins << '\n';
        }
        //cout << base << ' ' << ans << '\n';
        printf("%d\n", ans + base);
    }
    return 0;
}
