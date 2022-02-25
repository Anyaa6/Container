For main.cpp exe
--> make

For cleanmain.cpp = tester exe
--> make tester

in cleanmain.cpp if line "#if 1" --> does STD library test
./Container > tester1

in cleanmain.cpp if line "#if 0" --> does ft library test
./Container > tester0

Then
diff tester1 tester0

to check for differences of output