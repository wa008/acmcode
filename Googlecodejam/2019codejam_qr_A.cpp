#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+7;
const int mod = 1e9+7;
typedef long long ll;
int n,m;
int ar[maxn];

char ch[1000];
char c1[maxn],c2[maxn];
int main()
{
    int t;scanf("%d",&t);
    for(int fir=1;fir<=t;fir++){
        
    scanf("%s",ch);
    n=strlen(ch);
    int i1=0,i2=0;
    for(int i=0;i<n;i++){
        if(ch[i]=='4'){
            c1[i1++]='2';
            c2[i2++]='2';
        }
        else{
            c1[i1++]=ch[i];
            if(i2>0)c2[i2++]='0';
        }
    }
    if(i1==0)c1[i1++]='0';
    if(i2==0)c2[i2++]='0';
    c1[i1]='\0';
    c2[i2]='\0';
    printf("Case #%d: %s %s\n",fir,c1,c2);

    }

    return 0;
}