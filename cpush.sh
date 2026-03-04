#!/bin/bash

# Usage: ./cpush.sh <target_folder> <filename_without_ext>
# Example: ./cpush.sh UVa 10646
# Copies main.cpp → Cp/UVa/10646.cpp

TARGET=$1
NAME=$2

BASE_DIR="$(cd "$(dirname "$0")" && pwd)"  # Path to Cp/
DEST="$BASE_DIR/$TARGET"
SRC="$BASE_DIR/main.cpp"
DEST_FILE="$DEST/$NAME.cpp"

# Sanity checks
if [ -z "$TARGET" ] || [ -z "$NAME" ]; then
    echo "Usage: ./cpush.sh <kattis|UVa> <filename_without_ext>"
    exit 1
fi

if [ ! -d "$DEST" ]; then
    echo "Error: target folder '$DEST' does not exist."
    exit 1
fi

if [ ! -f "$SRC" ]; then
    echo "Error: source file 'main.cpp' not found in $BASE_DIR"
    exit 1
fi

# Copy with rename
cp "$SRC" "$DEST_FILE"
echo "✅ Copied main.cpp → $DEST_FILE"
