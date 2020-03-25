
#include <iostream>

#include <retdec/config/config.h>

int main(int argc, char* argv[])
{
	retdec::config::Config c;

	c.setInputFile("/home/whatever/input.elf");
	c.setEntryPoint(0x12345678);

	std::cout << c.generateJsonString() << std::endl;

	return 0;
}
