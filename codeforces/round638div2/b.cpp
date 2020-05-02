#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long ll;

int ar[maxn];
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0); //C++关同步
    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        set<int> s;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            s.insert(x);
        }
        if(s.size() > k)cout << "-1\n";
        else{
            int ins = 1;
            while(s.size() < k){
                s.insert(ins++);
            }
            cout << s.size() * n << "\n";
            int fir = 1;
            for(int i=0;i<n;i++){
                for(int x : s){
                    if(fir){
                        fir = 0;
                    }
                    else{
                        cout << " ";
                    }
                    cout << x;
                }
            }
            cout << "\n";
        }

    }
    return 0;
}
