/* COMPSCI 424 Program 1
   Name: Matthew Buske
   
   version1.h: contains the code to implement the process creation
   hierarchy for Version 1, which uses linked lists.

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

#ifndef VERSION1_H
#define VERSION1_H

// You may need to add more #include directives.
// Remember: use <angle brackets> for standard C++ headers/libraries
// and "double quotes" for headers in the same directory as this file.
#include <iostream>
#include "version1PCB.h"

using namespace std; // I normally use this, but feel free to delete it

const int MAX_SIZE_1 = 16;

class Version1 {
   private: // it's good OOP practice to make data members private
   Version1PCB** pcbArray;

   public:  // all methods are normally public
     Version1() { 
      /* Default constructor. Use this to allocate (if needed) and
      initialize the PCB array, create the PCB for process 0, and do
      any other initialization that is needed. 
      */ 
      pcbArray = new Version1PCB * [MAX_SIZE_1] {};
      pcbArray[0] = new Version1PCB(-1);
     }

     ~Version1() {
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
      if(pcbArray[parentPid] != NULL){
         for(int i = 0; i < MAX_SIZE_1; i++){
            if(pcbArray[i] == NULL){
               pcbArray[i] = new Version1PCB(parentPid);
               pcbArray[parentPid]->addChild(i);
               break;
            }
         }
      }

      // Assuming you've found the PCB for parentPid in the PCB array:
      // 1. Allocate and initialize a free PCB object from the array
      //    of PCB objects

      // 2. Insert the newly allocated PCB object into parentPid's
      //    list of children

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
      if(pcbArray[targetPid] != NULL){
        while(!pcbArray[targetPid]->getChildren()->empty()){
            destroy(pcbArray[targetPid]->getChildren()->front());
        }
        if(pcbArray[targetPid]->getParent() != -1){
            pcbArray[pcbArray[targetPid]->getParent()]->removeChild();
        }

        delete pcbArray[targetPid];
        pcbArray[targetPid] = NULL;
        
      }

        // create 0
        // create 1
        // destroy 1
        // destroy 2
        // end

      // Assuming you've found the PCB for targetPid in the PCB array:
      // 1. Recursively destroy all descendants of targetPid, if it
      //    has any, and mark their PCBs as "free" in the PCB array 
      //    (i.e., deallocate them)
      
      // 2. Remove targetPid from its parent's list of children

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
        for(int i = 0; i < MAX_SIZE_1; ++i){
            if(pcbArray[i] != nullptr){
                cout << "Process " << i << ": ";
                cout << "parent is " << pcbArray[i]->getParent() << " and ";

                auto children = pcbArray[i]->getChildren();
                if(!children->empty()){
                    cout << "children are ";
                    for(int child: *children){
                        cout << child << " ";
                    }
                }
                else{
                    cout << "has no children";
                }
                cout << endl;
            }
        }

     }

     /* If you need or want more functions, feel free to add them. */

};

#endif  // VERSION1_H
