#include "handler.h"

HandlerModule::~HandlerModule(){
}

void HandlerModule::print() const{
    std::cout << "Module name = " << m_name << ", this is a Handler, can handle topic = " << topic << std::endl;
}

void HandlerModule::trainData(const string &question, const string &answer){
    data.insert(question, answer);
}

string HandlerModule::answer(const string &question) const{
    string transQ=question;
    if(languageFilter){
        transQ=languageFilter->translatePreData(question);
    }
    if(toneFilter){
        transQ=toneFilter->translatePreData(transQ);
    }
    string ans=inneranswer(transQ);
    if(toneFilter){
        ans=toneFilter->translatePostData(ans);
    }
    if(languageFilter){
        ans=languageFilter->translatePostData(ans);
    }
    return ans;
}

string HandlerModule::inneranswer(const string &question) const{
    string ans=data.find(question);
    if(ans=="")
        return "Sorry, I don't know";
    return ans;
}

HandlerMap::HandlerMap()
    : arraySize(0), names(nullptr), handlerModules(nullptr){
}

HandlerMap::~HandlerMap(){
    clear();
}

void HandlerMap::insert(string key, HandlerModule* value){
    if(arraySize==0){
        arraySize++;
        names=new string[arraySize];
        handlerModules=new HandlerModule*[arraySize];
        names[0]=key;
        handlerModules[0]=value;
        return;
    }
    arraySize++;
    string* tempNames=new string[arraySize];
    HandlerModule** tempHM=new HandlerModule*[arraySize];
    for(int i=0;i<arraySize-1;i++){
        tempNames[i]=names[i];
        tempHM[i]=handlerModules[i];
    }
    tempNames[arraySize-1]=key;
    tempHM[arraySize-1]=value;
    delete[] names;
    delete[] handlerModules;
    names=tempNames;
    handlerModules=tempHM;
    return;
}

HandlerModule* HandlerMap::find(const string& key) const{
    for(int i=0;i<arraySize;i++){
        if(names[i]==key){
            return handlerModules[i];
        }
    }
    return nullptr;
}

string HandlerMap::getNames(int index) const{
    if(index<0||index>arraySize-1){
        return "";
    }
    return names[index];
}

void HandlerMap::clear(){
    if(arraySize!=0){
        delete[] names;
        delete[] handlerModules;
        names=nullptr;
        handlerModules=nullptr;
        arraySize=0;
        //dont have to delete all the members of handlerModules since we dont allocate them
    }
}