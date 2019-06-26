/*
	BOX STACKING PROBLEM
	Stack the boxes on top of each other to create a tall structure
	U can use same box multiple time(i.e with diff conf ovio)
	idea: create 6 configuration of same box then sort them according to volume then apply Longest increasing subsequence;
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;


bool comp(vector<int> &a,vector<int> &b)
{
	int a1 = a[1] * a[2];
	int a2 = b[1] * b[2];
	return a1>a2;
}


int main()
{
	int n;
	cin >> n;
	vector<vector<int> > b(6*n);
	int c = 0;
	for(int i=0;i<n;i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		b[c] = vector<int>(3);
		b[c][0] = x;
		b[c][1] = y;
		b[c][2] = z;
		b[c+1] = vector<int>(3);
		b[c+1][0] = x;
		b[c+1][1] =z;
		b[c+1][2] = y;

		b[c+2] = vector<int>(3);
		b[c+2][0] = y;
		b[c+2][1] = x;
		b[c+2][2] = z;
		b[c+3] = vector<int>(3);
		b[c+3][0] = y;
		b[c+3][1] = z;
		b[c+3][2] = x;

		b[c+4] = vector<int>(3);
		b[c+4][0] = z;
		b[c+4][1] = x;
		b[c+4][2] = y;
		b[c+5] = vector<int>(3);
		b[c+5][0] = z;
		b[c+5][1] = y;
		b[c+5][2] = x;
		
		c+=6;

	}
	
	// sort the boxes in decreasing base area
	sort(b.begin(),b.end(),comp);

	for(int i=0;i<b.size();i++)
	{
		cout << b[i][0] << " " << b[i][1] << " " << b[i][2] << ": " << b[i][1]*b[i][2] << endl;
	}
	// now find the increasing subsequence
	
	vector<vector<pair<int,pair<int,int> > > > L(6*n);
	L[0].push_back({b[0][0],{b[0][1],b[0][2]}});

	int msh[6*n];
	for(int i=0;i<6*n;i++)
		msh[i] = b[i][0];

	for(int i=1;i<6*n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(b[j][1] > b[i][1] && b[j][2] > b[i][2] && L[i].size() < L[j].size()+1)
			{
				L[i] = L[j];
			}
			if(b[j][1] > b[i][1] && b[j][2] > b[i][2])
				msh[i] = max(msh[i],b[i][0]+msh[j]);
		}
		L[i].push_back({b[i][0],{b[i][1],b[i][2]}});
	}

	vector<pair<int,pair<int,int> > > mLIS;
	mLIS = L[0];
	for(int i=0;i<L.size();i++)
	{
		if(mLIS.size() < L[i].size())
			mLIS = L[i];
	}

	// printintg the seleted boxes (imp method to get LIS among any sequence)
	for(int i=0;i<mLIS.size();i++)
	{
		cout << mLIS[i].first << "-" << mLIS[i].second.first << "-" << mLIS[i].second.second << endl;
	}
	cout << endl;
	cout << *max_element(msh,msh+6*n) << endl;
}