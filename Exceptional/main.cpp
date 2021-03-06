#include "stdafx.h"

#include <iostream>

#include "RangeInt.h"


int main() 
{
	RangeInt range;
	
	try {
		range.setLower(10);
	} catch(const std::logic_error& e) { std::cout << "an exception was caught, with message '" << e.what() << "'\n"; } //throws

	try	{
		range.setUpper(-9);
	} catch (const std::exception& e) { std::cout << "a standard exception was caught, with message '" << e.what() << "'\n"; } //throws

	try {
		range.setValue('-9');
	}
	catch (const std::exception& e) { std::cout << "a standard exception was caught, with message '" << e.what() << "'\n"; } //no throw

	try {
		range.setLower("-100");
	} catch (const std::exception& e) { std::cout << "a standard exception was caught, with message '" << e.what() << "'\n"; } //no throw

	try	{
		range.setUpper('100');
	} catch (const std::exception& e) { std::cout << "a standard exception was caught, with message '" << e.what() << "'\n"; } //no throw

	try {
		range.setValue(100); //throw is swallowed and then ensured
	} catch (const std::exception& e) { std::cout << "a standard exception was caught, with message '" << e.what() << "'\n"; } //no throw

	try {
		range.setUpper(-100);
	} catch (const std::exception& e) { std::cout << "a standard exception was caught, with message '" << e.what() << "'\n"; } //throws

	try {
		range.setValue("-9.c");
	} catch (const std::exception& e) { std::cout << "a standard exception was caught, with message '" << e.what() << "'\n"; } //no throw

	return 0;
}

