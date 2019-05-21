#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;

int n,m,k;
int ar[maxn];
char ch[maxn]="aeiou";
int main()
{
    int size=5;
    scanf("%d",&n);
    for(int i=5;i<n;i++){
        if(n%i==0 && n/i>=5){
            int j=n/i;
            vector<vector<char>> ans(j,vector<char>(i+1,'\0'));
            for(int x=0;x<i;x++){
                int nx=0,ny=x;
                for(int y=0;y<n/i;y++){
                    ans[nx][ny] = ch[x%size];
                    nx++;
                    ny = (ny+1)%i;
                }
            }
            for(int x=0;x<j;x++){
                for(int y=0;y<i;y++)printf("%c", ans[x][y]);
            }
            printf("\n");
            return 0;
        }
    }
    printf("-1\n");


    return 0;
}