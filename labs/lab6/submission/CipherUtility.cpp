#include "CipherUtility.h"

// TODO #5
// Implement the static member function isKeyValid
bool CipherUtility::isKeyValid(const Cipher* cipher){
    for(int i=0;i<cipher->key.length();i++){
        if(!isalpha(cipher->key[i]))
            return false;
    }
    return true;
}

// TODO #6
// Implement the static member function removeNonAlphaCharsHelper
string CipherUtility::removeNonAlphaCharsHelper(string str){
    if(str=="")
        return str;
    if((str[0]>='A'&&str[0]<='Z')||(str[0]>='a'&&str[0]<='z')){
        return str[0]+removeNonAlphaCharsHelper(str.substr(1));
    }
    return removeNonAlphaCharsHelper(str.substr(1));
}