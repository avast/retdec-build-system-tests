
#include <iostream>

#include <retdec/ar-extractor/archive_wrapper.h>
#include <retdec/ar-extractor/detection.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Expecting one argument - path to archive\n";
		return 1;
	}
	std::string input = argv[1];

	if (!retdec::ar_extractor::isArchive(input))
	{
		std::cerr << "Error: file is not an archive '" << input << "'\n";
		return 1;
	}

	bool succ = false;
	std::string errMsg;
	retdec::ar_extractor::ArchiveWrapper arch(input, succ, errMsg);

	if (!succ)
	{
		std::cerr << "Error: failed to parse archive: '" << errMsg << "'\n";
		return 1;
	}

	std::string objNames;
	if (!arch.getPlainTextList(objNames, errMsg, true, true))
	{
		std::cerr << "Error: failed to get obj names: '" << errMsg << "'\n";
		return 1;
	}

	std::cout << "Object file names in archive: '" << objNames << "'"
			<< std::endl;

	return 0;
}
