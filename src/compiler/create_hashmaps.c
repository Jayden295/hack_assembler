#include "hashmap.h"
#include "create_hashmaps.h"
#include <string.h>

// This files create the required hashmaps for hack_assembler
void add_hashmap_values(struct hashmap *map,
                        struct compiled_instruction items[],
                        unsigned short array_size);

// Functions required for hashmap.c
int instruction_compare(const void *a, const void *b,
                        __attribute__((unused)) void *udata) {
  const struct compiled_instruction *ia = a;
  const struct compiled_instruction *ib = b;
  return strcmp(ia->original, ib->original);
}

uint64_t instruction_hash(const void *item, uint64_t seed0, uint64_t seed1) {
  const struct compiled_instruction *user = item;
  return hashmap_sip(user->original, strlen(user->original), seed0, seed1);
}

struct hashmap *create_comp_hashmap() {
  struct hashmap *comp_hashmap =
      hashmap_new(sizeof(struct compiled_instruction), 0, 0, 0,
                  instruction_hash, instruction_compare, NULL, NULL);

  struct compiled_instruction comp_values[] = {
      {.original = "0", .compiled = "0101010"},
      {.original = "1", .compiled = "0111111"},
      {.original = "-1", .compiled = "0111010"},
      {.original = "D", .compiled = "0001100"},
      {.original = "A", .compiled = "0110000"},
      {.original = "!D", .compiled = "0001101"},
      {.original = "!A", .compiled = "0110001"},
      {.original = "-D", .compiled = "0001111"},
      {.original = "-A", .compiled = "0110011"},
      {.original = "D+1", .compiled = "0011111"},
      {.original = "A+1", .compiled = "0110111"},
      {.original = "D-1", .compiled = "0001110"},
      {.original = "A-1", .compiled = "0110010"},
      {.original = "D+A", .compiled = "0000010"},
      {.original = "D-A", .compiled = "0010011"},
      {.original = "A-D", .compiled = "0000111"},
      {.original = "D&A", .compiled = "0000000"},
      {.original = "D|A", .compiled = "0010101"},
      {.original = "M", .compiled = "1110000"},
      {.original = "!M", .compiled = "1110001"},
      {.original = "-M", .compiled = "1110011"},
      {.original = "M+1", .compiled = "1110111"},
      {.original = "M-1", .compiled = "1110010"},
      {.original = "D+M", .compiled = "1000010"},
      {.original = "D-M", .compiled = "1010011"},
      {.original = "M-D", .compiled = "1000111"},
      {.original = "D&M", .compiled = "1000000"},
      {.original = "D|M", .compiled = "1010101"}};

  unsigned short array_size = sizeof(comp_values) / sizeof(comp_values[0]);
  add_hashmap_values(comp_hashmap, comp_values, array_size);

  return comp_hashmap;
}

struct hashmap *create_jump_hashmap() {
  struct hashmap *jump_hashmap =
      hashmap_new(sizeof(struct compiled_instruction), 0, 0, 0,
                  instruction_hash, instruction_compare, NULL, NULL);

  struct compiled_instruction jump_values[] = {
      {.original = "JGT", .compiled = "001"},
      {.original = "JEQ", .compiled = "010"},
      {.original = "JGE", .compiled = "011"},
      {.original = "JLT", .compiled = "100"},
      {.original = "JNE", .compiled = "101"},
      {.original = "JLE", .compiled = "110"},
      {.original = "JMP", .compiled = "111"},
  };

  unsigned short array_size = sizeof(jump_values) / sizeof(jump_values[0]);
  add_hashmap_values(jump_hashmap, jump_values, array_size);

  return jump_hashmap;
}

void add_hashmap_values(struct hashmap *map,
                        struct compiled_instruction items[],
                        unsigned short array_size) {
  for (size_t i = 0; i < array_size; i++) {
    hashmap_set(map, &items[i]);
  }
}