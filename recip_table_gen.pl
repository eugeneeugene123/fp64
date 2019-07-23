#! /usr/bin/perl
use warnings;
use bigint;

print "unsigned long long __reciprocal_div_table[256]={\n";
for $i (0..255){
	$num =((((1<<128)-1)/((256+$i)<<56))); 
	print "\t".$num."ULL,\n";
}
print "};\n";
