/*
	GRID ILLUMINATION

	You are given an integer A. On a A x A grid of cells, each cell (x, y) with 0 <= x < A and 0 <= y < A has a lamp. 
	Initially, some number of lamps are on. B[i] tells us the location of the i-th lamp that is on. Each lamp that is on 
	illuminates every square on its x-axis, y-axis, and both diagonals (similar to a Queen in chess). 
	For the i-th query C[i] = (x, y), the answer to the query is 1 if the cell (x, y) is illuminated, else 0. 
	After each query (x, y) [in the order given by queries], 
	we turn off any lamps that are at cell (x, y) or are adjacent 8-directionally (ie., share a corner or edge with cell (x, y).)
*/	

/*
	Approach to hash the diagonals. Along Maj. Diagnoal -> Diff is constant ; and along Minor Diagonal ->Sum is constant.
	So hash that constants
*/

// solution by @pruvi007


#include<bits/stdc++.h>
using namespace std;
int main()
{
	int A;
	cin>>A;
	int b;
	cin>>b;
	vector<pair<int,int> > L;
	map<int,int> r,c,M,m;
	map<pair<int,int>,int> lamp;

	for(int i=0;i<b;i++)
	{
		int x,y;
		cin>>x>>y;
		L.push_back({x,y});

		if(lamp.find({x,y})==lamp.end())
		{
			lamp[{x,y}] = 1;
			r[x]++ ;	//mark the row to make it illuminated
			c[y]++;		//mark the column to make it illuminated
			M[x-y]++;	//mark the diff to make major diagonal illuminated
			m[x+y]++;	//mark the sum to make minor diagonal illuminated
		}
		
	}

	
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int glow = (r[x]>0) || (c[y]>0) || (M[x-y]>0) || (m[x+y]>0) ;
		cout<<glow<<endl;

		// now remove any lamp which is in any adjacent cell. 8 cells to check
		if(lamp[{x,y}]==1)
		{
			cout<<"found and removed\n";
			lamp[{x,y}] = 0;
			r[x]--;
			c[y]--;
			M[x-y]--;
			m[x+y]--;

		}
		if(lamp[{x,y+1}]==1)
		{
			cout<<"found and removed\n";
			lamp[{x,y+1}] = 0;
			r[x]--;
			c[y+1]--;
			M[x-(y+1)]--;
			m[x+y+1]--;
			
		}
		if(lamp[{x+1,y}]==1)
		{
			cout<<"found and removed\n";
			lamp[{x+1,y}] = 0;
			r[x+1]--;
			c[y]--;
			M[x+1-y]--;
			m[x+1+y]--;
			
		}
		if(lamp[{x,y-1}]==1)
		{
			cout<<"found and removed\n";
			lamp[{x,y-1}] = 0;
			r[x]--;
			c[y-1]--;
			M[x-(y-1)]--;
			m[x+y-1]--;
			
		}
		if(lamp[{x-1,y}] ==1)
		{
			cout<<"found and removed\n";
			lamp[{x-1,y}] = 0;
			r[x-1]--;
			c[y]--;
			M[x-1-y]--;
			m[x-1+y]--;
			
		}
		if(lamp[{x+1,y+1}]==1)
		{
			cout<<"found and removed\n";
			lamp[{x+1,y+1}] = 0;
			r[x+1]--;
			c[y+1]--;
			M[x+1-(y+1)]--;
			m[x+y+2]--;
			
		}
		if(lamp[{x-1,y+1}]==1)
		{
			cout<<"found and removed\n";
			lamp[{x-1,y+1}] = 0;
			r[x-1]--;
			c[y+1]--;
			M[x-1-(y+1)]--;
			m[x-1+y+1]--;
			
		}
		if(lamp[{x-1,y-1}]==1)
		{
			cout<<"found and removed\n";
			lamp[{x-1,y-1}] = 0;
			r[x-1]--;
			c[y-1]--;
			M[x-1-(y-1)]--;
			m[x-1+y-1]--;
			
		}
		if(lamp[{x+1,y-1}]==1)
		{
			cout<<"found and removed\n";
			lamp[{x+1,y-1}] = 0;
			r[x+1]--;
			c[y-1]--;
			M[x+1-(y-1)]--;
			m[x+1+y-1]--;
			
		}

	}

}