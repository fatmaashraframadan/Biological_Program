#ifndef SEQUENCE_H
#define SEQUENCE_H
#include<iostream>
#include<CodonsTable.h>

using namespace std;


class Sequence
{
    protected:
        char* seq;
        CodonsTable codonsTable;

    public:
 	 	// constructors and destructor
        Sequence();
        Sequence(int length);
        Sequence(Sequence& rhs);
        virtual ~Sequence();
 	 	// pure virtual function that should be overridden because every
        // type of sequence has its own details to be printed
        virtual void Print()= 0;
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism
        friend char* Align(Sequence * s1, Sequence * s2, int n, int m);
        // functions to load and read from a file
        virtual void saveSequenceToFile()=0;
        virtual void loadSequenceFromFile()=0;
        // function to get an element in sequence
        virtual char getElementInSeq(int index)=0;
};

#endif // SEQUENCE_H
