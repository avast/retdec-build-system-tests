
#include <iostream>

#include <retdec/fileformat/fileformat.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Expecting one argument - path to binary file\n";
		return 1;
	}
	std::string input = argv[1];

	auto file = retdec::fileformat::createFileFormat(input);
	if (file)
	{
		std::cout << "File '" << input << "':" << std::endl;
		std::cout << "\t" << "md5    = " << file->getMd5() << std::endl;
		std::cout << "\t" << "crc32  = " << file->getCrc32() << std::endl;
		std::cout << "\t" << "sha256 = " << file->getSha256() << std::endl;
	}
	else
	{
		std::cerr << "Error: parsing failed for '" << input << "'\n";
		return 1;
	}

	return 0;
}
