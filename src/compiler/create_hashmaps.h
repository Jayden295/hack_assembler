#include "hashmap.h"

// Compiled instructions are used for labels and
// Holding instructions (the comp and jump table)
struct compiled_instruction {
  char *original;
  char *compiled;
};

struct hashmap *create_comp_hashmap();
struct hashmap *create_jump_hashmap();
struct hashmap *create_predefined_hashmap();
struct hashmap *create_empty_compiled_hashmap();
