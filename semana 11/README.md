# Semana 11 — Análise de dados com Python e Pandas

## Introdução

Nesta atividade, realizei uma análise inicial das bases de dados de domicílios e moradores utilizando a linguagem Python e a biblioteca Pandas.

O objetivo foi conhecer a estrutura das bases, identificar os tipos das variáveis, consultar o dicionário de dados e observar possíveis valores estranhos por meio de uma análise descritiva.

## Importação da biblioteca

Inicialmente, importei a biblioteca Pandas:

```python
import pandas as pd
```

O Pandas foi utilizado para abrir os arquivos, consultar as informações das bases e realizar a análise dos dados.

---

## 1a. Quantidade de moradores e colunas

Para verificar a quantidade de linhas e colunas existentes nas bases, utilizei o atributo `shape`:

```python
print("Dimensões da base de moradores:", mor.shape)
print("Dimensões da base de domicílios:", dom.shape)
```

O primeiro número apresentado pelo `shape` corresponde à quantidade de linhas e o segundo corresponde à quantidade de colunas.

Na amostra analisada, a base `mor` apresentou 100 moradores. A quantidade de colunas pode ser consultada diretamente no resultado de `mor.shape`.

A mesma verificação foi realizada na base `dom`, que contém as informações relacionadas aos domicílios.

---

## 1b. Tipos das colunas

Para conhecer a estrutura das duas bases, utilizei o método `info()`:

```python
mor.info()
dom.info()
```

Esse método apresenta informações como:

- quantidade de linhas;
- nomes das colunas;
- quantidade de valores não nulos;
- tipos das variáveis;
- uso de memória da base.

Os principais tipos encontrados foram:

- `int64`: valores numéricos inteiros;
- `float64`: valores numéricos que podem possuir casas decimais;
- `object`: informações armazenadas como texto.

Essa etapa foi importante para entender como cada informação estava armazenada antes de iniciar a análise.

---

## 1c. Consulta ao dicionário de variáveis

Para entender o significado das variáveis, consultei o arquivo com o dicionário de dados.

Primeiro, verifiquei as planilhas existentes no arquivo:

```python
arquivo = pd.ExcelFile(
    PASTA + "dicionario_de_variaveis_pdada_2024_público.xlsx"
)

print(arquivo.sheet_names)
```

Foram encontradas planilhas relacionadas aos domicílios, moradores e anexos.

Depois, consultei o dicionário correspondente à base de moradores para localizar as variáveis solicitadas.

### Significado das variáveis

- `localidade`: Região Administrativa do Distrito Federal ou município da amostra;
- `idade_calculada`: idade calculada do morador;
- `id_genero`: composição entre as respostas de sexo de nascimento e identidade de gênero;
- `renda_ind`: soma dos rendimentos individuais;
- `peso_mor`: peso amostral do morador.

### Códigos da variável `id_genero`

Os códigos encontrados no dicionário foram:

- `1`: Cisgênero;
- `2`: Transgênero;
- `3`: Outro;
- `99999`: Não se aplica ou sem classificação.

No dicionário, algumas linhas apareceram com valores `NaN` na coluna que contém o nome da variável. Isso acontece porque essas linhas são a continuação das categorias da variável apresentada anteriormente.

Por exemplo, as linhas com os códigos `2`, `3` e `99999` continuam pertencendo à variável `id_genero`, mesmo que o nome dela não seja repetido em todas as linhas.

---

## 1d. Análise descritiva

Para observar o resumo estatístico das variáveis numéricas, utilizei o método `describe()`:

```python
mor.describe()
```

O resultado apresentou oito medidas estatísticas:

- `count`: quantidade de valores preenchidos;
- `mean`: média;
- `std`: desvio padrão;
- `min`: menor valor;
- `25%`: primeiro quartil;
- `50%`: mediana;
- `75%`: terceiro quartil;
- `max`: maior valor.

Como a base possui muitas colunas, também é possível transpor o resultado para facilitar a leitura:

```python
mor.describe().T
```

O `.T` troca as linhas pelas colunas, permitindo visualizar as estatísticas de cada variável de maneira mais organizada.

### Valores observados

Na amostra analisada, a variável `idade_calculada` apresentou:

- valor mínimo igual a 0;
- média igual a 31,67;
- mediana igual a 33;
- valor máximo igual a 84.

Esses valores parecem possíveis. O valor 0 pode representar moradores com menos de um ano de idade.

Também foram encontrados valores como `99999` em algumas variáveis, incluindo `E02_3` e `E03`.

O número `99999` não deve ser interpretado automaticamente como um valor numérico real. Conforme observado no dicionário, ele pode representar um código especial, como uma situação em que determinada pergunta não se aplica ou não possui classificação.

Por esse motivo, é importante consultar o dicionário antes de calcular médias ou obter conclusões a partir dessas variáveis.

O resultado apresentado pelo `describe()` possuía 8 linhas e 126 colunas. As 8 linhas correspondem às medidas estatísticas, enquanto as 126 colunas correspondem às variáveis numéricas analisadas.

---

## Minha experiência com a atividade

No começo, tive algumas dificuldades porque estou fazendo a transição da linguagem C para Python.

Como eu já estava mais acostumada com a estrutura da linguagem C, precisei me adaptar à forma de escrever os comandos em Python e ao uso de bibliotecas como o Pandas.

Apesar das dificuldades iniciais, percebi que Python possui uma sintaxe mais simples e direta. Em muitas situações, é possível realizar uma análise utilizando poucas linhas de código.

Eu já havia tido um contato anterior com Python na Caesb. Na ocasião, tentei utilizar a programação para facilitar uma tarefa do meu trabalho que era realizada no Excel.

Essa experiência mostrou que Python pode ser utilizado para automatizar tarefas repetitivas, organizar informações e tornar algumas atividades realizadas no Excel mais práticas.

Nesta atividade, consegui compreender melhor como utilizar Python e Pandas para:

- abrir bases de dados;
- verificar a quantidade de linhas e colunas;
- identificar os tipos das variáveis;
- consultar um dicionário de dados;
- gerar resumos estatísticos;
- identificar códigos especiais;
- analisar informações de forma mais organizada.

---

## Principais comandos utilizados

```python
import pandas as pd

# Verifica a quantidade de linhas e colunas
mor.shape
dom.shape

# Exibe informações sobre as bases
mor.info()
dom.info()

# Mostra as planilhas do dicionário
arquivo = pd.ExcelFile(
    PASTA + "dicionario_de_variaveis_pdada_2024_público.xlsx"
)

print(arquivo.sheet_names)

# Gera o resumo estatístico
mor.describe()

# Transpõe o resumo para facilitar a leitura
mor.describe().T
```

---

## Conclusão

A atividade permitiu conhecer melhor a estrutura das bases de moradores e domicílios e entender a importância do dicionário de variáveis durante uma análise de dados.

Também foi possível perceber que alguns números presentes na base, como `99999`, podem ser códigos especiais e não valores reais. Por isso, a consulta ao dicionário é necessária antes de interpretar os resultados.

Mesmo com as dificuldades iniciais causadas pela transição de C para Python, a atividade mostrou que Python possui uma escrita mais simples para análise de dados. O uso da biblioteca Pandas facilitou a visualização, a organização e a interpretação das informações.

Além do aprendizado acadêmico, essa experiência também se relaciona com uma necessidade que já encontrei no trabalho na Caesb: utilizar a programação para facilitar tarefas realizadas no Excel.
