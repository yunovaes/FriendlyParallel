                        #Paralelização do problema Mutually Friendly Numbers
###Descrição do Problema - Algoritmo 

Este problema consiste em, dados dois número inteiros e positivos, faz-se a seguinte conta para cada um deles: soma-se todos os seu divisores, e depois divide-se o resultado desta soma pelo próprio número. Em outras palavras, para cada número haverá uma divisão, na qual o numerador será a soma de todos os seus divisores, e o denominador será o próprio número em questão. Caso o resultado dessa conta seja o mesmo para ambos os números fornecidos, eles são mutually friendly. 
O problema apresentado na maratona consiste em encontrar todos os pares de números mutually friendly dentro de um intervalo, múltiplas vezes. Assim, a entrada consiste de vários pares de números que formam um intervalo, até que seja encontrado o par (0, 0). 

###Solução sequencial

O código sequencial apresenta três funções: gcd, friendly_numbers e main. A main lê a entrada e chama a funções friendly_numbers com os valores recebidos, enquanto não encontrar o par (0, 0). A função gcd é uma função auxiliar para encontrar o Maior Divisor Comum (Greater Commom Divisor) de dois números, usado pela função friendly_numbers. Por fim, tem-se a função friendly_numbers, que recebe os parâmetros inicio e fim (do intervalo) e realiza todo o processo para a execução do algoritmo descrito, apresentando a mensagem esperada para a saída. Para isso, três vetores são usados, representando os números do intervalo, os numeradores de cada divisão e os denominadores de cada divisão. Após armazenar todos os dados necessário, percorre-se o intervalo encontrando todos os pares muttually friendly e imprimindo a mensagem de saída. A complexidade do algoritmo é O(n^2). 

###Solução paralela

Durante a busca da solução paralela fizemos a inspeção do código com o uso da biblioteca time.h para medir, a partir do tempo total de execução, a percentagem de tempo levada por cada trecho do código. Mais especificamente, procuramos medir quanto tempo cada estrutura de repetição (instrução for) presente no código levava para ser executada. A partir disso foi possível descobrir qual a parte do código é a mais significativa em relação ao tempo para ser paralelizada. 
