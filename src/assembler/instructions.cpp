#include "instructions.h"

namespace instruction_mod {

    const std::unordered_map<std::string_view, OpCode> instruction_map {
        { "LOAD",   OpCode::LOAD },
        { "SEND",   OpCode::SEND },
        { "COPY",   OpCode::COPY },
        { "SET",    OpCode::SET },
        { "SWAP",   OpCode::SWAP },
        { "NOT",    OpCode::NOT },
        { "AND",    OpCode::AND },
        { "OR",     OpCode::OR },
        { "XOR",    OpCode::XOR },
        { "STL",    OpCode::STL },
        { "STR",    OpCode::STR },
        { "RTL",    OpCode::RTL },
        { "RTR",    OpCode::RTR },
        { "ADD",    OpCode::ADD },
        { "SUB",    OpCode::SUB },
        { "MUL",    OpCode::MUL },
        { "DIV",    OpCode::DIV },
        { "MOD",    OpCode::MOD },
        { "NEG",    OpCode::NEG },
        { "CMP",    OpCode::CMP },
        { "GOTO",   OpCode::GOTO },
        { "WEQ",    OpCode::WEQ },
        { "WGT",    OpCode::WGT },
        { "WLT",    OpCode::WLT },
        { "WCY",    OpCode::WCY },
        { "WOV",    OpCode::WOV },
        { "WDZ",    OpCode::WDZ },
        { "CAL",    OpCode::CAL },
        { "RET",    OpCode::RET },
        { "PUSH",   OpCode::PUSH },
        { "POP",    OpCode::POP },
        { "PRINT",  OpCode::PRINT },
        { "PRINTC", OpCode::PRINTC },
        { "END",    OpCode::END },
        { "CLR",    OpCode::CLR },
    };

    Token::Token() : 
        token_type{TokenType::Invalid}, value{0} { }
    Token::Token(TokenType type, OpCode val) :
        token_type{type}, value{val} { }
    Token::Token(TokenType type, int val) :
        token_type{type}, value{val} { }
    Token::Token(TokenType type, std::string val) :
        token_type{type}, value{val} { }

    Inst::Inst() :
        token_arr{std::nullopt},
        used_size{0}
    { }

    bool Inst::push_token(Token&& token) {
        if (used_size < INST_SIZE) {
            token_arr[used_size] = std::move(token);
            ++used_size;
            return true;
        }
        return false;
    }

}