#!/usr/bin/env bash

#unit test from "main.cpp" file with std AND ft
if [ "$1" == "unit" ]; then
	rm -f output_ft output_std
	
	make re DFLAGS=-Dstd_lib=0
	./Container > output_ft
	
	make re DFLAGS=-Dstd_lib=1
	./Container > output_std
	
	diff output_ft output_std

#unit test from "main.cpp" file with std ONLY
elif [ "$1" == "unit_std" ]; then
	make re DFLAGS=-Dstd_lib=1
	./Container > output_std
	echo 
	cat output_std

#unit test from "main.cpp" file with ft ONLY
elif [ "$1" == "unit_ft" ]; then
	make re DFLAGS=-Dstd_lib=0
	./Container > output_ft
	echo 
	cat output_ft

#complete tester with std AND ft + runtime comparison
elif [ "$1" == "tester" ]; then
	rm -f output_ft output_std

	make fclean
	make tester DFLAGS=-Dstd_lib=0
	./Container > output_ft
	
	make fclean
	make tester DFLAGS=-Dstd_lib=1
	./Container > output_std
	
	diff output_ft output_std

#Special main "map_tests" to test how map works
elif [ "$1" == "map" ]; then
	make re std
	./Container > output_std
	echo 
	cat output_std

elif [ "$1" == "clean" ]; then
	make fclean
	make tclean

fi