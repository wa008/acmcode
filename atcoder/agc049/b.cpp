#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
const ll mod = 1000000000000037;

int main()
{	
	deque<int> da, db;
	string sa, sb;
	int n;
	cin >> n;
	cin >> sa >> sb;
	for(int i = 0; i < n; ++i){
		if(sa[i] == '1')da.push_back(i);
		if(sb[i] == '1')db.push_back(i);
	}
	if(((da.size() - db.size()) % 2 != 0) || (da.size() < db.size())){
		cout << "-1\n";
		return 0 ;
	}
	ll ans = 0;
	while(db.size() > 0){
		//for (int i = 0; i < da.size(); i++)cout << da[i] << ' '; cout << '\n';
		//for (int i = 0; i < db.size(); i++)cout << db[i] << ' '; cout << '\n';
		//cout << ans << "\n\n";
		if(da.size() == 0 || da.size() < db.size())break;
		int a = da.front();
		int b = db.front();
		if(a < b){
			da.pop_front();
			if(da.size() == 0)break;
			int nex = da.front();
			da.pop_front();
			ans += nex - a;
		}
		else if(a >= b){
			ans += a - b;
			da.pop_front();
			db.pop_front();
		}
	}
	if(db.size() == 0){
		while(da.size() > 0){
			int a = da.front();
			da.pop_front();
			if(da.size() == 0){
				cout << "-1\n";
				return 0;
			}
			int nex = da.front();
			da.pop_front();
			ans += nex - a;
		}
	}
	//for (int i = 0; i < da.size(); i++)cout << da[i] << ' '; cout << '\n';
	//for (int i = 0; i < db.size(); i++)cout << db[i] << ' '; cout << '\n';
	//cout << da.size() << " " << db.size() << "\n";
	//cout << "ans = " << ans << '\n';
	if(int(db.size()) == 0)cout << ans << "\n";
	else cout  << "-1\n";

    return 0;
}
