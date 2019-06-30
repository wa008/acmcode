#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int sz = 31;

int n,m,ar[maxn];
map<int,int> ma;
vector<int> xx, yy;
int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1;i<=m;i++){
        int ins, l, r;
        scanf("%d%d%d", &ins, &l, &r);
        if(ins==1){
            ma[l] = max(ma[l], r);
        }
        else{
            xx.push_back(l);
            yy.push_back(r);
        }
    }
    ar[1] = 10000;
    int mx = ma[1];
    for(int i=2;i<=n;i++){
        if(i<=mx)ar[i] = ar[i-1]+1;
        else ar[i] = ar[i-1]-1;
        mx = max(mx, ma[i]);
    }
    for(int i=0;i<xx.size();i++){
        int x=xx[i], y = yy[i];
        int flag=0;
        for(int j=x;j<y;j++){
            if(ar[j]>ar[j+1]){
                flag=1;
                break;
            }
        }
        if(!flag){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;i++)printf("%d%c", ar[i], i==n?'\n':' ');
    return 0;
}
