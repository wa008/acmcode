#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e1+7;
typedef long long ll;

ll c[maxn][maxn];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    c[1][1] = 1;
    for(int i=2;i<maxn;i++){
        c[i][1] = c[i][i] = 1;
        for(int j=2;j<i;j++){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    for(int cas = 1; cas <= t; cas ++){
        int n;
        cin >> n;
        cout << "Case #" << cas << ":\n";
        int x = n, ins = 0;
        while(x > 0){
            ++ins;
            x >>= 1;
        }
        //cout << n << ' ' << ins << '\n';
        int last = ins;
        x = n - last, ins = 0;
        vector<int> row;
        while(x > 0){
            ++ins;
            if(x & 1)row.push_back(ins);
            x >>= 1;
        }
        last -= ins - int(row.size());
        int px = 1;
        ins = 0;
        for(int r : row){
            if(ins == 0){
                for(int j = px; j < r; j++)cout << j << ' ' << 1 << '\n';
                for(int j=1;j<=r;j++)cout << r << ' ' << j << '\n';
            }
            else{
                for(int j = px; j < r; j++)cout << j << ' ' << j << '\n';
                for(int j = r; j >= 1; j--)cout << r << ' ' << j << '\n';
            }
            n -= (1L << (r - 1));
            n -= r - px;
            px = r + 1;
            ins ^= 1;
        }
        assert(n == last);
        assert(n < 40);
        if(ins == 0){
            while(last > 0){
                last--;
                cout << px << ' ' << 1 << '\n';
                px++;
            }
        }
        else{
            while(last > 0){
                last--;
                cout << px << ' ' << px << '\n';
                px++;
            }
        }
    }
    return 0;
}
