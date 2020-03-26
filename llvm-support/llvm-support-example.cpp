
#include <iostream>

#include <retdec/llvm-support/diagnostics.h>

int main(int argc, char* argv[])
{
	retdec::llvm_support::printErrorMessage("this", " is", " error", " msg");
	retdec::llvm_support::printWarningMessage("this", " is", " warning", " msg");
	retdec::llvm_support::printInfoMessage("this", " is", " info", " msg");

	retdec::llvm_support::printPhase("phase");
	retdec::llvm_support::printSubPhase("sub-phase");

	retdec::llvm_support::printColoredLine(
			llvm::outs(),
			llvm::raw_ostream::Colors::GREEN,
			true, // bold
			"this", " should", " be", " bold green"
	);

	return 0;
}
