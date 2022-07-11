//***************************************************************************
////
////  Leonart Jaos
////  Z1911688
////  CSCI 463 class #2346 Section 0001
////  Assignment #4
////
////  I certify that this is my own work and where appropriate an extension 
////  of the starter code provided for the assignment.
////
////***************************************************************************
/** @file main.cpp
@author Jaos:Leonart:Z1911688
@version Revision 1.1
@brief This program simulates a system memory. Values are read and displayed. 
int main(int argc, char **argv)
@details Simulates the computer system memory. Reads instructions, decodes 
them, and formats them for printing.  
@date Saturday, October 16, 2021
*/

//Include section
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdint>
#include <getopt.h>
#include <sstream>
#include "hex.h"
#include "memory.h"
#include "rv32i_decode.h"

using namespace std;
/**
 * prints an appropriate “Usage” error message and “Pattern” to
 * stderr and terminates the program 
 *
 *
 * @note Default memory size is 0x100 if no memory is specified
 *
 ********************************************************************************/
 static void usage()
{
	cerr << "Usage: rv32i [-m hex-mem-size] infile" << endl;
	cerr << "    -m specify memory size (default = 0x100)" << endl;
	exit(1);
}
/**
 * Parses through memory to obtain 32-bit instructions. Uses helper functions to 
 * decode instructions and format them as their instruction encodings. 
 *
 * @param &mem is the pointer to our memory vector which contains our sim memory
 *
 ********************************************************************************/
static void disassemble(const memory &mem)
{
	uint32_t ind = 0;
	uint32_t addr = 0x00000000;
	string cde;
	while(ind != mem.get_size())
	{
		cde = rv32i_decode::decode(addr,mem.get32(addr));
		cout << hex::to_hex32(addr) << ": " << hex::to_hex32(mem.get32(addr)) << "  " << cde << endl;
		ind +=4;
		addr+=0x00000004;
	}
	//mem.dump();
}

/**
 * Simulates computer memory, demonstrates set and get function of bytes and displays 
 * memory contents.
 *
 * This function takes a user input memory size and user input of which to store 
 * into memory. The user input is then inserted into a memory object which is used 
 * to store the file input as bytes. Several utility functions are demonstrated below
 * such as a function to set x number of bytes, functions to return x number of bytes,
 * and a function to display the entire memory. 
 *
 * @param argc number of command line arguments
 * @param **argv array containing command line input
 *
 * @return 0 for success 1 for failure
 *
 ********************************************************************************/
int main(int argc, char **argv)
{
	uint32_t memory_limit = 0x100; // default memory size = 256 bytes
	int opt;
	while ((opt = getopt(argc, argv, "m:")) != -1)
	{
		switch (opt)
		{
			case 'm':
				{
					std::istringstream iss(optarg);
					iss >> std::hex >> memory_limit;
				}
				break;
			default: /* '?' */
				usage();
		}
	}
	if (optind >= argc)
		usage(); // missing filename
	memory mem(memory_limit);
	if (!mem.load_file(argv[optind]))
		usage();
	disassemble(mem);
	mem.dump();
	return 0;
}
