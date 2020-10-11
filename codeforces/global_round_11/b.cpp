#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int sum = 0, pre = -1;
		vector<int> v;
		if(n == 1){
			if(k > 0 || s[0] == 'W')cout << "1\n";
			else cout << "0\n";
			continue;
		}
		for(int i = 0; i < n; ++i){
			if(s[i] == 'W'){
				if(pre != -1 && pre != i - 1){
					v.push_back(i - pre - 1);
				}
				if(i > 0 && s[i - 1] == 'W')sum += 2;
				else sum++;
				pre = i;
			}
		}
		int cnt = 0, index = 0;
		while(index < n && s[index] == 'L')index++;
		cnt += index;
		index = n - 1;
		while(index >= 0 && s[index] == 'L'){
			index --;
			cnt++;
		}
		sort(v.begin(), v.end());
		for(int i = 0; i < v.size(); ++i){
			int x = v[i];
			if(k >= x){
				sum += x * 2 + 1;
			}
			else{
				sum += k * 2;
			}
			k -= min(k, x);
		}
		sum += min(k, cnt) * 2;
		if(index == -1){
			sum = max(0, min(n, k) * 2 - 1);
		}
		cout << sum << '\n';
	}



    return 0;
}
