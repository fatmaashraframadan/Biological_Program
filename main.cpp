/**
*   Title: Sequencer
*   Version: 0.2 (Alpha)
*   Authors: Fatma Ashraf, Catherine Atef, Ali Alfy
*   Last Modified Date: 07/12/2018
*   Purpose: Works with different types of sequences (DNA, RNA, Protein) and can transform any
*   of them to any other type of sequence and finds the longest common sequence.
*
*   Change log:
*   v 0.0:
*   -Implemented parent class and designed the UML
*
*   v 0.1:
*   -Designed the protein child class and the CodonsTable
*   -Added exception handling
*
*   v 0.2:
*   -Designed the DNA child class
*   -Added exception handling
*
*   v 0.3:
*   -Designed the DNA child class
*
*   v 0.4:
*   -Added the operators to all child classes
*   -Added the ability to save and load from a file
*
*   v 0.5:
*   -Fixed bugs and improved performance
*
*   v 0.901:
*   -Added the ability to align two sequences
*   -Added the ability to get all possible DNA strands from one big protein sequence
*
*   v 0.974:
*   -Fixed bugs and issues and improved performance
*
*   v 1.0(BETA):
*   -Added a simple user interface
*/


#include <bits/stdc++.h>
#include"RNA.h"
#include"Sequence.h"
#include"DNA.h"
#include"Protien.h"
#include"CodonsTable.h"
#include<conio.h>

using namespace std;

int main()
{
    vector<DNA> DNAVector(10);
    vector<RNA> RNAVector(10);
    vector<Protien> ProteinVector(10);
    int numOfDNA=0, numOfRNA=0, numOfProtein=0;

    start:
    cout << "Sequencer BETA version.\n 1- Enter a new sequence\n 2- Show current sequences\n 3- Save a sequence to file\n 4-Transform a sequence\n 5- Align two sequences" << endl;
    char mode;
    cin >> mode;
    switch(mode){
    case '1':
        cout << "Choose a sequence type:\n 1- DNA\n 2- RNA\n 3- Protein" << endl;
        char mode1;
        cin >> mode1;
        switch(mode1){
        case '1':
            {
                char mode11;
                cout << "Choose an option:\n 1- Enter manually\n 2- Load from a file" << endl;
                cin >> mode11;
                if(mode11 == '1'){
                    DNA newDNA;
                    cin >> newDNA;
                    DNAVector[numOfDNA] = newDNA;
                    numOfDNA++;
                }else if(mode11 == '2'){
                    DNA newDNA;
                    newDNA.loadSequenceFromFile();
                    DNAVector[numOfDNA] = newDNA;
                    numOfDNA++;
                }
                else{
                    cout << "Invalid option." << endl;
                }
                break;
            }
        case '2':
            {
                char mode11;
                cout << "Choose an option:\n 1- Enter manually\n 2- Load from a file" << endl;
                cin >> mode11;
                if(mode11 == '1'){
                    RNA newRNA;
                    cin >> newRNA;
                    RNAVector[numOfRNA] = newRNA;
                    numOfRNA++;
                }else if(mode11 == '2'){
                    RNA newRNA;
                    newRNA.loadSequenceFromFile();
                    RNAVector[numOfRNA] = newRNA;
                    numOfRNA++;
                }
                else{
                    cout << "Invalid option." << endl;
                }
                break;
            }
        case '3':
            {
                char mode11;
                cout << "Choose an option:\n 1- Enter manually\n 2- Load from a file" << endl;
                cin >> mode11;
                if(mode11 == '1'){
                    Protien newProtein;
                    cin >> newProtein;
                    ProteinVector[numOfProtein] = newProtein;
                    numOfProtein++;
                }else if(mode11 == '2'){
                    Protien newProtein;
                    newProtein.loadSequenceFromFile();
                    ProteinVector[numOfProtein] = newProtein;
                    numOfProtein++;
                }
                else{
                    cout << "Invalid option." << endl;
                }
                break;
            }
        default:
            cout << "Invalid option" << endl;
            break;
        }
        break;
    case '2':
        cout << "Current DNA Sequences:" << endl;
        for(int i=0; i<numOfDNA; i++){
            cout << i << ')' << endl << DNAVector[i] << endl;
        }
        cout << endl << "Current RNA Sequences:" << endl;
        for(int i=0; i<numOfRNA; i++){
            cout << i << ')' << endl << RNAVector[i] << endl;
        }
        cout << endl << "Current Protein Sequences:" << endl;
        for(int i=0; i<numOfProtein; i++){
            cout << i << ')' << endl << ProteinVector[i] << endl;
        }
        break;
    case '3':
        cout << "Choose a sequence type:\n 1- DNA\n 2- RNA\n 3- Protein" << endl;
        char mode3;
        cin >> mode3;
        cout << "Choose from current sequences" << endl;
        switch(mode3){
        case '1':
            {
                cout << "Current DNA Sequences:" << endl;
                for(int i=0; i<numOfDNA; i++){
                    cout << i << ')' << endl << DNAVector[i] << endl;
                }
                int index;
                cin >> index;
                if(index < 0 || index >= numOfDNA){
                    cout << "Invalid option. Make sure you choose an available index" << endl;
                }else{
                    DNAVector[index].saveSequenceToFile();
                }
                break;
            }
        case '2':
            {
                cout << "Current RNA Sequences:" << endl;
                for(int i=0; i<numOfRNA; i++){
                    cout << i << ')' << endl << RNAVector[i] << endl;
                }
                int index;
                cin >> index;
                if(index < 0 || index >= numOfRNA){
                    cout << "Invalid option. Make sure you choose an available index" << endl;
                }else{
                    RNAVector[index].saveSequenceToFile();
                }
                break;
            }
        case '3':
            {
                cout << "Current Protein Sequences:" << endl;
                for(int i=0; i<numOfProtein; i++){
                    cout << i << ')' << endl << ProteinVector[i] << endl;
                }
                int index;
                cin >> index;
                if(index < 0 || index >= numOfProtein){
                    cout << "Invalid option. Make sure you choose an available index" << endl;
                }else{
                    ProteinVector[index].saveSequenceToFile();
                }
                break;
            }
        default:
            cout << "Invalid option" << endl;
            break;
        }
        break;
    case '4':
        cout << "Choose a sequence type:\n 1- DNA\n 2- RNA\n 3- Protein" << endl;
        char mode4;
        cin >> mode4;
        cout << "Choose from current sequences" << endl;
        switch(mode4){
        case '1':
            {
                cout << "Current DNA Sequences:" << endl;
                for(int i=0; i<numOfDNA; i++){
                    cout << i << ')' << endl << DNAVector[i] << endl;
                }
                int index;
                cin >> index;
                if(index < 0 || index >= numOfDNA){
                    cout << "Invalid option. Make sure you choose an available index" << endl;
                }else{
                    cout << "To:\n 1- RNA\n 2- Protein" << endl;
                    int transformMode;
                    cin >> transformMode;
                    if(transformMode == 1){
                        DNA tempDNA = DNAVector[index];
                        RNA &&newRNA = tempDNA.ConvertToRNA();
                        RNAVector[numOfRNA] = newRNA;
                        numOfRNA++;
                    }else if(transformMode == 2){
                        DNA tempDNA = DNAVector[index];
                        RNA &&newRNA = tempDNA.ConvertToRNA();
                        Protien &&newProtein = newRNA.ConvertToProtein();
                        ProteinVector[numOfProtein] = newProtein;
                        numOfProtein++;
                    }else{
                        cout << "Invalid option." << endl;
                    }
                }
                break;
            }
        case '2':
            {
                cout << "Current RNA Sequences:" << endl;
                for(int i=0; i<numOfRNA; i++){
                    cout << i << ')' << endl << RNAVector[i] << endl;
                }
                int index;
                cin >> index;
                if(index < 0 || index >= numOfRNA){
                    cout << "Invalid option. Make sure you choose an available index" << endl;
                }else{
                    cout << "To:\n 1- Protein\n 2- DNA" << endl;
                    int transformMode;
                    cin >> transformMode;
                    if(transformMode == 2){
                        DNA &&newDNA = RNAVector[index].ConvertToDNA();
                        DNAVector[numOfDNA] = newDNA;
                        numOfDNA++;
                    }else if(transformMode == 1){
                        Protien &&newProtein = RNAVector[index].ConvertToProtein();
                        ProteinVector[numOfProtein] = newProtein;
                        numOfProtein++;
                    }else{
                        cout << "Invalid option." << endl;
                    }
                }
                break;
            }
        case '3':
            {
                cout << "Current Protein Sequences:" << endl;
                for(int i=0; i<numOfProtein; i++){
                    cout << i << ')' << endl << ProteinVector[i] << endl;
                }
                int index;
                cin >> index;
                if(index < 0 || index >= numOfProtein){
                    cout << "Invalid option. Make sure you choose an available index" << endl;
                }else{
                    cout << "To:\n 1- DNA\n 2- RNA" << endl;
                    int transformMode;
                    cin >> transformMode;
                    if(transformMode == 1){
                        cout << "You'll have to input a big DNA strand to use this function" << endl;
                        DNA bigDNA;
                        cin >> bigDNA;
                        DNA newDNA = ProteinVector[index].GetDNAStrandsEncodingMe(bigDNA)[0];
                        DNAVector[numOfDNA] = newDNA;
                        numOfDNA++;
                    }else if(transformMode == 2){
                        cout << "You'll have to input a big DNA strand to use this function" << endl;
                        DNA bigDNA;
                        cin >> bigDNA;
                        DNA newDNA = ProteinVector[index].GetDNAStrandsEncodingMe(bigDNA)[0];
                        RNA &&newRNA = newDNA.ConvertToRNA();
                        RNAVector[numOfRNA] = newRNA;
                        numOfRNA++;
                    }else{
                        cout << "Invalid option." << endl;
                    }
                }
                break;
            }
        default:
            cout << "Invalid option" << endl;
            break;
        }
        break;
    case '5':
        cout << "Choose a sequence type:\n 1- DNA\n 2- RNA\n 3- Protein" << endl;
        char mode5;
        cin >> mode5;
        cout << "Choose from current sequences, choose sequence 1 and 2 respectively" << endl;
        switch(mode5){
        case '1':
            {
                cout << "Current DNA Sequences:" << endl;
                for(int i=0; i<numOfDNA; i++){
                    cout << i << ')' << endl << DNAVector[i] << endl;
                }
                int index1, index2;
                cin >> index1 >> index2;
                if((index1 < 0 || index1 >= numOfDNA) || (index2 < 0 || index2 >= numOfDNA)){
                    cout << "Invalid option. Make sure you choose an available index" << endl;
                }else{
                    int firstSeqLength=0, secondSeqLength=0;
                    while(DNAVector[index1].getElementInSeq(firstSeqLength) != '\0'){
                        firstSeqLength++;
                    }
                    while(DNAVector[index2].getElementInSeq(secondSeqLength) != '\0'){
                        secondSeqLength++;
                    }
                    Sequence* s1 = &DNAVector[index1];
                    Sequence* s2 = &DNAVector[index2];
                    Align(s1, s2, firstSeqLength, secondSeqLength);
                }
                break;
            }
        case '2':
            {
                cout << "Current RNA Sequences:" << endl;
                for(int i=0; i<numOfRNA; i++){
                    cout << i << ')' << endl << RNAVector[i] << endl;
                }
                int index1, index2;
                cin >> index1 >> index2;
                if((index1 < 0 || index1 >= numOfRNA) || (index2 < 0 || index2 >= numOfRNA)){
                    cout << "Invalid option. Make sure you choose an available index" << endl;
                }else{
                    int firstSeqLength=0, secondSeqLength=0;
                    while(RNAVector[index1].getElementInSeq(firstSeqLength) != '\0'){
                        firstSeqLength++;
                    }
                    while(RNAVector[index2].getElementInSeq(secondSeqLength) != '\0'){
                        secondSeqLength++;
                    }
                    Sequence* s1 = &RNAVector[index1];
                    Sequence* s2 = &RNAVector[index2];
                    Align(s1, s2, firstSeqLength, secondSeqLength);
                }
                break;
            }
        case '3':
            {
                cout << "Current Protein Sequences:" << endl;
                for(int i=0; i<numOfProtein; i++){
                    cout << i << ')' << endl << ProteinVector[i] << endl;
                }
                int index1, index2;
                cin >> index1 >> index2;
                if((index1 < 0 || index1 >= numOfProtein) || (index2 < 0 || index2 >= numOfProtein)){
                    cout << "Invalid option. Make sure you choose an available index" << endl;
                }else{
                    int firstSeqLength=0, secondSeqLength=0;
                    while(ProteinVector[index1].getElementInSeq(firstSeqLength) != '\0'){
                        firstSeqLength++;
                    }
                    while(ProteinVector[index2].getElementInSeq(secondSeqLength) != '\0'){
                        secondSeqLength++;
                    }
                    Sequence* s1 = &ProteinVector[index1];
                    Sequence* s2 = &ProteinVector[index2];
                    Align(s1, s2, firstSeqLength, secondSeqLength);
                }
                break;
            }
        default:
            cout << "Invalid option" << endl;
            break;
        }
        break;
    default:
        cout << "Invalid option." << endl;
    }
    goto start;
}
