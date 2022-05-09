class MyHashMap
{
public:
    vector<long long> hash;

    MyHashMap()
    {
        hash.resize(10000000, -1);
    }

    void put(int key, int value)
    {
        hash[key] = value;
    }

    int get(int key)
    {
        return hash[key];
    }

    void remove(int key)
    {
        hash[key] = -1;
    }
};