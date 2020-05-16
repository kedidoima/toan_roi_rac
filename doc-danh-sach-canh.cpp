#include <iostream>
using namespace std;
#define nmax 101
#define mmax 1001

int x[mmax],y[mmax],head[nmax+1],adj[mmax*2+1],st[mmax],en[mmax],a[nmax+1][nmax+1],b[nmax+1][nmax+1];
int n,m;
void mtk();
void dsk();
void init();

int main()
{
    //doc vao la danh sach canh
    init();
    dsk();
}

void init()
{
    cin >> n >> m; // doc vao do thi n dinh, m canh
    for (int i=1; i<=m; i++) 
        cin >> st[i] >> en[i]; // doc m canh gom đỉnh bắt đầu st[i] và đỉnh kết thúc en[i] 
}

void mtk(){
    // khởi tạo ma trận a = 0
    for (int i=1; i<=n; i++) 
        for (int j=1; j<=n; j++) a[i][j]=0;
    // tạo ma trận kề
    for (int i=1; i<=m; i++)
    {
        a[st[i]][en[i]]=1; 
        a[en[i]][st[i]]=1; // có nếu là ma trận vô hướng - không có nếu có hướng
    }
    // xuất ra ma trận kề
    cout << n << endl;
    for (int i=1; i<=n; i++) 
    {
        for (int j=1; j<=n; j++) cout << a[i][j] << " " ;
        cout << endl;
    }
}

void dsk(){
    for (int i=0; i<=n+1; i++) head[i]=0; 
    // tạo mảng vị trí đầu cuối của mỗi đỉnh
    for (int i=1; i<=m; i++) 
    {
        head[st[i]]++;
        head[en[i]]++;
    }
    for (int i=2; i<=n+1; i++) head[i]=head[i-1]+head[i]; 
    // tạo danh sách kề
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) b[i][j]=a[i][j];// tạo ma trận b = ma trận a

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            if (b[i][j]){
                adj[head[i]]=j; // gan j vao danh sach ke dinh i
                adj[head[j]]=i; // gan i vao danh sach ke dinh j
                head[i]--; head[j]--;
                b[i][j]=0; b[j][i]=0;
            }
    for (int i=1; i<=m; i++)
    {
        adj[head[st[i]]]=i; head[st[i]]--;
        adj[head[en[i]]]=i; head[en[i]]--;
    }
    head[n+1]=2*m;
    // xuat ra danh sach ke
    cout << n << endl;
    for (int u=1; u<=n; u++)
    {
        cout << "ke (" << u << "):";
        for (int v=head[u]+1; v<=head[u+1]; v++) cout << adj[v] << " ";
        cout << endl;
    }
}