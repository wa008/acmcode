#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 998244353;
const int sz = 25;
#define afdafafafdafaf y1;
int n,m;
int ar[maxn];

bool cmp(const int &x, const int &y){
    return x>y;
}
vector<int> v[maxn];
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
    }
    for(int i=1; i<maxn; i++)sort(v[i].begin(), v[i].end(), cmp);
    vector<pair<int,int> > temp;
    for(int i=1; i<maxn; i++){
        if(v[i].size() > 0){
            temp.push_back(make_pair(v[i].size(), i));
        }
    }
    sort(temp.begin(), temp.end());
    if(temp.size() < m){
        printf("0 0\n");
        return 0;
    }
    int ins = temp.size() - m;
    int ans1 = temp[ins].first, ans2 = 0;
    vector<int> res;
    int x = ins-1;
    while(x>=0 && temp[x].first == ans1){
        int mid = 0;
        assert(v[temp[x].second].size() == ans1);
        for(int xx : v[temp[x].second]){
            mid += xx;
        }
        res.push_back(mid);
        x--;
    }
    x = ins;
    while(x<temp.size()){
        int now = temp[x].second;
        int mid = 0;
        for(int i=0; i<ans1; i++){
            mid += v[now][i];
            //cout << now << ' ' << v[now][i] << '\n';
        }
        res.push_back(mid);
        x++;
    }
    if(res.size() < m){
        while(1);
    }
    assert(res.size() >= m);
    sort(res.begin(), res.end(), cmp);
    for(int i=0;i<m;i++)ans2 += res[i];
    printf("%d %d\n", ans1, ans2);
    return 0;
}
