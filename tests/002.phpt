--TEST--
superchain_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('superchain')) {
	echo 'skip';
}
?>
--FILE--
<?php
$ret = superchain_test1();

var_dump($ret);
?>
--EXPECT--
The extension superchain is loaded and working!
NULL
