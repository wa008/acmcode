#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 1e6 + 7;

int n, m, k;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        cin >> n;
        vector<string> a, b;
        string ba, bb, ans;
        for(int _ = 1;_ <= n; _++){
            string s;
            cin >> s;
            string x, y;
            int l = 0, r = 0;
            for(int i=0;i<s.size();i++){
                if(s[i] != '*')x += s[i];
                else{
                    l = i;
                    break;
                }
            }
            for(int i = s.size() - 1; i >= 0; i--){
                if(s[i] != '*')y += s[i];
                else{
                    r = i;
                    break;
                }
            }
            for(int i = l + 1; i < r; i++){
                if(s[i] != '*')ans += s[i];
            }
            if(x.size() > 0)a.push_back(x);
            if(y.size() > 0)b.push_back(y);
            if(x.size() > ba.size())ba = x;
            if(y.size() > bb.size())bb = y;
        }
        /*
        cout << ba << '\n';
        cout << bb << '\n';
        cout << ans << '\n';
        */
        int flag = 1;
        for(string s : a){
            if(string(ba.substr(0, s.size())) != s){
                //cout << s << ' ' << ba << '\n';
                flag = 0;
                break;
            }
        }
        for(string s : b){
            if(string(bb.substr(0, s.size())) != s){
                //cout << s << ' ' << bb << '\n';
                flag = 0;
                break;
            }
        }
        cout << "Case #" << cas << ": ";
        reverse(bb.begin(), bb.end());
        if(flag == 1)cout << ba + ans + bb << "\n";
        else cout << "*\n";
    }

    return 0;
}
