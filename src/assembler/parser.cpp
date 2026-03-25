#include "parser.h"

Register::Register(std::string_view n, int i) : 
    name{n}, 
    id{i} 
{ };

Inst::Inst(OpCode i, Reg r1, Reg r2, Reg r3 ) :
    instruction{i}, 
    args{r1, r2, r3} 
{ };

Parser::Parser() :
    cur_state{State::Nil},
    buffer{" "},
    ir_vec{}
{ };