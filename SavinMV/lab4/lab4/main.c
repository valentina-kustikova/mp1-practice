#include <stdio.h>
#include <string.h>

int main() {
	int t[5] = {1001,1002,3451,5678,9999};
	char name[5][9] = {"moloko","limonad","xleb","kefir","konfeta"};
	int ct[5] = { 100,40,50,70,120 };
	int st[5] = { 10,20,5,15,30 };
	int k, g, shtrix = 0,i,j,i1, symm = 0, itog = 0;
	int chek[5] = {0};
	do {
		symm = 0;
		itog = 0;
		i = 0;
		i1 = 0;
		shtrix = 0;
		printf("Vvedite 1 chtob otscanit' tovar, vvedite 4 chtob pokazat' chek, vvedite 5 chtob yznat' symmy k oplate \n ");
		scanf_s("%d", &k);
		if (k == 4) {
			for (i == 0;i < 5;i++) {
				if (chek[i] != 0) {
					printf("nazvanie: %s,stoimost' za edinichky: %d,kol-vo tovara: %d,obshaya stoimost' so skidkoy: %d\n", name[i], ct[i], chek[i], chek[i] * ct[i] - (chek[i] * ct[i]) * st[i] / 100);
					symm = symm + ct[i]* chek[i];
					itog = itog + (chek[i] * ct[i] - (chek[i] * ct[i]) * st[i] / 100);

				}
				
			}
			printf("bez skidki: %d , symmar skidka: %d , itog symma k oplate: %d\n", symm, symm - itog, itog);
		}
		if (k == 5) {
			for (i == 0;i < 5;i++) {
				if (chek[i] != 0) {
					itog = itog + (chek[i] * ct[i] - (chek[i] * ct[i]) * st[i] / 100);

				}	
			}
			printf("itog symma k oplate: %d\n", itog);
		}
		
		if (k == 1) {
			do {
			printf("vvedite shtrix-kod: ");
			scanf_s("%d", &shtrix);
			} while (shtrix != t[0] && shtrix != t[1] && shtrix != t[2]
				&& shtrix != t[3] && shtrix != t[4]);
		}
		
		if (k == 1) {
			do {
				do {
					printf("2-vivesti opicanie tovara, 3-dobavit' v chek\n");
					scanf_s("%d", &g);
					if (g == 2) {
						for (i1 == 0;i1 < 5;i1++) {
							if (shtrix == t[i1]) printf("shtrix kod tovara: %d,nazvanie: %s,stoimost' za edinichky: %d,skidka: %d%\n", shtrix, name[i1], ct[i1], st[i1]);
						}
					}
				} while (g != 3);			
				if (g == 3) {
					do {
						printf("dobavit' v chek(1-da,0-net)");
						scanf_s("%d", &j);
						if (j == 1) {
							for (i == 0;i < 5;i++) {
								if (shtrix == t[i]) {
									chek[i]+=1;

								}
							}
						}
					} while (j != 0 && j != 1);
				}
			} while (j != 0 && j != 1);
		}	
	} while (k != 5);
	return 0;
}
