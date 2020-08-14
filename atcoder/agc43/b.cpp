#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
typedef long long ll;
int n, m, k;

char ch[maxn];

int twoNum(int x){
    int ans = 0;
    while(x > 0 && (x & 1) == 0){
        ans++;
        x >>= 1;
    }
    return ans;
}
int main()
{
    scanf("%d", &n);
    scanf("%s", ch);
    vector<int> v;
    for(int i=0;i<n-1;i++){
        v.push_back(abs((ch[i] - '0') - (ch[i+1] - '0')));
    }
    //for(int x : v)cout << x << ' '; cout << '\n';
    vector<int> cnt(3, 0);
    for(int x : v){
        cnt[x]++;
    }
    int coeff = 1;
    if(cnt[1] == 0){
        for(int & x : v){
            x >>= 1;
        }
        coeff = 2;
    }
    n = v.size();
    //for(int x : v)cout << x << ' '; cout << '\n';
    int res = 0, ans = 0;
    for(int i=0;i<n;i++){
        if(res <= 0){
            ans ^= v[i];
            //cout << i << ' ' << v[i] << '\n';
        }
        res += twoNum(n - 1 - i) - twoNum(i + 1);
    }
    //cout << "ans = " << ans << '\n';
    ans = ans & 1;
    printf("%d\n", ans * coeff);
    return 0;
}
