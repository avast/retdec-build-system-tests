
#include <iostream>

#include "retdec/yaracpp/yaracpp.h"

int main(int argc, char* argv[])
{
	retdec::yaracpp::YaraDetector yaraDetector;
	yaraDetector.addRules(R"(
rule ExampleRule
{
    strings:
        $my_text_string = "text here"
        $my_hex_string = { E2 34 A1 C8 23 FB }

    condition:
        $my_text_string or $my_hex_string
}
)");

	if (yaraDetector.isInValidState())
	{
		std::cout << "YARA detector in valid state" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "YARA detector in invalid state" << std::endl;
		return 1;
	}
}
