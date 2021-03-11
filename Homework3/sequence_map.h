#ifndef SEQUENCEMAP
#define SEQUENCEMAP
#include <string>
#include <vector>
#include <iostream>
class SequenceMap
{
public:
    //defualt constructor
    SequenceMap() = default;
    //paramterized constructor
    SequenceMap(const std::string &a_rec_seq, const std::string &an_enz_acro)
    {
        enzyme_acronyms_.push_back(an_enz_acro);
        recognition_sequence_ = a_rec_seq;
        //std::cout << recognition_sequence_ << std::endl;
        //std::cout << enzyme_acronyms_[0];
    }
    //copy constructor
    SequenceMap(const SequenceMap &rhs) = default;
    //move constructor
    SequenceMap(SequenceMap &&rhs) = default;
    //copy assignment
    SequenceMap &operator=(const SequenceMap &rhs) = default;
    //move assignment
    SequenceMap &operator=(SequenceMap &&rhs) = default;
    //destructor
    ~SequenceMap() = default;

    //end of big 5

    bool operator<(const SequenceMap &rhs) const
    {
        return recognition_sequence_ < rhs.recognition_sequence_;
    }
    friend std::ostream &operator<<(std::ostream &out, const SequenceMap &enzymeSeq)
    {
        for (auto i = 0; i < enzymeSeq.enzyme_acronyms_.size(); i++)
        {
            out << enzymeSeq.enzyme_acronyms_[i];
        }
        return out;
    }
    void Merge(const SequenceMap &other_sequence)
    {
        if (other_sequence.recognition_sequence_.empty())
        {
            return;
        }
        else if (this->recognition_sequence_ != other_sequence.recognition_sequence_)
        {

            std::cout << "Recognition sequences do not match" << std::endl;
            return;
        }

        for (auto character : other_sequence.enzyme_acronyms_)
        {
            this->enzyme_acronyms_.push_back(character);
        }
    }

private:
    std::string recognition_sequence_;
    std::vector<std::string> enzyme_acronyms_;
};
#endif
