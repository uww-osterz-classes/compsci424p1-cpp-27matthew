#ifndef VERSION2PCB_H
#define VERSION2PCB_H

using namespace std;

class Version2PCB {
private:
    int parent, first_child, younger_sibling, older_sibling;
    
public:
    Version2PCB(int parent) : parent(parent) {}

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

    void addChild(int child){
        if(first_child == -1){
            first_child = child;
        }
        else{
            int last_child = first_child;
            while(Version2PCB(last_child).getYoungerSibling() != -1){
                last_child = Version2PCB(last_child).getYoungerSibling();
            }

            Version2PCB(last_child).setYoungerSibling(child);
            Version2PCB(child).setOlderSibling(last_child);
        }
    }

    
};

#endif  // VERSION1PCB_H
