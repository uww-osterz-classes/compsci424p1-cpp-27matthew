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

    int get_first_child(){
        return first_child;
    }

    int get_younger_sibling(){
        return younger_sibling;
    }

    int get_older_sibling(){
        return older_sibling;
    }

    void set_first_child(int child){
        first_child = child;
    }

    void set_younger_sibling(int sibling){
        younger_sibling = sibling;
    }

    void set_older_sibling(int sibling){
        older_sibling = sibling;
    }

    void addChild(int child){
        if(first_child == -1){
            first_child = child;
        }
        else{
            int last_child = first_child;
            while(Version2PCB(last_child).get_younger_sibling() != -1){
                last_child = Version2PCB(last_child).get_younger_sibling();
            }

            Version2PCB(last_child).set_younger_sibling(child);
            Version2PCB(child).set_older_sibling(last_child);
        }
    }

    
};

#endif  // VERSION1PCB_H
