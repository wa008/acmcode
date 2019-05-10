#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+7;
const ll mod = 1e9+7;
int n,m;
int ar[maxn];

int num[maxn];
int depNum[maxn];

int main()
{
    scanf("%d",&n);
    int ans=1;
    for(int i=1;i<=n;i++)scanf("%d", ar+i);
    depNum[0] = n;
    set<int> se;
    for(int i=1;i<=n;i++){
        int dep = num[ar[i]];
        num[ar[i]]++;
        depNum[dep]--;
        depNum[dep+1]++;
        if(dep>0 && depNum[dep]==0){
            assert(se.count(dep)==1);
            se.erase(dep);
        }
        if(depNum[dep+1]==1){
            se.insert(dep+1);
        }
        if(se.size()==2){
            set<int>::iterator it = se.begin();
            int a = *it;
            it++;
            int b = *it;
            if(a==1 && depNum[a]==1){
                ans = i;
            }
            else if(a==b+1 && depNum[a]==1)ans=i;
            else if(b==1 && depNum[b]==1)ans=i;
            else if(b==a+1 && depNum[b]==1)ans=i;
        }
        else if(se.size()==1){
            set<int>::iterator it = se.begin();
            int a = *it;
            if(a==1 || depNum[a]==1)ans=i;
        }
    }
    printf("%d\n",ans);

    return 0;
}