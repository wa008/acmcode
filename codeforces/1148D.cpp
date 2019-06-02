#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5+7;
const ll mod = 1000000000000037;

int n,m,ar[maxn];
int br[maxn];
pair<int,int> p1[maxn],p2[maxn];
int main()
{
    scanf("%d",&n); 
    int c1=0,c2=0;
    for(int i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b){
            c1++;
            p1[c1].first=b;
            p1[c1].second=i;
        }
        else{
            c2++;
            p2[c2].first=a;
            p2[c2].second=i;
        }
    }
    printf("%d\n",max(c1,c2));
    if(c1>c2){
        sort(p1+1, p1+c1+1);
        for(int i=1;i<=c1;i++)printf("%d%c",p1[i].second,i==c1?'\n':' ');
    }
    else{
        sort(p2+1, p2+c2+1);
        for(int i=c2;i>=1;i--)printf("%d%c",p2[i].second,i==1?'\n':' ');
    }

    return 0;
}