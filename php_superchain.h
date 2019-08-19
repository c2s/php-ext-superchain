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

#ifndef PHP_SUPERCHAIN_H
# define PHP_SUPERCHAIN_H

extern zend_module_entry superchain_module_entry;
# define phpext_superchain_ptr &superchain_module_entry

# define PHP_SUPERCHAIN_VERSION "1.0.0"

# if defined(ZTS) && defined(COMPILE_DL_SUPERCHAIN)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

/* superchain.c functions */
PHP_FUNCTION(superchain_version);

#endif	/* PHP_SUPERCHAIN_H */

