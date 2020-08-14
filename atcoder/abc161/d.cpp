#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 7;
const int mod = 1e9 + 7;
typedef long long ll;
int n, m, k;

int ar[maxn];

ll dp[12][12];
ll dpz[12];
ll che(ll x){
    ll mid = x;
    vector<int> dig;
    while(x > 0){
        dig.push_back(x % 10);
        x /= 10;
    }
    if(dig.size() == 1)return mid;
    reverse(dig.begin(), dig.end());
    ll ans = dpz[dig.size()];
    //if(mid >= 200 && mid <= 201)cout << "debug nas = " << ans << '\n';
    int pre = -1;
    for(int i=0;i<dig.size();i++){
        int x = dig[i];
        if(pre == -1){
            for(int j=1;j<x;j++)ans += dp[dig.size()][j];
            /*
               ans += dp[dig.size() - i][1] * (x - 1);
               if(i == dig.size() - 1){
               if(x == 9)ans += dp[dig.size() - i][2];
               else ans += dp[1][1];
               }
               */
        }
        else{
            for(int j = -1; j <= 1; j++){
                int nx = pre + j;
                if(nx >= 0 && nx <= 9 && nx < x){
                    ans += dp[dig.size() - i][nx];
                    /*
                       if(nx == 0)ans += dp[dig.size() - i][0];
                       else if(nx == 9)ans += dp[dig.size() - i][2];
                       else ans += dp[dig.size() - i][1];
                       */
                }
                else if(nx >= 0 && nx <= 9 && nx == x && i == dig.size() - 1){
                    ans++;
                    //if(mid >= 200 && mid <= 201)
                }
            }
        }
        if(pre != -1 && abs(pre - x) > 1)break;
        pre = x;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    for(int i=0;i<12;i++)dp[1][i] = 1;
    dpz[1] = 0;
    for(int pos = 2; pos < 12; pos++){
        dpz[pos] = dpz[pos - 1];
        for(int j=0;j<=9;j++){
            for(int k=-1;k<=1;k++){
                int nx = j + k;
                if(nx >= 0 && nx <= 9)dp[pos][j] += dp[pos-1][nx];
            }
            if(j > 0)dpz[pos] += dp[pos-1][j];
        }
    }
    //for(int i=1;i<=10;i++)cout << i << ' ' << che(i) << '\n';
    int n;
    cin >> n;
    ll l = 1, r = 3234566699;
    while(l < r){
        ll mid = (l + r) / 2;
        if(che(mid) >= n)r = mid;
        else l = mid + 1;
    }
    cout << l << "\n";
    return 0;
}

/*
I hate digital dp !!!
*/
