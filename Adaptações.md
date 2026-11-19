# adaptações que fiz no código

## pokemon
Apenas algumas alterações na sintaxe para atribuir um atributo a um pokemon pois usamos notações diferentes para isso, mas acredito que não faça diferença.

## Pokelist
 Peguei a implementação que tinha feito antes que já era direto como vetor, alterando os nomes das funções para ingles, para deixar mais de acordo com o resto do código.
 Mantive a função de somar poder que já tinha no meu código anterior, só por manter mesmo, talvez retiraremos ela depois.
A implementação ficou bem diferente pelo fato de não ser mais uma lista encadeada.

## Pokecenter

Criei a estrutura SortingMetric para podemor comparar o numero de comparações e movimentações dos métodos.

Criei a estrutura de pokecenter para deixar mais fácil de eu conseguir trabalhar com os algoritmos de ordenação, e dividir melhor as tarefas dos tads Pokelist e Pokecenter.
Agora ao invés do pokecenter ser apenas um tad algoritmico, ele que recebe e cuida dos pokemons do arquivo e define as funções de ordenação, além de imprimir as métricas calculadas em arquivo txt e no terminal.

A implementação do quicksort foi completamente baseada na implementação feita pela taís nos slides e peguei apenas um elementoo do quicksort apresentado no livro "Algorithms in C", mais especificamente o uso da função "comesBefore".
O insertion foi baseado na lógica apresentada nos slides da taís e também no insertion do apresentado no livro "Introduction to Algorithms".


## Main

Quase nenhuma mudança, apenas adaptado para as novas funções de ordenação.

