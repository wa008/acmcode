#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 103;
const int con = 50;
const ll mod = 1000000000000037;

int cnt[maxn];

int main()
{	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		//cout << "n = " << n << '\n';
		for(int i = 0; i < n; ++i){
			int x;
			cin >> x;
			x += con;
			++cnt[x];
		}
		//for(int i = 0; i < maxn; ++i)cout << i << ' ' << cnt[i] << '\n';
		vector<int> ans;
		int sum = 0, no = -1, flag = 1;
		for(int i = 0; i < n; ++i){
			int mx = 0, mx_index = 0;
			for(int j = 0; j < maxn; ++j){
				if(cnt[j] > mx && j != no){
					mx = cnt[j];
					mx_index = j;
				}
			}
			if(mx > 0 && sum + mx_index - con != 0){
				cnt[mx_index]--;
				ans.push_back(mx_index);
				sum += mx_index - con;
				no = -1;
			}
			else if(mx > 0 && no == -1){
				i--;
				no = mx_index;
			}
			else{
				flag = 0;
				break;
			}
		}
		if(flag == 1){
			cout << "YES\n";
			cout << ans[0] - con;
			for(int i = 1; i < n; ++i)cout << ' ' << ans[i] - con;
			cout << "\n";
		}
		else{
			cout << "NO\n";
		}
		for(int i = 0; i < maxn; ++i)cnt[i] = 0;
	}



    return 0;
}
