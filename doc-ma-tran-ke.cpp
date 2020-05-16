#include <iostream>
using namespace std;
#define nmax 101
#define mmax 1001

int x[mmax],y[mmax],head[nmax+1],adj[mmax*2+1],st[mmax],en[mmax],a[nmax+1][nmax+1],b[nmax+1][nmax+1];
int n,m;
void dsc();
void dsk();
void init();

int main()
{
    //doc vao la ma tran ke
    init();
    dsc();
}

void init()
{
    cin >> n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) cin >> a[i][j]; //doc ma tran ke
}

void dsc(){
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) b[i][j]=a[i][j];// gan lai ma tran a

    m=0; // khởi tạo số cạnh = 0
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (b[i][j]){// neu i j ke nhau thi b[i][j]=1
                m++; // tang so canh
                st[m]=i; // gan dinh dau = i
                en[m]=j; // gan dinh cuoi = j
                b[i][j]=0; b[j][i]=0; // bo danh dau (i-j) (j-i) tren ma tran b
            }
    cout << n << m << endl;
    for (int i=1; i<=m; i++) cout << st[i] << " " << en[i] << endl;
}

void dsk(){
    for (int i=0; i<=n+1; i++) head[i]=0; 
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) b[i][j]=a[i][j];// gan lai ma tran a
    // tao mang vi tri cuoi cua moi dinh
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (b[i][j]){
                head[i]++; head[j]++;
                b[i][j]=0; b[j][i]=0;
            }
    for (int i=2; i<=n+1; i++) head[i]=head[i-1]+head[i]; 
    // tao danh sach ke
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) b[i][j]=a[i][j];// gan lai ma tran a
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (b[i][j]){
                adj[head[i]]=j; // gan j vao danh sach ke dinh i
                adj[head[j]]=i; // gan i vao danh sach ke dinh j
                head[i]--; head[j]--;
                b[i][j]=0; b[j][i]=0;
            }
    // xuat ra danh sach ke
    cout << n << endl;
    for (int u=1; u<=n; u++)
    {
        cout << "ke (" << u << "):";
        for (int v=head[u]+1; v<=head[u+1]; v++) cout << adj[v] << " ";
        cout << endl;
    }
}