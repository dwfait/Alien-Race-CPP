#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include "Exception.h"


class BadConvert : public Exception
{
public:
	BadConvert(std::string msg) : Exception(msg)
	{}
};





 template<typename T>
 inline std::string toString(const T& x)
 {
   std::ostringstream o;
   if (!(o << x))
     throw BadConvert(std::string("toString(")
                         + typeid(x).name() + ")");
   return o.str();
 }

 template<typename T>
 inline T stringTo(const std::string& str)
 {
	T x;
   std::istringstream o(str);
   if (!(o >> x))
     throw BadConvert(std::string("stringTo(")
                         + typeid(x).name() + ")");
   return x;
 }