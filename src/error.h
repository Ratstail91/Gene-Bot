#ifndef ERROR_H_
#define ERROR_H_

#include <exception>
#include <string>

/* -------------------------
 * Error base class
 * -------------------------
*/

class Error : public std::exception {
public:
	Error();
	Error(std::string s);
	virtual ~Error() noexcept {};

	virtual std::string GetError();
	virtual std::string GetMessage();

	virtual const char* what() const noexcept;
protected:
	std::string title;
	std::string message;
};

/* -------------------------
 * LogicError base class
 * -------------------------
*/

class LogicError : public Error {
public:
	LogicError();
	LogicError(std::string s);
	virtual ~LogicError() noexcept {};
};

/* -------------------------
 * DomainError
 * -------------------------
*/

class DomainError : public LogicError {
public:
	DomainError();
	DomainError(std::string s);
	virtual ~DomainError() noexcept {};
};

/* -------------------------
 * InvalidArgument
 * -------------------------
*/

class InvalidArgument : public LogicError {
public:
	InvalidArgument();
	InvalidArgument(std::string s);
	virtual ~InvalidArgument() noexcept {};
};

/* -------------------------
 * LengthError
 * -------------------------
*/

class LengthError : public LogicError {
public:
	LengthError();
	LengthError(std::string s);
	virtual ~LengthError() noexcept {};
};

/* -------------------------
 * OutOfRange
 * -------------------------
*/

class OutOfRange : public LogicError {
public:
	OutOfRange();
	OutOfRange(std::string s);
	virtual ~OutOfRange() noexcept {};
};

/* -------------------------
 * RuntimeError base class
 * -------------------------
*/

class RuntimeError : public Error {
public:
	RuntimeError();
	RuntimeError(std::string s);
	virtual ~RuntimeError() noexcept {};
};

/* -------------------------
 * RangeError
 * -------------------------
*/

class RangeError : public RuntimeError {
public:
	RangeError();
	RangeError(std::string s);
	virtual ~RangeError() noexcept {};
};

/* -------------------------
 * OverflowError
 * -------------------------
*/

class OverflowError : public RuntimeError {
public:
	OverflowError();
	OverflowError(std::string s);
	virtual ~OverflowError() noexcept {};
};

/* -------------------------
 * UnderflowError
 * -------------------------
*/

class UnderflowError : public RuntimeError {
public:
	UnderflowError();
	UnderflowError(std::string s);
	virtual ~UnderflowError() noexcept {};
};


#endif
