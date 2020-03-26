
#include <iostream>

#include <retdec/fileformat/fileformat.h>
#include <retdec/cpdetect/cpdetect.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Expecting one argument - path to binary file\n";
		return 1;
	}
	std::string input = argv[1];

	auto file = retdec::fileformat::createFileFormat(input);
	if (!file)
	{
		std::cerr << "Error: parsing failed for '" << input << "'\n";
		return 1;
	}

	retdec::cpdetect::ToolInformation toolInfo;
	retdec::cpdetect::DetectParams detectionParams(
			retdec::cpdetect::SearchType::MOST_SIMILAR,
			true,
			true
	);
	auto detector = retdec::cpdetect::createCompilerDetector(
			*file.get(),
			detectionParams,
			toolInfo
	);

	if (detector)
	{
		detector->getAllInformation();

		std::cout << "Detected tools for '" << input << "':\n";
		for (auto& r : toolInfo.detectedTools)
		{
			std::cout << "\t" << r.name << "\n";
		}
	}
	else
	{
		std::cerr << "Error: parsing failed for '" << input << "'\n";
		return 1;
	}

	return 0;
}
