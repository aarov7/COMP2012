#include "VigenereCipher.h"
#include "Utility.h"

// TODO #1
// Initialize the static data member alphabetSize here
const int VigenereCipher::alphabetSize {26};

// TODO #2
// Implement the encrypt member function according to the given algoirthm.
string VigenereCipher::encrypt(string plaintextMsg) const{
    string ans="";
    int keyInd=0;
    for(int i=0;i<plaintextMsg.length();i++){
        if(!isalpha(plaintextMsg[i])){
            ans+=plaintextMsg[i];
            keyInd++;
            continue;
        }
        if(plaintextMsg[i]>='A'&&plaintextMsg[i]<='Z'){
            plaintextMsg[i]+=('a'-'A');//covert to lowercase
        }
        int shift=key[keyInd%key.length()]-'a';
        //std::cout<<"Encrypt shift: "<<shift<<"\n";
        ans+=((plaintextMsg[i]+shift)%'a'%alphabetSize+'a');
        keyInd++;
    }
    return ans; 
}

// TODO #3
// Implement the decrypt member function according to the given algoirthm.
string VigenereCipher::decrypt(string ciphertextMsg) const{
    string ans="";
    int keyInd=0;
    for(int i=0;i<ciphertextMsg.length();i++){
        if(!isalpha(ciphertextMsg[i])){
            ans+=ciphertextMsg[i];
            keyInd++;
            continue;
        }
        if(ciphertextMsg[i]>='A'&&ciphertextMsg[i]<='Z'){
            ciphertextMsg[i]+=('a'-'A');
        }
        int shift=key[keyInd%key.length()]-'a';
        //std::cout<<"Decrypt shift: "<<shift<<"\n";
        ans+=((ciphertextMsg[i]-shift+alphabetSize)%'a'%alphabetSize+'a');
        keyInd++;
    }
    return ans;
}

// TODO #4
// Implement the static member function generateRandomKey
// according to the given algorithm.
string VigenereCipher::generateRandomKey(int length){
    string ans="";
    for(int i=0;i<length;i++){
        ans+=(_rand()%alphabetSize+'a');
    }
    return ans;
}