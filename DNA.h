#ifndef DNA_H
#define DNA_H
#include "Sequence.h"
#include "RNA.h"
#include<iostream>
#include"Protien.h"
#include"CodonsTable.h"
#include <fstream>
#include <bits/stdc++.h>

class RNA;


enum DNA_Type{promoter, motif, tail, noncoding};

class DNA : public Sequence
{
  	private:
        DNA_Type type;
        DNA * complementary_strand;
        int startIndex;
        int endIndex;
        bool valid;
        int length;
    public:
 	 	// constructors and destructor
        DNA();
        DNA(char * _seq, DNA_Type atype);
        DNA(char *_seq, DNA_Type atype, int _startIndex, int _endIndex);
        DNA(DNA& rhs);
        ~DNA();
 	 	// function printing DNA sequence information to user
        void Print();
        // function to convert the DNA sequence to RNA sequence
        // It starts by building the complementary_strand of the current
        // DNA sequence (starting from the startIndex to the endIndex), then,
        // it builds the RNA corresponding to that complementary_strand.
        RNA ConvertToRNA();
 	 	// function to build the second strand/pair of DNA sequence
	    // To build a complementary_strand (starting from the startIndex to
        // the endIndex), convert each A to T, each T to A, each C to G, and
        // each G to C. Then reverse the resulting sequence.
        void BuildComplementaryStrand();
        //function to check if the strand is valid
        void isValid();
        //function to add two strands together
        DNA operator +(DNA& dna2);
        //function to check if the two strands are equal
        bool operator ==(DNA &dna2);
        //function to check if the two strands aren't equal
        bool operator !=(DNA &dna2);
        //function to equate the sequence
        void operator =(DNA &dna2);
        //function to cout the strands
        friend ostream& operator << (ostream& out, DNA dna2);
        //function to cin the strands
        friend istream& operator >> (istream& in, DNA &dna2);
        //function to load sequence from file
        void loadSequenceFromFile();
        //function to creat new file from the user and load it
        void saveSequenceToFile();
        //getter for length
        int getLength();
        //getter for an element in the sequence
        char getElementInSeq(int index);
  };


#endif // DNA_H
