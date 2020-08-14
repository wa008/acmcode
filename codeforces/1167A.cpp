#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
typedef long long ll;

int n,m;
int ar[maxn];

int main()
{
    int t;scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        char ch[1000];
        scanf("%s",ch);
        int flag=0;
        for(int i=0;i<n;i++){
            if(ch[i]=='8' && n-i>=11){
                flag=1;
                break;
            }
        }
        printf("%s\n",flag==1?"YES":"NO");
    }

    return 0;
}