project('elfwrangler', 'cpp')
src = ['main.cpp', 'elf-parser/elf_parser.cpp']
cppargs = ['-std=c++17', '-Wall', '-pedantic']

incdir = include_directories(['elf-parser'])

executable('test_me', 'test.cpp', cpp_args : cppargs)
executable('elfwrangler', src, cpp_args : cppargs, include_directories : incdir)


