#ifndef RNA_H
#define RNA_H
#include<iostream>
#include "Sequence.h"
#include"Protien.h"
#include <iostream>
#include"DNA.h"
#include <fstream>
#include <bits/stdc++.h>
class DNA;
enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

using namespace std;
class Protien;
class CodonsTable;

class RNA: public Sequence
{
private:
    RNA_Type type;
public:
    // constructors and destructor
    RNA();
    RNA(char * _seq, RNA_Type atype);
    RNA(RNA& rhs);
    ~RNA();
    //boolean variable to check validation.
    bool Seqvalid = true ;
    //boolean variable to check type validation.
    bool Typevalid = true;
    // function to be overridden to print all the RNA information
     void Print();
    // function to convert the RNA sequence into protein sequence
    // using the codonsTable object
    Protien ConvertToProtein();
    // function to convert the RNA sequence back to DNA.
    DNA ConvertToDNA();
    //istream function to take RNA from user.
    friend istream& operator>> (istream&, RNA& rna2);
    //ostream function to cout RNA for user.
    friend ostream& operator<< (ostream&, RNA& rna);
    //function to add two RN sequences to each other.
    RNA operator+(RNA& inseq);
    //function to check if two RNA sequences are equal.
    bool operator==(RNA& inseq);
    //function to check if two RNA sequences are not equal.
    bool operator!=(RNA& inseq);
    //function to load sequence from file.
    void loadSequenceFromFile();
    //function to create new file for user and save it.
    void saveSequenceToFile();
     //function to check RNA sequence validation.
    void checkRNAValidation();
    //function to check RNA Type validation.
    void check_RNAType_Validation(RNA_Type atype);
     //function to copy object value to an otehr object.
    void operator =(RNA &rna2);
    char getElementInSeq(int index);

};
#endif // RNA_H
