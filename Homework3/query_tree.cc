// <Your name>
// Main file for Part 2.1 of Homework 3.

#include "avl_tree.h"
// You will have to add #include "sequence_map.h"

#include "sequence_map.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

namespace
{

  // @dbx_filename: an input filename.
  // @a_tree: an input tree of the type TreeType. It is assumed to be
  //  empty.
  template <typename TreeType>
  void QueryTree(const string &dbx_filename, TreeType &a_tree)
  {
    // Code for running Part 2.1
    // You can use public functions of TreeType. For example:
    // SequenceMap first{"test", "test2"};
    // a_tree.insert(first);
    // a_tree.printTree();
    /**
     *
  @param dbx_filename is the database file where we get the strings from
  @param a_tree is the tree that we are building
  */
    vector<string> recognition_sequences;
    string db_line, an_enz_acro;
    ifstream openFile; //opening the file
    openFile.open(dbx_filename);
    if (openFile.fail())
    {
      std::cout << "File cannot be openned" << std::endl;
      exit(1);
    }

    //for loop to skip over the header of the file
    for (int i = 0; i < 10; i++)
    {
      getline(openFile, db_line);
      //cout << db_line;
    }

    while (getline(openFile, db_line))
    {
      string a_reco_seq;
      int positionFirstSlash = db_line.find('/');
      an_enz_acro = db_line.substr(0, positionFirstSlash);
      a_reco_seq = db_line.substr(positionFirstSlash + 1, db_line.find("//") - positionFirstSlash - 1);
      // cout << a_reco_seq << endl;
      if (!(a_reco_seq.empty()) && !(an_enz_acro.empty()))
      {
        SequenceMap new_sequence_map(a_reco_seq, an_enz_acro);
        a_tree.insert(new_sequence_map);
        // recognition_sequences.push_back(a_reco_seq);
      }
    }
    // a_tree.printTree();
    openFile.close();
    string userInput;

    cin >> userInput;
    while (cin >> userInput)
    {
      //cout << userInput << endl;
      SequenceMap UserSequence(userInput, "");
      // a_tree.insert(UserSequence);
      if (a_tree.contains(UserSequence))
      {
        cout << a_tree.find(UserSequence) << endl;
      }
      else
      {
        cout << "not Found" << endl;
      }
    }
  }
} // namespace

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    cout << "Usage: " << argv[0] << " <databasefilename>" << endl;
    return 0;
  }
  const string dbx_filename(argv[1]);
  cout << "Input filename is " << dbx_filename << endl;
  // Note that you will replace the type AvlTree<int> with AvlTree<SequenceMap>
  AvlTree<SequenceMap> a_tree;
  QueryTree(dbx_filename, a_tree);
  return 0;
}