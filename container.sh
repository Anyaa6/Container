#!/usr/bin/env bash

if [ "$1" == "unit" ]; then
	rm -f output_ft output_std
	
	make re DFLAGS=-Dstd_lib=0
	./Container > output_ft
	
	make re DFLAGS=-Dstd_lib=1
	./Container > output_std
	
	diff output_ft output_std

elif [ "$1" == "unit_std" ]; then
	make re DFLAGS=-Dstd_lib=1
	./Container > output_std
	echo 
	cat output_std

elif [ "$1" == "unit_ft" ]; then
	make re DFLAGS=-Dstd_lib=0
	./Container > output_ft
	echo 
	cat output_ft

elif [ "$1" == "tester" ]; then
	rm -f output_ft output_std

	make fclean
	make tester DFLAGS=-Dstd_lib=0
	./Container > output_ft
	
	make fclean
	make tester DFLAGS=-Dstd_lib=1
	./Container > output_std
	
	diff output_ft output_std
fi