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

#ifndef MEMORY_H
#define MEMORY_H
#include <vector>
#include <string>
#include "hex.h"

class memory : public hex
{
public :
/**
 * constructor for memory object. Allocate siz bytes in the mem vector and initialize
 * every byte/element to 0xa5.
 *
 * @param unsignged 32 bit integer s that represents the size of our memory
 *
 * @note function rounds length up by mod-16
 ********************************************************************************/
	memory ( uint32_t s);
/**
 * Deconstructs any allocated objects.
 *
 * @note No memory is dynamically allocated, but memory is cleared in vector
 ********************************************************************************/
	~ memory ();
/**
 * Checks if addr parameter is within the bounds of our simulated memory.
 *
 * @param unsigned 32 bit integer i used to represent address to check within bounds
 *
 * @return returns 1 is the address is out of bounds and 0 if the address is not
 *
 * @note prints a warning message if the address is out of bounds
 ********************************************************************************/	
	bool check_illegal ( uint32_t addr ) const ;
/**
 * Get function for the mem object that returns the size of the memory
 *
 * @return a 32-bit unsigned integer containing the size of our simulated mem
 *
 * @note rounds up by mod-16
 ********************************************************************************/
	uint32_t get_size () const ;
/**
 * Checks if address is valid and returns a byte from the address
 *
 * @param unsigned 32-bit integer addr that represents address to retrieve
 *
 * @return unsigned 8-bit value of the byte from simulated memory at
*  the given address
 *
 * @note Only function that direcly reads from simulated memory
 ********************************************************************************/
	uint8_t get8 ( uint32_t addr ) const ;
/**
 * Returns 2 bytes from address
 *
 * @param unsigned 32-bit integer addr that represents address to retrieve
 *
 * @return unsigned 16-bit value of the byte from simulated memory at
*  the given address
 *
 * @note Calls get8() twice
 ********************************************************************************/
	uint16_t get16 ( uint32_t addr ) const ;
/**
 * Returns 4 bytes from address
 *
 * @param unsigned 32-bit integer addr that represents address to retrieve
 *
 * @return unsigned 32-bit value of the byte from simulated memory at
*  the given address
 *
 * @note Calls get16() twice
 ********************************************************************************/
	uint32_t get32 ( uint32_t addr ) const ;
/**
 * calls get8() and then return the sign-extended value of the 
 * byte as a 32-bit signed integer
 *
 * @param 32-bit unsigned integer addr representing the address of the byte to extend
 *
 * @return the sign-extended value of the byte as a 32-bit signed integer
 ********************************************************************************/
	int32_t get8_sx ( uint32_t addr ) const ;
/**
 * calls get16() and then return the sign-extended value of the 
 * byte as a 32-bit signed integer
 *
 * @param 32-bit unsigned integer addr representing the address of the byte to extend
 *
 * @return the sign-extended value of the byte as a 32-bit signed integer
 ********************************************************************************/
	int32_t get16_sx ( uint32_t addr ) const ;
/**
 * calls get32() and then return the sign-extended value of the 
 * byte as a 32-bit signed integer
 *
 * @param 32-bit unsigned integer representing the address of the byte to extend
 *
 * @return the sign-extended value of the byte as a 32-bit signed integer
 ********************************************************************************/
	int32_t get32_sx ( uint32_t addr ) const ;
/**
 * Writes an 8-bit value into the specified memory 
 *
 * @param unsigned 32-bit integer addr represents the address of the value you
 * want to set
 * @param unsigned 8-bit integer val is the value to be written
 *
 * @note The only function that writes into memory 
 ********************************************************************************/
	void set8 ( uint32_t addr , uint8_t val );
/**
 * Writes an 16-bit value into the specified memory 
 *
 * @param unsigned 32-bit integer addr represents the address of the value you
 * want to set
 * @param unsigned 16-bit integer val is the value to be written 
 ********************************************************************************/
	void set16 ( uint32_t addr , uint16_t val );
/**
 * Writes an 32-bit value into the specified memory 
 *
 * @param unsigned 32-bit integer addr represents the address of the value you
 * want to set
 *
 * @param unsigned 32-bit integer val is the value to be written 
 ********************************************************************************/
	void set32 ( uint32_t addr , uint32_t val );
/**
 * Dump the entire contents of your simulated memory in hex with the corresponding ASCII2
 * characters on the right 
 ********************************************************************************/
	void dump () const ;
/**
 * Open the file named fname in binary mode and read its contents into 
 * the simulated memory
 *
 * @param String fname that represents the file name 
 *
 * @return 1 if file can be opened, 0 if file cannot be opened
 ********************************************************************************/
	bool load_file ( const std :: string & fname );

private:
	// vector that holds byte values of memory
	std :: vector < uint8_t > mem ;
};

#endif 
