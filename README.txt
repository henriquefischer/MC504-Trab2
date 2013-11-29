
##################################################
#####
#####   Name: Multikill
#####
##################################################

Descrição: Envia SIGKILL para n processos


# Synopsis
_________________________

#include <sys/types.h>
#include <signal.h>

int multikill(int sig, pid_t *pids, int length);


# Parameters
_________________________
sig : signal to be sent to the processes list
pids : address of the vector of pids
length : the length of the vector
# Return value
number of processes that returned 0




# Instalação:
_________________________
1º - Alterar a tabela linux-3.12/arch/x86/syscalls/syscall_32.tlb, acrescentando uma nova linha ao final do arquivo, após a linha do finit_module:

350     i386    finit_module            sys_finit_module
351     i386    multikill               sys_multikill

2º - Incluir uma declaração da função sys_mycall em linux-3.12/include/linux/syscalls.h, novamente após a linha relacionada ao finit_module:

asmlinkage long sys_finit_module(int fd, const char _user *uargs, int flags);
asmlinkage long sys_multikill(void);

3º - Copiar o arquivo "Multikill.c" para a pasta: /arch/x86/kernel/

4º - Alterar o Makefile do diretório linux-3.12/arch/x86/kernel/, incluindo uma linha:

obj-y                                   += multikill.o

5º - No diretório linux-3.12 executar

$ make