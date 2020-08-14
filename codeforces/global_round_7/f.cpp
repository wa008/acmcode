#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 3e5 + 7;

int n, m;
int mx[maxn << 2], mn[maxn << 2], sum[maxn << 2], ad[maxn << 2], se[maxn << 2];
int max_val, min_val, sum_val, v, x, y;

void init(int n){
    for(int i = 0; i <= (n << 2); i++)
        mx[i] = mn[i] = sum[i] = ad[i] = se[i] = 0;
}
void maintain(int l, int r, int o){
    if(se[o] >= 0){
        mx[o] = se[o] + ad[o];
        mn[o] = se[o] + ad[o];
        sum[o] = (se[o] + ad[o]) *(r - l + 1);
        return ;
    }
    mx[o] = 0; mn[o] = 0; sum[o] = 0;
    if(l<r){
        mx[o] = max(mx[o << 1], mx[o << 1 ^ 1]);
        mn[o] = min(mn[o << 1], mn[o << 1 ^ 1]);
        sum[o] = sum[o << 1] + sum[o << 1 ^ 1];
    }
    mx[o] += ad[o];
    mn[o] += ad[o];
    sum[o] += ad[o] * (r - l + 1);
}
void pushdown(int o){
    if(se[o] >= 0){
        se[o << 1] = se[o << 1 ^ 1] = se[o];
        ad[o << 1] = 0; 
        ad[o << 1 ^ 1] = 0;
        se[o] =  - 1;
    }
    if(ad[o]>0){
        ad[o << 1] += ad[o];
        ad[o << 1 ^ 1] += ad[o];
        ad[o] = 0;
    }
}

void add(int l, int r, int o){
    if(l >= x && r <= y){
        ad[o] += v;
    }
    else{
        pushdown(o);
        int mid = (l + r) >> 1;
        if(mid >= x)add(l, mid, o << 1);
        else maintain(l, mid, o << 1);
        if(mid<y)add(mid + 1, r, o << 1 ^ 1);
        else maintain(mid + 1, r, o << 1 ^ 1);
    }
    maintain(l, r, o);
}
void set_func(int l, int r, int o){
    if(l >= x && r <= y){
        se[o] = v;
        ad[o] = 0;
    }
    else{
        int mid = (l + r) >> 1;
        pushdown(o);
        if(mid >= x)set_func(l, mid, o << 1);
        else maintain(l, mid, o << 1);
        if(mid < y)set_func(mid + 1, r, o << 1 ^ 1);
        else maintain(mid + 1, r, o << 1 ^ 1);
    }
    maintain(l, r, o);
}

void que(int l, int r, int o, int add = 0){
    if(se[o] >= 0){
        int v_mid = se[o] + add + ad[o];
        min_val = min(min_val, v_mid);
        max_val = max(max_val, v_mid);
        sum_val += v_mid * (min(y, r) - max(l, x) + 1);
        return ;
    }
    else if(l >= x && r <= y){
        min_val = min(min_val, mn[o] + add);
        max_val = max(max_val, mx[o] + add);
        sum_val += sum[o] + add * (r - l + 1);
        return ;
    }
    add += ad[o];
    int mid = (l + r) >> 1;
    if(mid >= x)que(l, mid, o << 1, add);
    if(mid < y)que(mid + 1, r, o << 1 ^ 1, add);
}

int pos[maxn], ar[maxn];
int main()
{
    scanf("%d", &n);
    for(int i = 1;i<=n;i++){
        scanf("%d", &x);
        pos[x] = i;
    }
    for(int i=1;i<=n;i++)scanf("%d", ar + i);
    printf("%d ", n);
    int ans = n;
    x = 1, y = pos[n], v = 1;
    add(1, n, 1);
    for(int i = 1; i < n; i++){
        x = 1, y = ar[i], v = -1;
        add(1, n, 1);
        while(mx[1] <= 0){
            ans--;
            x = 1, y = pos[ans], v = 1;
            add(1, n, 1);
        }
        printf("%d%c", ans, i == n - 1 ? '\n' : ' ');
    }

    return 0;
}
