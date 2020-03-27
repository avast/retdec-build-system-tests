
#include <iostream>
#include <memory>

#include <retdec/utils/dynamic_buffer.h>
#include <retdec/unpacker/signature.h>

int main(int argc, char* argv[])
{
	retdec::unpacker::Signature sig = { 0x62, 0x63 };
	retdec::utils::DynamicBuffer matchedBuffer({ 0x60, 0x61, 0x62, 0x63, 0x64 });
	retdec::unpacker::Signature::MatchSettings settings(0, 5);

	std::cout << "signature matched : "
		<< sig.match(settings, matchedBuffer)
		<< std::endl;

	return 0;
}
