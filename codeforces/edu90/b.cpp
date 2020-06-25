#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e2 + 10;
const int mod = 998244353;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        stack<char> st;
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i){
            if(st.size() > 0 && s[i] != st.top()){
                ++cnt;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(cnt & 1)cout << "DA\n";
        else cout << "NET\n";
    }
    return 0;
}
