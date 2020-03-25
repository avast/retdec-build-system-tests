
#include <iostream>

#include <retdec/crypto/hash_context.h>

int main(int argc, char* argv[])
{
	std::string data = "hello world";

	retdec::crypto::HashContext hctx;
	hctx.init(retdec::crypto::HashAlgorithm::Sha256);
	hctx.addData(reinterpret_cast<const uint8_t*>(data.data()), data.size());

	std::cout << "'" << data << "' sha256 hash = "
			<< std::hex << hctx.getHash() << std::endl;

	return 0;
}
