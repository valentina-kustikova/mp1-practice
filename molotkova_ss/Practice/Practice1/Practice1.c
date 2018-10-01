#include <stdio.h> 
#include <math.h> 
#include <locale.h> 

void main()
{ 
    float dsp=0.65; float dvp=0.82; float der=0.5; // ДСП,ДВП,плотность дерева в см3
	float h, w, d; // вводимые пользователем данные: высота, ширина, глубина
	float kolvopolok;
	float mz, mb, mk, md, mp, m;//суммы
	float t1, t2, t3, t4;// толщина
	t1=0.5;//5 мм в см(п1)
	t2=1.5;// 15мм в см(п2)
	t3=1.5;//15 мм в см(п3)
	t4=1;// см(п4)
    setlocale(LC_ALL, "Russian"); 

    printf("Введите высоту\n" ); 
	scanf("%f", &h); 
	printf("Введите ширину\n"); 
	scanf("%f", &w); 
	printf("Введите глубину\n"); 
    scanf("%f", &d); 
	kolvopolok=floor(h/40);
    if ((180<h)&&(h<220)&&(80<w)&&(w<120)&&(50<d)&&(d<90))
	{
		mz=h*w*t1*dvp;
		mb=2*h*d*t2*dsp;
		mk=2*dsp*w*d*t3;
		md=2*h*w*t4*der;
		mp=d*dsp*w*kolvopolok;
		m= (mz+mb+mk+md+mp)/1000;
		
		printf("Масса шкафа %0.f кг\n",m);
	}
	else printf("Введенные значения не соответствуют должным");
}