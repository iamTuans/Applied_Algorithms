//C++ 
#include <bits/stdc++.h> 
using namespace std;
int n;
#define max 100
int appear[max];
int cap;
int load = 0;
int c[2*max+1][2*max+1];
int cmin = 9999999;
int x[max];
int f;
int f_best;

int check(int v, int k)
{
	if(appear[v] == 1)
	{
		return 0;
	}
	if(v > n)
	{
		if(!appear[v-n])
		{
			return 0;
		}
	}
	else
	{
		if(load + 1 > cap)
		{
			return 0;
		}
	}
	return 1;
}
void solution()
{
	if(f + c[x[2*n]][0] < f_best)
	{
		f_best = f + c[x[2*n]][0];
	}
}
void TRY(int k)
{
	for(int v = 1; v <= 2*n; v++)
	{		
		if(check(v, k))
		{			
			x[k] = v;
			f += c[x[k-1]][x[k]];
			if(v <= n)
			{
				load+=1;
			}
			else
			{
				load -= 1;
			}
			appear[v] = 1;
			if(k == 2*n)
			{
				solution();
			}
			else
			{
				if(f + cmin*(2*n+1-k) < f_best)
				{
					TRY(k+1);
				}
			}
			if(v <= n)
			{
				load -= 1;
			}
			else
			{
				load += 1;
			}
			appear[v] = 0;
			f -= c[x[k-1]][x[k]];
		}
	}
}
int main()
{
	cin>>n>>cap;
	for(int i = 0; i < 2*n + 1 ; i++)
	{
		for(int j = 0; j < 2*n + 1; j++)
		{
			cin>>c[i][j];
			if(c[i][j] < cmin && c[i][j] > 0)
			{
				cmin = c[i][j];
			}
		}
		cout<<endl;
		appear[i] = 0;
		//appear[i+n] = 0;
	}
	load = 0;
	f = 0;
	f_best = 1000000;
	x[0] = 0;
	TRY(1);
	cout<<f_best;
	return 0;
}
