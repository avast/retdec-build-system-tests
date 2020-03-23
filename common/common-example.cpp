
#include <iostream>

#include <retdec/common/address.h>

int main(int argc, char* argv[])
{
	retdec::common::Address addr(0x12345678);
	std::cout << "hello world @ " < addr << std::endl;
	return 0;
}
