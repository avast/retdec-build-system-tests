
#include <iostream>

#include <retdec/pelib/PeFile.h>
#include <retdec/pelib/PeLib.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Expecting one argument - path to PE file\n";
		return 1;
	}
	std::string input = argv[1];

	PeLib::PeFile* pe = PeLib::openPeFile(input);
	if (pe)
	{
		try
		{
			pe->readMzHeader();

			std::cout << "Parsing succeeded for '" << input << "'\n";
			std::cout << "MZ header size = " << pe->mzHeader().size() << "\n";
		}
		catch (...)
		{
			std::cerr << "Error: parsing failed for '" << input << "'\n";
			return 1;
		}
	}
	else
	{
		std::cerr << "Error: parsing failed for '" << input << "'\n";
		return 1;
	}

	return 0;
}
