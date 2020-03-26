
#include <iostream>
#include <memory>

#include <retdec/utils/conversion.h>
#include <retdec/capstone2llvmir/capstone2llvmir.h>

// byte ptr [0x12345678], 0x11
std::vector<uint8_t> code = retdec::utils::hexStringToBytes("80 05 78 56 34 12 11 00");

int main(int argc, char* argv[])
{
	llvm::LLVMContext ctx;
	llvm::Module module("test", ctx);

	auto* f = llvm::Function::Create(
			llvm::FunctionType::get(llvm::Type::getVoidTy(ctx), false),
			llvm::GlobalValue::ExternalLinkage,
			"root",
			&module);
	llvm::BasicBlock::Create(module.getContext(), "entry", f);
	llvm::IRBuilder<> irb(&f->front());

	try
	{
		auto c2l = retdec::capstone2llvmir::Capstone2LlvmIrTranslator::createArch(
				CS_ARCH_X86,
				&module,
				CS_MODE_32,
				CS_MODE_LITTLE_ENDIAN);

		c2l->translate(code.data(), code.size(), 0x1000, irb);

		module.print(llvm::outs(), nullptr);
	}
	catch (...)
	{
		std::cerr << "Error: something went wrong!" << std::endl;
		return 1;
	}

	return 0;
}
