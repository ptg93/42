#!/bin/bash

GREEN="\033[32m"
RED="\033[31m"
YELLOW="\033[33m"
NC="\033[0m"

echo -e "${YELLOW}=== PRUEBAS EXHAUSTIVAS PIPEX ===${NC}\n"

# Test 1: Argumentos incorrectos
echo -e "${YELLOW}Test 1: Validación de argumentos${NC}"
./pipex 2>/dev/null && echo -e "${RED}❌ Debería fallar sin argumentos${NC}" || echo -e "${GREEN}✅ Falla correctamente sin argumentos${NC}"
./pipex file1 2>/dev/null && echo -e "${RED}❌ Debería fallar con pocos argumentos${NC}" || echo -e "${GREEN}✅ Falla correctamente con pocos argumentos${NC}"
./pipex file1 cmd1 cmd2 2>/dev/null && echo -e "${RED}❌ Debería fallar con pocos argumentos${NC}" || echo -e "${GREEN}✅ Falla correctamente con pocos argumentos${NC}"
echo

# Test 2: Comandos con espacios y caracteres especiales
echo -e "${YELLOW}Test 2: Comandos con espacios${NC}"
echo -e "hello world\ntest line" > test_input.txt
./pipex test_input.txt "grep hello" "wc -w" test_output.txt 2>/dev/null
if [ -f test_output.txt ]; then
    result=$(cat test_output.txt)
    if [ "$result" = "2" ]; then
        echo -e "${GREEN}✅ Comandos con espacios funcionan${NC}"
    else
        echo -e "${RED}❌ Resultado incorrecto: $result${NC}"
    fi
else
    echo -e "${RED}❌ No se creó archivo de salida${NC}"
fi
echo

# Test 3: Comandos con rutas absolutas
echo -e "${YELLOW}Test 3: Comandos con rutas absolutas${NC}"
echo "test content" > test_input.txt
./pipex test_input.txt "/bin/cat" "/usr/bin/wc -c" test_output.txt 2>/dev/null
if [ -f test_output.txt ]; then
    echo -e "${GREEN}✅ Rutas absolutas funcionan${NC}"
else
    echo -e "${RED}❌ Rutas absolutas fallan${NC}"
fi
echo

# Test 4: Archivos con permisos especiales
echo -e "${YELLOW}Test 4: Permisos de archivos${NC}"
echo "test" > readonly.txt
chmod 444 readonly.txt
./pipex readonly.txt "cat" "wc -c" test_output.txt 2>/dev/null
if [ -f test_output.txt ]; then
    echo -e "${GREEN}✅ Lectura de archivo solo lectura funciona${NC}"
else
    echo -e "${RED}❌ No puede leer archivo solo lectura${NC}"
fi
chmod 644 readonly.txt
rm readonly.txt
echo

# Test 5: Archivo de salida en directorio sin permisos
echo -e "${YELLOW}Test 5: Directorio sin permisos de escritura${NC}"
mkdir -p test_dir
chmod 555 test_dir
echo "test" > test_input.txt
./pipex test_input.txt "cat" "wc -c" test_dir/output.txt 2>/dev/null
if [ ! -f test_dir/output.txt ]; then
    echo -e "${GREEN}✅ Falla correctamente con directorio sin permisos${NC}"
else
    echo -e "${RED}❌ Debería fallar con directorio sin permisos${NC}"
fi
chmod 755 test_dir
rmdir test_dir
echo

# Test 6: Comandos que fallan
echo -e "${YELLOW}Test 6: Manejo de comandos que fallan${NC}"
echo -e "line1\nline2" > test_input.txt
./pipex test_input.txt "grep nonexistent" "wc -l" test_output.txt 2>/dev/null
if [ -f test_output.txt ]; then
    result=$(cat test_output.txt)
    if [ "$result" = "0" ]; then
        echo -e "${GREEN}✅ Maneja correctamente comandos sin salida${NC}"
    else
        echo -e "${RED}❌ Resultado incorrecto: $result${NC}"
    fi
else
    echo -e "${RED}❌ No se creó archivo de salida${NC}"
fi
echo

# Test 7: Archivos grandes (stress test)
echo -e "${YELLOW}Test 7: Archivos grandes${NC}"
seq 1 10000 > large_input.txt
./pipex large_input.txt "head -5000" "tail -1000" test_output.txt 2>/dev/null
if [ -f test_output.txt ]; then
    lines=$(wc -l < test_output.txt)
    if [ "$lines" = "1000" ]; then
        echo -e "${GREEN}✅ Maneja archivos grandes correctamente${NC}"
    else
        echo -e "${RED}❌ Resultado incorrecto: $lines líneas${NC}"
    fi
else
    echo -e "${RED}❌ Falla con archivos grandes${NC}"
fi
rm large_input.txt
echo

# Test 8: Múltiples espacios en comandos
echo -e "${YELLOW}Test 8: Comandos con múltiples espacios${NC}"
echo "a b c d" > test_input.txt
./pipex test_input.txt "tr ' ' '\n'" "wc -l" test_output.txt 2>/dev/null
if [ -f test_output.txt ]; then
    result=$(cat test_output.txt)
    if [ "$result" = "4" ]; then
        echo -e "${GREEN}✅ Maneja múltiples espacios correctamente${NC}"
    else
        echo -e "${RED}❌ Resultado incorrecto: $result${NC}"
    fi
else
    echo -e "${RED}❌ Falla con múltiples espacios${NC}"
fi
echo

# Test 9: Comandos con flags complejos
echo -e "${YELLOW}Test 9: Comandos con flags complejos${NC}"
echo -e "apple\nbanana\napricot" > test_input.txt
./pipex test_input.txt "grep -v banana" "sort -r" test_output.txt 2>/dev/null
if [ -f test_output.txt ]; then
    first_line=$(head -1 test_output.txt)
    if [ "$first_line" = "apricot" ]; then
        echo -e "${GREEN}✅ Flags complejos funcionan${NC}"
    else
        echo -e "${RED}❌ Resultado incorrecto: $first_line${NC}"
    fi
else
    echo -e "${RED}❌ Falla con flags complejos${NC}"
fi
echo

# Test 10: Archivo vacío
echo -e "${YELLOW}Test 10: Archivo vacío${NC}"
touch empty_file.txt
./pipex empty_file.txt "cat" "wc -l" test_output.txt 2>/dev/null
if [ -f test_output.txt ]; then
    result=$(cat test_output.txt)
    if [ "$result" = "0" ]; then
        echo -e "${GREEN}✅ Maneja archivos vacíos correctamente${NC}"
    else
        echo -e "${RED}❌ Resultado incorrecto: $result${NC}"
    fi
else
    echo -e "${RED}❌ Falla con archivos vacíos${NC}"
fi
rm empty_file.txt
echo

echo -e "${YELLOW}=== PRUEBAS BONUS ===${NC}\n"

# Test Bonus 1: Múltiples comandos
echo -e "${YELLOW}Test Bonus 1: Múltiples comandos (5 comandos)${NC}"
echo -e "apple\nbanana\ncherry\ndate\napricot" > test_input.txt
./pipex_bonus test_input.txt "grep a" "sort" "uniq" "wc -l" "cat" test_output.txt 2>/dev/null
if [ -f test_output.txt ]; then
    result=$(cat test_output.txt)
    if [ "$result" = "3" ]; then
        echo -e "${GREEN}✅ Múltiples comandos funcionan${NC}"
    else
        echo -e "${RED}❌ Resultado incorrecto: $result${NC}"
    fi
else
    echo -e "${RED}❌ Falla con múltiples comandos${NC}"
fi
echo

# Test Bonus 2: Solo un comando
echo -e "${YELLOW}Test Bonus 2: Un solo comando${NC}"
echo "test line" > test_input.txt
./pipex_bonus test_input.txt "wc -w" test_output.txt 2>/dev/null
if [ -f test_output.txt ]; then
    result=$(cat test_output.txt)
    if [ "$result" = "2" ]; then
        echo -e "${GREEN}✅ Un solo comando funciona${NC}"
    else
        echo -e "${RED}❌ Resultado incorrecto: $result${NC}"
    fi
else
    echo -e "${RED}❌ Falla con un solo comando${NC}"
fi
echo

# Limpieza
rm -f test_input.txt test_output.txt

echo -e "${YELLOW}=== PRUEBAS COMPLETADAS ===${NC}"
