# this file is called sortrace.sh
# it must have execute privilege set to run
# run it as a background task like this:
# $ rm sortrace.log 
# start with fresh log file
# $ sortrace.sh >> sortrace.log &

# // Omeed Enshaie
# // CECS 325-02
# // Prog 5 threads
# // Due Date(10/31/2023)
# // I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program.

echo "========Start========"
date
echo My machine has this many processors
nproc
echo Generating 1000000 random numbers
sleep 1
./generate 1000000 100000 999999 # you have to write generate.cpp
sleep 1
echo Starting system sort
sleep 1
{ time sort numbers.dat > systemsort.out; } 2>> sortrace.log
sleep 1
echo Starting my sort
sleep 1
{ time ./mysort numbers.dat > mysort.out; } 2>> sortrace.log # you have to write mysort.cpp
sleep 1
ls -l systemsort.out
ls -l mysort.out
echo Comparing systemsort.out to mysort.out
diff systemsort.out mysort.out 2>> sortrace.log
echo ALL done
echo "========END========"
date
#sort -c mysort.out 2>> sortrace.log # verify file is sorted