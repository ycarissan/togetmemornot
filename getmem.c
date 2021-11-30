#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>

/* msleep(): Sleep for the requested number of milliseconds. */
int msleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        errno = EINVAL;
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

int main(int argc, char **argv) {
	char *cvalue = NULL;
	int index;
	int c;
	unsigned long long int fact=1000;
	unsigned long long int val=1000;

	while ((c = getopt (argc, argv, "mgMG")) != -1)
		switch (c)
		{
			case 'm':
			case 'M':
				printf("mega");
				fact = 1;
				break;
			case 'g':
			case 'G':
				printf("giga");
				fact=1000;
				break;
			default:
				abort ();
		}
	for (index = optind; index < argc; index++)
		val = (unsigned long long int)argv[index];
		printf ("Valeur lue :%llu\n", val);

	unsigned long long int nelem = fact*val;
	printf("Taille de l'allocation en octets :%llu\n",nelem);
	printf("Debut de l'allocation\n");
	char *array = malloc(nelem);
	if (array == NULL) {
		fprintf(stderr, "malloc failed\n");
		return -1;
	}
	printf("Fin de l'allocation\n");
        for (unsigned long long int i=0; i<nelem; i++){
                array[i] = 'A';
        }

	printf("Zzzzz\n");
	msleep(10*1000);
	printf("  OoO\n");

}
