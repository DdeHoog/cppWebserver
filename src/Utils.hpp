#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <map>

using namespace std;

template <typename T> class EnumParser
{
    map<string, T> enumMap;
    public:
        EnumParser(){};

    T ParseSomeEnum(const string &value)
    { 
        typename map <string, T>::const_iterator iValue = enumMap.find(value);
        if (iValue  == enumMap.end())
            throw runtime_error("");
        return iValue->second;
    }

    // TODO: implement method parse string to enum
};

#endif