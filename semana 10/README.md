# APC - Atividades de Python

## Sobre a atividade

Este repositório apresenta as atividades de 01 a 08 desenvolvidas na disciplina de Introdução à Programação.

Os exercícios foram feitos em Python e reunidos em um único arquivo. Cada atividade está separada por comentários para facilitar a leitura, a execução e a identificação dos conteúdos estudados.

Durante as atividades, foram utilizados valores de exemplo para testar o funcionamento dos programas e conferir os resultados apresentados.

## Objetivos

Os principais objetivos desta atividade foram:

- praticar operações matemáticas em Python;
- conhecer os tipos básicos de dados;
- receber e converter valores digitados pelo usuário;
- utilizar estruturas condicionais;
- trabalhar com estruturas de repetição;
- armazenar valores em listas;
- criar e utilizar funções;
- manipular textos.

## Conteúdos trabalhados

Ao longo dos exercícios, foram utilizados os seguintes recursos da linguagem Python:

- `print()`;
- variáveis;
- tipos `int`, `float` e `str`;
- função `input()`;
- conversão de tipos;
- operadores aritméticos;
- estruturas `if`, `elif` e `else`;
- laços `while` e `for`;
- função `range()`;
- listas;
- função `max()`;
- criação de funções com `def`;
- retorno de valores com `return`;
- método `count()`;
- fatiamento de strings.

---

## Atividade 01 - Operações matemáticas

A primeira atividade demonstra o funcionamento de diferentes operadores matemáticos do Python.

```python
print("\nAtividade 01")

print("17 / 5 =", 17 / 5)
print("17 // 5 =", 17 // 5)
print("17 % 5 =", 17 % 5)
print("2 ** 10 =", 2 ** 10)
```

### Operadores utilizados

- `/`: divisão comum;
- `//`: divisão inteira;
- `%`: resto da divisão;
- `**`: potenciação.

### Resultados

```text
17 / 5 = 3.4
17 // 5 = 3
17 % 5 = 2
2 ** 10 = 1024
```

Essa atividade mostrou que a divisão comum pode gerar um número decimal, enquanto a divisão inteira desconsidera a parte decimal do resultado.

---

## Atividade 02 - Tipos de dados

A segunda atividade mostra que uma variável pode receber valores de tipos diferentes em momentos diferentes.

```python
print("\nAtividade 02")

x = 10
print(x, type(x))

x = 2.5
print(x, type(x))

x = "dez"
print(x, type(x))
```

### Resultados

```text
10 <class 'int'>
2.5 <class 'float'>
dez <class 'str'>
```

Os tipos encontrados foram:

- `int`: número inteiro;
- `float`: número com casas decimais;
- `str`: texto.

A variável `x` foi reutilizada, recebendo um número inteiro, um número decimal e depois um texto. Isso demonstra que Python permite alterar o tipo do valor armazenado em uma variável.

---

## Atividade 03 - Operações com valores digitados

Nesta atividade, o programa solicita dois números inteiros e calcula a soma, a diferença e o produto.

```python
print("\nAtividade 03")

a = int(input("Digite o primeiro numero: "))
b = int(input("Digite o segundo numero: "))

print("Soma:", a + b)
print("Diferenca:", a - b)
print("Produto:", a * b)
```

### Valores utilizados no teste

```text
10 e 3
```

### Resultados

```text
Soma: 13
Diferenca: 7
Produto: 30
```

A função `input()` recebe o valor digitado como texto. Por isso, foi usada a função `int()` para converter os valores para números inteiros.

---

## Atividade 04 - Número positivo, negativo ou zero

A quarta atividade utiliza uma estrutura condicional para classificar um número inteiro.

```python
print("\nAtividade 04")

numero = int(input("Digite um numero inteiro: "))

if numero > 0:
    print("Positivo")
elif numero < 0:
    print("Negativo")
else:
    print("Zero")
```

### Valor utilizado no teste

```text
-5
```

### Resultado

```text
Negativo
```

A estrutura verifica três possibilidades:

1. se o número for maior que zero, apresenta `Positivo`;
2. se o número for menor que zero, apresenta `Negativo`;
3. caso contrário, apresenta `Zero`.

---

## Atividade 05 - Contagem regressiva

Nesta atividade, uma contagem regressiva é realizada de duas formas: primeiro com `while` e depois com `for`.

```python
print("\nAtividade 05")

n = int(input("Digite um numero: "))

print("Com while:")

contador = n

while contador >= 0:
    print(contador)
    contador -= 1

print("Com for:")

for i in range(n, -1, -1):
    print(i)
```

### Valor utilizado no teste

```text
5
```

### Resultado

```text
Com while:
5
4
3
2
1
0

Com for:
5
4
3
2
1
0
```

No primeiro caso, a variável `contador` é reduzida manualmente até chegar a zero.

No segundo caso, `range(n, -1, -1)` cria a sequência regressiva. O último `-1` indica que a contagem deve diminuir de um em um.

---

## Atividade 06 - Maior valor de uma lista

A sexta atividade solicita cinco números, armazena os valores em uma lista e identifica o maior número de duas maneiras.

```python
print("\nAtividade 06")

numeros = []

for i in range(5):
    valor = float(input("Digite um numero: "))
    numeros.append(valor)

maior = numeros[0]

for numero in numeros:
    if numero > maior:
        maior = numero

print("Maior usando laco:", maior)
print("Maior usando max():", max(numeros))
```

### Valores utilizados no teste

```text
12, 45, 8, 32 e 19
```

### Resultado

```text
Maior usando laco: 45.0
Maior usando max(): 45.0
```

O maior valor foi encontrado de duas formas:

- comparando os números da lista por meio de um laço;
- utilizando a função pronta `max()`.

As duas formas apresentaram o mesmo resultado.

---

## Atividade 07 - Cálculo de fatorial

Nesta atividade, foi criada uma função para calcular o fatorial de um número.

```python
print("\nAtividade 07")

def fatorial(n):
    resultado = 1

    for i in range(1, n + 1):
        resultado *= i

    return resultado

print("0! =", fatorial(0))
print("5! =", fatorial(5))
print("20! =", fatorial(20))
```

### Resultados

```text
0! = 1
5! = 120
20! = 2432902008176640000
```

O fatorial de um número é calculado pela multiplicação dos números inteiros positivos até o próprio número.

Por definição, o fatorial de zero é igual a 1.

Python consegue trabalhar com números inteiros grandes. Por isso, o fatorial de 20 é calculado sem o estouro que poderia ocorrer com um inteiro de 32 bits na linguagem C.

---

## Atividade 08 - Manipulação de texto

A última atividade solicita uma frase, conta quantas vezes a letra `a` aparece e mostra o texto invertido.

```python
print("\nAtividade 08")

frase = input("Digite uma frase: ")

print("Quantidade de letras 'a':", frase.count("a"))
print("Frase invertida:", frase[::-1])
```

### Frase utilizada no teste

```text
A arara azul
```

### Resultado

```text
Quantidade de letras 'a': 4
Frase invertida: luza arara A
```

O método `count("a")` conta as ocorrências da letra minúscula `a`.

O comando `frase[::-1]` utiliza o fatiamento para percorrer a frase de trás para frente.

É importante observar que letras maiúsculas e minúsculas são consideradas diferentes. Por isso, o `A` maiúsculo do começo da frase não foi contado como um `a` minúsculo.

---

## Valores utilizados nos testes

| Atividade | Valores de teste |
|---|---|
| Atividade 03 | `10` e `3` |
| Atividade 04 | `-5` |
| Atividade 05 | `5` |
| Atividade 06 | `12`, `45`, `8`, `32` e `19` |
| Atividade 08 | `A arara azul` |

---

## Minha experiência com a atividade

Esta atividade fez parte do meu processo de transição da linguagem C para Python.

No começo, tive algumas dificuldades por estar aprendendo uma linguagem nova e por já estar acostumada com a estrutura da linguagem C. Apesar disso, percebi que Python possui uma sintaxe mais simples, direta e fácil de ler.

Algumas tarefas que precisariam de mais detalhes em C puderam ser realizadas com menos linhas em Python. Um exemplo foi a atividade do fatorial, pois Python consegue armazenar números inteiros grandes sem o mesmo limite de um `int` de 32 bits em C.

Eu já havia tido um contato anterior com Python na Caesb, quando tentei utilizar a linguagem para facilitar uma tarefa do meu trabalho realizada no Excel. Essa experiência mostrou que a programação pode ajudar na automatização de tarefas repetitivas e na organização de informações.

Com esta lista de exercícios, consegui praticar os fundamentos da linguagem e compreender melhor o uso de variáveis, condições, repetições, listas, funções e textos.

---

## Principais aprendizados

Com a realização das atividades, aprendi a:

- diferenciar divisão comum, divisão inteira e resto;
- identificar os tipos dos valores;
- receber dados digitados pelo usuário;
- converter textos para números;
- criar decisões com estruturas condicionais;
- repetir instruções com `while` e `for`;
- armazenar números em listas;
- comparar valores de uma lista;
- utilizar funções prontas do Python;
- criar uma função própria;
- calcular o fatorial de um número;
- contar caracteres em uma frase;
- inverter um texto.

---

## Conclusão

As oito atividades ajudaram a reforçar conceitos fundamentais de programação por meio de exemplos simples e práticos.

A transição de C para Python apresentou dificuldades iniciais, mas a sintaxe mais simples de Python facilitou a compreensão dos exercícios. As atividades também mostraram que existem diferentes formas de resolver um mesmo problema, como na contagem regressiva e na busca pelo maior valor de uma lista.

Além do aprendizado acadêmico, os conteúdos podem ser aplicados em situações reais, como a automatização e a organização de tarefas realizadas no Excel.
