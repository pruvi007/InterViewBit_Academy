#include<bits/stdc++.h>
using namespace std;




int swaps(char *s)
{
	vector<int> f(26);
	int n = strlen(s);

	for(int i=0; i<n; i++){
		f[s[i]-'a']++;
	}

	int even = 0, odd = 0;
	for(int i=0; i<26; i++){
		if(f[i] != 0){
			if( f[i] % 2 == 0 ) even++;
			else odd++;
		}
	}

	//cout << n << " " << odd << " " << even << endl;

	if(n%2 == 0 && odd != 0){
		return -1;
	}
	else if(n%2 != 0 && odd > 1){
		return -1;
	}
	else {

		int i=0, j=n-1;
		int ans = 0;

		while(i < j){

			if(s[i] == s[j]){
				i++;
				j--;
				continue;
			}
			else {

				int k = j;
				while(k > i && s[k] != s[i]){
					k--;
				}

				while(k < j){
					swap(s[k], s[k+1]);
					ans++;
					k++;
				}

				i++;
				j--;

			}
		}

		return ans;
	}
}

int main(){
	char s[100005];
	cin >> s;
	cout << s << '\n';
	int ans = swaps(s);
	cout << ans << '\n';

}