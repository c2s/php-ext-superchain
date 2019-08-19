/* superchain extension for PHP */

#ifndef PHP_SUPERCHAIN_H
# define PHP_SUPERCHAIN_H

extern zend_module_entry superchain_module_entry;
# define phpext_superchain_ptr &superchain_module_entry

# define PHP_SUPERCHAIN_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_SUPERCHAIN)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_SUPERCHAIN_H */

