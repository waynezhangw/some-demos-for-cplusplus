#include <iostream>
#include <list>
#include <unordered_map>

using std::cout;
using std::endl;
using std::pair;
using std::make_pair;
using std::list;
using std::unordered_map;

class LRUCache {
private:
    int capacity;
    list< pair<int,int> > lruList;     // key, value pair
    unordered_map< int, list<pair<int,int>>::iterator > hash;   // key to <key,val> iterator map

    void moveToFront( int key, int value ) {
        // erase and add a new entry to front
        lruList.erase( hash[key] ); // this is O(1) since we are using iterator
        lruList.push_front( make_pair(key, value) );
        hash[key] = lruList.begin();
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int getHead() {
        return std::get<1>(lruList.front());
    }

    int getTail() {
        return std::get<1>(lruList.back());
    }

    void getAll() {
        cout << "all values:";
        for (list< pair<int,int> >::iterator it = lruList.begin(); it != lruList.end(); ++it){
            cout << ' ' << std::get<1>(*it);
        }
        cout << '\n';
    }
    
    int get(int key) {
        if( hash.find(key) == hash.end() )
            return -1;
        // move the key, value pair to front
        int value = (*hash[key]).second;
        moveToFront( key, value );
        return (*hash[key]).second;
    }
    
    void put(int key, int value) {
        if( hash.find(key) != hash.end() ) {
            // when key is already in hash
            moveToFront( key, value );
        } else {
            // add to the cache
            lruList.push_front( make_pair( key, value ) );
            hash[key] = lruList.begin();
            if( hash.size() > (unsigned)capacity ) {
                // erase
                hash.erase( lruList.back().first );
                lruList.pop_back();
            }
        }
    }
};

int main() {
    int n = 6;
    LRUCache lru(n);
    lru.put(1,1);
    lru.put(2,2);
    lru.put(3,3);
    lru.put(4,4);
    lru.put(5,5);
    lru.put(6,6);
    lru.getAll();

    cout << "head value:" << lru.getHead() << endl;
    cout << "tail value:" << lru.getTail() << endl;

    cout << "get value two:" << lru.get(2) << endl;
    lru.getAll();

    cout << "head value:" << lru.getHead() << endl;
    cout << "tail value:" << lru.getTail() << endl;

    cout << "adding two values: 99 and 88" << endl;
    lru.put(88,88);
    lru.put(99,99);
    lru.getAll();
    
    cout << "head value:" << lru.getHead() << endl;
    cout << "tail value:" << lru.getTail() << endl;
    return 0;
}