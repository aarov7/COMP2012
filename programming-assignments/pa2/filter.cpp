#include "filter.h"

FilterModule::~FilterModule(){
}//no dynamically allocated members

void FilterModule::print() const{
    std::cout << "Module name = " << m_name << ", this is a filter, filter type = " << getFilterType(type) << std::endl;
}

void FilterModule::trainPreData(const string &source, const string &target){
    preData.insert(source,target);
}

void FilterModule::trainPostData(const string &source, const string &target){
    postData.insert(source,target);
}

string FilterModule::translatePreData(string question) const{
    string ans=preData.find(question);
    if(ans!=""){
        return ans;
    }
    return question;
}

string FilterModule::translatePostData(string question) const{
    string ans=postData.find(question);
    if(ans!=""){
        return ans;
    }
    return question;
}

void FilterArray::insert(FilterModule* input){
    if (0 == arraySize)
    {
        arraySize = 1;
        array = new FilterModule*[1];
        array[0] = input;
        return;
    }
    arraySize++;
    FilterModule** temp = new FilterModule*[arraySize];
    for (int i = 0; i < arraySize - 1; i++)
    {
        temp[i] = array[i];
    }
    temp[arraySize - 1] = input;
    delete[] array;
    array = temp;
    return;
}

FilterModule* FilterArray::get(int index) const{
    if(index<0||index>arraySize-1)
        return nullptr;
    return array[index];
}