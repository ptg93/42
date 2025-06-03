#!/bin/bash

PIPEX=./pipex
INFILE=infile_test.txt
OUTFILE=outfile_test.txt

# Limpieza previa
rm -f $INFILE $OUTFILE result.txt

# Test 1: archivo de entrada válido, comandos válidos
echo -e "line 1\nline 2\nline 3" > $INFILE
$PIPEX $INFILE "cat" "wc -l" $OUTFILE
echo "Test 1 - cat | wc -l:"
cat $OUTFILE
echo

# Test 2: archivo de entrada no existe
$PIPEX nofile "cat" "wc -l" $OUTFILE 2> result.txt
echo "Test 2 - infile inexistente (espera error):"
cat result.txt
echo

# Test 3: comando inexistente
$PIPEX $INFILE "badcommand" "wc -l" $OUTFILE 2> result.txt
echo "Test 3 - comando inexistente (espera error):"
cat result.txt
echo

# Test 4: permisos denegados
touch restricted.txt
chmod 000 restricted.txt
$PIPEX restricted.txt "cat" "wc" $OUTFILE 2> result.txt
echo "Test 4 - sin permisos de lectura (espera error):"
cat result.txt
chmod 644 restricted.txt
rm restricted.txt
echo

# Test 5: comparar resultado con ejecución normal de bash
echo -e "apple\nbanana\ncherry" > $INFILE
$PIPEX $INFILE "grep a" "wc -l" $OUTFILE
grep a $INFILE | wc -l > result.txt
diff $OUTFILE result.txt && echo "Test 5 - salida idéntica al pipe de bash ✅" || echo "Test 5 - salida diferente ❌"
echo

# Limpieza final
rm -f $INFILE $OUTFILE result.txt

