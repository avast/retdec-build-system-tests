
#include <iostream>

#include <retdec/retdec/retdec.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Expecting one argument - path to binary file\n";
		return 1;
	}
	std::string input = argv[1];

	retdec::common::FunctionSet fs;
	auto res = retdec::disassemble(input, &fs);

	for (auto& f : fs)
	{
		std::cout << f.getStart() << " @ " << f.getName() << std::endl;
	}

	return 0;
}
