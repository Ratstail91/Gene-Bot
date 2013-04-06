#ifndef ERROR_H_
#define ERROR_H_

#include <string>

class Error {
public:
	Error();
	Error(std::string s);
	virtual ~Error() {};

	virtual std::string GetError();
	virtual std::string GetMessage();
protected:
	std::string message;
};

class LogicError : public Error {
public:
	LogicError();
	LogicError(std::string s);
	virtual ~LogicError() {};

	virtual std::string GetError();
	
};

class RuntimeError : public Error {
public:
	RuntimeError();
	RuntimeError(std::string s);
	virtual ~RuntimeError() {};

	virtual std::string GetError();
	
};

#endif
