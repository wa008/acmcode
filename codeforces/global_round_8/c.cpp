#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e2 + 10;
const int mod = 998244353;

int dir[7][2] = {
    {-1, 1}, 
    {-1, 0}, 
    {0, -1}, 
    {0, 1}, 
    {1, -1}, 
    {1, 0}, 
    {1, 1}, 
};
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int n;
    cin >> n;
    cout << n * 7 + 8 << "\n";
    cout << "-1 -1\n";
    for(int i = 0; i <= n; ++i){
        int x = i * 2;
        for(int j = 0; j < 7; ++j){
            int nx = x + dir[j][0];
            int ny = x + dir[j][1];
            cout << nx << ' ' << ny << '\n';
        }
    }
    return 0;
}
