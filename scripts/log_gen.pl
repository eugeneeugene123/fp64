#! /usr/bin/perl
use warnings;
use Math::BigFloat;
use Math::BigInt;

Math::BigFloat->accuracy(50);

print "const unsigned long long __log_table[256]={\n";
for $i (0..255){
	$x = Math::BigFloat->new('1');
	$y = Math::BigFloat->new($i);
	$z = Math::BigFloat->new('0');
	$t = Math::BigFloat->new('256');
	$d = Math::BigFloat->new('2');
	$z = $x+$y*($x/$t);
	$t = $z->blog();
	$exp = 0;
	if ($t < 0.5){
		$t = $t*$d;
		$exp = $exp+1;
	}
	if ($t < 0.5){
		$t = $t*$d;
		$exp = $exp+1;
	}
	if ($t < 0.5){
		$t = $t*$d;
		$exp = $exp+1;
	}
	if ($t < 0.5){
		$t = $t*$d;
		$exp = $exp+1;
	}
	if ($t < 0.5){
		$t = $t*$d;
		$exp = $exp+1;
	}
	if ($t < 0.5){
		$t = $t*$d;
		$exp = $exp+1;
	}
	if ($t < 0.5){
		$t = $t*$d;
		$exp = $exp+1;
	}
	if ($t < 0.5){
		$t = $t*$d;
		$exp = $exp+1;
	}
	push @e, $exp;
	$t = $t* (2**64);
	print "\t".$t->numify()."ULL,\n";
}
print "};\n\n";

print "const unsigned char __log_exp[256]={\n";
for $x (@e){
	print "\t".$x.",\n";
}
print "};\n\n";


