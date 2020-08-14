#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e1+7;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    for(int cas = 1; cas <= t; cas++){
        string s;
        cin >> s;
        //cout << "s = " << s << "\n";
        int flag = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] != s[i - 1]){
                flag = 0;
                break;
            }
        }
        if(flag == 1)cout << s << "\n";
        else{
            for(int i=0;i<s.size();i++)cout << "01";
            cout << "\n";
        }
    }
    return 0;
}
