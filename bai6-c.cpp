#include <iostream>
using namespace std;
int n,a[20][20],fr[20],qu[20];

void dfs(int u)
{
    cout << u << " " ;
    fr[u]=0;
    for (int v=1; v<=n; v++)
        if (a[u][v] && fr[v]) dfs(v);
}

void bfs(int u)
{
    int l=0,r=0;
    r++; qu[r]=u;
    fr[u]=0;
    while (l<r)
    {
        l++;
        u=qu[l];
        cout << u << " ";
        for (int v=1; v<=n; v++)
            if (a[u][v] && fr[v])
            {
                r++; qu[r]=v;
                fr[v]=0;
            }
    }
}

int main()
{
    n=13;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) cin >> a[i][j];
    for (int j=1; j<=n; j++) fr[j]=1;
    fr[1]=0;
        dfs(2);
        cout << endl;
    for (int i=2; i<=n; i++)
    {
        for (int j=1; j<=n; j++) fr[j]=1;
        fr[i]=0;
        dfs(1);
        cout << endl;
    }
}