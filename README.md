# Disk Write Speed - A simple test program

By Cralina (https://cralina.com)

The program in this repository helps you to do a simple write speed test (using the standard file write library function) with different buffer/block sizes during the write call.

# Programs
**USE test5.c & test5_no_sync.c for actual timing measurements**  
test4.c -> Writes to disk starting with write buffer size varying from 32k - 16M with O_SYNC set (writes without buffering), measures CPU time using clock function  
test4_no_sync.c -> Writes to disk starting with write buffer size varying from 32k - 16M WITHOUT O_SYNC set (default write method, writes are cached by kernel buffer), measures CPU time using clock function  

test5.c -> Same as test4.c uses a different timing function (clock_gettime) should be used on POSIX compliant systems only.  
test5_no_sync.c -> Same as test4_no_sync.c uses a different timing function (clock_gettime) should be used on POSIX compliant systems only.  

# Generating the binary
gcc test5.c -o test_sync.o  
gcc test5_no_sync.c -o test_no_sync.o  

## Usage 
binary FileName Size  
FileName : Writes a file specified by this name  
Size : Specify the size of FileName in MB    

Sample usage of test_sync, writes a file with name abc - 512MB in size:  
_____

./test_sync.o abc 512 

./test_sync.o abc 512  
Writing block size of 65536, 8192 times, file size 512MB  
Write speed in megabytes per second = 34.18, Blocksize:64k  
Writing block size of 131072, 4096 times, file size 512MB  
Write speed in megabytes per second = 46.14, Blocksize:128k  
Writing block size of 262144, 2048 times, file size 512MB  
Write speed in megabytes per second = 32.96, Blocksize:256k  
Writing block size of 524288, 1024 times, file size 512MB  
Write speed in megabytes per second = 59.34, Blocksize:512k  
Writing block size of 1048576, 512 times, file size 512MB  
Write speed in megabytes per second = 102.01, Blocksize:1024k  
Writing block size of 2097152, 256 times, file size 512MB  
Write speed in megabytes per second = 145.90, Blocksize:2048k  
Writing block size of 4194304, 128 times, file size 512MB  
Write speed in megabytes per second = 216.43, Blocksize:4096k  
Writing block size of 8388608, 64 times, file size 512MB  
Write speed in megabytes per second = 225.58, Blocksize:8192k  
Writing block size of 16777216, 32 times, file size 512MB  
Write speed in megabytes per second = 268.53, Blocksize:16384k  
