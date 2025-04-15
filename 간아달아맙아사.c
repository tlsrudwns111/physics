//---------------------------------------------------------

// �񽺵��� ���� ���� � ���α׷���

//-----------------------------------------------------------
#include <stdio.h>
#include <math.h>

int main() {
    double v0 = 100.0; 
    double angle = 37.0;          
    double y0 = 140.0;
    double pi = 3.14159;
    double g = 9.81;

    printf("�ʱ� �ӵ�:  ");
    scanf_s("%lf", &v0);
    printf("�߻� ����:  ");
    scanf_s("%lf", &angle);
    printf("�ʱ� ����:  ");
    scanf_s("%lf", &y0);

    
    double rad = angle * pi / 180.0;

   
    double v0x = v0 * cos(rad);
    double v0y = v0 * sin(rad);

  
    double a = -0.5 * g;
    double b = v0y;
    double c = y0;
    double D = b*b-4*a*c;

    if (D < 0) {
        printf("����: �Ǳ��� ����X.\n");
        return 1;
    }

    double t1 = (-b + sqrt(D)) / (2 * a);
    double t2 = (-b - sqrt(D)) / (2 * a);
    double t3 = fmax(t1, t2);

    printf("(a) ���鿡 ������ �������� �ð�: %.2f ��\n", t3);


    double d = v0x * t3;
    printf("(b) ���� �Ÿ�: %.2f m\n", d);

   
    double vx = v0x;
    double vy = v0y - g * t3;
    printf("(c) �ӵ��� ���� ����: %.2f m/s\n", vx);
    printf("(c) �ӵ��� ���� ����: %.2f m/s\n", vy);

   
    double s = sqrt(vx * vx + vy * vy);
    printf("(d) �ӵ��� ũ��: %.2f m/s\n", s);

    double ang = atan2(vy, vx) * 180.0 / pi;
    printf("(e) ���� ����� �̷�� ����: %.2f ��\n", ang);

    return 0;
}