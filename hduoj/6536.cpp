#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;

int n,m,k;
int ar[maxn];

char ch[maxn];
char c[maxn]="0xtCpc";
int main()
{
    while(scanf("%d",&n)==1){

        scanf("%s",ch);
        m=strlen(c)-1;
        for(int i=0;i<=m;i++)ar[i]=0;
        ar[0] = n;
        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                if(ch[i]==c[j]){
                    if(ar[j-1]>0){
                        ar[j-1]--;
                        ar[j]++;
                    }
                    break;
                }
            }
        }
        printf("%d\n", ar[m]);
    }


    return 0;
}
