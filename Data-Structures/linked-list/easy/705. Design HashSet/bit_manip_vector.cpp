#include <vector>

class MyHashSet {
private:
    std::vector<int> num;

    int getIdx(int key) const {
        return key / 32;
    }

    int getMask(int key) const {
        return 1 << (key % 32);
    }

public:
    MyHashSet() : num(31251, 0) {}

    void add(int key) {
        num[getIdx(key)] |= getMask(key);
    }

    void remove(int key) {
        num[getIdx(key)] &= ~getMask(key);
    }

    bool contains(int key) const {
        return (num[getIdx(key)] & getMask(key)) != 0;
    }
};