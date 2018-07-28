#pragma once
#include <stdexcept>
//simple excpetion class for errors - displays error message. no error handling
class SimpleException : public std::exception {
public:
	//further the message to the standard exception class to use the "what()" for output
	SimpleException(const char *message) : std::exception(message){}
	~SimpleException() throw(){}

};