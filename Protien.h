#ifndef PROTIEN_H
#define PROTIEN_H
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include<iostream>
#include<vector>

class DNA;
class RNA;

using namespace std;

enum Protein_Type{Hormone, Enzyme, TF, Cellular_Function};

class Protien: public Sequence
{
    private:
        Protein_Type type;
        bool noErrors;
    public:
 	 	// constructors and destructor
 	 	Protien();
 	 	Protien(char* p);
 	 	Protien(Protien &protein);
 	 	~Protien();
 	 	// return an array of DNA sequences that can possibly
        // generate that protein sequence
        DNA* GetDNAStrandsEncodingMe(DNA & bigDNA);
        // function to print info
        void Print();
        /// global variable to detect if an error happened so that we can check later each object if it was successfully created
        /// or not and can delete it if not
        bool isOkay();
        // functions to load ans save to or from a file
        void saveSequenceToFile();
        void loadSequenceFromFile();
        //cin and cout
        friend ostream& operator<<(ostream& out, Protien &protein);
        friend istream& operator>>(istream& in, Protien &protein);
        //function to add two strands together
        Protien operator +(Protien &protein2);
        //function to check if the two strands are equal
        bool operator ==(Protien &protein2);
        //function to check if the two strands aren't equal
        bool operator !=(Protien &protein2);
        //function to equate the sequence
        void operator =(Protien &protein2);
        char getElementInSeq(int index);
};

#endif // PROTIEN_H
