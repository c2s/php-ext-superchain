--TEST--
Check if superchain is loaded
--SKIPIF--
<?php
if (!extension_loaded('superchain')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "superchain" is available';
?>
--EXPECT--
The extension "superchain" is available
