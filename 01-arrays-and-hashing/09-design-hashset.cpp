class MyHashSet {
private:
    int numBuckets;
    vector<list<int>> buckets;

    int hash(int key) {
        return key % numBuckets;
    }

public:
    MyHashSet() {
        numBuckets = 1001;
        buckets.resize(numBuckets);
    }
    
    void add(int key) {
        int idx = hash(key);
        auto it = find(buckets[idx].begin(), buckets[idx].end(), key);
        if (it == buckets[idx].end()) {
            buckets[idx].push_back(key);
        }
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto it = find(buckets[idx].begin(), buckets[idx].end(), key);
        if (it != buckets[idx].end()) {
            buckets[idx].erase(it);
        }
    }
    
    bool contains(int key) {
        int idx = hash(key);
        auto it = find(buckets[idx].begin(), buckets[idx].end(), key);
        return it != buckets[idx].end();   
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */