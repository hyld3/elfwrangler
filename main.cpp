#include <iostream>
#include <inttypes.h>
#include <memory>
#include <vector>
#include <elf.h>

#include "elf_parser.hpp"

using namespace elf_parser;

void print_relocations(std::vector<elf_parser::relocation_t> &relocations);



auto main(int argc, char * argv[]) -> int
{
  std::string program;
  
  if (argc < 2)
    program = std::string("./build/test_me");
  else
    program = std::string((std::string)argv[1]);


  Elf_parser elf_parser(program);

  auto m = elf_parser.get_memory_map();


  auto elf_header = (Elf64_Ehdr *)m;

  std::cout << (elf_header->e_ident[EI_CLASS] == ELFCLASS64) << std::endl;
  
  // std::vector<relocation_t> relocs = elf_parser.get_relocations();
  // print_relocations(relocs);
  
  return 0;
}


void print_relocations(std::vector<elf_parser::relocation_t> &relocations) {
    printf("  [*] %-16s %-16s %-16s %-16s %s\n", "Offset", "Info", "Type", "Sym. Value", "Sym. Name (section)");
    printf("  [*] %-16s\n", "Calculated PLT Address");
    for (auto &rel : relocations) {
        printf("%016" PRIx64 "  %016" PRIx64 " %-16s %016" PRIx64 " %-16s (%s)\n",
            rel.relocation_offset,
            rel.relocation_info,
            rel.relocation_type.c_str(),
            rel.relocation_symbol_value,
            rel.relocation_symbol_name.c_str(),
            rel.relocation_section_name.c_str());
        printf("%016" PRIx64 "\n", rel.relocation_plt_address);
    }
}
