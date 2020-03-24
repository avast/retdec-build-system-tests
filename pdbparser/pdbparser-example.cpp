
#include <iostream>

#include "retdec/pdbparser/pdb_file.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: Expecting one argument - path to PDB file\n";
		return 1;
	}
	std::string input = argv[1];

	retdec::pdbparser::PDBFile pdbFile;
	auto state = pdbFile.load_pdb_file(input.c_str());

	if (state == retdec::pdbparser::PDB_STATE_OK)
	{
		std::cout << "PDB file loaded OK" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "PDB file loaded NOT OK" << std::endl;
		return 1;
	}
}
