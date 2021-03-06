#include "libtest.h"

EXTERN int
string_matches_foobarbaz(const char *value)
{
  return !strcmp(value, "foobarbaz");
}

EXTERN const char *
string_return_foobarbaz(void)
{
  return "foobarbaz";
}

typedef const char *my_string_t;
typedef void (*closure_t)(my_string_t);
static closure_t my_closure;

EXTERN void
string_set_closure(closure_t closure)
{
  my_closure = closure;
}

EXTERN void
string_call_closure(const char *value)
{
  my_closure(value);
}

EXTERN const char *
string_pointer_pointer_get(const char **ptr)
{
  return *ptr;
}

EXTERN void
string_pointer_pointer_set(const char **ptr, const char *value)
{
  *ptr = value;
}

EXTERN char **
string_pointer_pointer_return(char *value)
{
  static char buffer[512];
  static char *tmp;
  if(value != NULL)
  {
    strcpy(buffer, value);
    tmp = buffer;
  }
  else
  {
    tmp = value;
  }
  return &tmp;
}

EXTERN const char *
string_fixed_test(int i)
{
  static char buffer[] = "zero one  two  threefour ";
  return &buffer[i*5];
}

EXTERN const char *
string_test_pointer_arg(char **arg)
{
  static char buffer[512];

  if(arg == NULL)
    return  "arg==NULL";

  if(*arg == NULL)
    sprintf(buffer, "*arg==NULL");
  else
    sprintf(buffer, "*arg==%s", *arg);

  *arg = "out";

  return buffer;
}

EXTERN char **
string_test_pointer_ret(char *arg)
{
  static char buffer[512];
  static char *null = NULL;
  if(arg == NULL)
    return &null;
  else
    sprintf(buffer, "%s", arg);
  return (char**) &buffer;
}

EXTERN void
string_write_to_string(char *dst, char *src)
{
  int i=0;
  while(src[i] != '\0')
  {
    dst[i]=src[i];
    i++;
  }
  dst[i]=0;
}
