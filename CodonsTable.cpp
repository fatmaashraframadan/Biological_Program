#include "CodonsTable.h"

CodonsTable::CodonsTable()
{
    string fileName;
    /*cout << "Enter File Name" << endl;
    cin >> fileName;*/ ///found no use in taking the name every time we use the constructor so hard coded
                       /// the name since it doesnt change

    fileName = "RNA_codon_table.txt";

    LoadCodonsFromFile(fileName);
}

CodonsTable::~CodonsTable()
{
    delete[] codons;
}

void CodonsTable::LoadCodonsFromFile(string codonsFileName){
    ifstream theFile(codonsFileName.c_str());
    string item;
    char acid;
    for(int i=0; i<64; i++){
        if(i==56 || i== 50 || i== 48){
            theFile >> item;
            for(int j=0; j<3; j++){
                codons[i].value[j] = item[j];
            }
            codons[i].value[3] = '\0';
            codons[i].AminoAcid = '\0';
        }else{
            theFile >> item;
            theFile >> acid;
            for(int j=0; j<3; j++){
                codons[i].value[j] = item[j];
            }
            codons[i].value[3] = '\0';
            codons[i].AminoAcid = acid;
        }
    }
}

Codon CodonsTable::getAminoAcid(char* value){
    for(int i=0; i<64; i++){
        if((value[0] == codons[i].value[0]) && (value[1] == codons[i].value[1]) && (value[2] == codons[i].value[2])){
            return codons[i];
        }
    }
    cout << "Not Found" << endl;
}

void CodonsTable::setCodon(char * value, char AminoAcid, int index){
    for(int i=0; i<3; i++){
        codons[index].value[i] = value[i];
    }
    codons[index].value[3] = '\0';
    codons[index].AminoAcid = AminoAcid;
}

bool CodonsTable::isAminoAcidValid(char a){
    for(int j=0; j<64; j++){
        if(a == codons[j].AminoAcid){
            return true;
        }
    }
    return false;
}
