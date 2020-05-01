#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+10;
typedef long long ll;

int dp[maxn][maxn];
vector<pair<int, int> > vals[maxn];
string stands[10] = {
    "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
};
void get_vals(int index, string s){
    for(int i = 9; i >= 0; --i){
        int a = 0, flag = 1;
        for(int j = 0; j < 7; ++j){
            if(stands[i][j] == s[j]);
            else if(s[j] == '0')a++;
            else flag = 0;
            //cout << i << ' ' << j << ' ' << flag << ' ' << a << '\n';
        }
        if(flag == 1)vals[index].push_back(make_pair(a, i));
    }
}
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        //cout << "s = " << s << "\n";
        get_vals(i, s);
    }
    /*
       for(int i = 1; i <= n; ++i){
       for(pair<int, int> x : vals[i]){
       cout << i << ' ' << x.first << ' ' << x.second << '\n';
       }
       }
       */
    memset(dp, -1, sizeof(dp));
    dp[n][k] = 1;
    for(int i = n; i > 0; --i){
        for(int j = 0; j <= k; ++j){
            if(dp[i][j] != -1){
                for(pair<int, int> val : vals[i]){
                    int a = val.first, b = val.second;
                    if(j - a >= 0){
                        dp[i - 1][j - a] = 1;
                    }
                }
            }
        }
    }
    if(dp[0][0] != 1){
        cout << "-1\n";
        return 0;
    }
    int j = 0;
    for(int i = 0; i < n; ++i){
        int ins = -1, mx = -1;
        assert(dp[i][j] != -1);
        for(pair<int, int> val : vals[i + 1]){
            int a = val.first, b = val.second;
            if(dp[i + 1][j + a] == 1){
                if(b > mx){
                    mx = b;
                    ins = j + a;
                }
            }
        }
        cout << mx;
        j = ins;
    }

    return 0;
}
