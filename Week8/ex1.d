
ex.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <main>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	48 8d 3d 00 00 00 00 	lea    0x0(%rip),%rdi        # b <main+0xb>
   b:	e8 00 00 00 00       	callq  10 <main+0x10>
  10:	b8 00 00 00 00       	mov    $0x0,%eax
  15:	5d                   	pop    %rbp
  16:	c3                   	retq   
