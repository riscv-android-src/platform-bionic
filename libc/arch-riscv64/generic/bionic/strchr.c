#include <stdint.h>

char *
strchr_generic (const char *s, int c_in)
{
  const unsigned char *char_ptr;
  const unsigned long int *longword_ptr;
  unsigned long int longword = 0, magic_bits, charmask;
  unsigned char c;

  c = (unsigned char) c_in;

  for (char_ptr = (const unsigned char *) s;
       ((unsigned long int) char_ptr & (sizeof (longword) - 1)) != 0;
       ++char_ptr)
    if (*char_ptr == c)
      return (void *) char_ptr;
    else if (*char_ptr == '\0')
      return NULL;

  longword_ptr = (unsigned long int *) char_ptr;

  magic_bits = -1;
  magic_bits = magic_bits / 0xff * 0xfe << 1 >> 1 | 1;

  /* Set up a longword, each of whose bytes is C.  */
  charmask = c | (c << 8);
  charmask |= charmask << 16;
  charmask |= (charmask << 16) << 16;

 for (;;)
    {

      /* Add MAGIC_BITS to LONGWORD.  */
      if ((((longword + magic_bits)
            ^ ~longword)
           & ~magic_bits) != 0

          || ((((longword ^ charmask) + magic_bits) ^ ~(longword ^ charmask))
              & ~magic_bits) != 0)
        {
          /* Which of the bytes was C or zero?
             If none of them were, it was a misfire; continue the search.  */

          const unsigned char *cp = (const unsigned char *) (longword_ptr - 1);

          if (*cp == c)
            return (char *) cp;
          else if (*cp == '\0')
            return NULL;
          if (*++cp == c)
            return (char *) cp;
          else if (*cp == '\0')
            return NULL;
          if (*++cp == c)
            return (char *) cp;
          else if (*cp == '\0')
            return NULL;
          if (*++cp == c)
            return (char *) cp;
          else if (*cp == '\0')
            return NULL;
          if (sizeof (longword) > 4)
            {
              if (*++cp == c)
                return (char *) cp;
              else if (*cp == '\0')
                return NULL;
              if (*++cp == c)
                return (char *) cp;
              else if (*cp == '\0')
                return NULL;
              if (*++cp == c)
                return (char *) cp;
              else if (*cp == '\0')
                return NULL;
              if (*++cp == c)
                return (char *) cp;
              else if (*cp == '\0')
                return NULL;
            }
        }
    }
    
  return NULL;
}
