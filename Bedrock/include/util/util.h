#ifndef BEDROCK_UTIL_H
#define BEDROCK_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define DEBUG

typedef enum bool_ { false, true } bool;

#ifndef DEBUG
# define bedrock_assert(var) \
	if (!(var)) \
		return;
# define bedrock_assert_ret(var, ret) \
	if (!(var)) \
		return (ret);
# define bedrock_assert_do(var, what) \
	if (!(var)) \
		what;
#else
# define bedrock_assert(var) \
	if (!(var)) \
	{ \
		printf("Debug assertion failed: %s:%d\n", __FILE__, __LINE__); \
		return; \
	}
# define bedrock_assert_ret(var, ret) \
	if (!(var)) \
	{ \
		printf("Debug assertion failed: %s:%d\n", __FILE__, __LINE__); \
		return (ret); \
	}
# define bedrock_assert_do(var, what) \
	if (!(var)) \
	{ \
		printf("Debug assertion failed: %s:%d\n", __FILE__, __LINE__); \
		what; \
	}
#endif

#endif // BEDROCK_UTIL_H
