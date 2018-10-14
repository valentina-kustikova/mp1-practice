#include <stdio.h>
#include <math.h>
void main ()
{
	float Mdvp, Mdsp, Mderevo, M;
	float Pdsp, Pdvp, Pderevo;
	float Vzs, Vb,Vd, Vp,Vvnk;
	float h, w,t1; //накладная задняя стенка из ДВП
	float d, t2; //2 боковины из ДСП
	float t3; //накладные верхняя и нижняя крышки из ДСП
	float t4; //2 накладные двери шкафа из ДЕРЕВА
	float r; //внутренние полки из ДСП


	scanf("%f %f %f %f %f %f %f %f %f %f", &Pdsp, &Pdvp, &Pderevo, &h, &w, &t1, &d, &t2, &t3, &t4);
 //ВСЕ ИЗМЕРЕНИЯ ВВОДИТЬ В СМ, КРОМЕ ПЛОТНОСТИ//
		if ((h>=180)&&(h<=220))
			{
			r=h/40;
			}
		else 
			printf("Такого шкафа не существует");
		
		
		  if (((w>=80)&&(w<=120))&&((d>=50)&&(d<=90)))
		    {
				Vzs=h*w*t1;//ДВП накладная стенка
				Vb=2*h*d*t2;//ДСП боковины
				Vvnk=2*w*d*t3;//ДСП верхняя и нижняя крышки
				Vd=2*h*w*t4;//дерево двери
				Vp=r*w*d;//ДСП полки
			}
 
				Mdsp=(Vb+Vvnk+Vp)*Pdsp;
				Mdvp=Vzs*Pdvp;
				Mderevo=Vd*Pderevo;
				M= (Mdsp+Mdvp+Mderevo)/1000000;
				printf("Масса шкафа = %f кг", M );
}