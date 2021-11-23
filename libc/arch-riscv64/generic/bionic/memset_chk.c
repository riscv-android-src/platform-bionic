#include <unistd.h>

void *memset(void * s, int c, unsigned long n);

extern void* __memset_chk_fail();
void *
__memset_chk_generic (void *dstpp, int c, unsigned long len, unsigned long dstlen)
{
  if (dstlen < len)
    __memset_chk_fail ();

  return memset (dstpp, c, len);
}
