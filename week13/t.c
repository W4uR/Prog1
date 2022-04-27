#define MAX_TITKOS 4096
#define OLVASAS_BUFFER 256
#define KULCS_MERET 5
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <string.h>

double atlagos_szohossz(const char titkos[], int titkos_meret){

	int sz = 0;

	for (int i = 0; i < titkos_meret; i++)
		if (titkos[i] == ' ')
			++sz;

	return (double) titkos_meret / sz;

}

int tiszta_lehet (const char titkos[], int titkos_meret){

	double szohossz = atlagos_szohossz(titkos, titkos_meret);

	return szohossz < 9.0 && szohossz > 6.0 &&
		strcasestr (titkos, "nem") && strcasestr (titkos, "hogy") &&
		strcasestr (titkos, "az") && strcasestr (titkos, "Ha");

}

void exor (const char kulcs[], int kulcs_meret, 
	char titkos[], int tikos_meret){

	int kulcs_index = 0;

	for (int i = 0; i < tikos_meret; i++){
		titkos[i] = titkos[i] ^ kulcs[kulcs_index];
		kulcs_index = (kulcs_index + 1) % kulcs_meret;
	}
}

int exor_tores(const char kulcs[], int kulcs_meret, 
	char titkos[], int titkos_meret){

	exor (kulcs, kulcs_meret, titkos, titkos_meret);

	return tiszta_lehet (titkos, titkos_meret);

}

int main(){

	char kulcs[KULCS_MERET];
	char titkos[MAX_TITKOS];
	char *p = titkos;
	int olvasott_bajtok;

	while ((olvasott_bajtok = 
		read ( 0, (void*) p, 
		(p - titkos + OLVASAS_BUFFER <
		MAX_TITKOS) ? OLVASAS_BUFFER : titkos + MAX_TITKOS - p )))

	p += olvasott_bajtok;

	for (int i = 0; i < MAX_TITKOS - (p - titkos); ++i)
		titkos[p - titkos + i] = '\0';

	for (char ii = 'a'; ii <= 'z'; ++ii)
		for (char ji = 'a'; ji <= 'z'; ++ji)
			for (char ki = 'a'; ki <= 'z'; ++ki)
				for (char li = 'a'; li <= 'z'; ++li)
					for (char mi = 'a'; mi <= 'z'; ++mi){
									kulcs[0] = ii;
									kulcs[1] = ji;
									kulcs[2] = ki;
									kulcs[3] = li;
									kulcs[4] = mi;


					if (exor_tores(kulcs, KULCS_MERET, titkos, p - titkos))
						printf(
							"Kulcs: [%c%c%c%c%c]\nTiszta szöveg: [%s\n]",
							ii, ji, ki, li, mi, titkos);

					exor (kulcs, KULCS_MERET, titkos, p - titkos);
					}
				

	return 0;
}