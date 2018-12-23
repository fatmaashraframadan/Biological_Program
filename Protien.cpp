#include "Protien.h"
#include "CodonsTable.h"

Protien::Protien()
{
    //ctor
}

Protien::Protien(Protien &protein2){
    int counter = 0;
    while(protein2.seq[counter] != '\0')
    {
        counter +=1;
    }
    seq = new char[counter+1];
    for(int i=0; i<counter; i++)
    {
        seq[i] = protein2.seq[i];
    }
    seq[counter] = '\0';
    type = protein2.type;
}

Protien::Protien(char* p){
    int length = 0;
    while(p[length] != '\0'){
        length++;
    }

    seq = new char[length+1];

    noErrors = true;
    bool validProtein = false;
    for(int i=0; i<length; i++){
        try{
            validProtein = codonsTable.isAminoAcidValid(p[i]);
            if(validProtein == false){
                throw 99;
            }
            seq[i] = p[i];
            validProtein = false;
        }catch(...){
            cout << "Invalid type of protein. Make sure the values are valid." << endl;
            noErrors = false;
            break;
        }
    }
    seq[length] = '\0';

    if(noErrors == true){
        tryAgainType:
        cout << "Type of Protein?:\n1- Hormone\n2- Enzyme\n3- TF\n4- Cellular Function" << endl;
        char proteinType;
        cin >> proteinType;

        switch(proteinType){
        case '1':
            type = Hormone;
            break;
        case '2':
            type = Enzyme;
            break;
        case '3':
            type = TF;
            break;
        case '4':
            type = Cellular_Function;
            break;
        default:
            cout << "Invalid choice, try again:" << endl;
            goto tryAgainType;
        }
    }
}

Protien::~Protien()
{
    delete[] seq;
}

void Protien::Print(){
    cout << "Protein: ";
    int i=0;
    while(seq[i] != '\0'){
        cout << seq[i];
        i++;
    }
    cout << endl << "Protein Type: ";
    switch(type){
    case 0:
        cout << "Hormone" << endl;
        break;
    case 1:
        cout << "Enzyme" << endl;
        break;
    case 2:
        cout << "TF" << endl;
        break;
    case 3:
        cout << "Cellular Function" << endl;
        break;
    }
}

bool Protien::isOkay(){
    return noErrors;
}

void Protien::saveSequenceToFile(){
    int length2 = 0;
    while(seq[length2] != '\0'){
        length2++;
    }

    string fileName;
    cout << "Enter file name" << endl;
    cin >> fileName;
    fileName = fileName + ".txt";
    ofstream createSequence(fileName.c_str());

    createSequence << length2 << ' '; //assigning length

    for(int i=0; i<length2; i++){
        createSequence << seq[i];
    }
    createSequence << ' ' << type;
}

void Protien::loadSequenceFromFile(){
    string fileName;
    cout << "Enter the name of the file you want to load sequence from: " << endl;
    cin >> fileName;
    fileName = fileName + ".txt";
    ifstream loadSequence(fileName.c_str());
    int length1;
    loadSequence >> length1;
    seq = new char[length1+1];
    for(int i = 0 ; i <length1 ; i++)
    {
        loadSequence >> seq[i];
    }
    seq[length1] = '\0';
    int h;
    loadSequence >> h;
    switch(h)
    {
    case 0:
        type = Hormone;
        break;
    case 1:
        type = Enzyme;
        break;
    case 2:
        type = TF;
        break;
    case 3:
        type = Cellular_Function;
        break;
    }
}

ostream& operator << (ostream& out, Protien &protein){
    protein.Print();
    return out;
}

istream& operator >> (istream& in, Protien &protein){
    CodonsTable codonsTable;
    int len;
    char s;
    char t;
    cout << "Please enter your length: ";
    cin >> len;
    cout << "Enter a number for your type \n 0 for Hormone \n 1 for Enzyme \n 2 for TF \n 3 for Cellular Function " << endl;
    typeTry:
    cin >> t;
    switch(t){
    case '0':
        protein.type = Hormone;
        break;
    case '1':
        protein.type = Enzyme;
        break;
    case '2':
        protein.type = TF;
        break;
    case '3':
        protein.type = Cellular_Function;
        break;
    default:
        cout << "Please enter a number from 0 to 3. Try again: " << endl;
        goto typeTry;
        break;
    }
    protein.seq = new char [len+1];
    start:
    cout << "Enter you sequence: ";
    for(int i = 0 ; i  < len; i++){
        cin >> s;
        bool valid = codonsTable.isAminoAcidValid(s);
        if(valid){
            protein.seq[i] = s;
        }else{
            cout << "Invalid protein. Try again." << endl;
            goto start;
        }
    }
    protein.seq[len] = '\0';
    protein.noErrors = true;
    return in;
}

Protien Protien::operator +(Protien &protein2){
    int length1=0, length2=0;
    while(seq[length1] != '\0'){
        length1++;
    }
    length1++;

    while(protein2.seq[length2] != '\0'){
        length2++;
    }
    length2++;

    int newLength = length2 + length1-1;
    char *addedSeq = new char[newLength];
    for(int i=0; i<length1-1; i++){
        addedSeq[i]=seq[i];
    }
    for(int i=length1-1; i<newLength; i++){
        addedSeq[i] = protein2.seq[abs(length1-1-i)];
    }
    Protien sum1(addedSeq);
    return sum1;
}

bool Protien::operator ==(Protien &protein2){
    int length1=0, length2=0;
    while(seq[length1] != '\0'){
        length1++;
    }
    length1++;

    while(protein2.seq[length2] != '\0'){
        length2++;
    }
    length2++;

    if(type == protein2.type)
    {
         if(length1 == length2)
    {
        for(int i = 0 ; i < length1 ; i++)
        {
            if(this->seq[i] != protein2.seq[i])
                return false;
        }
        return true;
    }
    else
        return false;
    }
    else
        return false;
}

bool Protien::operator !=(Protien &protein2){
    int length1=0, length2=0;
    while(seq[length1] != '\0'){
        length1++;
    }
    length1++;

    while(protein2.seq[length2] != '\0'){
        length2++;
    }
    length2++;

    if(type == protein2.type)
    {
         if(length1 == length2)
    {
        for(int i = 0 ; i < length1 ; i++)
        {
            if(this->seq[i] != protein2.seq[i])
                return true;
        }
        return false;
    }
    else
        return true;
    }
    else
        return true;
}

void Protien::operator =(Protien &protein2){
    int counter = 0;
    while(protein2.seq[counter] != '\0')
    {
        counter +=1;
    }
    seq = new char[counter+1];
    for(int i=0; i<counter; i++)
    {
        seq[i] = protein2.seq[i];
    }
    seq[counter] = '\0';
    type = protein2.type;
}

DNA* Protien::GetDNAStrandsEncodingMe(DNA &bigDNA){
    int currentProteinLength = 0;
    bool isSubSeqExist = true;
    while(seq[currentProteinLength] != '\0'){
        currentProteinLength++;
    }

    int DNALength = bigDNA.getLength()-1, proteinLength = DNALength/3;

    if(DNALength%3 == 0){
        vector<int> subSeqs;

        RNA &&newRNA = bigDNA.ConvertToRNA();

        Protien &&newProtein = newRNA.ConvertToProtein();

        for(int i=0; i<proteinLength; i++){
            if(seq[0] == newProtein.seq[i]){
                for(int j=1; j<currentProteinLength; j++){
                    if(seq[j] != newProtein.seq[i+j]){
                        isSubSeqExist = false;
                    }
                }
                if(isSubSeqExist == true){
                    subSeqs.push_back(i);
                }
                isSubSeqExist = true;
            }
        }

        DNA* possibleStrands = new DNA[subSeqs.size()];

        char* newDNASeq = new char[currentProteinLength*3 + 1];

        for(int i=0; i<subSeqs.size(); i++){
            for(int j=0; j<currentProteinLength*3; j++){
                newDNASeq[j] = bigDNA.getElementInSeq((subSeqs[i]*3) + j);
            }
            newDNASeq[currentProteinLength*3] = '\0';
            DNA &&newDNA = DNA(newDNASeq, promoter);
            cout << newDNA << endl;
            possibleStrands[i] = newDNA;
        }

        return possibleStrands;

    }else{
        cout << "The big DNA must have a length divisible by 3" << endl;
    }

}

char Protien::getElementInSeq(int index){
    return seq[index];
}
