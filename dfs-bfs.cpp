#include <iostream>
using namespace std;
int n,s,t,a[20][20],fr[20],qu[20],tr[20];

void dfs(int u)                       // dfs bằng đệ quy, stack đọc trong giáo trình :)
{
    cout << u << " ";                 // in ra các đỉnh đã thăm
    fr[u]=0;                          // gán đỉnh u đã thăm
    for (int v=1; v<=n; v++)
        if (a[u][v] && fr[v]) {       // nếu u đến được v và v chưa thăm
            tr[v]=u;                  // cái này dùng để truy xuất đường đi
            dfs(v);                   // thăm v
        }
}

void bfs(int u)
{
    int l=0,r=0;                      // khởi tạo queue rỗng (left,right là 2 chỉ số đầu cuối của queue)
    r++; qu[r]=u;                     // push u vào queue
    tr[u]=0;
    fr[u]=0;                          // gán u đã thăm
    while (l<r) {
        l++; u=qu[l];                 // gán u = queue.pop 
        cout << u << " ";
        for (int v=1; v<=n; v++)
            if (a[u][v] && fr[v]) {
                r++; qu[r]=v;         // push v vào queue
                tr[v]=u;
                fr[v]=0;
            }
    }
}

void duong_s_den_t (){
    int m=0,b[20];
    m++; b[m]=t;
    if (tr[t]==0) {
        cout << "Khong co duong di";
        return;
    }
    int u=tr[t];
    while (tr[u]!=0)
    {
        m++; b[m]=u;
        u=tr[u]; 
    }
    m++; b[m]=s;
    for (int i=m; i>0; i--) cout << b[i] << " " ;
}

int main()
{
    // đọc ma trận nxn, đỉnh s và t
    cin >> n >> s >> t;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) cin >> a[i][j];

    for (int j=1; j<=n; j++) fr[j]=1; // khởi tạo mảng chưa thăm
    tr[s]=0;
    
    dfs(s);
}