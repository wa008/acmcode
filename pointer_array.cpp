/*
 *指针数组作为参数传递
 *可实现传递第二维长度不确定的二维数组
 *
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define frewri freopen("1.ou","w",stdout)
const int maxn=3e5+7;
const ll mod=1e9+7;
int ar[maxn],n,m,k;
int arr[10][10];

void func(int *aa[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++)cout<<aa[i][j]<<" ";cout<<endl;
    }
}
int a2[10][10];
int main()
{
    int *aa[maxn];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)arr[i][j]=i+j;
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++)a2[i][j]=i+j+100;
    }
    for(int i=0;i<10;i++)aa[i]=arr[i];
    func(aa,10);
    for(int i=0;i<10;i++)aa[i]=a2[i];
    func(aa,10);


    return 0;
}
