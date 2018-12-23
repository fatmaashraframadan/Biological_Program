#include "RNA.h"
#include<array>
#include<list>

//default constructor to set default value to variables.
RNA::RNA()
{
    this->type = mRNA;

}
//parameterize constructor to set sequence and type.
RNA::RNA(char * _seq, RNA_Type atype)
{
    //copying value from parameter sequence to inherited sequence.
    int length = 0;
    //getting length of given sequence.
    while(_seq[length] != '\0')
    {
        length++;
    }
    seq = new char[length + 1];
    try
    {
        //checking if the length is divisible by 3

        if(length%3 != 0){
            throw 'd';
        }

        char s;
        //checking if there is any errors in the input sequence.
        for(int i = 0 ; i < length ; i++)
        {
            if((_seq[i] != 'A') && (_seq[i] != 'C') && (_seq[i] != 'G') && (_seq[i] != 'U'))
            {
                throw 99;

            }
            this->seq[i] = _seq[i];
            Seqvalid = true;
        }
    }
    catch(int x)
    {
        cout << "A, U, C, G are only acceptable. Created Failed." << endl;
        Seqvalid = false;
    }catch(char z){
        cout << "Length must be divisible by 3. Creation failed" << endl;
        Seqvalid = false;
    }

    seq[length] = '\0';
    //setting RNA type to enumeration
    int t;
    tryAgainType:
    try
    {
        if((atype != mRNA )&& (atype != pre_mRNA ) && (atype != mRNA_exon ) && (atype != mRNA_intron ))
        {
            throw 98;
        }
        this->type = atype;
    }
    catch(...)
    {
        Typevalid = false;
    }
    if(!Typevalid)
    {
        cout << endl << "Invalid RNA sequence Type !!!" << endl
             << endl <<"Type of RNA sequence must be one of the following 1-mRNA. \n2-pre_mRNA. \n3-mRNA_exon. \n4-mRNA_intron."<<endl<<
             "Try Again : ";
        cin >> t;
        goto tryAgainType;
    }

}

///Copy Constructor
RNA::RNA(RNA& rhs)
{
    int length = 0;
    while(rhs.seq[length] != '\0')
    {
        length++;
    }
    length++;
    seq = new char[length];
    for(int i=0; i<length; i++)
    {
        seq[i] = rhs.seq[i];
    }
    type = rhs.type;

}
///Destructor to delete sequence.
RNA::~RNA()
{
    delete seq;
}
///virtual function to print RNA sequence and its type.
void RNA::Print()
{
    if(Seqvalid)
    {
        cout << "RNA: ";
        int i=0;
        while(seq[i] != '\0')
        {
            cout << seq[i];
            i++;
        }
        cout << endl << "RNA Type: ";
        switch(type)
        {
        case 0:
            cout << "mRNA" << endl;
            break;
        case 1:
            cout << "pre_mRNA" << endl;
            break;
        case 2:
            cout << "mRNA_exon" << endl;
            break;
        case 3:
            cout << "mRNA_intron" << endl;
            break;
        }
    }
    else
    {
        cout << "Sorry can't print your wrong Data !!"<<endl;
    }

}
//Function to convert from RNA to DNA.
DNA RNA::ConvertToDNA()
{
    int length = 0;
    while(seq[length] != '\0')
    {
        length++;
    }
    char* newSeq = new char[length + 1];
    for(int  i = 0  ; i < length ; i++)
    {
        if (seq[i]=='U')
        {
            newSeq[i]='T';
        }
        else
        {
            newSeq[i] = seq[i];
        }

    }
    newSeq[length] = '\0';
    start :
    cout << "Enter a number for your type \n 0 for promoter \n 1 for motif \n 2 for tail \n 3 for noncoding " << endl;
    char t;
    cin >> t;
    typeTry:
    DNA_Type typee;
    switch(t){
    case '0':
        typee = promoter;
        break;
    case '1':
        typee = motif;
        break;
    case '2':
        typee = tail;
        break;
    case '3':
        typee = noncoding;
        break;
    default:
        cout << "Enter a number between 0 and 3. Try again: " << endl;
        cin >> t;
        goto typeTry;
        break;
    }
    DNA ob(newSeq, typee);
    return ob;
}

///Function to convert from RNA to Protein.
Protien RNA::ConvertToProtein()
{
    int length = 0;
    while(seq[length]!='\0')
    {
        length++;
    }

    //sequence to store Protein in.
    char* subSeq = new char[4];
    char* NEWSeq = new char[length / 3 + 1];

    //array to put each 3 characters in.
    //setting every 3 characters in seq to newseq.
    for (int i = 0; i < length ; i+=3)
    {
        //Setting sunSeq value.
        subSeq[0] = seq[i];
        subSeq[1] = seq[i+1];
        subSeq[2] = seq[i+2];
        subSeq[3] = '\0';
        //sub character to store acid in .
        char Acid;
        //Setting Amino Acid to Acid .
        Acid = codonsTable.getAminoAcid(subSeq).AminoAcid;
        //checking if amino acid is correct.
        NEWSeq[i/3] = Acid;
    }
    NEWSeq[length/3] = '\0';

    Protien ob(NEWSeq);
    return ob ;
}

//istream function to take RNA from user.
istream& operator >> (istream& in, RNA &rna2)
{
    int len;
    char s;
    char t;
    cout << "Please enter your length: ";
    cin >> len;
    while(len%3 != 0){
        cout << "Length must be divisible by 3. Try again: " << endl;
        cin >> len;
    }
    cout << "Enter a number for your type \n 0 for mRNA \n 1 for pre_mRNA \n 2 for mRNA_exon \n 3 for mRNA_intron " << endl;
    cin >> t;
    typeTry:
    switch(t){
    case '0':
        rna2.type = mRNA;
        break;
    case '1':
        rna2.type = pre_mRNA;
        break;
    case '2':
        rna2.type = mRNA_exon;
        break;
    case '3':
        rna2.type = mRNA_intron;
        break;
    default:
        cout << "Enter a number between 0 and 3. Try again: " << endl;
        cin >> t;
        goto typeTry;
        break;
    }
    rna2.seq = new char [len+1];
    start:
    cout << "Enter you sequence: ";
    for(int i = 0 ; i  < len; i++){
        cin >> s;
        if(s == 'A' || s == 'G' || s == 'U' || s == 'C'){
            rna2.seq[i] = s;
        }else{
            cout << "Please enter only A or T or G or C" << endl;
            goto start;
        }
    }
    rna2.seq[len] = '\0';
    return in;
}
ostream& operator<<(ostream& out, RNA &rna)
{
    rna.Print();
    return out;
}
//Function to add two RNA sequences .
RNA RNA::operator+(RNA &inseq)
{
    int length1=0, length2=0;
    while(seq[length1] != '\0'){
        length1++;
    }
    length1++;

    while(inseq.seq[length2] != '\0'){
        length2++;
    }
    length2++;

    int newLength = length2 + length1-1;
    char *addedSeq = new char[newLength];
    for(int i=0; i<length1-1; i++){
        addedSeq[i]=seq[i];
    }
    for(int i=length1-1; i<newLength; i++){
        addedSeq[i] = inseq.seq[abs(length1-1-i)];
    }
    RNA sum1(addedSeq, type);
    return sum1;
}
bool RNA::operator==(RNA& inseq)
{
    int length1 = 0;
    int length2 = 0;
    while(this->seq[length1] != '\0')
    {
        length1++;
    }
    while(inseq.seq[length2] != '\0')
    {
        length2++;
    }
    if(type == inseq.type)
    {
         if(length1 == length2)
    {
        for(int i = 0 ; i < length1 ; i++)
        {
            if(this->seq[i] != inseq.seq[i])
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
bool RNA::operator!=(RNA& inseq)
{
    int length1 = 0;
    int length2 = 0;
    while(this->seq[length1] != '\0')
    {
        length1++;
    }
    while(inseq.seq[length2] != '\0')
    {
        length2++;
    }
    if(type == inseq.type)
    {
         if(length1 == length2)
    {
        for(int i = 0 ; i < length1 ; i++)
        {
            if(this->seq[i] != inseq.seq[i])
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
//function to load sequence from file.
void RNA::loadSequenceFromFile()
{
    string fileName;
    cout << "Enter the name of the file you want to load" << endl;
    cin >> fileName;
    fileName = fileName + ".txt";
    ifstream loadSequence(fileName.c_str());
    int length;
    loadSequence >> length;
    seq = new char[length+1];
    for(int i = 0 ; i <length ; i++)
    {
        loadSequence >> seq[i];
    }
    seq[length] = '\0';
    int h;
    loadSequence >> h;
    switch(h)
    {
    case 0:
        type = mRNA;
        break;
    case 1:
        type = pre_mRNA;
        break;
    case 2:
        type = mRNA_exon;
        break;
    case 3:
        type = mRNA_intron;
        break;
    }

}
//function to create new file for user and save it.
void RNA::saveSequenceToFile()
{
    int length = 0;
    while(seq[length] != '\0')
    {
        length ++;
    }

    string fileName;
    cout << "Enter file name" << endl;
    cin >> fileName;
    fileName = fileName + ".txt";
    ofstream createSequence(fileName.c_str());

    createSequence << length << ' ';

    for(int i=0; i<length; i++)
    {
        createSequence << seq[i];
    }
    createSequence << ' ' << type;

}

//function to check RNA sequence validation.
void RNA::checkRNAValidation()
{
    int length = 0;
    while(seq[length] != '\0')
    {
        length++;
    }

    for(int i = 0 ; i <length ; i++)
    {
        try
        {
            if((seq[i] != 'A') && (seq[i] != 'C') && (seq[i] != 'G') && (seq[i] != 'U'))
            {
                throw 99;
            }
            Seqvalid = true;
        }
        catch(...)
        {
            cout << endl << "Invalid RNA sequence !!!" << endl << endl << "RNA sequence must contain only A , C , G or U"<<endl;
            cout <<  "Try Again : ";
            Seqvalid = false;
        }
    }
}

//function to check RNA Type validation.
void RNA::check_RNAType_Validation(RNA_Type atype)
{
    try
    {
        if((atype != mRNA )&& (atype != pre_mRNA ) && (atype != mRNA_exon ) && (atype != mRNA_intron ))
        {
            throw 98;
        }
        Typevalid = true;
    }
    catch(...)
    {
        cout << endl << "Invalid RNA sequence Type !!!" << endl
             << endl <<"Type of RNA sequence must be one of the following 1-mRNA. \n2-pre_mRNA. \n3-mRNA_exon. \n4-mRNA_intron.";
        Typevalid = false;
    }
}

void RNA::operator =(RNA &rna2)
{
    int counter = 0;
    while(rna2.seq[counter] != '\0')
    {
        counter +=1;
    }
    seq = new char[counter+1];
    for(int i=0; i<counter; i++)
    {
        seq[i] = rna2.seq[i];
    }
    seq[counter] = '\0';
    type = rna2.type;
}

char RNA::getElementInSeq(int index){
    return seq[index];
}
