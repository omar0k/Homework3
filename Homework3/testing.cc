#include <iostream>
#include <fstream>
#include <string>
#include "sequence_map.h"
#include "avl_tree.h"

int main()
{
    AvlTree<SequenceMap> a_tree;
    string recseq = "ABC";
    string enz = "wtf";
    SequenceMap SeqMap(recseq, enz);
    a_tree.insert(SeqMap);
    if (a_tree.contains(SeqMap))
    {
        cout << a_tree.find(SeqMap);
    }
    // a_tree.printTree();
}