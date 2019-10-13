#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e2+7;
const ll mod = 1e9 + 9;
#define afdafafafdafaf y1;
int ar[maxn], n, m;

int arr[maxn][maxn], dp[maxn][maxn];
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)scanf("%d", &arr[i][j]);
    }
    int mn = -5e6;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++)dp[i][j] = mn;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int mx = arr[i][j];
            if(dp[i - 1][j - 1] != mn)dp[i][j] = max(dp[i][j], dp[i-1][j-1] + mx);
            if(dp[i][j-1] != mn)dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }
    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)cout << dp[i][j] << ' ';
        cout << "\n";
    }
    */
    vector<int> ans;
    int j = m;
    for(int i = n; i >= 1; i--){ 
        for(;;){
            if(dp[i][j] > dp[i][j-1]){
                ans.push_back(j);
                j--;
                break;
            }
            j--;
        }
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", dp[n][m]);
    for(int i = 0; i < ans.size(); i++){
        printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
    }
    return 0;
}
