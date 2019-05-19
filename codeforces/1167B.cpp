#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
const int maxm = 2e1+7;
typedef long long ll;

int n,m;

int ar[10] = {
    0,4,8,15,16,23,42
};
vector<int> ve[maxn];
int ans[100];
int main()
{
    set<int> se;
    for(int i=1;i<=6;i++){
        for(int j=i+1;j<=6;j++){
            ve[ar[i]*ar[j]].push_back(i);
            ve[ar[i]*ar[j]].push_back(j);
        }
    }
    int x;
    for(int i=1;i<=6;i+=3){
        printf("? %d %d\n",i,i+1);
        fflush(stdout);
        scanf("%d",&x);
        ans[i] = ve[x][0];
        ans[i+1] = ve[x][1];

        printf("? %d %d\n",i+1,i+2);
        fflush(stdout);
        scanf("%d",&x);
        //cout<<ar[i]<<" "<<ar[i+1]<<endl;
        //cout<<ve[x][0]<<" "<<ve[x][1]<<endl;
        if(ve[x][0] == ans[i+1]){
            ans[i+2] = ve[x][1];
        }
        else if(ve[x][0] == ans[i]){
            swap(ans[i], ans[i+1]);
            ans[i+2] = ve[x][1];
        }
        else if(ve[x][1] == ans[i+1]){
            ans[i+2] = ve[x][0];
        }
        else if(ve[x][1] == ans[i]){
            swap(ans[i], ans[i+1]);
            ans[i+2] = ve[x][0];
        }
        else{
            assert(1==2);
        }
    }
    printf("!");
    for(int i=1;i<=6;i++)printf(" %d", ar[ans[i]]);
    printf("\n");
    fflush(stdout);
    return 0;
}