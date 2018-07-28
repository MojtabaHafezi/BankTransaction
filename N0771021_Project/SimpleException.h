/*
Plagiarism Declaration
I am aware of the University’s rules on plagiarism and collusion and I understand that,
if I am found to have broken these rules, it will be treated as Academic Misconduct and dealt with accordingly.
I understand that if I lend this piece of work to another student and they copy all or part of it, either with or
without my knowledge or permission, I shall be guilty of collusion.  In submitting this work, I confirm that
I am aware of, and am abiding by, the University’s expectations for proof-reading.

Name: Mojtaba Hafezi ID No: N0771021
*/

#pragma once
#include <stdexcept>
//simple excpetion class for errors - displays error message. no error handling
class SimpleException : public std::exception
{
public:
	//further the message to the standard exception class to use the "what()" for output
	SimpleException(const char *message) : std::exception(message) {}
	~SimpleException() throw() {}

};