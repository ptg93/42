#!/bin/bash

set -x

PIPEX=./pipex_bonus
INFILE=infile_bonus.txt
OUTFILE=outfile_bonus.txt
REF_OUT=ref_output.txt

GREEN="\033[32m"
RED="\033[31m"
NC="\033[0m" # Sin color

test_case() {
	desc=$1
	infile=$2
	outfile=$3
	shift 3
	commands=("$@")

	echo "$desc"
	echo "Contenido de entrada:" > $infile
	echo -e "banana\napple\ncherry\ndate\napricot" >> $infile

	# Comando para pipex_bonus
	cmd_str="$PIPEX $infile"
	for cmd in "${commands[@]}"; do
		cmd_str+=" \"$cmd\""
	done
	cmd_str+=" $outfile"

	# Comando para bash normal
	ref_cmd="< $infile"
	for cmd in "${commands[@]}"; do
		ref_cmd+=" | $cmd"
	done
	ref_cmd+=" > $REF_OUT"

	# Ejecutar ambos
	eval "$cmd_str" 2> /dev/null
	eval "$ref_cmd"

	# Comparar resultados
	if diff $outfile $REF_OUT > /dev/null; then
		echo -e "${GREEN}✅ OK${NC}"
	else
		echo -e "${RED}❌ ERROR: salida diferente${NC}"
		diff $outfile $REF_OUT
	fi
	echo
}

# Test 1: grep + sort + wc
test_case "Test 1: grep a | sort | wc -l" $INFILE $OUTFILE "grep a" "sort" "wc -l"

# Test 2: tr + sort + uniq
test_case "Test 2: tr a-z A-Z | sort | uniq" $INFILE $OUTFILE "tr a-z A-Z" "sort" "uniq"

# Limpieza
rm -f $INFILE $OUTFILE $REF_OUT

