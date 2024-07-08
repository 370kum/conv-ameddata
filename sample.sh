#!/bin/bash 

input_file="$1"
if [ "$input_file" == "" ];then
	echo "error: input file cannot be found"
	exit 0
fi

./bin2txt $input_file | \
awk '{ for (i = 1; i <= NF; i++) { hex_val = "0x"$i;dec_val = hex_val + 0; printf "%d ", dec_val} printf "\n"}'

exit 0
