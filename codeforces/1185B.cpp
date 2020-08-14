#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const int maxm = 2e6+7;
const ll mod = 1e9+7;

int n;
char c1[maxn],c2[maxn];
int main()
{
    scanf("%d", &n);
    while(n--){
        scanf("%s", c1);
        scanf("%s", c2);
        int n1=strlen(c1);
        int n2=strlen(c2);
        int i1=0,i2=0;
        int flag=1;
        while(i1<n1 && i2<n2){
            int ins1=0,ins2=0, ni1=i1+1,ni2=i2+1;
            while(ni1<n1 && c1[ni1]==c1[i1])ni1++;
            while(ni2<n2 && c2[ni2]==c2[i2])ni2++;
            if(ni2-i2 < ni1-i1 || c1[i1]!=c2[i2]){
                flag=0;
                break;
            }
            i1=ni1;
            i2=ni2;
        }
        if(i1!=n1 || i2!=n2)flag=0;
        printf("%s\n", flag==1?"YES":"NO");
    }

    return 0;
}