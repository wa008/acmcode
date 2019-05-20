#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
const int mod = 1e9+7;
typedef long long ll;

int n,m;
int ar[maxn];

char c1[maxn],c2[maxn];
int a1[maxn],a2[maxn];
int main()
{
    while(scanf("%s%s",c1,c2)==2){
        n=strlen(c1);
        m=strlen(c1);
        int flag=1;
        for(int i=0;i<max(n,m);i++){
            if(c1[i]!=c2[i]){
                flag=0;
                break;
            }
        }
        if(flag){
            printf("Equal\n");
            continue;
        }
        flag=1;
        for(int i=0;i<26;i++)a1[i]=a2[i]=0;
        for(int i=0;i<n;i++){
            a1[c1[i]-'a']++;
        }
        for(int i=0;i<m;i++){
            a2[c2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(a1[i]!=a2[i]){
                flag=0;
                break;
            }
        }
        if(flag){
            if(c1[0]==c2[0] && c1[n-1]==c2[m-1]);
            else flag=0;
        }
        printf("%s\n",flag==1? "Yes":"No");
    }
    return 0;
}