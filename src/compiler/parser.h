#include <stdio.h>
#include <stdbool.h>

enum instruction {
  NONE,
  FINISHED_VALUE,
  FINISHED_INSTRUCTION,
  SLASH_ONE,
  SLASH_TWO,
  LABEL,
  A_INSTRUCTION,
  C_INSTRUCTION
};

struct c_instruction_value {
  char value[4];
  bool validity;
};

void parse_line(FILE *assembly_file, FILE *output_file, char *line,
                const size_t current_line, enum instruction *instruction_parsed,
                char a_value[], struct c_instruction_value *dest,
                struct c_instruction_value *comp,
                struct c_instruction_value *jump);