#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

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


int main() {

	printf("Debut de l'allocation\n");
	int ngiga = 4;
	long long int nelem = ngiga*1000000000;
	char *array = malloc(nelem);
	if (array == NULL) {
		fprintf(stderr, "malloc failed\n");
		return -1;
	}
	printf("Fin de l'allocation\n");
        for (long long int i=0; i<nelem; i++){
                array[i] = 'A';
        }

	printf("Zzzzz\n");
	msleep(10*1000);
	printf("  OoO\n");

}
