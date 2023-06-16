#include "array.h"
//completed on 14:02, 25/03

DataMap::DataMap()
    : arraySize(0), keys(nullptr), values(nullptr){
}

DataMap::~DataMap(){
    clear();
}

void DataMap::insert(const string &key, const string &value){
    if(arraySize==0){
        arraySize++;
        keys=new string[arraySize];
        values=new string[arraySize];
        keys[0]=key;
        values[0]=value;
        return;
    }
    arraySize++;
    string* tempKeys=new string[arraySize];
    string* tempVals=new string[arraySize];
    for(int i=0;i<arraySize-1;i++){
        tempKeys[i]=keys[i];
        tempVals[i]=values[i];
    }
    tempKeys[arraySize-1]=key;
    tempVals[arraySize-1]=value;
    delete[] keys;
    delete[] values;
    keys=tempKeys;
    values=tempVals;
    return;
}

string DataMap::find(const string &key) const{
    //linear search over keys, if found return the corresponding value, if not return empty string
    for(int i=0;i<arraySize;i++){
        if(keys[i]==key){
            return values[i];
        }
    }
    return "";
}
 
void DataMap::clear(){
    if(arraySize!=0){
        delete[] keys;
        delete[] values;
        keys=nullptr;
        values=nullptr;
        arraySize=0;
    }
}