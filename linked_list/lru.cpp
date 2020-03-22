#include<bits/stdc++.h>
int s;
list<int> lru;
unordered_map<int,list<int>::iterator> mp;    // key and its iterator (address)
unordered_map<int,int> kv;                    // key and its value
LRUCache::LRUCache(int capacity) {
    s = capacity;
    mp.clear();
    kv.clear();
    lru.clear();
}
void updateLRU(int key)
{
    // if its already there, move it and push front of LRU
    if(kv.count(key))
        lru.erase(mp[key]);
    lru.push_front(key);

    // update the new iterator for that node
    mp[key] = lru.begin();

}
void evict(){
    // remove the last node from everywhere
    mp.erase(lru.back());
    kv.erase(lru.back());
    lru.pop_back();
}
int LRUCache::get(int key) {
   if( kv.count(key)==0 ) return -1;
   // if refernced, update LRU
   updateLRU(key);
   return kv[key];
}

void LRUCache::set(int key, int value) {
    // eviction policy
    if( kv.size()== s and kv.count(key)==0 )
        evict();
    
    updateLRU(key);
    kv[key] = value;
}

