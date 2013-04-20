#include "error.h"

#include <exception>
#include <iostream>

using namespace std;

int main() {
	try {
		throw(InvalidArgument("foobar"));
	}
	catch(exception& e) {
		cerr << e.what() << endl;
		return 1;
	}
	return 0;
}