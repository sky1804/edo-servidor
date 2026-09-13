# Modelagem da Utilização de um Servidor Computacional por meio de EDO

Projeto desenvolvido para a disciplina de **Cálculo III**, com o objetivo de modelar a utilização de um servidor computacional em um sistema de filas por meio de uma Equação Diferencial Ordinária (EDO) de primeira ordem.

## Modelo matemático

Considera-se:

- `λ` — taxa média de chegada de requisições;
- `μ` — taxa média de processamento do servidor;
- `u(t)` — estimativa da utilização do servidor no instante `t`;
- `u(t0) = u0` — condição inicial do PVI.

A EDO utilizada é:

\[
\frac{du}{dt} = \lambda - \mu u
\]

ou, na forma linear,

\[
u' + \mu u = \lambda
\]

A solução analítica para um PVI genérico \(u(t_0)=u_0\) é:

\[
u(t)=\frac{\lambda}{\mu}+\left(u_0-\frac{\lambda}{\mu}\right)e^{-\mu(t-t_0)}
\]

O valor de equilíbrio é:

\[
u_e=\frac{\lambda}{\mu}
\]

## Exemplo analisado

Para:

- `λ = 5 req/h`
- `μ = 10 req/h`
- `u(0) = 0`

temos:

\[
u(t)=0,5(1-e^{-10t})
\]

e a utilização tende a:

\[
u_e=\frac{5}{10}=0,5
\]

ou seja, **50% de utilização em regime permanente**.

## Código em C

O programa permite informar diferentes valores para:

- taxa de chegada `λ`;
- taxa de processamento `μ`;
- instante inicial `t0`;
- utilização inicial `u0`;
- instante `t` a ser analisado.

O código representa a resolução analítica da EDO, incluindo:

- fator integrante;
- primitiva utilizada na integração;
- cálculo da constante `C` a partir do PVI;
- cálculo de `u(t)`;
- cálculo da utilização de equilíbrio.

## Compilação

O projeto foi desenvolvido no **Microsoft Visual Studio** como aplicação de console em C.

Arquivo principal:

```text
main.c
```

Para compilar no Visual Studio:

```text
Build > Build Solution
```

ou:

```text
Ctrl + Shift + B
```

Para executar:

```text
Ctrl + F5
```

## Referência principal

MUEEN, Zeina. *Estimating server utilization rate in single server queuing models using an approximate solution of stiff fluid flow model*. **Ain Shams Engineering Journal**, v. 11, n. 3, p. 805–809, 2020.

DOI: `10.1016/j.asej.2019.12.006`
