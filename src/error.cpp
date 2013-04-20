#include "error.h"

/* -------------------------
 * Error base class
 * -------------------------
*/

Error::Error() {
	title = "Error";
	message = "no message";
}

Error::Error(std::string s) {
	title = "Error";
	message = s;
}

std::string Error::GetError() {
	return title + ": " + message;
}

std::string Error::GetMessage() {
	return message;
}

const char* Error::what() const noexcept {
	return (title + ": " + message).c_str();
}

/* -------------------------
 * LogicError base class
 * -------------------------
*/

LogicError::LogicError() {
	title = "LogicError";
	message = "no message";
}

LogicError::LogicError(std::string s) {
	title = "LogicError";
	message = s;
}

/* -------------------------
 * DomainError
 * -------------------------
*/

DomainError::DomainError() {
	title = "DomainError";
	message = "no message";
}

DomainError::DomainError(std::string s) {
	title = "DomainError";
	message = s;
}

/* -------------------------
 * InvalidArgument
 * -------------------------
*/

InvalidArgument::InvalidArgument() {
	title = "InvalidArgument";
	message = "no message";
}

InvalidArgument::InvalidArgument(std::string s) {
	title = "InvalidArgument";
	message = s;
}

/* -------------------------
 * LengthError
 * -------------------------
*/

LengthError::LengthError() {
	title = "LengthError";
	message = "no message";
}

LengthError::LengthError(std::string s) {
	title = "LengthError";
	message = s;
}

/* -------------------------
 * OutOfRange
 * -------------------------
*/

OutOfRange::OutOfRange() {
	title = "OutOfRange";
	message = "no message";
}

OutOfRange::OutOfRange(std::string s) {
	title = "OutOfRange";
	message = s;
}

/* -------------------------
 * RuntimeError base class
 * -------------------------
*/

RuntimeError::RuntimeError() {
	title = "RuntimeError";
	message = "no message";
}

RuntimeError::RuntimeError(std::string s) {
	title = "RuntimeError";
	message = s;
}

/* -------------------------
 * RangeError
 * -------------------------
*/

RangeError::RangeError() {
	title = "RangeError";
	message = "no message";
}

RangeError::RangeError(std::string s) {
	title = "RangeError";
	message = s;
}

/* -------------------------
 * OverflowError
 * -------------------------
*/

OverflowError::OverflowError() {
	title = "OverflowError";
	message = "no message";
}

OverflowError::OverflowError(std::string s) {
	title = "OverflowError";
	message = s;
}

/* -------------------------
 * UnderflowError
 * -------------------------
*/

UnderflowError::UnderflowError() {
	title = "UnderflowError";
	message = "no message";
}

UnderflowError::UnderflowError(std::string s) {
	title = "UnderflowError";
	message = s;
}
