#pragma once

#include <string>
#include <unordered_map>

#include "instructions.hpp"
#include "error.hpp"

namespace codegen_mod {

    class CodeGen {

        private: 

            std::unordered_map<std::string, int> var_table;
            std::unordered_map<std::string, int> lbl_table;

        public:

            CodeGen();
            int generate(const instruction_mod::Inst& inst);

    };

}