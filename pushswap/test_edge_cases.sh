#!/bin/bash

echo "=== PUSH_SWAP EDGE CASE TESTING ==="
echo

# Test 1: No arguments
echo "Test 1: No arguments"
./pushswap
echo "Expected: No output, exit code 0"
echo

# Test 2: Empty string
echo "Test 2: Empty string"
./pushswap ""
echo "Expected: Error"
echo

# Test 3: Invalid characters
echo "Test 3: Invalid characters"
./pushswap "abc" "123abc" "12.3"
echo "Expected: Error"
echo

# Test 4: Signs without numbers
echo "Test 4: Signs without numbers"
./pushswap "+" "-" "+123-"
echo "Expected: Error"
echo

# Test 5: Integer overflow
echo "Test 5: Integer overflow"
./pushswap "2147483648" "-2147483649"
echo "Expected: Error"
echo

# Test 6: Valid INT_MAX and INT_MIN
echo "Test 6: Valid INT_MAX and INT_MIN"
./pushswap "2147483647" "-2147483648"
echo "Expected: sa (or other valid operations)"
echo

# Test 7: Duplicates
echo "Test 7: Duplicates"
./pushswap "1" "2" "3" "1"
echo "Expected: Error"
echo

# Test 8: Single number
echo "Test 8: Single number"
./pushswap "42"
echo "Expected: No output"
echo

# Test 9: Already sorted
echo "Test 9: Already sorted"
./pushswap "1" "2" "3" "4" "5"
echo "Expected: No output"
echo

# Test 10: Memory leak test (requires valgrind)
echo "Test 10: Memory leak test"
echo "Run: valgrind --leak-check=full ./pushswap 5 4 3 2 1"
echo "Expected: No leaks, 0 errors"
echo

echo "=== ALL TESTS COMPLETED ==="
