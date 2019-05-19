#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
const int mod = 1e9+7;
typedef long long ll;

int n,m,k;
int ar[maxn];
int num[maxn<<1];
int ins;
void add(int x,int v){
    for(; x<=ins; x += x&(-x)){
        num[x] += v;
    }
}
int que(int x){
    int ans=0;
    for(; x>0; x -= x&(-x)){
        ans += num[x];
    }
    return ans;
}
set<int> se;
set<int>::iterator it;

map<int,int> ma;
int al[maxn];
pair<pair<int,int>, int> pa[maxn];
int sq;
bool cmp(pair<pair<int,int>, int>& p1, pair<pair<int,int>, int>& p2){
    if(p1.first.first/sq == p2.first.first/sq)return p1.first.second<p2.first.second;
    else return p1.first.first<p2.first.first;
}
int xx[maxn][3];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    ins=0;
    for(int i=1;i<=n;i++){
        scanf("%d", ar+i);
        se.insert(ar[i]);
        se.insert(ar[i]-k-1);
        se.insert(ar[i]+k);
    }
    for(it=se.begin(); it!=se.end(); it++){
        ma[*it] = ++ins;
    }
    for(int i=1;i<=n;i++){
        xx[i][0] = ma[ar[i]-k-1];
        xx[i][1] = ma[ar[i]];
        xx[i][2] = ma[ar[i]+k];
    }
    sq = sqrt(n);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&pa[i].first.first, &pa[i].first.second);
        pa[i].second = i;
    }
    sort(pa+1, pa+1+m, cmp);
    int l=1,r=0,mid=0;
    for(int i=1;i<=m;i++){
        while(r<pa[i].first.second){
            r++;
            mid += que(xx[r][2]) - que(xx[r][0]);
            add(xx[r][1],1);
        }
        while(l<pa[i].first.first){
            add(xx[l][1],-1);
            mid -= que(xx[l][2]) - que(xx[l][0]);
            l++;
        }
        while(r>pa[i].first.second){
            add(xx[r][1],-1);
            mid -= que(xx[r][2]) - que(xx[r][0]);
            r--;
        }
        while(l>pa[i].first.first){
            l--;
            mid += que(xx[l][2]) - que(xx[l][0]);
            add(xx[l][1], 1);
        }
        al[pa[i].second]=mid;
    }
    for(int i=1;i<=m;i++)printf("%d\n", al[i]);
    return 0;
}
