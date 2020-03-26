
#include <iostream>
#include <memory>

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/raw_ostream.h>

#include <retdec/llvmir-emul/llvmir_emul.h>

/**
 * Parse the provided LLVM IR @c code into a LLVM module.
 * @param code LLVM IR code string.
 * @param ctx LLVM IR context.
 * @return LLVM module created by parsing the provided @c code.
 */
std::unique_ptr<llvm::Module> parseInput(
		const std::string& code,
		llvm::LLVMContext& ctx)
{
	std::string c =
			"target datalayout = \"e-p:32:32:32-f80:32:32\"\n"
			+ code;
	auto mb = llvm::MemoryBuffer::getMemBuffer(c);
	if (mb == nullptr)
	{
		std::cerr << "failed to create llvm::MemoryBuffer" << std::endl;
		exit(1);
	}

	llvm::SMDiagnostic err;
	auto module = parseIR(mb->getMemBufferRef(), err, ctx);
	if (module == nullptr)
	{
		std::cerr << "invalid LLVM IR" << std::endl;
		exit(1);
	}

	return module;
}

int main(int argc, char* argv[])
{
	std::string input(R"(
		define i32 @f() {
			%a = add i32 1, 2    ; 1 + 2 = 3
			%b = add i32 %a, 3   ; 3 + 3 = 6
			%c = mul i32 %a, %b  ; 3 * 6 = 18
			ret i32 %c           ; return 18
		}
	)");

	llvm::LLVMContext context;
	auto module = parseInput(input, context);
	auto* f = module->getFunction("f");

	retdec::llvmir_emul::LlvmIrEmulator emu(module.get());
	emu.runFunction(f);

	std::cout << "emulated program exit value = "
		<< emu.getExitValue().IntVal.getZExtValue()
		<< std::endl;

	return 0;
}
