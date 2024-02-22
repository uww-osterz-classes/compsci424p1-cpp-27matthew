/* COMPSCI 424 Program 1
   Name:
   
   version2.h: contains the code to implement the process creation
   hierarchy for Version 2, which does not use linked lists.

   This is a template. Feel free to edit any of these files, even
   these pre-written comments or my provided code. You can add any
   classes, methods, and data structures that you need to solve the
   problem and display your solution in the correct format.

   C++ style note:
   This .h file is set up to include both declarations and code. It's 
   considered good practice for .h files to contain only declarations
   and for most or all non-declaration code to be in .cpp files (which
   #include the relevant .h file(s)). However, if you're not used to
   compiling and linking multiple .cpp (or .cc or .C) files at once, 
   putting both declarations and code in the .h files is easier. 
   
   If you prefer to separate your declarations and code, feel free to
   do that. GitHub Classroom is set up to compile all .cpp, .cc, and
   .C files that are in your repository.
*/

#ifndef VERSION2_H
#define VERSION2_H

// You may need to add more #include directives.
// Remember: use <angle brackets> for standard C++ headers/libraries
// and "double quotes" for headers in the same directory as this file.
#include <iostream>
#include "version2PCB.h"

using namespace std; // I normally use this, but feel free to delete it

const int MAX_SIZE_2 = 16;

class Version2 {
    private: // it's good OOP practice to make data members private
    Version2PCB** pcbArray;

   public:  // all methods are normally public
     Version2() { 
      /* Default constructor. Use this to allocate (if needed) and
      initialize the PCB array, create the PCB for process 0, and do
      any other initialization that is needed. 
      */ 
      pcbArray = new Version2PCB * [MAX_SIZE_2] {};
      pcbArray[0] = new Version2PCB(-1);
     }

     ~Version2() {
      /* Destructor. If you allocated anything with "new" during
      the lifetime of this object, and you haven't yet "delete"d
      it, "delete" it (using the "delete" keyword) here.
      */
     delete[] pcbArray;
     }

     /* Creates a new child process of process with ID parentPid. 
     */
     int create(int parentPid) {
      // If parentPid is not in the process hierarchy, do nothing; 
      // your code may return an error code or message in this case,
      // but it should not halt.
      
        if(pcbArray[parentPid] != 0){
            for(int i = 0; i < MAX_SIZE_2; i++){
                if(pcbArray[i] == 0){
                    pcbArray[i] = new Version2PCB(parentPid);
                    if(pcbArray[parentPid]->getFirstChild() == 0){
                        pcbArray[parentPid]->setFirstChild(i);
                    }
                    else{
                        int older = -1;
                        for(int j = 0; j < i; j++){
                            if(pcbArray[j]->getParent() == parentPid){
                                older = j;
                            }
                        }
                        pcbArray[i]->setOlderSibling(older);
                        pcbArray[older]->setYoungerSibling(i);
                    }
                    break;
                }
            }
        }
     
      // Assuming you've found the PCB for parentPid in the PCB array:
      // 1. Allocate and initialize a free PCB object from the array
      //    of PCB objects

      // 2. Connect the new PCB object to its parent, its older
      //    sibling (if any), and its younger sibling (if any)

      // You can decide what the return value(s), if any, should be.
      return 0; // often means "success" or "terminated normally"
     }

     

     /* Recursively destroys the process with ID parentPid and all of
        its descendant processes (child, grandchild, etc.).
     */
     int destroy(int targetPid) {
      // If targetPid is not in the process hierarchy, do nothing; 
      // your code may return an error code or message in this case,
      // but it should not halt

        if(pcbArray[targetPid] != 0){
            if(pcbArray[targetPid]->getFirstChild() != 0){
                if(pcbArray[pcbArray[targetPid]->getFirstChild()]->getYoungerSibling() != 0){
                    destroy(pcbArray[pcbArray[targetPid]->getFirstChild()]->getYoungerSibling());
                }
                destroy(pcbArray[targetPid]->getFirstChild());
                destroy(targetPid);
            }
            else{
                if(pcbArray[targetPid]->getOlderSibling() == 0 && pcbArray[targetPid]->getYoungerSibling() == 0){
                    pcbArray[pcbArray[targetPid]->getParent()]->setFirstChild(0);
                }
                else if(pcbArray[targetPid]->getOlderSibling() == 0 && pcbArray[targetPid]->getYoungerSibling() != 0){
                    pcbArray[pcbArray[targetPid]->getParent()]->setFirstChild(pcbArray[targetPid]->getYoungerSibling());
                    pcbArray[pcbArray[targetPid]->getYoungerSibling()]->setOlderSibling(0);
                }
                else if(pcbArray[targetPid]->getOlderSibling() != 0 && pcbArray[targetPid]->getYoungerSibling() == 0){
                    pcbArray[pcbArray[targetPid]->getOlderSibling()]->setYoungerSibling(0);
                }
                else if(pcbArray[targetPid]->getOlderSibling() != 0 && pcbArray[targetPid]->getYoungerSibling() != 0){
                    pcbArray[pcbArray[targetPid]->getOlderSibling()]->setYoungerSibling(pcbArray[targetPid]->getYoungerSibling());
                    pcbArray[pcbArray[targetPid]->getYoungerSibling()]->setOlderSibling(pcbArray[targetPid]->getOlderSibling());
                }
                delete pcbArray[targetPid];
                pcbArray[targetPid] = 0;
            }
        }
        
    

      // Assuming you've found the PCB for targetPid in the PCB array:
      // 1. Recursively destroy all descendants of targetPid, if it
      //    has any, and mark their PCBs as "free" in the PCB array 
      //    (i.e., deallocate them)
      
      // 2. Adjust connections within the hierarchy graph as needed to
      //    re-connect the graph

      // 3. Deallocate targetPid's PCB and mark its PCB array entry
      //    as "free"

      // You can decide what the return value(s), if any, should be.
      return 0; // often means "success" or "terminated normally"
     }

     /* Traverse the process creation hierarchy graph, printing
        information about each process as you go. See Canvas for the
        *required* output format. 
        
        You can directly use "cout" or "printf" statements to send
        the required output to stdout, or you can change the return
        type of this function to return the text to the main program
        for printing. It's your choice. 
     */
     void showProcessInfo() {
        for (int i = 0; i < MAX_SIZE_2; ++i) {
            if (pcbArray[i] != nullptr) {
                cout << "Process " << i << ": ";
                cout << "parent is " << pcbArray[i]->getParent() << " and ";
                int child = pcbArray[i]->getFirstChild();
                if (child != -1) {
                    cout << "children are ";
                    while (child != -1) {
                        cout << child << " ";
                        child = pcbArray[child]->getYoungerSibling();
                    }
                } else {
                    cout << "has no children";
                }
                cout << endl;
            }
        }

     }

     /* If you need or want more functions, feel free to add them. */

};

#endif  // VERSION2_H
