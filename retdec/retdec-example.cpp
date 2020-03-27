
#include <iostream>

#include <retdec/loader/loader.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Expecting one argument - path to binary file\n";
		return 1;
	}
	std::string input = argv[1];

	auto image = retdec::loader::createImage(input);
	if (image)
	{
		std::cout << "File '" << input << "':" << std::endl;
		std::cout << "\t" << "base addr    = "
				<< std::hex << image->getBaseAddress() << std::endl;
		std::cout << "\t" << "segments num = "
				<< image->getNumberOfSegments() << std::endl;
		for (const auto& s : image->getSegments())
		{
			std::cout << "\t" << "seg "	<< s->getName()
				<< " @ " << std::hex << s->getAddress() << std::endl;
		}
	}
	else
	{
		std::cerr << "Error: parsing failed for '" << input << "'\n";
		return 1;
	}

	return 0;
}
