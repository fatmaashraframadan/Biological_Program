#include "DNA.h"

DNA::DNA(){}

DNA::DNA(char *_seq, DNA_Type atype)
{
    cout << "Please enter your startindex" << endl;
    cin >> startIndex;
    cout << "Please enter your endindex" << endl;
    cin >> endIndex;
    int counter=0;
    while(_seq[counter] != '\0'){
        counter +=1;
    }
    seq = new char[counter+1];
    for(int i=0; i<counter; i++){
        seq[i] = _seq[i];
    }
    seq[counter] = '\0';

    type = atype;

    length = counter +1;
    isValid();
}
DNA::DNA(DNA& rhs)
{
    int counter = 0;
    while(rhs.seq[counter] != '\0'){
         counter +=1;
    }
    seq = new char[counter+1];
    length = counter+1;
    for(int i=0; i<counter; i++){
        seq[i] = rhs.seq[i];
    }
    seq[counter] = '\0';
    endIndex = rhs.endIndex;
    startIndex = rhs.startIndex;
    type = rhs.type;
}

///for the comp strand
DNA::DNA(char *_seq, DNA_Type atype, int _startIndex, int _endIndex)
{
    startIndex = _endIndex;
    endIndex = _startIndex;
    int counter=0;
    while(_seq[counter] != '\0'){
        counter +=1;
    }
    seq = new char[counter+1];
    for(int i=0; i<counter; i++){
        seq[i] = _seq[i];
    }
    seq[counter] = '\0';

    type = atype;

    Print();
}

void DNA::Print(){
    cout << "DNA: ";
    int i=0;
    while(seq[i] != '\0'){
        cout << seq[i];
        i++;
    }
    cout << endl << "DNA Type: ";
    switch(type){
    case 0:
        cout << "promoter" << endl;
        break;
    case 1:
        cout << "motif" << endl;
        break;
    case 2:
        cout << "tail" << endl;
        break;
    case 3:
        cout << "noncoding" << endl;
        break;
    }
    cout << "Your startindex: " << startIndex << endl;
    cout << "Your endindex: " << endIndex << endl;
}

void DNA::isValid(){
    try{
        int counter=0;
        while(seq[counter] != '\0'){
            if(seq[counter] != 'A' && seq[counter]!= 'C' && seq[counter]!= 'T' && seq[counter]!= 'G'){
                throw 97;
            }
            counter++;
        }
        valid = true;
    }catch(...){
        cout << "Letters should be A or T or G or C" << endl;
        valid = false;
    }
}

RNA DNA::ConvertToRNA(){
    char* convert = new char [length];
    for(int i=0; i<length; i++){
        if(seq[i] == 'T'){
            convert[i] = 'U';
        }else{
            convert[i] = seq[i];
        }
    }
    cout << "Enter a number for your type \n 0 for mRNA \n 1 for pre_mRNA \n 2 for mRNA_exon \n 3 for mRNA_intron " << endl;
    int t;
    cin >> t;
    RNA_Type typee;
    switch(t){
    case 0:
        typee = mRNA;
        break;
    case 1:
        typee = pre_mRNA;
        break;
    case 2:
         typee = mRNA_exon;
        break;
    case 3:
         typee = mRNA_intron;
        break;
    }
    RNA con1(convert, typee);
    return con1;
}

void DNA::BuildComplementaryStrand(){
    char* comp = new char [length];
    for(int i=0; i< length-1; i++){
        comp[i] = seq[length - 2 - i];
    }
    comp[length-1] = '\0';
    for(int i=0; i<length-1; i++){
        if(comp[i] == 'A'){
            comp[i] = 'T';
        }else if(comp[i] == 'C'){
            comp[i] = 'G';
        }else if(comp[i] == 'T'){
            comp[i] = 'A';
        }else if(comp[i] == 'G'){
            comp[i] = 'C';
        }
    }
    complementary_strand = new DNA(comp, type, startIndex, endIndex);
}

DNA::~DNA()
{
    delete[] seq;
}

DNA DNA::operator +(DNA& dna2){
    int newLength = dna2.length + length-1;
    char *addedSeq = new char[newLength];
    for(int i=0; i<length-1; i++){
        addedSeq[i]=seq[i];
    }
    for(int i=length-1; i<newLength; i++){
        addedSeq[i] = dna2.seq[abs(length-1-i)];
    }
    DNA sum1(addedSeq, type);
    return sum1;
}

bool DNA::operator ==(DNA &dna2){
    if(dna2.length == length){
        for(int i=0; i<length-1; i++){
            if(seq[i] != dna2.seq[i]){
                return false;
            }
        }
    return true;
    }
    else
        {return false;}
}

bool DNA::operator !=(DNA &dna2){
    if(dna2.length == length){
        for(int i=0; i<length-1; i++){
            if(seq[i] != dna2.seq[i]){
                return true;
            }
        }
    return false;
    }else
        {return true;}
}

ostream& operator << (ostream& out, DNA dna2){
    dna2.Print();
    return out;
}

istream& operator >> (istream& in, DNA &dna2){
    int len;
    char s;
    char t;
    cout << "Please enter your length: ";
    cin >> len;
    dna2.length = len+1;
    cout << "Enter your startindex: " << endl;
    cin >> dna2.startIndex;
    cout << "Enter your endindex: " << endl;
    cin >> dna2.endIndex;
    cout << "Enter a number for your type \n 0 for promoter \n 1 for motif \n 2 for tail \n 3 for noncoding " << endl;
    typeTry:
    cin >> t;
    switch(t){
    case '0':
        dna2.type = promoter;
        break;
    case '1':
        dna2.type = motif;
        break;
    case '2':
        dna2.type = tail;
        break;
    case '3':
        dna2.type = noncoding;
        break;
    default:
        cout << "Please enter a number from 0 to 3. Try again: " << endl;
        goto typeTry;
        break;
    }
    dna2.seq = new char [len+1];
    start:
    cout << "Enter you sequence: ";
    for(int i = 0 ; i  < len; i++){
        cin >> s;
        if(s == 'A' || s == 'G' || s == 'T' || s == 'C'){
            dna2.seq[i] = s;
        }else{
            cout << "Please enter only A or T or G or C" << endl;
            goto start;
        }
    }
    dna2.seq[len] = '\0';
    dna2.valid = true;
    return in;
}

void DNA:: operator =(DNA &dna2){
    int counter = 0;
    while(dna2.seq[counter] != '\0'){
         counter +=1;
    }
    seq = new char[counter+1];
    for(int i=0; i<counter; i++){
        seq[i] = dna2.seq[i];
    }
    seq[counter] = '\0';
    endIndex = dna2.endIndex;
    startIndex = dna2.startIndex;
    type = dna2.type;
}

void DNA::loadSequenceFromFile()
{
    string fileName;
    cout << "Enter the name of the file you want to load sequence from: " << endl;
    cin >> fileName;
    fileName = fileName + ".txt";
    ifstream loadSequence(fileName.c_str());
    int length1;
    loadSequence >> startIndex;
    loadSequence >> endIndex;
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
        type = promoter;
        break;
    case 1:
        type = motif;
        break;
    case 2:
        type = tail;
        break;
    case 3:
        type = noncoding;
        break;
    }
}

void DNA::saveSequenceToFile()
{
    int length2 = 0;
    while(seq[length2] != '\0'){
        length2++;
    }

    string fileName;
    cout << "Enter file name" << endl;
    cin >> fileName;
    fileName = fileName + ".txt";
    ofstream createSequence(fileName.c_str());

    createSequence << startIndex << ' ' << endIndex << ' '; //assigning startindex and endindex

    createSequence << length2 << ' '; //assigning length

    for(int i=0; i<length2; i++){
        createSequence << seq[i];
    }
    createSequence << ' ' << type;

}

int DNA::getLength(){
    return length;
}

char DNA::getElementInSeq(int index){
    return seq[index];
}
