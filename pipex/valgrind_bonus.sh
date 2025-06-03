#!/bin/bash

PIPEX=./pipex_bonus
INFILE=infile_bonus.txt
OUTFILE=outfile_bonus.txt

echo -e "one\ntwo\ntree\ntwo\none\napple\nbanana" > $INFILE

valgrind --leak-check=full --error-exitcode=42 \
  $PIPEX $INFILE "grep o" "sort" "uniq" "wc -l" $OUTFILE > /dev/null 2> vg.txt

if [ $? -eq 42 ]; then
    echo "❌ Memory leak o error detectado:"
    grep "definitely lost" vg.txt
else
    echo "✅ Sin fugas de memoria"
fi

rm -f $INFILE $OUTFILE vg.txt

