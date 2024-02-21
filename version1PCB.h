#ifndef VERSION1PCB_H
#define VERSION1PCB_H

#include <vector>
using namespace std;

class Version1PCB {
private:
    int parent;
    vector<int> children;

public:
    Version1PCB(int parent) : parent(parent) {}

    int getParent() const {
        return parent;
    }

    const vector<int>* getChildren() const {
        return &children;
    }

    void addChild(int child) {
        children.push_back(child);
    }

    void removeChild() {
        if (!children.empty()) {
            children.pop_back();
        }
    }
};

#endif  // VERSION1PCB_H
