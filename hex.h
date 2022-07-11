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
#ifndef HEX_H
#define HEX_H


class hex
{
	public :
/**
 * Converts a 32-bit unsigned into into a 5-bit hex digit as a string
 *
 * @param uint32_t i is a unsigned integer to be converted into 5-bit hex
 *
 * @return a 5-bit hex string
 *
 ********************************************************************************/
	static std :: string to_hex0x20(uint32_t i);
/**
 * Converts a 32-bit unsigned into into a 3-bit hex digit as a string
 *
 * @param uint32_t i is a unsigned integer to be converted into 3-bit hex
 *
 * @return a 3-bit hex string
 *
 ********************************************************************************/
	static std :: string to_hex0x12(uint32_t i);
/**
 * Takes the input param, converts it to 8 bit hex, type is a string
 *
 * @param an unsigned 8 bit integer to convert into 2 byte hex
 *
 * @return return a std::string with exactly 2 hex digits representing the 8 bits of
 * the i argument.
 ********************************************************************************/
	static std :: string to_hex8 ( uint8_t i);
/**
 * Takes the input param, converts it to 32 bit hex, type is a string
 *
 * @param an unsigned 32 bit integer to convert into 8 byte hex
 *
 * @return return a std::string with exactly 8 hex digits representing the 32 bits of
 * the i argument.
 ********************************************************************************/
	static std :: string to_hex32 ( uint32_t i);
/**
 * Takes the input param, converts it to 32 bit hex, type is a string. Appends 0x
 * to the front of the regular to_hex32() as a display option
 *
 * @param an unsigned 8 bit integer to convert into 8 byte hex
 *
 * @return return a std::string with exactly 8 hex digits representing the 32 bits of
 * the i argument.
 ********************************************************************************/
	static std :: string to_hex0x32 ( uint32_t i);
};

#endif
