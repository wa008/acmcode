#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
const int mod = 1e9+7;
typedef long long ll;

int n,m;
multiset<int> s;
multiset<int>::iterator it;
int a[maxn], b[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        for(int i=1;i<=n;i++)scanf("%d", a+i);
        for(int i=1;i<=n;i++)scanf("%d", b+i);
        s.clear();
        int ins=1;
        for(int i=1;i<=n;i++){
            s.insert(a[i]);
            for(;;){
                it = s.begin();
                int x = *it;
                if(x==b[ins]){
                    s.erase(it);
                    ins++;
                }
                else{
                    break;
                }
                if(s.size()==0)break;
            }
        }
        printf("%s\n", ins==n+1?"YES":"NO");
    }
    return 0;
}
