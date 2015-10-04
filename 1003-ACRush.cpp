#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <sstream>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

//BEGINTEMPLATE_BY_ACRUSH_TOPCODER
#define SIZE(X) ((int)(X.size()))//NOTES:SIZE(
#define LENGTH(X) ((int)(X.length()))//NOTES:LENGTH(
#define MP(X,Y) make_pair(X,Y)//NOTES:MP(
typedef long long int64;//NOTES:int64
typedef unsigned long long uint64;//NOTES:uint64
#define two(X) (1<<(X))//NOTES:two(
#define twoL(X) (((int64)(1))<<(X))//NOTES:twoL(
#define contain(S,X) (((S)&two(X))!=0)//NOTES:contain(
#define containL(S,X) (((S)&twoL(X))!=0)//NOTES:containL(

const double pi=acos(-1.0);//NOTES:pi
const double eps=1e-11;//NOTES:eps
class bigint;

template<class T> inline void checkmin(T &a,T b)  //将a,b中的较小数存在a中
{
    if(b<a) 
        a=b;
}

template<class T> inline void checkmax(T &a,T b)  //将a,b中的较大数存在a中
{
    if(b>a) 
        a=b;
}

template<class T> inline T sqr(T x)  //返回x的平方
{
    return x*x;
}

typedef pair<int,int> ipair;//NOTES:ipair
template<class T> inline T lowbit(T n)  //返回n的最低位
{
    return (n^(n-1))&n;
}

template<class T> inline int countbit(T n)   //返回位为1的个数
{
    return (n==0)?0:(1+countbit(n&(n-1)));
}

//Numberic Functions
template<class T> inline T gcd(T a,T b)        //返回a,b的最大公约数
{
    if(a<0)
        return gcd(-a,b);
    if(b<0)
        return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}

template<class T> inline T lcm(T a,T b)        //返回a,b的最小公倍数
{
    if(a<0)
        return lcm(-a,b);
    if(b<0)
        return lcm(a,-b);
    return a*(b/gcd(a,b));
}

template<class T> inline T euclide(T a,T b,T &x,T &y)//NOTES:euclide(
{
    if(a<0)
    {
        T d=euclide(-a,b,x,y);
        x=-x;
        return d;
    }
    if(b<0)
    {
        T d=euclide(a,-b,x,y);
        y=-y;
        return d;
    }
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        T d=euclide(b,a%b,x,y);
        T t=x;
        x=y;
        y=t-(a/b)*y;
        return d;
    }
}

template<class T> inline vector<pair<T,int> > factorize(T n)//NOTES:factorize(
{
    vector<pair<T,int> > R;
    for (T i=2;n>1;)
    {
        if (n%i==0)
        {
            int C=0;
            for(;n%i==0;C++,n/=i);
            R.push_back(make_pair(i,C));
        }
        i++;
        if (i>n/i) 
            i=n;
    }
    if (n>1) 
        R.push_back(make_pair(n,1));
    return R;
}

template<class T> inline bool isPrimeNumber(T n) //验证是否为素数
{
    if(n<=1)
        return false;
    for(T i=2;i*i<=n;i++) 
        if (n%i==0) 
            return false;
    return true;
}

template<class T> inline T eularFunction(T n)//NOTES:eularFunction(
{
    vector<pair<T,int> > R=factorize(n);
    T r=n;
    for(int i=0;i<R.size();i++)
        r=r/R[i].first*(R[i].first-1);
    return r;
}

//Matrix Operations
const int MaxMatrixSize=40;//NOTES:MaxMatrixSize
template<class T> inline void showMatrix(int n,T A[MaxMatrixSize][MaxMatrixSize])//NOTES:showMatrix(
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<A[i][j];
        cout<<endl;
    }
}

template<class T> inline T checkMod(T n,T m) //返回n除以m后的余数
{
    return (n%m+m)%m;
}

template<class T> inline void identityMatrix(int n,T A[MaxMatrixSize][MaxMatrixSize])//使A为单位矩阵
{
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) 
            A[i][j]=(i==j)?1:0;
}

template<class T> inline void addMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//两矩阵相加，C=A+B
{
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) 
            C[i][j]=A[i][j]+B[i][j];
}

template<class T> inline void subMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//两矩阵相减，C=A-B
{
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) 
            C[i][j]=A[i][j]-B[i][j];
}

template<class T> inline void mulMatrix(int n,T C[MaxMatrixSize][MaxMatrixSize],T _A[MaxMatrixSize][MaxMatrixSize],T _B[MaxMatrixSize][MaxMatrixSize])//两矩阵相乘，C=A*B
{ 
    T A[MaxMatrixSize][MaxMatrixSize],B[MaxMatrixSize][MaxMatrixSize];
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) 
            A[i][j]=_A[i][j],B[i][j]=_B[i][j],C[i][j]=0;
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) 
            for(int k=0;k<n;k++) 
                C[i][j]+=A[i][k]*B[k][j];
}

template<class T> inline void addModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//两矩阵相加后取模，C=(A+B)%m
{
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) 
            C[i][j]=checkMod(A[i][j]+B[i][j],m);
}

template<class T> inline void subModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T A[MaxMatrixSize][MaxMatrixSize],T B[MaxMatrixSize][MaxMatrixSize])//两矩阵相减后取模，C=(A-B)%m
{
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) 
            C[i][j]=checkMod(A[i][j]-B[i][j],m);
}

template<class T> inline T multiplyMod(T a,T b,T m) //相乘后取模 (a*b)%m
{
    return (T)((((int64)(a)*(int64)(b)%(int64)(m))+(int64)(m))%(int64)(m));
}

template<class T> inline void mulModMatrix(int n,T m,T C[MaxMatrixSize][MaxMatrixSize],T _A[MaxMatrixSize][MaxMatrixSize],T _B[MaxMatrixSize][MaxMatrixSize])//矩阵的元素对应相乘，再加上C的对应元素，取模
{ 
    T A[MaxMatrixSize][MaxMatrixSize],B[MaxMatrixSize][MaxMatrixSize];
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) 
            A[i][j]=_A[i][j],B[i][j]=_B[i][j],C[i][j]=0;
    
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) 
            for (int k=0;k<n;k++) 
            C[i][j]=(C[i][j]+multiplyMod(A[i][k],B[k][j],m))%m;
}

template<class T> inline T powerMod(T p,int e,T m)//返回(p^e)%m
{
    if(e==0)
        return 1%m;
    else if(e%2==0)
    {
        T t=powerMod(p,e/2,m);
        return multiplyMod(t,t,m);
    }
    else 
        return multiplyMod(powerMod(p,e-1,m),p,m);
}

//Point&Line
double dist(double x1,double y1,double x2,double y2) //返回(x1,y1),(x2,y2)的距离
{
    return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

double distR(double x1,double y1,double x2,double y2) //返回(x1,y1),(x2,y2)的距离的平方
{
    return sqr(x1-x2)+sqr(y1-y2);
}

template<class T> T cross(T x0,T y0,T x1,T y1,T x2,T y2) //(x1,y1)减去(x0,y0) 点乘 (x2,y2)减去(x0,y0)
{
    return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}

int crossOper(double x0,double y0,double x1,double y1,double x2,double y2)//判断两向量点乘后的符号
{
    double t=(x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
    if (fabs(t)<=eps) 
        return 0;
    return (t<0)?-1:1;
}

bool isIntersect(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)//NOTES:isIntersect(
{
    return crossOper(x1,y1,x2,y2,x3,y3)*crossOper(x1,y1,x2,y2,x4,y4)<0 && crossOper(x3,y3,x4,y4,x1,y1)*crossOper(x3,y3,x4,y4,x2,y2)<0;
}

//Translator
bool isUpperCase(char c) //判断是否为大写字母
{
    return c>='A' && c<='Z';
}

bool isLowerCase(char c) //判断是否为小写字母
{
    return c>='a' && c<='z';
}

bool isLetter(char c) //判断是否为字母
{
    return c>='A' && c<='Z' || c>='a' && c<='z';
}

bool isDigit(char c) //判断是否为数字
{
    return c>='0' && c<='9';
}

char toLowerCase(char c) //变为小写字母
{
    return (isUpperCase(c))?(c+32):c;
}

char toUpperCase(char c) //变为大写字母
{
    return (isLowerCase(c))?(c-32):c;
}

template<class T> string toString(T n) //转化为字符串
{
    ostringstream ost;ost<<n;
    ost.flush();
    return ost.str();
}

int toInt(string s) //字符串转化为数字
{
    int r=0;
    istringstream sin(s);
    sin>>r;
    return r;
}

int64 toInt64(string s) //字符串转化为int64
{
    int64 r=0;
    istringstream sin(s);
    sin>>r;
    return r;
}

double toDouble(string s) //字符串转化为double
{
    double r=0;
    istringstream sin(s);
    sin>>r;
    return r;
}

template<class T> void stoa(string s,int &n,T A[]) //字符串转化为数组(空格为分界)
{
    n=0;
    istringstream sin(s);
    for(T v;sin>>v;A[n++]=v);
}

template<class T> void atos(int n,T A[],string &s) //数组转化为字符串(空格分界)
{
    ostringstream sout;
    for(int i=0;i<n;i++)
    {
        if(i>0)
            sout<<' ';
        sout<<A[i];
    }
    s=sout.str();
}

template<class T> void atov(int n,T A[],vector<T> &vi) //数组转化为向量
{
    vi.clear();
    for(int i=0;i<n;i++) 
        vi.push_back(A[i]);
}

template<class T> void vtoa(vector<T> vi,int &n,T A[]) //向量转化为数组
{
    n=vi.size();
    for(int i=0;i<n;i++)
        A[i]=vi[i];
}

template<class T> void stov(string s,vector<T> &vi) //字符串转化为向量
{
    vi.clear();
    istringstream sin(s);
    for(T v;sin>>v;vi.push_bakc(v));
}

template<class T> void vtos(vector<T> vi,string &s) //向量转化为字符串
{
    ostringstream sout;
    for(int i=0;i<vi.size();i++)
    {
        if(i>0)
            sout<<' ';
        sout<<vi[i];
    }
    s=sout.str();
}

//Fraction
template<class T> struct Fraction
{
    T a,b;
    Fraction(T a=0,T b=1);
    string toString();
};

template<class T> Fraction<T>::Fraction(T a,T b)
{
    T d=gcd(a,b);
    a/=d;
    b/=d;
    if (b<0) 
    {
        a=-a;
        b=-b;
    }
    this->a=a;
    this->b=b;
}

template<class T> string Fraction<T>::toString()
{
    ostringstream sout;
    sout<<a<<"/"<<b;
    return sout.str();
}

template<class T> Fraction<T> operator+(Fraction<T> p,Fraction<T> q)
{
    return Fraction<T>(p.a*q.b+q.a*p.b,p.b*q.b);
}

template<class T> Fraction<T> operator-(Fraction<T> p,Fraction<T> q)
{
    return Fraction<T>(p.a*q.b-q.a*p.b,p.b*q.b);
}

template<class T> Fraction<T> operator*(Fraction<T> p,Fraction<T> q)
{
    return Fraction<T>(p.a*q.a,p.b*q.b);
}

template<class T> Fraction<T> operator/(Fraction<T> p,Fraction<T> q)
{
    return Fraction<T>(p.a*q.b,p.b*q.a);
}

template<class T> bool operator>(Fraction<T> p,Fraction<T> q)
{
    return p.a*q.b > p.b*q.a;
}

template<class T> bool operator<(Fraction<T> p,Fraction<T> q)
{
    return p.a*q.b < p.b*q.a;
}

template<class T> bool operator>=(Fraction<T> p,Fraction<T> q)
{
    return !(p.a*q.b < p.b*q.a);
}

template<class T> bool operator<=(Fraction<T> p,Fraction<T> q)
{
    return !(p.a*q.b > p.b*q.a);
}

template<class T> bool operator>(Fraction<T> p,bigint q)
{
    return p.a > p.b * q;
}

template<class T> bool operator<(Fraction<T> p,bigint q)
{
    return p.a < p.b * q;
}

template<class T> bool operator>=(Fraction<T> p,bigint q)
{
    return !(p.a < p.b * q);
}

template<class T> bool operator<=(Fraction<T> p,bigint q)
{
    return !(p.a > p.b * q);
}
//ENDTEMPLATE_BY_ACRUSH_TOPCODER

//BIGINT
const int maxlength=200;

class bigint
{
public:
    int oper;            //负数时，oper = -1;非负数时，oper = 1
    int length;            //4位一段，段数
    int* a;    //每段的内容。下标从1到length
    bigint(int=0);
    bigint(const bigint& m); //拷贝构造函数
    ~bigint();
    int max(int a,int b);
    void check();
    void operator=(bigint m);
    void operator=(int m);
    void operator=(char *s);
    bool operator<(bigint m) const;
    bool operator<=(bigint m) const;
    bool operator>(bigint m) const;
    bool operator>=(bigint m) const;
    bool operator==(bigint m) const;
    bool operator!=(bigint m) const;
    bigint operator-() const;
    bigint operator+(bigint m);
    void operator+=(bigint m);
    bigint operator-(bigint m);
    void operator-=(bigint m);
    bigint operator*(bigint m);
    bigint operator*(int m);
    void operator*=(bigint m);
    void operator*=(int m);
    bigint operator/(bigint m);
    bigint operator/(int m);
    void operator/=(bigint m);
    void operator/=(int m);
    bigint operator%(bigint m);
    bigint operator%(int m);
    void operator%=(bigint m);
    void operator%=(int m);
};

std::ostream& operator<<(std::ostream& result, const bigint& a); //输出
std::istream& operator>>(std::istream& result, bigint& a); //输入
bigint abs(bigint m);
bool read(bigint &m);
void write(bigint m);
void swrite(char *s,bigint m);
void writeln(bigint m);
bigint sqr(bigint m);
bigint pow(bigint m, int e);
bigint sqrt(bigint m);
bigint gcd(bigint a,bigint b);
bigint lcm(bigint a,bigint b);

string int2str_big(int m)
{
    stack<int> st;
    string s = "";
    int i = 0;
    while(i < 4)
    {
        st.push(m%10);
        m /= 10;
        i++;
    }
    while(!st.empty())
    {
        s.append(1, char('0' + st.top()));
        st.pop();
    }
    return s;
}

int str2int(string s)
{
    int m = 0;
    int option = 0; //0时表示还没开始找到第一位有效数字，1时表示已经找到有效数字
    unsigned int i = 0;
    while(i < s.length())
    {

        if(option == 0)
        {
            if(s[i] == '0')
            {        
                i++;
            }
            else
            {
                option = 1;
                m = 10*m + (s[i] - '0');
                i++;
            }
            continue;
        }
        if(option == 1)
        {
            m = 10*m + (s[i] - '0');
            i++;
        }
    }
    return m;
}

string check(string s)
{
    string tmpstr = "";
    int zerocount = 0;
    int oper = 1;
    if (s[0] == '-')
    {
        oper = -1;
        zerocount++;//负号占了一位，故偏移量加1，消完0后再补上
    }
    while(true)
    {
        if(s[zerocount] != '0')
            break;
        zerocount++;
    }
    if(oper == -1)
    {
        tmpstr = "-";
    }
    tmpstr += s.substr(zerocount, s.length());
    return tmpstr;
}

int bigint::max(int a,int b)
{
    return (a>b)?a:b;
}

bigint::bigint(int v)
{
    a = new int[maxlength];
    (*this)=v;
    this->check();
}

bigint::bigint(const bigint& m) //拷贝构造函数
{
    a = new int[maxlength];
    memcpy(a,m.a,maxlength*sizeof(int));
    oper = m.oper;
    length = m.length;
}

bigint::~bigint()
{
    delete[] a;
}

void bigint::check()
{
    for(;length>0 && a[length]==0;length--);
    if(length==0)
        oper=1;
}

void bigint::operator=(bigint m)
{
    oper=m.oper;
    length=m.length;
    memcpy(a,m.a,maxlength*sizeof(int));
    this->check();
}

void bigint::operator=(int m)
{
    oper=(m>0)?1:-1;
    m=abs(m);
    memset(a,0,maxlength*sizeof(int));
    for (length=0;m>0;m=m/10000)
        a[++length]=m%10000;
    this->check();
}

void bigint::operator=(char *s)
{
    int i,L;
    (*this)=0;
    if(s[0]=='-' || s[0]=='+')
    {
        if(s[0]=='-')
            oper=-1;
        L=strlen(s);
        for(i=0;i<L;i++)
            s[i]=s[i+1];
    }
    L=strlen(s);
    length=(L+3)/4;
    for (i=0;i<L;i++)
        a[(L-i+3)/4]=a[(L-i+3)/4]*10+(s[i]-48);
    this->check();
}

bool bigint::operator<(bigint m) const
{
    if (oper!=m.oper)
        return oper<m.oper;
    if (length!=m.length)
        return oper*length<m.length*oper;
    for (int i=length;i>=1;i--)
        if (a[i]!=m.a[i])
            return a[i]*oper<m.a[i]*oper;
    return false;
}

bool bigint::operator<=(bigint m) const
{
    return !(m<(*this));
}

bool bigint::operator>(bigint m) const
{
    return m<(*this);
}

bool bigint::operator>=(bigint m) const
{
    return !((*this)<m);
}

bool bigint::operator==(bigint m) const
{
    return (!((*this)<m)) && (!(m<(*this)));
}

bool bigint::operator!=(bigint m) const
{
    return ((*this)<m) || (m<(*this));
}

bigint bigint::operator-() const
{
    bigint c=(*this);
    c.oper=-c.oper;
    c.check();
    return c;
}

bigint abs(bigint m)
{
    bigint c=m;
    c.oper=abs(c.oper);
    c.check();
    return c;
}

bigint pow(bigint m, int e)
{
    if(e == 0)
        return bigint(1);
    if(e%2 == 0)
    {
        return pow(sqr(m), e/2);
    }
    else
        return pow(m,e-1) * m;
}

bigint bigint::operator+(bigint m)
{
    if (m.length==0)
        return (*this);
    if (length==0)
        return m;
    if (oper==m.oper)
    {
        bigint c;
        c.oper=oper;
        c.length=max(length,m.length)+1;
        for (int i=1,temp=0;i<=c.length;i++)
            c.a[i]=(temp=(temp/10000+a[i]+m.a[i]))%10000;
        c.check();
        return c;
    }
    return (*this)-(-m);
}

bigint bigint::operator-(bigint m)
{
    if (m.length==0)
        return (*this);
    if (length==0)
        return (-m);
    if (oper==m.oper)
    {
        bigint c;
        if (abs(*this)>=abs(m))
        {
            c.oper=oper;
            c.length=length;
            for (int i=1,temp=0;i<=length;i++)
                c.a[i]=((temp=(-int(temp<0)+a[i]-m.a[i]))+10000)%10000;
            c.check();
            return c;
        }
        return -(m-(*this));
    }
    return (*this)+(-m);
}

bool read(bigint &m) //读入
{
    char s[maxlength*4+10];
    if (scanf("%s",&s)==-1)
        return false;
    for (int i=0;s[i];i++)
        if (!(s[i]>='0' && s[i]<='9' || (s[i]=='+' || s[i]=='-') && i==0))
            return false;
    m=s;
    return true;
}

void swrite(char *s,bigint m) //将m写在s里，并加一个空格
{
    int L=0;
    if (m.oper==-1)
        s[L++]='-';
    sprintf(s+L,"%d",m.a[m.length]);
    for(;s[L]!=0;L++);
    for(int i=m.length-1;i>=1;i--)
    {
        sprintf(s+L,"%04d",m.a[i]);
        L+=4;
    }
    s[L]=0;
}

string bigint2str(bigint m)
{
    string s = "";
    m.check();
    if(m.oper == -1)
        s += "-";
    for(int i = 0; i < m.length; i++)
    {
        s += int2str_big(m.a[m.length - i]);
    }
    s = check(s);
    return s;
}

bigint str2bigint(string s)
{
    bigint m;
    if(s[0] == '-')
    {
        m.oper = -1;
        s = s.substr(1, s.length()); //注意substr的用法。
    }
    
    m.length = (s.length() - 1)/4 + 1;
    m.a[0] = 0;
    int tmp = s.length()%4;
    if(tmp == 0)
        tmp += 4;
    m.a[m.length] = str2int(s.substr(0, tmp));
    for(int i = 1; i < m.length; i++)
    {
        m.a[i] = str2int(s.substr(s.length() - 4*i, 4));
    }
    m.check();
    return m;
}

void write(bigint m) //输出
{
    if (m.oper==-1)
        printf("-");
    printf("%d",m.a[m.length]);
    for(int i=m.length-1;i>=1;i--)
        printf("%04d",m.a[i]);
}

void writeln(bigint m) //输出换行
{
    write(m);
    printf("\n");
}

bigint bigint::operator*(bigint m)
{
    bigint c;
    c.oper=oper*m.oper;
    c.length=length+m.length;
    for(int i=1;i<=m.length;i++)
    {
        int number=m.a[i],j,temp=0;
        for(j=1;j<=length;j++)
            c.a[i+j-1]+=number*a[j];
        if(i%10==0 || i==m.length)
        {
            for(j=1;j<=c.length;j++)
                c.a[j]=(temp=(temp/10000)+c.a[j])%10000;
        }
    }
    c.check();
    return c;
}

bigint bigint::operator*(int m)
{
    if (m<0)
        return -((*this)*(-m));
    if (m>100000)
        return (*this)*bigint(m);
    bigint c;
    c.length=length+2;
    c.oper=oper;
    int t=0;
    for (int i=1;i<=c.length;i++)
        c.a[i]=(t=(t/10000+a[i]*m))%10000;
    c.check();
    return c;
}

bigint bigint::operator/(bigint m)
{
    if (m.length==0)
    {
        printf("Division by zero.\n");
        exit(0);
    }
    if (abs(*this)<abs(m))
        return 0;
    bigint c,left;
    c.oper=oper/m.oper;
    m.oper=1;
    c.length=length-m.length+1;
    left.length=m.length-1;
    memcpy(left.a+1,a+length-left.length+1,left.length*sizeof(int));
    for(int i=c.length;i>=1;i--)
    {
        left=left*10000+a[i];
        int head=0,tail=10000,mid;
        while (head+1<tail)
        {
            mid=(head+tail)/2;
            if (m*mid<=left)
                head=mid;
            else
                tail=mid;
        }
        c.a[i]=head;
        left-=m*head;
    }
    c.check();
    return c;
}

bigint bigint::operator/(int m)
{
    if (m<0)
        return -((*this)/(-m));
    if (m>100000)
        return (*this)/bigint(m);
    bigint c;
    c.oper=oper;
    c.length=length;
    int t=0;
    for (int i=c.length;i>=1;i--)
        c.a[i]=(t=(t%m*10000+a[i]))/m;
    c.check();
    return c;
}

bigint bigint::operator %(bigint m)
{
    return (*this)-((*this)/m)*m;
}

bigint bigint::operator%(int m)
{
    if (m<0)
        return -((*this)%(-m));
    if (m>100000)
        return (*this)%bigint(m);
    int t=0;
    for (int i=length;i>=1;i--)
        t=(t*10000+a[i])%m;
    return t;
}

bigint sqr(bigint m)
{
    return m*m;
}

bigint sqrt(bigint m)
{
    if (m.oper<0 || m.length==0)
        return 0;
    bigint c,last,now,templast;
    c.length=(m.length+1)/2;
    c.a[c.length]=int(sqrt((double)m.a[c.length*2]*10000+m.a[c.length*2-1])+1e-6);
    templast.length=c.length*2;
    templast.a[c.length*2-1]=(c.a[c.length]*c.a[c.length])%10000;
    templast.a[c.length*2]=(c.a[c.length]*c.a[c.length])/10000;
    templast.check();
    for (int i=c.length-1;i>=1;i--)
    {
        last=templast;
        int head=0,tail=10000,mid,j,temp;
        while (head+1<tail)
        {
            mid=(head+tail)/2;
            now=last;
            now.a[2*i-1]+=mid*mid;
            for (j=i+1;j<=c.length;j++)
                now.a[i+j-1]+=mid*c.a[j]*2;
            now.length++;
            for (j=2*i-1,temp=0;j<=now.length;j++)
                now.a[j]=(temp=(temp/10000+now.a[j]))%10000;
            now.check();
            if (now<=m)
            {
                templast=now;
                head=mid;
            }
            else
                tail=mid;
        }
        c.a[i]=head;
    }
    c.check();
    return c;
}

bigint gcd(bigint a,bigint b)
{
    return (b==0)?a:gcd(b,a%b);
}

bigint lcm(bigint a,bigint b)
{
    return a*b/gcd(a,b);
}

void bigint::operator+=(bigint m)
{
    (*this)=(*this)+m;
}

void bigint::operator-=(bigint m)
{
    (*this)=(*this)-m;
}

void bigint::operator*=(bigint m)
{
    (*this)=(*this)*m;
}

void bigint::operator/=(bigint m)
{
    (*this)=(*this)/m;
}

void bigint::operator%=(bigint m)
{
    (*this)=(*this)%m;
}

void bigint::operator*=(int m)
{
    (*this)=(*this)*m;
}

void bigint::operator/=(int m)
{
    (*this)=(*this)/m;
}

void bigint::operator%=(int m)
{
    (*this)=(*this)%m;
}

std::ostream& operator<<(std::ostream& result, const bigint& a) //输出
{
    write(a);
    return result;
}

std::istream& operator>>(std::istream& result, bigint& a) //输入
{
    read(a);
    return result;
}
//END OF BIGINT

int least[520] = {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10,10,10,10,11,11,11,11,11,11,11,11,11,12,12,12,12,12,12,12,12,13,13,13,13,13,13,13,14,14,14,14,14,14,15,15,15,15,15,15,15,16,16,16,16,16,17,17,17,17,17,17,18,18,18,18,18,19,19,19,19,19,20,20,20,20,20,21,21,21,21,21,22,22,22,22,23,23,23,23,24,24,24,24,25,25,25,25,26,26,26,26,27,27,27,28,28,28,28,29,29,29,30,30,30,31,31,31,32,32,32,33,33,33,34,34,34,35,35,35,36,36,36,37,37,38,38,38,39,39,40,40,40,41,41,42,42,43,43,43,44,44,45,45,46,46,47,47,48,48,49,49,50,50,51,51,52,52,53,53,54,54,55,55,56,57,57,58,58,59,60,60,61,61,62,63,63,64,65,65,66,67,67,68,69,69,70,71,71,72,73,74,74,75,76,77,77,78,79,80,81,81,82,83,84,85,86,87,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,113,114,115,116,117,118,120,121,122,123,125,126,127,128,130,131,132,134,135,136,138,139,141,142,143,145,146,148,149,151,152,154,155,157,159,160,162,163,165,167,168,170,172,174,175,177,179,181,183,184,186,188,190,192,194,196,198,200,202,204,206,208,210,212,214,217,219,221,223,226,228,230,232,235,237,240,242,244,247,249,252,254,257,260,262,265,267,270,273};//储存最小块数

void solve()
{
    int start = 1;
    int cardcount = 1;
    Fraction<bigint> current(100, 2);
    while(cardcount <= 273)
    {
        while(current >= start)
        {
            least[start] = cardcount;
            start++;
        }
        cardcount++;
        Fraction<bigint> now(100, cardcount+1);
        current = current + now;
        for(;start <  100/(cardcount+1); start++)
        {
            least[start] = cardcount;
        }
    }
}

int main()
{
//    solve();
    string s;
    while(cin>>s)
    {
        if(s == "0.00")
            break;
        int m = (s[0]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');
        cout<<least[m]<<" card(s)"<<endl;
    }
    return 0;
}
