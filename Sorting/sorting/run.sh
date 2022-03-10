# making the nullbytes
if [ ! -f "nullbytes" ]
then
  dd if=/dev/urandom of=nullbytes count=4096 bs=1048576
fi

g++ make-random-data.cpp -o make-random-data
g++ bubbleSort.cpp -o bubbleSort

./make-random-data 1
./bubbleSort 1