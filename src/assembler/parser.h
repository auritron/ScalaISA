#pragma once

#include <string>
#include <string_view>
#include <array>
#include <vector>
#include <optional>

#include "instructions.h"

enum class State {
    OpC,    //opcode
    Reg,    //register
    Sep,    //seperator (,)
    Imm,    //immediate
    Cmt,    //comment
    New,    //newline
    Nil,    //none (whitespace type char)
};

enum class Action {
    Push,
    Emit,
};

class Register {
    private:

        std::string_view name;
        int id;

    public:

        Register() = delete;

        Register(std::string_view n, int i);

};

class Inst {

    using Reg = std::optional<Register>;

    private:

        OpCode instruction;
        std::array<Reg, 3> args;

    public:

        Inst(OpCode i, Reg r1 = std::nullopt, Reg r2 = std::nullopt, Reg r3 = std::nullopt);

};

class Parser {
    private:
        State cur_state;
        std::string buffer;
        std::vector<Inst> ir_vec;
    
    public:

        Parser();
};