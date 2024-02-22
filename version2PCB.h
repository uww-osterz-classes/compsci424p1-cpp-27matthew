#ifndef VERSION2PCB_H
#define VERSION2PCB_H

using namespace std;

class Version2PCB {
private:
    int parent, first_child, younger_sibling, older_sibling;
    
public:
    Version2PCB(int parent) : parent(parent) {
        first_child = -1;
        younger_sibling = -1;
        older_sibling = -1;
    }

    int getParent() const {
        return parent;
    }

    int getFirstChild(){
        return first_child;
    }

    int getYoungerSibling(){
        return younger_sibling;
    }

    int getOlderSibling(){
        return older_sibling;
    }

    void setFirstChild(int child){
        first_child = child;
    }

    void setYoungerSibling(int sibling){
        younger_sibling = sibling;
    }

    void setOlderSibling(int sibling){
        older_sibling = sibling;
    }

};

#endif  // VERSION1PCB_H
