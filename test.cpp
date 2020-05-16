#include<bits/stdc++.h>
using namespace std;
 
int n;
int g[100][100],path[100];
bool ok[100];
 
void nhap()
{
	ifstream fi;
	fi.open("graph.txt",ios::in);
	fi>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) fi>>g[i][j];
	fi.close();
}
 
void xuat()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++) cout<<g[i][j]<<" ";
		cout<<"\n";
	}
}
 
void khoitao()
{
	for (int i=1;i<=n;i++) 
	{
		ok[i]=true;
		path[i]=0;
	}
}
 
void dfs(int u)
{
	cout<<u<<" ";
	ok[u]=false;
	for (int i=1;i<=n;i++)
		if (ok[i] && g[i][u]==1)
			dfs(i);
}
 
void dfs_st(int u)
{
	stack <int> a;
	a.push(u);
	ok[u]=false;
	while(!a.empty())
	{
		int s=a.top();
		a.pop();
		//cout << s << " ";
		for (int i=1;i<=n;i++)
			if (ok[i] && g[i][s]==1)
			{
				ok[i]=false;
				a.push(s);
				a.push(i);
				path[i]=s;
				break;
			}	
	}
	cout<<"\n";
}
 
void bfs(int u)
{
	queue <int> a;
	a.push(u);
	ok[u]=false;
	while(!a.empty())
	{
		int s=a.front();
		a.pop();
		cout<<s<<" ";
		for (int i=1;i<=n;i++)
			if (ok[i] && g[i][s]==1)
			{
				a.push(i);
				ok[i]=false;
				path[i]=s;
			}
	}
}
 
void demtplt()
{
	int dem=0;
	for (int i=1;i<=n;i++)
		if (ok[i])
		{
			dem++;
			dfs_st(i);
			cout<<"\n";
		}
	cout<<"So thanh phan lien thong: "<<dem;
}
 
void road(int s,int t)
{
	if (path[t]==0) cout<<"No path from s to t";
	else
	{
		cout<<t<<" ";
		int u=path[t];
		while(u!=s)
		{
			cout<<u<<" ";
			u=path[u];
		}
		cout<<s<<"\n";
	}
}
 
bool lt()
{
	for (int i=1;i<=n;i++)
		if (ok[i]==true) return false;
	return true;
}
 
bool lt_manh()
{
	khoitao();
	for (int i=1;i<=n;i++)
	{
		dfs_st(i);
		if (lt()==false) return false; 
		khoitao();
	}
	return true;
}
 
void tru()
{
	cout<<"Dinh tru: ";
	khoitao();
	for (int i=1;i<=n;i++)
	{
		ok[i]=false;
		if (i==1) dfs_st(2);
		dfs_st(1);
		if (lt()==true) cout<<i<<" ";
		khoitao();
	}
	cout<<"\n";
}
 
main()
{
	nhap();
	xuat();
	khoitao();
	//dfs(1);
	//dfs_st(1);
	//bfs(1);
	//demtplt();
	//road(1,4);
	//if (lt_manh()) cout<<"Lien thong manh";
	//else cout<<"Lien thong yeu";
	tru();
}