Git clone then at root 

sh container.sh unit
-> for unit test / current things being tested

sh container.sh tester
-> for tester, compiles my version of containers (ft::) and std version, then does diff and compares exec time

-----------------------------------------------------

sh container.sh unit_std
-> for unit test with std::

sh container.sh unit_std
-> for unit test with ft::

to check for differences of output

--------------------------------------------------
make tclean
-> deletes output files