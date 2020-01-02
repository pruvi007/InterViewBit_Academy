#include<bits/stdc++.h>
using namespace std;

struct trie{
      bool end;
      map<char,trie *> child;
      trie(){
            this->end = false;
      }
};
trie *root = NULL;
void insert(string s)
{
      trie *cur;
      if(root == NULL)
            root = new trie();
      cur = root;
      for(int i=0;i<s.length();i++)
      {
            trie *next = cur->child[s[i]];
            if(next == NULL)
            {
                  next = new trie();
                  cur->child[s[i]] = next;
            }
      }
      cur->end = true;
}
vector<string> search(string s)
{
      trie *cur = root;
      vector<string> ans;
      for(int i=0;i<s.length();i++)
      {
            trie *next = cur->child[s[i]];
            if( next == NULL )
                  return ans;
            cur = next;
      }
      ans = cur->child;
      return ans;
}
int main(){
      int n;
      cin >> n;
      vector<string> product(n);
      for(int i=0;i<n;i++)
      {
            cin >> product[i];
            insert( product[i] );
      }

      string search;
      cin >> search;

}
