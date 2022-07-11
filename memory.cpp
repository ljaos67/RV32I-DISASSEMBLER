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
#include <fstream>
#include "memory.h"
#include "hex.h"
#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;


memory::memory(uint32_t siz)
{
	siz = (siz+15)&0xfffffff0;	// round size mod-16
	while(siz != 0x00000000)	// populate mem w default values
	{
		mem.push_back(0xa5);
		siz += 0xffffffff;
	}
}
memory::~memory()
{
	mem.clear();	// empties vector
}

bool memory::check_illegal(uint32_t i) const	
{
	uint32_t siz = mem.size();
	if(i >= siz)
	{
		cout << "WARNING: Address out of range: " << hex::to_hex0x32(i) <<endl;
		return true;
	}
	else
	{
		return false;
	}
}

uint32_t memory::get_size() const 
{
	uint32_t siz = mem.size();
	siz = (siz+15)&0xfffffff0;
	return siz;
}

uint8_t memory::get8(uint32_t addr) const
{
	if(check_illegal(addr))
	{
		return 0x00; 	
	}
	else
	{
		return mem.at(addr);
	}
}
uint16_t memory::get16(uint32_t addr) const
{	
	uint16_t val = get8(addr);	// grabs address in little endian order
	addr += 0x00000001;
	uint16_t val2 = get8(addr);
	val2 <<= 8;
	val += val2;
	return val;

}
uint32_t memory::get32(uint32_t addr) const
{	
	uint32_t val = get16(addr);
	addr += 0x00000002;
	uint32_t val2 = get16(addr);
	val2 <<= 16;
	val += val2;
	return val;
}
int32_t memory::get8_sx(uint32_t addr) const
{
	int32_t aloc = get8(addr);
	return aloc | (aloc&0x00000080 ? 0xffffff00 : 0);
}
int32_t memory::get16_sx(uint32_t addr) const
{
	int32_t aloc = get16(addr);
	return aloc | (aloc&0x00008000 ? 0xffff0000 : 0);
}
int32_t memory::get32_sx(uint32_t addr) const
{
	return get32(addr);
}
void memory::set8(uint32_t addr, uint8_t val)
{
	if(check_illegal(addr))
	{
		// does nothing if addressis illegal
	}
	else
	{
		mem.at(addr) = val;
	}
}
void memory::set16(uint32_t addr, uint16_t val)
{
	uint16_t chk = val;
	val <<= 8;
	val >>= 8;
	set8(addr,val);
	chk >>= 8;
	addr += 0x00000001;
	set8(addr,chk);
}
void memory::set32(uint32_t addr, uint32_t val)
{
	uint32_t chk = val;
	val <<= 16;
	val >>= 16;
	set16(addr,val);
	chk >>= 16;
	addr += 0x0000002;
	set16(addr,chk);
}
void memory::dump() const
{
	int cnt = 0;
	int num = get_size();
	int icnt = 0;
	uint8_t ch;
	while(cnt < num)	// outer loop goes though mem
	{
			// inner loop for 16 byte printing
			cout << hex::to_hex32(cnt) << ": ";
			while(icnt < 8)
			{
				std::cout << hex::to_hex8(get8(cnt)) << " ";
				cnt++;
				icnt++;
			}
			std::cout << " ";
			while(icnt < 16)
			{
				std::cout << hex::to_hex8(get8(cnt)) << " ";
				cnt++;
				icnt++;
			}
			cout << "*";
			cnt -= 16;
			for(int i = 0; i < 16; i++)
			{
				ch = get8(cnt);
				ch = isprint(ch) ? ch : '.';
				cout << ch;
				cnt++;
			}
			cout << "*";
			cout << endl;
			icnt = 0;	
	}
}
bool memory::load_file(const std::string &fname)
{
	std::ifstream infile(fname, std::ios::in|std::ios::binary);
	if(infile.fail())
	{
		cerr << "can't open file '" << fname << "' for reading" << endl; 
	}
	uint8_t i;
	infile >> std::noskipws;
	for (uint32_t addr = 0; infile >> i; ++addr)
	{
		if(check_illegal(addr))
		{
			cerr << "Program too big." << endl;
			return 0;
		}
		else
		{
			mem.at(addr) = i;
		}
	}
	return 1;
}
