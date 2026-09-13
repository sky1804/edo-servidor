#include <stdio.h>
#include <math.h>

/*
    Fator integrante da EDO:

    u' + mu*u = lambda

    I(t) = e^(mu*t)
*/
double calcularFatorIntegrante(double mu, double t)
{
    return exp(mu * t);
}

/*
    Primitiva utilizada durante a integracao:

    integral e^(mu*t) dt = e^(mu*t) / mu
*/
double calcularIntegralExponencial(double mu, double t)
{
    return exp(mu * t) / mu;
}

/*
    A solucao geral da EDO e:

    u(t) = lambda/mu + C*e^(-mu*t)

    Para um PVI generico:

    u(t0) = u0

    temos:

    C = (u0 - lambda/mu) * e^(mu*t0)
*/
double calcularConstanteC(double lambda, double mu,
    double t0, double u0)
{
    return (u0 - (lambda / mu)) * exp(mu * t0);
}

/*
    Calcula a solucao da EDO no instante t.
*/
double calcularSolucao(double lambda, double mu,
    double t0, double u0, double t)
{
    double C = calcularConstanteC(lambda, mu, t0, u0);

    return (lambda / mu) + C * exp(-mu * t);
}

int main(void)
{
    double lambda;
    double mu;
    double t0;
    double u0;
    double t;

    printf("===== MODELO DE FILA DE SERVIDOR =====\n\n");

    printf("Taxa de chegada lambda (requisicoes/hora): ");
    scanf_s("%lf", &lambda);

    printf("Taxa de processamento mu (requisicoes/hora): ");
    scanf_s("%lf", &mu);

    printf("Instante inicial t0 (horas): ");
    scanf_s("%lf", &t0);

    printf("Utilizacao inicial u(t0) (0 a 1): ");
    scanf_s("%lf", &u0);

    printf("Tempo que deseja analisar t (horas): ");
    scanf_s("%lf", &t);

    /* Validacoes */
    if (lambda < 0)
    {
        printf("\nErro: lambda nao pode ser negativo.\n");
        return 1;
    }

    if (mu <= 0)
    {
        printf("\nErro: mu deve ser maior que zero.\n");
        return 1;
    }

    if (u0 < 0 || u0 > 1)
    {
        printf("\nErro: a utilizacao inicial deve estar entre 0 e 1.\n");
        return 1;
    }

    if (t0 < 0 || t < t0)
    {
        printf("\nErro: o tempo analisado deve ser maior ou igual a t0.\n");
        return 1;
    }

    /*
        Representacao das etapas da resolucao analitica.
    */
    double fatorIntegrante = calcularFatorIntegrante(mu, t);
    double integralExponencial = calcularIntegralExponencial(mu, t);
    double C = calcularConstanteC(lambda, mu, t0, u0);

    double u = calcularSolucao(lambda, mu, t0, u0, t);
    double ue = lambda / mu;

    printf("\n===== RESULTADOS =====\n");

    printf("Taxa de chegada (lambda):       %.2f req/h\n", lambda);
    printf("Taxa de processamento (mu):    %.2f req/h\n", mu);
    printf("PVI: u(%.2f) = %.4f\n", t0, u0);
    printf("Tempo analisado:               %.2f h\n", t);

    printf("\n===== RESOLUCAO ANALITICA =====\n");

    printf("Fator integrante I(t):         %.4f\n",
        fatorIntegrante);

    printf("Integral analitica de\n e^(mu*t) dt = e^(mu*t) / mu + C\n Valor de e^(mu*t)/mu em t:         %.4f\n",
        integralExponencial);

    printf("Constante C obtida pelo PVI:   %.4f\n",
        C);

    printf("\n===== SOLUCAO =====\n");

    printf("u(%.2f) = %.4f\n", t, u);
    printf("Utilizacao em t = %.2f:        %.2f%%\n",
        t, u * 100);

    printf("Utilizacao de equilibrio:      %.4f\n", ue);
    printf("Percentual de equilibrio:      %.2f%%\n",
        ue * 100);

    if (ue > 1)
    {
        printf("\nAVISO: a demanda ultrapassa a capacidade "
            "de processamento do servidor.\n");
    }

    return 0;
}