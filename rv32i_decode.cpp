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

// include statements
#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <sstream>
#include <cassert>
#include <cstdint>
#include <iomanip>
#include "memory.h"
#include "hex.h"
#include "rv32i_decode.h"

std::string rv32i_decode::decode(uint32_t addr, uint32_t insn)
{
	// parses by opcode of machine instruction
	// Then parses by funct 3 if needed
	// if funct3 is not enough, parses and renders by funct7
	switch(get_opcode(insn))
	{
	default: return render_illegal_insn(insn);
	case opcode_lui: return render_lui(insn);
	case opcode_auipc: return render_auipc(insn);
	case opcode_jal: return render_jal(addr,insn);
	case opcode_jalr: return render_jalr(insn);
	case opcode_btype:
		switch (get_funct3(insn))
		{
		default: return render_illegal_insn(insn);
		case funct3_beq: return render_btype(addr, insn, "beq");
		case funct3_bne: return render_btype(addr, insn, "bne");
		case funct3_blt: return render_btype(addr, insn, "blt");
		case funct3_bge: return render_btype(addr, insn, "bge");
		case funct3_bltu: return render_btype(addr, insn, "bltu");
		case funct3_bgeu: return render_btype(addr, insn, "bgeu");
		}
		assert(0 && "unrecognized funct3"); // impossible
	case opcode_load_imm:
		switch(get_funct3(insn))
		{
		default: return render_illegal_insn(insn);
		case funct3_lb: return render_itype_load(insn, "lb");
		case funct3_lh: return render_itype_load(insn, "lh");
		case funct3_lw: return render_itype_load(insn, "lw");
		case funct3_lbu: return render_itype_load(insn, "lbu");
		case funct3_lhu: return render_itype_load(insn, "lhu");
		}
		assert(0 && "unrecognized funct3"); // impossible
	case opcode_stype:
		switch(get_funct3(insn))
		{
		default: return render_illegal_insn(insn);
		case funct3_sb: return render_stype(insn, "sb");
		case funct3_sh: return render_stype(insn, "sh");
		case funct3_sw: return render_stype(insn, "sw");
		}
		assert(0 && "unrecognized funct3"); // impossible
	case opcode_alu_imm:
		switch (get_funct3(insn))
		{
		default: return render_illegal_insn(insn);
		case funct3_add: return render_itype_alu(insn, "addi", get_imm_i(insn));
		case funct3_slt: return render_itype_alu(insn, "slti", get_imm_i(insn));
		case funct3_sltu: return render_itype_alu(insn, "sltiu", get_imm_i(insn));
		case funct3_xor: return render_itype_alu(insn, "xori", get_imm_i(insn));
		case funct3_or: return render_itype_alu(insn, "ori", get_imm_i(insn));
		case funct3_and: return render_itype_alu(insn, "andi", get_imm_i(insn));
		case funct3_sll: return render_itype_alu(insn, "slli", get_imm_i(insn)%XLEN);
		case funct3_srx:
			switch(get_funct7(insn))
			{
			default: return render_illegal_insn(insn);
			case funct7_sra: return render_itype_alu(insn, "srai", get_imm_i(insn)%XLEN);
			case funct7_srl: return render_itype_alu(insn, "srli", get_imm_i(insn)%XLEN);
			}
			assert(0 && "unrecognized funct7"); // impossible
		}
		assert(0 && "unrecognized funct3"); // impossible
	case opcode_rtype:
		switch(get_funct3(insn))
		{
			default: return render_illegal_insn(insn);
			case funct3_add:
				switch(get_funct7(insn))
				{
				default: return render_illegal_insn(insn);
				case funct7_add: return render_rtype(insn, "add");
				case funct7_sub: return render_rtype(insn, "sub");
				}
				assert(0 && "unrecognized funct7"); // impossible
			case funct3_srx:
				switch(get_funct7(insn))
				{
				default: return render_illegal_insn(insn);
				case funct7_srl: return render_rtype(insn, "srl");
				case funct7_sra: return render_rtype(insn, "sra");
				}
				assert(0 && "unrecognized funct7"); // impossible
			case funct3_sll: return render_rtype(insn,"sll");
			case funct3_slt: return render_rtype(insn,"slt");
			case funct3_sltu: return render_rtype(insn,"sltu");
			case funct3_xor: return render_rtype(insn,"xor");
			case funct3_or: return render_rtype(insn,"or");
			case funct3_and: return render_rtype(insn,"and");
		}
		assert(0 && "unrecognized funct3"); // impossible
	case opcode_system:
		switch(get_funct3(insn))
		{
		default: return render_illegal_insn(insn);
		case funct3_add:
				switch(insn)
				{
				default: return render_illegal_insn(insn);
				case insn_ecall: return render_ecall(insn);
				case insn_ebreak: return render_ebreak(insn);
				}
				assert(0 && "unrecognized funct7"); // impossible
		case funct3_csrrw: return render_csrrx(insn, "csrrw");
		case funct3_csrrs: return render_csrrx(insn, "csrrs");
		case funct3_csrrc: return render_csrrx(insn, "csrrc");
		case funct3_csrrwi: return render_csrrxi(insn, "csrrwi");	
		case funct3_csrrsi: return render_csrrxi(insn, "csrrsi");
		case funct3_csrrci: return render_csrrxi(insn, "csrrci");			
		}
		assert(0 && "unrecognized funct3"); // impossible
	}
	assert(0 && "unrecognized opcode"); // It should be impossible to ever get here!
}
// add 0x to integer output of register
std::string rv32i_decode::render_reg(int r)
{
	return ("x" + std::to_string(r));
}
std::string rv32i_decode::render_base_disp(uint32_t base, int32_t imm)
{
	int val = imm;
	return(std::to_string(val) + "(" + render_reg(base) + ")");
}
std::string rv32i_decode::render_mnemonic(const std::string &mnemonic)
{
if(mnemonic == "ecall" || mnemonic == "ebreak")
{
	return mnemonic;
}
else
{
	std::ostringstream os;
	os << std::left << std::setw(8) << mnemonic;
	return os.str();
}
}
std::string rv32i_decode::render_illegal_insn(uint32_t insn)
{
	(void)insn;
	return "ERROR: UNIMPLEMENTED INSTRUCTION";
}
std::string rv32i_decode::render_lui(uint32_t insn)
{
	uint32_t rd = get_rd(insn);
	uint32_t imm_u = get_imm_u(insn);
	std::ostringstream os;
	os << render_mnemonic("lui") << render_reg(rd) << ","
	<< hex::to_hex0x20((imm_u >> 12)&0x0fffff);
	return os.str();
}
std::string rv32i_decode::render_auipc(uint32_t insn)
{
	uint32_t rd = get_rd(insn);
	uint32_t imm_u = get_imm_u(insn);
	std::ostringstream os;
	os << render_mnemonic("auipc") << render_reg(rd) << ","
	<< hex::to_hex0x20((imm_u >> 12)&0x0fffff);
	return os.str();	
}
std::string rv32i_decode::render_jal(uint32_t addr, uint32_t insn)
{
	uint32_t rd = get_rd(insn);
	int32_t imm_j = get_imm_j(insn);
	imm_j += addr;
	std::ostringstream os;
	os << render_mnemonic("jal") << render_reg(rd) << ","
	<< hex::to_hex0x32(imm_j);
	return os.str();
}
std::string rv32i_decode::render_jalr(uint32_t insn)
{
	uint32_t rd = get_rd(insn);
	int32_t imm_i = get_imm_i(insn);
	uint32_t rs1 = get_rs1(insn);
	std::ostringstream os;
	os << render_mnemonic("jalr") << render_reg(rd) << ","
	<< render_base_disp(rs1,imm_i);
	return os.str();
	
}
///@parm addr The memory address where the insn is stored.
std::string rv32i_decode::render_btype(uint32_t addr, uint32_t insn, const char *mnemonic)
{
	int32_t imm_b = get_imm_b(insn);
	imm_b += (int32_t)addr;
	uint32_t rs1 = get_rs1(insn);
	uint32_t rs2 = get_rs2(insn);
	std::ostringstream os;	
	os << render_mnemonic(mnemonic) << render_reg(rs1) << ","
	<< render_reg(rs2) << ","<< hex::to_hex0x32(imm_b);
	return os.str();
}
std::string rv32i_decode::render_itype_load(uint32_t insn, const char *mnemonic)
{
	uint32_t rd = get_rd(insn);
	int32_t imm_i = get_imm_i(insn);
	uint32_t rs1 = get_rs1(insn);
	std::ostringstream os;	
	os << render_mnemonic(mnemonic) << render_reg(rd) << ","
	<< render_base_disp(rs1,imm_i);
	return os.str();	
}
std::string rv32i_decode::render_stype(uint32_t insn, const char *mnemonic)
{
	uint32_t rs1 = get_rs1(insn);
	int32_t imm_s = get_imm_s(insn);
	uint32_t rs2 = get_rs2(insn);
	std::ostringstream os;	
	os << render_mnemonic(mnemonic) << render_reg(rs2) << ","
	<< render_base_disp(rs1,imm_s);
	return os.str();	
}
std::string rv32i_decode::render_itype_alu(uint32_t insn, const char *mnemonic, int32_t imm_i)
{
	uint32_t rd = get_rd(insn);
	uint32_t rs1 = get_rs1(insn);
	std::ostringstream os;	
	os << render_mnemonic(mnemonic) << render_reg(rd) << "," << render_reg(rs1) << ","
	<< std::dec << imm_i;
	return os.str();	
}
std::string rv32i_decode::render_rtype(uint32_t insn, const char *mnemonic)
{
	uint32_t rd = get_rd(insn);
	uint32_t rs1 = get_rs1(insn);
	uint32_t rs2 = get_rs2(insn);
	std::ostringstream os;	
	os << render_mnemonic(mnemonic) << render_reg(rd) << ","
	<< render_reg(rs1) << ","<< render_reg(rs2);
	return os.str();	
}
std::string rv32i_decode::render_ecall(uint32_t insn)
{
	insn +=1;
	std::ostringstream os;
	os << render_mnemonic("ecall");	
	return os.str();
}
std::string rv32i_decode::render_ebreak(uint32_t insn)
{
	insn +=1;
	std::ostringstream os;
	os << render_mnemonic("ebreak");
	return os.str();
}
std::string rv32i_decode::render_csrrx(uint32_t insn, const char *mnemonic)
{
	uint32_t rd = get_rd(insn);
	uint32_t csr = get_imm_i(insn);
	uint32_t rs1 = get_rs1(insn);
	std::ostringstream os;	
	os << render_mnemonic(mnemonic) << render_reg(rd) << ","
	<< hex::to_hex0x12(csr) << "," << render_reg(rs1);
	return os.str();	
}
std::string rv32i_decode::render_csrrxi(uint32_t insn, const char *mnemonic)
{
	uint32_t rd = get_rd(insn);
	uint32_t csr = get_imm_i(insn);
	uint32_t rs1 = get_rs1(insn);
	std::ostringstream os;	
	os << render_mnemonic(mnemonic) << render_reg(rd) << ","
	<< hex::to_hex0x12(csr) << "," << std::dec << rs1;
	return os.str();	
}
uint32_t rv32i_decode::get_opcode(uint32_t insn)
{
	return(insn & 0x0000007f);
}
uint32_t rv32i_decode::get_rd(uint32_t insn)
{
		insn = insn & 0x00000f80;
		insn >>=7;
		return insn;
}
uint32_t rv32i_decode::get_funct3(uint32_t insn)
{
		insn = insn & 0x00007000;
		insn >>=12;
		return insn;
}	
uint32_t rv32i_decode::get_rs1(uint32_t insn)
{
		insn = insn & 0x000f8000;
		insn >>=15;
		return insn;	
}
uint32_t rv32i_decode::get_rs2(uint32_t insn)
{
		insn = insn & 0x01f00000;
		insn >>=20;
		return insn;	
}
uint32_t rv32i_decode::get_funct7(uint32_t insn)
{
		insn = insn & 0xfe000000;
		insn >>=25;
		return insn;	
}
int32_t rv32i_decode::get_imm_i(uint32_t insn)
{
		uint32_t res;
		res = insn & 0xfff00000;
		res >>=20;
		if (insn & 0x80000000)
			res |= 0xfffff000; // sign-extend the left
		return res;
}
int32_t rv32i_decode::get_imm_u(uint32_t insn)
{
		insn = insn & 0xfffff000;
		return insn;
}
// parse fields of imm and combine
int32_t rv32i_decode::get_imm_b(uint32_t insn)
{
	uint32_t chk = insn;
	uint32_t tmp = insn; 
	uint32_t tmp2 = insn;
	uint32_t tmp3 = insn; 
	uint32_t tmp4 = insn;
	tmp >>= 31;
	tmp <<= 12;
	tmp2 = tmp2 & 0x7e000000;
	tmp2 >>= 25;
	tmp2 <<= 5;
	tmp3 = tmp3 & 0x00000f00;
	tmp3 >>= 8;
	tmp3 <<= 1;
	tmp4 = tmp4 & 0x00000080;
	tmp4 >>= 7;
	tmp4 <<= 11;
	tmp += tmp2 + tmp3 + tmp4;
	if (chk & 0x80000000)
		tmp |= 0xffffe000; // sign-extend the left
	return tmp;
}
int32_t rv32i_decode::get_imm_s(uint32_t insn)
{
	int32_t imm_s = (insn & 0xfe000000) >> (25-5);
	imm_s |= (insn & 0x00000f80) >> (7-0);
	if (insn & 0x80000000)
		imm_s |= 0xfffff000; // sign-extend the left
	return imm_s;
}
// parse fields of imm and combine
int32_t rv32i_decode::get_imm_j(uint32_t insn)
{
	uint32_t chk = insn; 
	uint32_t tmp = insn; 
	uint32_t tmp2 = insn;
	uint32_t tmp3 = insn; 
	uint32_t tmp4 = insn;
	tmp >>= 31;
	tmp <<= 20;
	tmp2 = tmp2 & 0x000ff000;
	tmp += tmp2;
	tmp3 = tmp3 & 0x00100000;
	tmp3 >>= 20;
	tmp3 <<= 11;
	tmp += tmp3;
	tmp4 = tmp4 & 0x7fe00000;
	tmp4 >>= 21;
	tmp4 <<=1;
	tmp += tmp4;
	if (chk & 0x80000000)
		tmp |= 0xffe00000; // sign-extend the left
	return tmp;	
}