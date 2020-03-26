
#include <iostream>
#include <memory>
#include <sstream>

#include <retdec/ctypesparser/json_ctypes_parser.h>

int main(int argc, char* argv[])
{
	std::stringstream json(R"(
{
	"functions": {
		"ff": {
			"decl": "long ff(int b);",
			"header": "CHeader.h",
			"name": "ff",
			"params": [
				{
					"name": "b",
					"type": "46f8ab7c0cff9df7cd124852e26022a6bf89e315"
				}
			],
			"ret_type": "3338ab7c0cff9df7cd124852e26022a6bf89e315"
		}
	},
	"types": {
		"46f8ab7c0cff9df7cd124852e26022a6bf89e315": {
			"name": "int",
			"type": "integral_type"
		},
		"3338ab7c0cff9df7cd124852e26022a6bf89e315": {
			"name": "long",
			"type": "integral_type"
		}
	}
}
	)");
	retdec::ctypesparser::CTypesParser::TypeWidths typeWidths{
			{"int", 32},
			{"long", 64}
	};

	retdec::ctypesparser::JSONCTypesParser parser;

	auto mod = parser.parse(json, typeWidths);
	auto func = mod->getFunctionWithName("ff");

	if (func)
	{
		std::cout << "function's 'ff' return type is"
			<< "'" << func->getReturnType()->getName() << "'"
			<< std::endl;
	}
	else
	{
		std::cerr << "Error: parsing failed" << std::endl;
		return 1;
	}

	return 0;
}
