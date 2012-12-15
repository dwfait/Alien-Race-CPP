#pragma once

#include <string>


class Exception 
{
private:
	std::string msg;
public:

	Exception(std::string msg)
	{
		this->msg = msg;
	}


	std::string getMessage()
	{
		return msg;
	}

	virtual ~Exception(void)
	{
	}
};
