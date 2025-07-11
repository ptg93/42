#!/bin/bash

echo "=== COMPREHENSIVE PUSH SWAP TESTING ==="
echo

# Function to test with checker
test_with_checker() {
    local description="$1"
    local args="$2"
    
    echo "Testing: $description"
    echo "Arguments: $args"
    
    # Generate moves
    ./push_swap $args > /tmp/test_moves.txt
    
    # Check if sorting is correct
    result=$(./checker_linux $args < /tmp/test_moves.txt)
    moves=$(wc -l < /tmp/test_moves.txt)
    
    if [ "$result" = "OK" ]; then
        echo "✓ PASS: $moves moves"
    else
        echo "✗ FAIL: Incorrect sorting!"
        return 1
    fi
    echo
    return 0
}

# Test 1: Small sets (≤5 numbers)
echo "=== TESTING SMALL ALGORITHM (≤5 numbers) ==="
test_with_checker "2 numbers" "2 1"
test_with_checker "3 numbers" "3 1 2"
test_with_checker "4 numbers" "4 2 1 3"
test_with_checker "5 numbers" "5 3 1 4 2"

# Test 2: Medium sets (6-200 numbers)
echo "=== TESTING MEDIUM ALGORITHM (6-200 numbers) ==="

# Test with 10 numbers
ARG_10=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1, 21), 10))))")
test_with_checker "10 numbers (random)" "$ARG_10"

# Test with 50 numbers
ARG_50=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1, 101), 50))))")
test_with_checker "50 numbers (random)" "$ARG_50"

# Test with 100 numbers (3 different sets)
for i in {1..3}; do
    ARG_100=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1, 201), 100))))")
    test_with_checker "100 numbers (random set $i)" "$ARG_100"
done

# Test with 200 numbers (threshold test)
ARG_200=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1, 401), 200))))")
test_with_checker "200 numbers (threshold)" "$ARG_200"

# Test 3: Large sets (>200 numbers)
echo "=== TESTING LARGE ALGORITHM (>200 numbers) ==="

# Test with 250 numbers
ARG_250=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1, 501), 250))))")
test_with_checker "250 numbers (radix)" "$ARG_250"

# Test with 500 numbers
ARG_500=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(1, 1001), 500))))")
test_with_checker "500 numbers (radix)" "$ARG_500"

# Test 4: Edge cases
echo "=== TESTING EDGE CASES ==="
test_with_checker "Already sorted (5)" "1 2 3 4 5"
test_with_checker "Reverse sorted (5)" "5 4 3 2 1"
test_with_checker "Single number" "42"

# Test with duplicates (should fail)
echo "Testing duplicate detection:"
./push_swap 1 2 3 2 4 2>/dev/null
if [ $? -eq 1 ]; then
    echo "✓ PASS: Correctly detected duplicates"
else
    echo "✗ FAIL: Should have detected duplicates"
fi

echo
echo "=== TEST SUMMARY ==="
echo "All tests completed. Check above for any failures."
