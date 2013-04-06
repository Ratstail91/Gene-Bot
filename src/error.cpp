#include "error.h"

/* Define the Error class
*/

Error::Error() {
	message = "error";
}

Error::Error(std::string s) : message(s) {
}

std::string Error::GetError() {
	return std::string("Error: ") + message;
}

std::string Error::GetMessage() {
	return message;
}

/* Define the LogicError class
*/

LogicError::LogicError() {
	message = "logic error";
}

LogicError::LogicError(std::string s) : Error(s) {
}

std::string LogicError::GetError() {
	return std::string("Logic Error: ") + message;
}

/* Define the RuntimeError class
*/

RuntimeError::RuntimeError() {
	message = "runtime error";
}

RuntimeError::RuntimeError(std::string s) : Error(s) {
}

std::string RuntimeError::GetError() {
	return std::string("Runtime Error: ") + message;
}
