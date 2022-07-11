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
#ifndef RV32I_DECODE_H
#define RV32I_DECODE_H
#include <vector>
#include <string>
#include "memory.h"
#include "hex.h"

class rv32i_decode : public hex
{
public:

/**
 * Takes in current address in memory and uses helper functions to decode the 
 * machine instruction at the memory address and formats the instruction as a 
 * string.
 *
 * @param uint32_t addr represents current address of machine instruction
 * @param uint32_t represents content of address, which is the machine instruction
 *
 * @return return a string containing formatted machine instruction 
 ********************************************************************************/
	static std::string decode(uint32_t addr, uint32_t insn);

protected:
	//opcode constants by unique designation for parsing
	static constexpr int mnemonic_width             = 8;

	static constexpr uint32_t opcode_lui			= 0b0110111;
	static constexpr uint32_t opcode_auipc			= 0b0010111;
	static constexpr uint32_t opcode_jal			= 0b1101111;
	static constexpr uint32_t opcode_jalr			= 0b1100111;
	static constexpr uint32_t opcode_btype			= 0b1100011;
	static constexpr uint32_t opcode_load_imm		= 0b0000011;
	static constexpr uint32_t opcode_stype			= 0b0100011;
	static constexpr uint32_t opcode_alu_imm		= 0b0010011;
	static constexpr uint32_t opcode_rtype			= 0b0110011;
	static constexpr uint32_t opcode_system			= 0b1110011;
	//funct3 constants by unique designation for parsing
	static constexpr uint32_t funct3_beq			= 0b000;
	static constexpr uint32_t funct3_bne			= 0b001;
	static constexpr uint32_t funct3_blt			= 0b100;
	static constexpr uint32_t funct3_bge			= 0b101;
	static constexpr uint32_t funct3_bltu			= 0b110;
	static constexpr uint32_t funct3_bgeu			= 0b111;

	static constexpr uint32_t funct3_lb				= 0b000;
	static constexpr uint32_t funct3_lh				= 0b001;
	static constexpr uint32_t funct3_lw				= 0b010;
	static constexpr uint32_t funct3_lbu			= 0b100;
	static constexpr uint32_t funct3_lhu			= 0b101;

	static constexpr uint32_t funct3_sb				= 0b000;
	static constexpr uint32_t funct3_sh				= 0b001;
	static constexpr uint32_t funct3_sw				= 0b010;

	static constexpr uint32_t funct3_add			= 0b000;
	static constexpr uint32_t funct3_sll			= 0b001;
	static constexpr uint32_t funct3_slt			= 0b010;
	static constexpr uint32_t funct3_sltu			= 0b011;
	static constexpr uint32_t funct3_xor			= 0b100;
	static constexpr uint32_t funct3_srx			= 0b101;
	static constexpr uint32_t funct3_or				= 0b110;
	static constexpr uint32_t funct3_and			= 0b111;
	//funct7 constants by unique designation for parsing
	static constexpr uint32_t funct7_srl			= 0b0000000;
	static constexpr uint32_t funct7_sra			= 0b0100000;

	static constexpr uint32_t funct7_add			= 0b0000000;
	static constexpr uint32_t funct7_sub			= 0b0100000;

	static constexpr uint32_t insn_ecall			= 0x00000073;
	static constexpr uint32_t insn_ebreak			= 0x00100073;
	//funct3 constants by unique designation for parsing
	static constexpr uint32_t funct3_csrrw			= 0b001;
	static constexpr uint32_t funct3_csrrs			= 0b010;
	static constexpr uint32_t funct3_csrrc			= 0b011;
	static constexpr uint32_t funct3_csrrwi			= 0b101;
	static constexpr uint32_t funct3_csrrsi			= 0b110;
	static constexpr uint32_t funct3_csrrci			= 0b111;
/**
 * parses instruction to extract opcode. Returns result
 *
 * @param uint32_t insn represents the instruction of which to parse opcode
 *
 * @return returns 32-bit unsigned int representing instruction opcode 
 ********************************************************************************/
	static uint32_t get_opcode(uint32_t insn);
/**
 * parses instruction to extract rd field. Returns result
 *
 * @param uint32_t insn represents the instruction of which to parse rd field
 *
 * @return returns 32-bit unsigned int representing rd field 
 ********************************************************************************/
	static uint32_t get_rd(uint32_t insn);
/**
 * parses instruction to extract funct3 field. Returns result
 *
 * @param uint32_t insn represents the instruction of which to parse funct3 field
 *
 * @return returns 32-bit unsigned int representing funct3 field 
 ********************************************************************************/
	static uint32_t get_funct3(uint32_t insn);
/**
 * parses instruction to extract rs1 field. Returns result
 *
 * @param uint32_t insn represents the instruction of which to parse rs1 field
 *
 * @return returns 32-bit unsigned int representing rs1 field 
 ********************************************************************************/
	static uint32_t get_rs1(uint32_t insn);
/**
 * parses instruction to extract rs2 field. Returns result
 *
 * @param uint32_t insn represents the instruction of which to parse rs2 field
 *
 * @return returns 32-bit unsigned int representing rs2 field 
 ********************************************************************************/
	static uint32_t get_rs2(uint32_t insn);
/**
 * parses instruction to extract funct7 field. Returns result
 *
 * @param uint32_t insn represents the instruction of which to parse funct7 field
 *
 * @return returns 32-bit unsigned int representing funct7 field 
 ********************************************************************************/
	static uint32_t get_funct7(uint32_t insn);
/**
 * parses instruction to extract imm_i field. Returns result
 *
 * @param uint32_t insn represents the instruction of which to imm_i field
 *
 * @return returns 32-bit unsigned int representing imm_i field 
 ********************************************************************************/
	static int32_t get_imm_i(uint32_t insn);
/**
 * parses instruction to extract imm_u field. Returns result
 *
 * @param uint32_t insn represents the instruction of which to imm_u field
 *
 * @return returns 32-bit unsigned int representing imm_u field 
 ********************************************************************************/
	static int32_t get_imm_u(uint32_t insn);
/**
 * parses instruction to extract imm_b field. Returns result
 *
 * @param uint32_t insn represents the instruction of which to imm_b field
 *
 * @return returns 32-bit unsigned int representing imm_b field 
 ********************************************************************************/
	static int32_t get_imm_b(uint32_t insn);
/**
 * parses instruction to extract imm_s field. Returns result
 *
 * @param uint32_t insn represents the instruction of which to imm_s field
 *
 * @return returns 32-bit unsigned int representing imm_s field 
 ********************************************************************************/
	static int32_t get_imm_s(uint32_t insn);
/**
 * parses instruction to extract imm_j field. Returns result
 *
 * @param uint32_t insn represents the instruction of which to imm_j field
 *
 * @return returns 32-bit unsigned int representing imm_j field 
 ********************************************************************************/
	static int32_t get_imm_j(uint32_t insn);
// instruction length 
	static constexpr uint32_t XLEN = 32;
/**
 * casts void on instruction and returns a string containing an error message.
 * used for illegal instructions.
 *
 * @param uint32_t insn represents the instruction to check
 *
 * @return returns error message for invalid instruction
 ********************************************************************************/
	static std::string render_illegal_insn(uint32_t insn);
/**
 * parses instruction to properly format lui instruction. Returns formatted string
 *
 * @param uint32_t insn represents the instruction of which to extract lui info
 *
 * @return string containing formatted lui instruction 
 ********************************************************************************/
	static std::string render_lui(uint32_t insn);
/**
 * parses instruction to properly format auipc instruction. Returns formatted string
 *
 * @param uint32_t insn represents the instruction of which to extract auipc info
 *
 * @return string containing formatted auipc instruction 
 ********************************************************************************/
	static std::string render_auipc(uint32_t insn);
/**
 * parses instruction to properly format jal instruction. Returns formatted string
 *
 * @param uint32_t insn represents the instruction of which to extract jal info
 * @param addr The memory address where the insn is stored.
 
 * @return string containing formatted jal instruction 
 ********************************************************************************/
	static std::string render_jal(uint32_t addr, uint32_t insn);
/**
 * parses instruction to properly format jalr instruction. Returns formatted string
 *
 * @param uint32_t insn represents the instruction of which to extract jalr info
 
 * @return string containing formatted jalr instruction 
 ********************************************************************************/
	static std::string render_jalr(uint32_t insn);
/**
 * parses instruction to properly format b-type instructions
 *
 * @param uint32_t insn represents the instruction of which to extract b-type info
 * @param addr The memory address where the insn is stored.
 * @param *mnemonic represents name of the instruction
 *
 * @return string containing formatted b-type instruction 
 ********************************************************************************/
	static std::string render_btype(uint32_t addr, uint32_t insn, const char *mnemonic);
/**
 * parses instruction to properly format i-type loading instructions
 *
 * @param uint32_t insn represents the instruction of which to extract i-type info
 * @param *mnemonic represents name of the instruction
 *
 * @return string containing formatted i-type instruction 
 ********************************************************************************/
	static std::string render_itype_load(uint32_t insn, const char *mnemonic);
/**
 * parses instruction to properly format s-type instructions
 *
 * @param uint32_t insn represents the instruction of which to extract s-type info
 * @param *mnemonic represents name of the instruction
 *
 * @return string containing formatted s-type instruction 
 ********************************************************************************/
	static std::string render_stype(uint32_t insn, const char *mnemonic);
/**
 * parses instruction to properly format i-type alu instructions
 *
 * @param uint32_t insn represents the instruction of which to extract i-type info
 * @param *mnemonic represents name of the instruction
 * @param int32_t imm_i represents the immediate value ot which to render instruction
 *
 * @return string containing formatted i-type instruction 
 ********************************************************************************/
	static std::string render_itype_alu(uint32_t insn, const char *mnemonic, int32_t imm_i);
/**
 * parses instruction to properly format r-type instructions
 *
 * @param uint32_t insn represents the instruction of which to extract r-type info
 * @param *mnemonic represents name of the instruction
 *
 * @return string containing formatted r-type instruction 
 ********************************************************************************/
	static std::string render_rtype(uint32_t insn, const char *mnemonic);
/**
 * parses instruction to properly ecall instruction
 *
 * @param uint32_t insn represents the ecall instruction
 *
 * @return string containing formatted ecall instruction 
 ********************************************************************************/
	static std::string render_ecall(uint32_t insn);
/**
 * parses instruction to properly ebreak instruction
 *
 * @param uint32_t insn represents the ebreak instruction
 *
 * @return string containing formatted ebreak instruction 
 ********************************************************************************/
	static std::string render_ebreak(uint32_t insn);
/**
 * parses instruction to properly format csrr instructions
 *
 * @param uint32_t insn represents the instruction of which to extract csrr type info
 * @param *mnemonic represents name of the instruction
 *
 * @return string containing formatted cssr-type instruction 
 ********************************************************************************/
	static std::string render_csrrx(uint32_t insn, const char *mnemonic);
/**
 * parses instruction to properly format csrrxi instructions
 *
 * @param uint32_t insn represents the instruction of which to extract csrrxi type info
 * @param *mnemonic represents name of the instruction
 *
 * @return string containing formatted cssrxi-type instruction 
 ********************************************************************************/
	static std::string render_csrrxi(uint32_t insn, const char *mnemonic);
/**
 * formats register with appended "0x"
 *
 * @param integer r represents the number of the register
 *
 * @return string containing formatted register number "0x#"
 ********************************************************************************/
	static std::string render_reg(int r);
/**
 * parses instruction to properly format csrr instructions
 *
 * @param uint32_t represents the base register 
 * @param 32-bit integer disp is displacement from the base register
 *
 * @return string containing imm(register) format
 ********************************************************************************/
	static std::string render_base_disp(uint32_t base, int32_t disp);
/**
 * formats each instruction with at least 8 spaces
 *
 * @param string&m containing the unformatted mnemonic string
 *
 * @return string with formatted mnemonic for printing
 ********************************************************************************/
	static std::string render_mnemonic(const std::string &m);
};
#endif
