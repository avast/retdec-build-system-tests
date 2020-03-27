
#include <iostream>

#include <retdec/loader/loader.h>
#include <retdec/rtti-finder/rtti_finder.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Expecting one argument - path to binary file\n";
		return 1;
	}
	std::string input = argv[1];

	auto image = retdec::loader::createImage(input);
	if (!image)
	{
		std::cerr << "Error: parsing failed for '" << input << "'\n";
		return 1;
	}

	retdec::rtti_finder::RttiFinder rtti;
	rtti.findGcc(image.get());
	rtti.findMsvc(image.get());

	std::cout << "has vtables gcc : " << !rtti.getVtablesGcc().empty() << "\n";
	std::cout << "has vtables msvc: " << !rtti.getVtablesMsvc().empty() << "\n";
	std::cout << "has rtti gcc    : " << !rtti.getRttiGcc().empty() << "\n";
	std::cout << "has rtti msvc   : " << !rtti.getRttiMsvc().typeDescriptors.empty() << "\n";

	return 0;
}
