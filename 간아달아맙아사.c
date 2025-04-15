//---------------------------------------------------------

// 비스듬이 던진 공의 운동 프로그래밍

//-----------------------------------------------------------
#include <stdio.h>
#include <math.h>

int main() {
    double v0 = 100.0; 
    double angle = 37.0;          
    double y0 = 140.0;
    double pi = 3.14159;
    double g = 9.81;

    printf("초기 속도:  ");
    scanf_s("%lf", &v0);
    printf("발사 각도:  ");
    scanf_s("%lf", &angle);
    printf("초기 높이:  ");
    scanf_s("%lf", &y0);

    
    double rad = angle * pi / 180.0;

   
    double v0x = v0 * cos(rad);
    double v0y = v0 * sin(rad);

  
    double a = -0.5 * g;
    double b = v0y;
    double c = y0;
    double D = b*b-4*a*c;

    if (D < 0) {
        printf("오류: 실근이 존재X.\n");
        return 1;
    }

    double t1 = (-b + sqrt(D)) / (2 * a);
    double t2 = (-b - sqrt(D)) / (2 * a);
    double t3 = fmax(t1, t2);

    printf("(a) 지면에 도달할 때까지의 시간: %.2f 초\n", t3);


    double d = v0x * t3;
    printf("(b) 수평 거리: %.2f m\n", d);

   
    double vx = v0x;
    double vy = v0y - g * t3;
    printf("(c) 속도의 수평 성분: %.2f m/s\n", vx);
    printf("(c) 속도의 수직 성분: %.2f m/s\n", vy);

   
    double s = sqrt(vx * vx + vy * vy);
    printf("(d) 속도의 크기: %.2f m/s\n", s);

    double ang = atan2(vy, vx) * 180.0 / pi;
    printf("(e) 수평 방향과 이루는 각도: %.2f 도\n", ang);

    return 0;
}