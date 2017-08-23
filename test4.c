#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <malloc.h>
#include <time.h>




//#define BUFFERSIZE (512*1024)
#define MEGABYTE (1024*1024)
#define KILOBYTE (1024)

/* Takes two arguments.  Arg 1 is file name.
arg 2 is number of megabytes to write*/
main(int argc, char * argv[]) {
	long megabytes, size = 64*1024; //size in k;
	char *filename;
	int i = 0;

	if (argc !=3)
	    {
	    printf("Arguments are filename to create and size in megabytes\n");
	    return -1;
	    }

	megabytes=atol(argv[2]);
	filename = argv[1];
	while (size <= 16*1024*1024) {//till 16M
		writer(argc, megabytes, size, filename);
		size = size * 2;
	}

}

writer (int argc, long megabytes, long writeblocksize, char *filename)
{
	long j,i,r;
	int outputfile;
	char *buffer;
	clock_t t;


	

	
	//printf("Blocksize= %ldk\n", writeblocksize/1024);

	buffer = malloc(writeblocksize);

	if (buffer == NULL) {
		printf("Out of memory\n");
		exit (1);
	}

	for (j=0 ; j < writeblocksize ;j++)
	    buffer[j]='X';

	outputfile = open(filename, O_CREAT | O_WRONLY | O_SYNC);


	t = clock();
	//printf("Megabytes %ld, writeblocksize %ld\n", megabytes, writeblocksize);
	r = (megabytes*MEGABYTE)/writeblocksize;
	//printf("Writing block size of %ld, %ld times\n",writeblocksize, r);
	for (i=0 ; i<((megabytes*MEGABYTE/writeblocksize)) ; i++)
	   write(outputfile,buffer,writeblocksize);

	t = clock() -t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds

	//printf("Time taken %lf\n", time_taken);
	if (time_taken > 0) {
		printf("Bytes per second written = %lf\n",(MEGABYTE*megabytes)/time_taken);
	 	double mbps = 1.0 * megabytes/time_taken;
	 	//printf("Megabytes = %ld, timetowrite seconds %lf\n",megabytes, time_taken);
	 	printf("MegaBytes per second written = %4.2lf, Blocksize:%ldk\n", mbps, writeblocksize/1024);
 	}

	close(outputfile);

	return 0;
}
