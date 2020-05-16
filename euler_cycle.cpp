#include <iostream>
using namespace std;
int main(){
    int a[100][100],n,st[100],ce[100],top,m,u;
    /*cin >> n >> u; 
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) cin >> a[i][j];
    }*/
    for (int i=0; i<100; i++) 
        for (int j=0; j<100; j++) a[i][j]=0;
    for (int i=1; i<=13; i++){
        cin >> n;
        for (int j=1; j<=n; j++) 
        {
            cin >> u;
            a[i][u]=1; 
        }
    }
    n=13; u=6;
    top=0; m=0;
    top++; st[top]=u;
    while (top>0){
        int s=st[top];
        int t=-1;
        for (int i=1; i<=13; i++){
            if (a[s][i]==1){
                t=i;
                top++; st[top]=t;
                a[s][t]=0; a[t][s]=0;
                
                break;
            }
        }
        if (t==-1){
            m++; ce[m]=s;
            top--;
        }
        for (int j=1; j<=top; j++) cout << st[j] << " ";
        cout << "|";
        for (int j=1; j<=m; j++) cout << ce[j] << " ";
        cout << endl;
    }
    for (int i=m; i>0; i--) cout << ce[i] << " ";
}