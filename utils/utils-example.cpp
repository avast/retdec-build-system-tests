
#include <iostream>

#include <retdec/utils/binary_path.h>

int main(int argc, char* argv[])
{
	std::cout << "This binary path: "
		<< retdec::utils::getThisBinaryPath().getAbsolutePath()
		<< std::endl;

	return 0;
}
