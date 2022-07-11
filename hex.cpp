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
#include <iostream>
#include <iomanip>
#include <cstdint>
#include <sstream>
#include "hex.h"

using std::hex;
using std::dec;
using std::cout;
using std::cin;
using std::endl;
using std::setfill;
using std::setw;

std::string hex::to_hex0x20(uint32_t i)
{
	std::ostringstream os;
	os << std::hex << std::setfill('0') << std::setw(5) << i;
	return std::string("0x") + os.str();
}
std::string hex::to_hex0x12(uint32_t i)
{
	i &= 0x00000fff;
	std::ostringstream os;
	os << std::hex << std::setfill('0') << std::setw(3) << (int)i;
	return std::string("0x") + os.str();	
}
std::string hex::to_hex8(uint8_t i)
{
	std::ostringstream os;
	os << std::hex << std::setfill('0') << std::setw(2) << static_cast<uint16_t>(i);
	return os.str();
}

std::string hex::to_hex32(uint32_t i)
{
	std::ostringstream os;
	os << std::hex << std::setfill('0') << std::setw(8) << static_cast<uint64_t>(i);
	return os.str();
}

std::string hex::to_hex0x32(uint32_t i)
{
	return std::string("0x")+to_hex32(i);
}



