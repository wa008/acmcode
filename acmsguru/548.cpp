#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 998244353;
const int sz = 25;
#define afdafafafdafaf y1;
int n,m;
int ar[maxn];

int main()
{
    scanf("%d", &n);
    multiset<pair<int,int>> s;
    ll sum=0;
    for(int i=2; i<=n; i++){
        char ch[2];
        int x;
        scanf("%s%d", ch, &x);
        if(ch[0] == 'd'){
            s.insert(make_pair(x, i));
            sum += x;
        }
        else if(i==n){
            if(s.size() >= x){
                printf("%lld\n%d\n", sum, int(s.size()));
                vector<int> out;
                for(auto it : s){
                    out.push_back(it.second);
                }
                sort(out.begin(), out.end());
                for(int i=0;i<out.size();i++){
                    printf("%d%c", out[i], i==out.size()-1 ? '\n' : ' ');
                }
            }
            else{
                printf("-1\n");
            }
        }
        else{
            while(s.size() >= x){
                sum -= s.begin()->first;
                s.erase(s.begin());
            }
        }
    }
    return 0;
}
