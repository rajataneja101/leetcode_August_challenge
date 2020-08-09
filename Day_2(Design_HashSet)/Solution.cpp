class MyHashSet {
public:
    /** Initialize your data structure here. */
    bool myHashSet[100000] ={false};
    MyHashSet() {
        
    }
    
    void add(int key) {
        myHashSet[key]=true;
    }
    
    void remove(int key) {
        myHashSet[key]=false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return myHashSet[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */