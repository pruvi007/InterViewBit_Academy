// C++ program to build the smallest number by removing n digits from 
// a given number 
#include<iostream> 
using namespace std; 

// A recursive function that removes 'n' characters from 'str' 
// to store the smallest possible number in 'res' 
void buildLowestNumberRec(string str, int n, string &res) 
{ 
	// If there are 0 characters to remove from str, 
	// append everything to result 
	if (n == 0) 
	{ 
		res.append(str); 
		return; 
	} 

	int len = str.length(); 

	// If there are more characters to remove than string 
	// length, then append nothing to result 
	if (len <= n) 
		return; 

	// Find the smallest character among first (n+1) characters 
	// of str. 
	int minIndex = 0; 
	for (int i = 1; i<=n ; i++) 
		if (str[i] < str[minIndex]) 
			minIndex = i; 

	// Append the smallest character to result 
	res.push_back(str[minIndex]); 

	// substring starting from minIndex+1 to str.length() - 1. 
	string new_str = str.substr(minIndex+1, len-minIndex); 

	// Recur for the above substring and n equals to n-minIndex 
	buildLowestNumberRec(new_str, n-minIndex, res); 
} 

// A wrapper over buildLowestNumberRec() 
string buildLowestNumber(string str, int n) 
{ 
	string res = ""; 

	// Note that result is passed by reference 
	buildLowestNumberRec(str, n, res); 

	return res; 
} 

// Driver program to test above function 
int main() 
{ 
	string str = "15423"; 
	int n = 2; 
	cout << buildLowestNumber(str, n); 
	return 0; 
} 