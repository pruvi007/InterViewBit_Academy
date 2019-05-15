// check if partially filled SUDOKU is valid or not
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	n=9;m=9;

	char a[9][9]; /*= { { '5', '3', '.', '.', '7', '.', '.', '.', '.' }, 
                     { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, 
                     { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, 
                     { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, 
                     { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, 
                     { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, 
                     { '.', '1', '.', '.', '.', '.', '2', '8', '.' }, 
                     { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, 
                     { '.', '.', '.', '.', '8', '.', '.', '7', '9' } }; */
    for(int i=0;i<9;i++)
    {
    	for(int j=0;j<9;j++)
    		cin>>a[i][j];
    }
	
	map<char,int> r,c;
	
	int valid=0;
	for(int i=0;i<n;i++)
	{
		int flag=0;
		for(int j=0;j<m;j++)
		{
			if(a[i][j]!='.')
			{
				r[a[i][j]]++;
				if(r[a[i][j]]>1)
				{
					flag=1;
					break;
				}

			}
		}
		for(int j=0;j<m;j++)
		{
			if(a[j][i]!='.')
			{
				c[a[j][i]]++;
				if(c[a[j][i]]>1)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
		{
			valid=1;
			break;
		}
		r.clear();
		c.clear();
	}
	if(valid)
		cout<<"NOT VALID\n";
	else cout<<"VALID\n";

}