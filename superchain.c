/*
  +----------------------------------------------------------------------+
  | SuperChain Extension                                                 |
  +----------------------------------------------------------------------+
  | Copyright (c) 2018-2019 The Mofei                                    |
  +----------------------------------------------------------------------+
  | https://www.mofei.org                                                |
  +----------------------------------------------------------------------+
  | Author: mofei <masterscao@gmail.com>                                 |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_superchain.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

/* {{{ void superchain_test1()
 */
PHP_FUNCTION(superchain_version)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("Extension Version %s\r\n", PHP_SUPERCHAIN_VERSION);
}
/* }}} */

/* {{{ string superchain_test2( [ string $var ] )
 */
PHP_FUNCTION(superchain_test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(superchain)
{
#if defined(ZTS) && defined(COMPILE_DL_SUPERCHAIN)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(superchain)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "Superchain Support", "enabled");
#if defined(PHP_SUPERCHAIN_VERSION)
    php_info_print_table_row(2, "Extension Version", PHP_SUPERCHAIN_VERSION);
#endif
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_superchain_version, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_superchain_test2, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ superchain_functions[]
 */
static const zend_function_entry superchain_functions[] = {
	PHP_FE(superchain_version,		arginfo_superchain_version)
	PHP_FE(superchain_test2,		arginfo_superchain_test2)
	PHP_FE_END
};
/* }}} */

/* {{{ superchain_module_entry
 */
zend_module_entry superchain_module_entry = {
	STANDARD_MODULE_HEADER,
	"superchain",					/* Extension name */
	superchain_functions,			/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(superchain),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(superchain),			/* PHP_MINFO - Module info */
	PHP_SUPERCHAIN_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_SUPERCHAIN
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(superchain)
#endif

