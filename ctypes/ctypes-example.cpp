
#include <iostream>
#include <memory>

#include <retdec/ctypes/ctypes.h>

int main(int argc, char* argv[])
{
	auto ctx = std::make_shared<retdec::ctypes::Context>();
	retdec::ctypes::Module module(ctx);
	auto intType = retdec::ctypes::IntegralType::create(
			ctx,
			"uint64_t",
			64,
			retdec::ctypes::IntegralType::Signess::Unsigned
	);

	std::cout << "type '" << intType->getName() << "'"
			<< " is " << intType->getBitWidth() << " bits"
			<< std::endl;

	return 0;
}
