
#include <iostream>
#include <memory>

#include <retdec/demangler/demangler.h>

int main(int argc, char* argv[])
{
	retdec::demangler::ItaniumDemangler demangler;

	std::string name = "__ZN1A1B6myFuncEii";

	std::cout << "'" << name << "'"
			<< "  ->  " << demangler.demangleToString(name)
			<< std::endl;

	return 0;
}
