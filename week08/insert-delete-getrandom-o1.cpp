// TC: O(1)
// SC: O(N)
class RandomizedSet {
private:
    vector<int> vc;
    unordered_map<int,int> mp;
public:
    
    RandomizedSet() {}
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        
        vc.push_back(val);
        mp[val] = vc.size() - 1;
        
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        
        int last = vc.back();  
        vc[mp[val]] = vc.back();
        vc.pop_back();
        mp[last] = mp[val];	  
        mp.erase(val);
        
        return true;
    }

    int getRandom() {
        return vc[rand() % vc.size()];
    }
};