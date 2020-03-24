
#include <iostream>

#include <rapidjson/error/en.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/encodings.h>

#include <retdec/common/address.h>
#include <retdec/serdes/address.h>

int main(int argc, char* argv[])
{
	retdec::common::Address addr(0x12345678);

	rapidjson::StringBuffer sb;
	rapidjson::PrettyWriter<rapidjson::StringBuffer, rapidjson::ASCII<>> writer(sb);

	writer.StartObject();
	writer.String("address");
	retdec::serdes::serialize(writer, addr);
	writer.EndObject();

	std::cout << addr << " serialized: \n"
		<< sb.GetString()
		<< std::endl;

	return 0;
}
