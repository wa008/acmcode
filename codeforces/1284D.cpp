#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
typedef long long ll;
int n,m;

void print(pair<pair<int, int>, pair<int, int>> x){
    cout << "print " << x.first.first << " " << x.first.second << " " << x.second.first << " " << 
        x.second.second << '\n';
}
vector<int> sa, ea, sb, eb;
bool solve(vector<int> sa, vector<int> sb, vector<int> ea, vector<int> eb){
    vector<pair<pair<int, int>, pair<int, int>>> v, vr;
    for(int i=0;i<sa.size();i++){
        v.push_back(make_pair(make_pair(sa[i], sb[i]), make_pair(ea[i], eb[i])));
        vr.push_back(make_pair(make_pair(sb[i], sa[i]), make_pair(ea[i], eb[i])));
    }
    sort(v.begin(), v.end());
    sort(vr.begin(), vr.end());
    int mxs = 0, mxe = 0, ins = 0, mne = 1e9+1;
    set<pair<int, int>> s;
    for(int i=0;i<v.size();i++){
        while(ins < vr.size() && vr[ins].first.first < v[i].first.first){
            mxe = max(mxe, vr[ins].second.second);
            mne = min(mne, vr[ins].second.first);
            s.insert(vr[ins].second);
            ins++;
        }
        set<pair<int, int>>::iterator it = s.upper_bound(v[i].second);
        if(it != s.end()){
            if(it->first <= v[i].second.second)return 0;
        }
        if(it != s.begin()){
            it--;
            if(it->second >= v[i].second.first)return 0;
        }
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        int a,b,c,d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        sa.push_back(a);
        ea.push_back(b);
        sb.push_back(c);
        eb.push_back(d);
    }
    if(solve(sa, ea, sb, eb) && solve(sb, eb, sa, ea))printf("YES\n");
    else printf("NO\n");
    return 0;
}
