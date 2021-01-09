#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 7;
const ll mod = 1000000000000037;

int ar[maxn << 2], l[maxn << 2], r[maxn << 2];
set<pair<int, int>> s1, s2;
int mn[maxn << 2], mx[maxn << 2], sum[maxn << 2];

void update_mn(int x, int y){
	while(x > 0){
		mn[x] = min(mn[x], y);
		x -= x & (-x);
	}
}
void update_mx(int x, int y){
	while(x < (n << 2)){
		mn[x] = min(mn[x], y);
		x += x & (-x);
	}
}
void update_mn(int x, int y){
	while(x > 0){
		mn[x] = min(mn[x], y);
		x -= x & (-x);
	}
}
int main()
{	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i < (n << 2); ++i)mn[i] = n + 1;
		for(int i = 1; i <= n; ++i){
			cin >> ar[i];
		}
		for(int i = 1; i <= n; ++i){
			update_mn(ar[i], i);
			l[i] = query_mn(ar[i]);
		}
		for(int i = n; i > 0; --i){
			update_mx(ar[i], i);
			r[i] = query_mx(ar[i]);
		}
		for(int i = 1; i <= n; ++i){
			if(l[i] == i || r[i] == i){
				update_sum(i, 1);
				update_sum(i - 1, -1);
			}
			else{
				update_sum(i, 1);
			}
		}
		for(int i = 1; i <= n; ++i){
			if(query_sum(i) + i == n + 1)cout << "1";
			else count << "0";
		}
		cout << "\n";
		for(int i = 0; i < (n << 2); ++i)ar[i] = l[i] = r[i] = mn[i] = mx[i] = sum[i] = 0;
	}


    return 0;
}
