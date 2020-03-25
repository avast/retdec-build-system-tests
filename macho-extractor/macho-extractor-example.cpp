
#include <iostream>

#include <retdec/macho-extractor/break_fat.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Expecting one argument - path to universal Mach-O\n";
		return 1;
	}
	std::string input = argv[1];

	retdec::macho_extractor::BreakMachOUniversal machoExtr(input);
	if (!machoExtr.isValid())
	{
		std::cerr << "Error: failed to parse universal Mach-O" << std::endl;
		return 1;
	}

	if (!machoExtr.listArchitectures(std::cout))
	{
		std::cerr << "Error: failed to list architectures" << std::endl;
		return 1;
	}

	return 0;
}
