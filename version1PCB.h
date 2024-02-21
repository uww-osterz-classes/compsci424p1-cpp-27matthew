#ifndef VERSION1PCB_H
#define VERSION1PCB_H

#include <vector>
#include <algorithm>
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

    void removeChild(int targetPid) {
        auto it = find(children.begin(), children.end(), targetPid);
        if (it != children.end()) {
            children.erase(it);
        }
    }
};

#endif  // VERSION1PCB_H
