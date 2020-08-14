#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 6e3 + 7;
const ll mod = 1e9+7;

int n,m;

char c1[maxn], c2[maxn], c3[maxn];
int k1, k2, k3, len;

vector<bool> func(string s1, string s2){
    vector<bool> ans(len * 2 + 2, true);
    for(int i = -len; i <= len; i++){
        for(int j = 0; j < s1.size(); j++){
            int k = j - i;
            if(k >= 0 && k < s2.size() && (s1[j] != s2[k] && s1[j] != '?' && s2[k] != '?')){
                ans[i+len] = false;
                break;
            }
        }
    }
    return ans;
}

int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int ans = s1.size() + s2.size() + s3.size();
    len = ans;
    vector<bool> ab = func(s1, s2);
    vector<bool> ac = func(s1, s3);
    vector<bool> bc = func(s2, s3);
    //cout << s1 << '\n';
    //cout << s2 << '\n';
    //cout << s3 << '\n';
    for(int i = -len; i <= len; i++){
        if(ab[i + len] == false)continue;
        for(int j = -len; j <= len; j++){
            if(ac[j + len] == false)continue;
            int k = j - i;
            if(k >= -len && k <= len && bc[k + len]){
                int x = 0, y = i, z = j;
                int mn = min(x, min(y, z));
                x += s1.size();
                y += s2.size();
                z += s3.size();
                int mx = max(x, max(y, z));
                //cout << i << " " << j << " " << mn << ' ' << mx << '\n';
                ans = min(ans, mx - mn);
            }
        }
    }
    printf("%d\n", ans);



    return 0;
}
