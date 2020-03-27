
#include <iostream>

#include <retdec/loader/loader.h>
#include <retdec/stacofin/stacofin.h>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cerr << "Error: Expecting 2 arguments:\n"
				<< "\t path to binary file"
				<< "\t path to YARA rules file"
				<< "\n";
		return 1;
	}
	std::string input = argv[1];
	std::string yara = argv[2];

	auto image = retdec::loader::createImage(input);
	if (!image)
	{
		std::cerr << "Error: parsing failed for '" << input << "'\n";
		return 1;
	}

	retdec::stacofin::Finder finder;
	finder.search(*image.get(), yara);
	auto detections = finder.getConfirmedDetections();

	std::cout << "Confirmed detections:" << std::endl;
	for (auto& p : detections)
	{
		std::cout << p.first << " @ " << p.second->getName() << std::endl;
	}

	return 0;
}
