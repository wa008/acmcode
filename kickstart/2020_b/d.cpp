#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const int mod = 1e9 + 7;
typedef long long ll;
typedef long double ld;
const ld eps = 1e-30;

ld f[maxn], p2[maxn];
ld C(int x, int y){
    if(y < 0 || y > x)return 0;
    return exp (f[x] - f[y] - f[x - y] - p2[x]);
}
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t;
    cin >> t;
    p2[1] = log(2);
    f[1] = log(1);
    for(int i=2;i<maxn;i++){
        p2[i] = p2[i - 1] + p2[1]; 
        f[i] = f[i - 1] + log(i);
    }
    /*
    cout << C(3, 2) << "\n";
    for(int  i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            cout << fixed << setprecision(12) << C(i, j) << " ";
        }
        cout << "\n";
    }
    */
    for(int cas = 1; cas <= t; cas ++ ){
        int w, h, l, u, r, d;
        cin >> w >> h >> l >> u >> r >> d;
        --w; --h; --l; --u; --r; --d;
        cout << "Case #" << cas << ": ";
        int lx = u, ly = r;
        ld mult = 1.0, ans = 0;
        if(r < w){
            while(lx > 0){
                --lx;
                ++ly;
                if(ly >= w){
                    --ly;
                    mult = 0.5;
                }
                //cout << lx << ' ' << ly << ' ' << C(lx + ly, ly) << ' ' << mult << '\n';
                ans += mult * C(lx + ly, ly);
            }
        }
        swap(h, w);
        swap(u, l);
        swap(d, r);
        lx = u, ly = r;
        mult = 1.0;
        if(r < w){
            while(lx > 0){
                --lx;
                ++ly;
                if(ly >= w){
                    --ly;
                    mult = 0.5;
                }
                //cout << lx << ' ' << ly << ' ' << C(lx + ly, ly) << ' ' << mult << '\n';
                ans += mult * C(lx + ly, ly);
            }
        }

        cout << fixed << setprecision(12) << (ans) << "\n";
    }
    return 0;
}
