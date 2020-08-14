#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+7;
const ll mod = 1e9+7;
const int sz = 62;
#define afdafafafdafaf y1;
int n,m;


double eps = 1e-9;
//几何基础
struct coor
{
    double a,b;
    coor(double a=0,double b=0):a(a),b(b) {}
};
void prin(coor c)
{
    printf("%.6lf\t%.6lf\n",c.a,c.b);
}
typedef coor point;//边
coor operator + (coor A,coor B){return coor(A.a+B.a,A.b+B.b);}

coor operator - (coor A,coor B){return coor(A.a-B.a,A.b-B.b);}

coor operator * (coor A,double d){return coor(A.a*d,A.b*d);}

coor operator / (coor A,double d){return coor(A.a/d,A.b/d);}

bool operator == (const coor& A,const coor& B){return fabs(A.a-B.a)<=eps&&fabs(A.b-B.b)<=eps;}

bool operator < (const coor& A,const coor& B){return A.a<B.a||(A.a==B.a&&A.b<B.b);}
int dcmp(double d)
{
    if(fabs(d)<eps)return 0;
    else return d<0?-1:1;
}
double Dot(coor A,coor B){return A.a*B.a+A.b*B.b;}//cos

double Cross(coor A,coor B){return A.a*B.b-A.b*B.a;}//面积2倍,a在b的顺时针方向,面积为正

double Area2(coor A,coor B,coor C){return fabs(Cross(A-B,C-B));}

double Length(coor A){return sqrt(Dot(A,A));}

double Length(coor A,coor B){return Length(A-B);}

coor normal(coor A)
{
    double L=Length(A);
    return coor(A.a/L,A.b/L);
}

double Angle(coor A,coor B){return acos(Dot(A,B)/Length(A)/Length(B));}

double Angle(coor A){return atan2(A.b,A.a);}//A与x轴横坐标的夹角

point Rotate(coor A,double rad)//逆时针旋转
{
    return coor(A.a*cos(rad)-A.b*sin(rad),A.a*sin(rad)+A.b*cos(rad));
}
coor jiaodian(coor p,coor v,coor q,coor w)//过p的线段v，过q的线段w
{
    coor u=p-q;
    double t=Cross(w,u)/Cross(v,w);
    return p+v*t;
}
coor chuizhi(coor A)
{
    coor B;
    B.a=-A.b;B.b=A.a;
    return B;
}
double distanceto1(coor p,coor x,coor y)//p到线段xy的最小距离
{
    if(x==y)return Length(p-x);
    coor c1=y-x,c2=p-x,c3=p-y;
    if(dcmp(Dot(c1,c2))<0)return Length(c2);
    else if(dcmp(Dot(c1,c3))>0)return Length(c3);
    else return fabs(Cross(c1,c2)/Length(c1));
}
double distanceto2(coor p,coor x,coor y)//p到直线xy的最小距离
{
    return Area2(p,x,y)/Length(x-y);
}
coor distanceto_touying(coor p,coor x,coor y)//求p在直线xy上的投影
{
    coor c=y-x;
    //prin(c);
    return x+c*(Dot(c,p-x)/Dot(c,c));
}
bool xiangjiao1(coor a1,coor a2,coor b1,coor b2)//判断线段a1 a2于线段b1 b2是否相交 且交点不在两线段的端点
{
    double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),
           c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
bool xiangjiao2(coor p,coor x,coor y)//判断p是否在线段xy上且不在端点
{
    return dcmp(Cross(x-p,y-p))==0&&dcmp(Dot(x-p,y-p))<0;
}
struct line
{
    coor p,q;
    line(coor c1,coor c2):p(c1),q(c2){}
    coor v=normal(q-p);
    coor point(double t){
        return p+v*t;
    }
};


point p[maxn],ch[maxn]; //凸包
bool coor_cmp(coor c1,coor c2)
{
    return c1.a<c2.a||(c1.a==c2.a&&c1.b<c2.b);
}
int convex(vector<point>& p, vector<point>& ch) 
{
    sort(p.begin(), p.end(), coor_cmp);
    int con_len=0, n = p.size();
    for(int i=0;i<n;i++){
        if(i>1&&p[i]==p[i-1])continue;
        while(con_len>1&&Cross(ch[con_len-1]-ch[con_len-2],p[i]-ch[con_len-2])<=0){
            con_len--;
            ch.pop_back();
        }
        ch.push_back(p[i]);
        con_len++;
    }
    int k=con_len;
    for(int i=n-2;i>=0;i--){
        if(i<n-1&&p[i]==p[i+1])continue;
        while(con_len>k&&Cross(ch[con_len-1]-ch[con_len-2],p[i]-ch[con_len-2])<=0){
            con_len--;
            ch.pop_back();
        }
        ch.push_back(p[i]);
        con_len++;
    }
    if(n>1)con_len--;
    /*
    printf("\n\nnew convex\n");
    for(auto pp : p)prin(pp);
    printf("\n");
    for(auto pp : ch)prin(pp); */
    return con_len;
}
int xx[maxn], yy[maxn];
int main()
{
    vector<int> xx, yy;
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        int x,y;
        scanf("%d%d", &x, &y);
        xx.push_back(x);
        yy.push_back(y);
    }
    vector<point> pre, nex;
    pre.push_back(point(0, 0));
    for(int i=0; i<n; i++){
        int x = xx[i], y = yy[i];
        m = pre.size();
        for(int i=0; i<m; i++){
            pre.push_back(point(pre[i].a + x, pre[i].b + y));
        }
        nex.resize(0);
        convex(pre, nex);
        pre = nex;
    }
    ll ans = 0;
    for(int i=0; i<pre.size(); i++){
        ll x = pre[i].a, y = pre[i].b;
        ans = max(ans, x*x + y*y);
    }
    printf("%.11lf\n", sqrt(double(ans)));

    return 0;
}
