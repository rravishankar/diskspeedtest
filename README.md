# Disk Write Speed - A simple test program

By Cralina (https://cralina.com)

The program in this repository helps you to do a simple write speed test (using the standard file write library function) with different buffer/block sizes during the write call.

# Programs

test4.c -> Writes to disk starting with write buffer size varying from 32k - 16M with O_SYNC set (writes without buffering)  
test4_no_sync.c -> Writes to disk starting with write buffer size varying from 32k - 16M WITHOUT O_SYNC set (default write method, writes are cached by kernel buffer)  

# Generating the binary
gcc test4.c -o test_sync.o  
gcc test4_no_sync.c -o test_no_sync.o  

## Usage 
binary FileName Size  
FileName : Writes a file specified by this name  
Size : Specify the size of FileName in MB    

Sample usage of test_sync, writes a file with name abc - 512MB in size:  
_____

./test_sync.o abc 512 

Writing block size of 65536, 8192 times, file size 512MB  
Bytes per second written = 612443360.464519  
Write speed in megabytes per second = 584.07, Blocksize:64k  
Writing block size of 131072, 4096 times, file size 512MB  
Bytes per second written = 770516028.290622  
Write speed in megabytes per second = 734.82, Blocksize:128k  
Writing block size of 262144, 2048 times, file size 512MB  
Bytes per second written = 931642170.328479  
Write speed in megabytes per second = 888.48, Blocksize:256k  
Writing block size of 524288, 1024 times, file size 512MB  
Bytes per second written = 1144128616.486233  
Write speed in megabytes per second = 1091.13, Blocksize:512k  
Writing block size of 1048576, 512 times, file size 512MB  
Bytes per second written = 1227877255.937882  
Write speed in megabytes per second = 1171.00, Blocksize:1024k  
Writing block size of 2097152, 256 times, file size 512MB  
Bytes per second written = 1239477290.409865  
Write speed in megabytes per second = 1182.06, Blocksize:2048k  
Writing block size of 4194304, 128 times, file size 512MB  
Bytes per second written = 1306458699.164833  
Write speed in megabytes per second = 1245.94,  Blocksize:4096k  
Writing block size of 8388608, 64 times, file size 512MB  
Bytes per second written = 1484545160.933525  
Write speed in megabytes per second = 1415.77, Blocksize:8192k  
Writing block size of 16777216, 32 times, file size 512MB  
Bytes per second written = 1454012664.055856  
Write speed in megabytes per second = 1386.65, Blocksize:16384k  
  
___

Usage of test_no_sync is same as test_sync.  

