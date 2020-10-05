#include <bits/stdc++.h>
using namespace std;
#define y1 adfasfafa
const int maxn = 3e5+7;
const int inf = 3e5+7;
typedef long long ll;


int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> ar[n + 1];
		for(int i = 1; i <= n; ++i){
			int x;
			cin >> x;
			ar[x].push_back(i);
		}
		vector<int> ans(n + 1, inf);
		for(int i = 1; i <= n; ++i){
			if(ar[i].size() > 0){
				sort(ar[i].begin(), ar[i].end());
				int cnt = 1;
				for(int j = 1; j < ar[i].size(); ++j){
					cnt = max(ar[i][j] - ar[i][j - 1], cnt);
				}
				cnt = max(ar[i][0], cnt);
				cnt = max(cnt, n - ar[i][ar[i].size() - 1] + 1);
				ans[cnt] = min(ans[cnt], i);
			}
		}
		for(int i = 1; i <= n; ++i){
			ans[i] = min(ans[i - 1], ans[i]);
		}
		for(int i = 1; i <= n; ++i){
			if(ans[i] == inf)ans[i] = -1;
			cout << ans[i];
			cout << (i == n ? '\n' : ' ');
		}
	}


    return 0;
}
