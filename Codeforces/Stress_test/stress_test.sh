#!/bin/bash

# Number of test cases to run
TEST_CASES=100

# Compile the solutions
g++ -o optimized_solution optimized_solution.cpp -O2 || { echo "Failed to compile optimized solution"; exit 1; }
g++ -o brute_force_solution brute_force_solution.cpp -O2 || { echo "Failed to compile brute force solution"; exit 1; }
g++ -o generate_input generate_input.cpp -O2 || { echo "Failed to compile input generator"; exit 1; }

# Start stress testing
FAILED_CASE=""
for ((i=1; i<=TEST_CASES; i++)); do
    echo "Running Test Case #$i"

    # Generate random input
    ./generate_input > input.txt || { echo "Failed to generate input"; exit 1; }

    # Run both solutions
    ./optimized_solution < input.txt > output_optimized.txt || { echo "Optimized solution crashed"; exit 1; }
    ./brute_force_solution < input.txt > output_brute.txt || { echo "Brute force solution crashed"; exit 1; }

    # Compare outputs
    if ! diff -q output_optimized.txt output_brute.txt > /dev/null; then
        echo "Test Case #$i Failed!"
        FAILED_CASE="$i"

        # Save the failed input/output
        mv input.txt failed_input.txt
        cp output_optimized.txt failed_output_optimized.txt
        cp output_brute.txt failed_output_brute.txt
        break
    fi

    echo "Test Case #$i Passed."
done

if [ -n "$FAILED_CASE" ]; then
    echo "\n--------------------------------------"
    echo "Test Case #$FAILED_CASE Failed!"
    echo "--------------------------------------"
    echo "Input (failed_input.txt):"
    cat failed_input.txt
    echo "--------------------------------------"
    echo "Output (Optimized - failed_output_optimized.txt):"
    cat failed_output_optimized.txt
    echo "--------------------------------------"
    echo "Output (Brute Force - failed_output_brute.txt):"
    cat failed_output_brute.txt
    echo "--------------------------------------"
    exit 1
fi

echo "All test cases passed successfully!"
