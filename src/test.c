#include <zephyr/ztest.h>

#include <regex.h>

ZTEST_SUITE(parser_suite, NULL, NULL, NULL, NULL, NULL);

ZTEST(parser_suite, test_regex_inline) {
	int err;
	regex_t re;
	err = regcomp(&re, "He(ll)o", REG_EXTENDED);
  	printf("Err: %d\n", err);
  	printf("re_nsub: %lu\n", re.re_nsub);
	zassert_not_equal(re.re_nsub, 0, "There really is a match group");
}

extern void regex_test();

ZTEST(parser_suite, test_regex_external_fun) {
	regex_test();
	zassert_equal(0,0);
}

#define CRASH
#ifdef CRASH
void same_file_regex() {
	int err;
	regex_t re;
	err = regcomp(&re, "He(ll)o", REG_EXTENDED);
  	printf("Err: %d\n", err);
  	printf("re_nsub: %lu\n", re.re_nsub);
}

ZTEST(parser_suite, test_regex3_fun) {
	same_file_regex();
	zassert_equal(0,0);
}
#endif



