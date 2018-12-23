#include "Sequence.h"

Sequence::Sequence()
{

}

Sequence::Sequence(int length){
    cout << "Enter the sequence" << endl;
    seq = new char[length];
    char p;
    for(int i=0; i<length; i++){
        cin >> p;
        seq[i] = p;
    }
}

Sequence::Sequence(Sequence& rhs){
    int length = 0;
    while(rhs.seq[length] != '\0'){
        length++;
    }
    length++;

    for(int i=0; i<length; i++){
        seq[i] = rhs.seq[i];
    }
}

Sequence::~Sequence()
{
    delete[] seq;
}

char* Align(Sequence * s1, Sequence * s2, int n, int m){
    int **arr = new int *[m+1];
    for(int i=0; i<n+1; i++){
        arr[i] = new int[m+1];
    }
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            arr[i][j] = 0;
        }
    }
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(s2->seq[i-1] == s1->seq[j-1]){
                arr[i][j] = arr[i-1][j-1] +1;
            }else{
                if(arr[i-1][j] > arr[i][j-1]){
                    arr[i][j] = arr[i-1][j];
                }else{
                    arr[i][j] = arr[i][j-1];
                }
            }
        }
    }

    int lengthOfSeq = arr[m][n];
    int loop = lengthOfSeq;
    char *validSeq = new char[lengthOfSeq];
    validSeq[lengthOfSeq] = '\0'; ///come back
    while(lengthOfSeq >= 0 && m != 0 && n != 0){
        if(arr[m][n] == arr[m-1][n] && arr[m][n] == arr[m][n-1]){
            n--;
        }else if(arr[m][n-1] == arr[m-1][n] && arr[m][n] > arr[m][n-1]){
            validSeq[lengthOfSeq-1] = s2->seq[m-1];
            m--;
            n--;
            lengthOfSeq--;
        }else{
            if(arr[m][n-1] > arr[m-1][n]){
                n--;
            }else{
                m--;
            }
        }
    }
    for(int i=0; i<loop; i++){
        cout << validSeq[i] << ' ';
    }
    cout << endl;

    return validSeq;
   /**int L[m+1][n+1];
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0){
         L[i][j] = 0;
       }
       else if (s1->seq[i-1] == s2->seq[j-1]){
         L[i][j] = L[i-1][j-1] + 1;
       }
       else{
         L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
     }
   }

   int size1 = L[m][n];

   char lcs[size1+1];
   lcs[size1] = '\0'; // Set the terminating character

   int loop = size1;

   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      if (s1->seq[i-1] == s2->seq[j-1])
      {
          lcs[i-1] = s1->seq[i-1]; // Put current character in result
          i--; j--; size1--;
      }

      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1]){
         i--;
      }
      else{
         j--;
      }
   }

   for(int i=0; i<loop+1; i++){
    cout << lcs[i] << ' ';
   }
   cout << endl;

   return lcs;

   // Print the lcs
   ///cout << "LCS of " << s1 << " and " << s2 << " is " << lcs;*/
}
