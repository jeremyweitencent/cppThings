#!/bin/bash

source_name=$1
if [ ! -n "$source_name" ]; then
  source_name="marco_hpp.h"
fi

dest_name=$2
if [ ! -n "$dest_name" ]; then
  dest_name="marco_hpp.h.i"
fi

rm $dest_name

echo "gcc -P -E ${source_name} -o $dest_name"
gcc -P -E ${source_name} -o $dest_name
echo "compile success"