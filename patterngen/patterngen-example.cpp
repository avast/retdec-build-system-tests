
#include <iostream>

#include <retdec/patterngen/patterngen.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Expecting one argument - path to binary file\n";
		return 1;
	}
	std::string input = argv[1];

	retdec::patterngen::PatternExtractor patternExtr(input);
	if (!patternExtr.isValid())
	{
		std::cerr << "Error: pattern extractor construction failed '"
				<< input << "'\n";
		return 1;
	}

	std::cout << "Detected rules for '" << input << "':\n";
	patternExtr.printRules(std::cout);

	return 0;
}
