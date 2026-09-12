#include <stdio.h>
#include <math.h>

int main(void)
{
    double lambda;  // Taxa média de chegada de requisições
    double mu;      // Taxa média de processamento
    double u0;      // Utilização do servidor no instante inicial
    double t;       // Tempo
    double u;       // Utilização do servidor no instante 't'

    printf("Taxa de chegada lambda: ");
    scanf_s("%lf", &lambda);

    printf("Taxa de processamento mu: ");
    scanf_s("%lf", &mu);

    printf("Utilizacao inicial u0: ");
    scanf_s("%lf", &u0);

    printf("Tempo t: ");
    scanf_s("%lf", &t);

    u = (lambda / mu) + (u0 - (lambda / mu)) * exp(-mu * t);

    printf("\nUtilizacao no tempo %.2f: %.4f\n", t, u);

    return 0;
}