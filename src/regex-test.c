#include <stdio.h>
#include <regex.h>

#ifdef STANDALONE
void main() {
#else
void regex_test() {
#endif
  int err;
  regex_t re;
  err = regcomp(&re, "He(ll)o", REG_EXTENDED);
  printf("Err: %d\n", err);
  printf("re_nsub: %lu\n", re.re_nsub);
}
