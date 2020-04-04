#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;

int l[maxn], r[maxn];
int main() {
    int n, k, c;
    string s;
    cin >> n >> k >> c;
    cin >> s;
    for(int i=1; i <= n; i++){
        if(i > c + 1 && s[i - 1] == 'o')l[i] = max(l[i - 1], l[i - c - 1] + 1);
        else if(s[i - 1] == 'o')l[i] = max(1, l[i - 1]);
        else l[i] = l[i - 1];
    }
    for(int i = n; i >= 1; i--){
        if(s[i - 1] == 'o')r[i] = max(r[i + 1], r[i + c + 1] + 1);
        else r[i] = r[i + 1];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(s[i - 1] == 'o' && l[i - 1] + r[i + 1] < k)cout << i << "\n";
    }


    return 0;
}
