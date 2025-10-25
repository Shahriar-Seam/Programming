#!/bin/bash

# Quick compilation and testing script for competitive programming
# Usage: ./compile.sh filename [input_file]

if [ $# -eq 0 ]; then
    echo "Usage: $0 <filename> [input_file]"
    echo "Example: $0 solution.cpp input.txt"
    exit 1
fi

filename="$1"
input_file="${2:-input.txt}"

# Get file extension
extension="${filename##*.}"

case "$extension" in
    "cpp"|"cc"|"cxx")
        echo "Compiling C++ file: $filename"
        g++ -O2 -std=c++17 -Wall -Wextra "$filename" -o "${filename%.*}"
        if [ $? -eq 0 ]; then
            echo "Compilation successful!"
            if [ -f "$input_file" ]; then
                echo "Running with input from $input_file:"
                "./${filename%.*}" < "$input_file"
            else
                echo "No input file found. Running interactively:"
                "./${filename%.*}"
            fi
        else
            echo "Compilation failed!"
            exit 1
        fi
        ;;
    "c")
        echo "Compiling C file: $filename"
        gcc -O2 -std=c11 -Wall -Wextra "$filename" -o "${filename%.*}"
        if [ $? -eq 0 ]; then
            echo "Compilation successful!"
            if [ -f "$input_file" ]; then
                echo "Running with input from $input_file:"
                "./${filename%.*}" < "$input_file"
            else
                echo "No input file found. Running interactively:"
                "./${filename%.*}"
            fi
        else
            echo "Compilation failed!"
            exit 1
        fi
        ;;
    "py")
        echo "Running Python file: $filename"
        if [ -f "$input_file" ]; then
            echo "Running with input from $input_file:"
            python3 "$filename" < "$input_file"
        else
            echo "No input file found. Running interactively:"
            python3 "$filename"
        fi
        ;;
    "java")
        echo "Compiling Java file: $filename"
        javac "$filename"
        if [ $? -eq 0 ]; then
            echo "Compilation successful!"
            class_name="${filename%.*}"
            if [ -f "$input_file" ]; then
                echo "Running with input from $input_file:"
                java "$class_name" < "$input_file"
            else
                echo "No input file found. Running interactively:"
                java "$class_name"
            fi
        else
            echo "Compilation failed!"
            exit 1
        fi
        ;;
    *)
        echo "Unsupported file extension: $extension"
        echo "Supported extensions: .cpp, .c, .py, .java"
        exit 1
        ;;
esac