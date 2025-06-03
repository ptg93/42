#!/bin/bash

PIPEX=./pipex
INFILE=infile_test.txt
OUTFILE=outfile_test.txt

GREEN="\033[32m"
RED="\033[31m"
NC="\033[0m" # sin color

run_valgrind() {
	echo -e "🔹 $1"
	valgrind --leak-check=full --error-exitcode=42 $PIPEX $2 $3 $4 $5 > /dev/null 2> valgrind_output.txt
	if [ $? -eq 42 ]; then
		echo -e "${RED}❌ Memory leak o error detectado${NC}"
		cat valgrind_output.txt | grep "definitely lost"
	else
		echo -e "${GREEN}✅ Sin fugas de memoria${NC}"
	fi
	echo
}

# Test 1: cat | wc -l
echo -e "a\nb\nc" > $INFILE
run_valgrind "Test 1 - cat | wc -l" "$INFILE" "cat" "wc -l" "$OUTFILE"

# Test 2: infile no existe
run_valgrind "Test 2 - infile inexistente" "nofile" "cat" "wc -l" "$OUTFILE"

# Test 3: comando no existe
run_valgrind "Test 3 - comando inválido" "$INFILE" "zzz" "wc" "$OUTFILE"

# Limpieza
rm -f $INFILE $OUTFILE valgrind_output.txt

