#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 7;
const ll mod = 1e9+7;

int n,m;

int a[maxn], b[maxn], c[maxn];
multiset<int> sa, sb, sc;
multiset<int>::iterator it;

int main()
{
    int A, B, C;
    cin >> n >> m >> A >> B >> C;
    for(int i=0;i<A;i++){
        int x;
        cin >> x;
        sa.insert(x);
    }
    for(int i=0;i<B;i++){
        int x;
        cin >> x;
        sb.insert(x);
    }
    for(int i=0;i<C;i++){
        int x;
        cin >> x;
        sc.insert(x);
    }
    while(sa.size() > n){
        sa.erase(sa.begin());
    }
    while(sb.size() > m){
        sb.erase(sb.begin());
    }
    while(sc.size() > 0){
        it = sc.end();
        it--;
        int x = int(*it);
        if(x <= *sa.begin() && x <= *sb.begin())break;
        if(x > *sa.begin() && x > *sb.begin()){
            if(*sa.begin() < *sb.begin()){
                sa.erase(sa.begin());
                sa.insert(x);
            }
            else{
                sb.erase(sb.begin());
                sb.insert(x);
            }
        }
        else if(x > *sa.begin()){
            sa.erase(sa.begin());
            sa.insert(x);
        }
        else if(x > *sb.begin()){
            sb.erase(sb.begin());
            sb.insert(x);
        }
        else{
            assert(1 == 2);
        }
        sc.erase(it);
    }
    /*
    for(int x : sa)cout << x << ' '; cout << '\n';
    for(int x : sb)cout << x << ' '; cout << '\n';*/
    ll ans = 0;
    for(int x : sa)ans += x;
    for(int x : sb)ans += x;
    cout << ans << '\n';
    return 0;
}
