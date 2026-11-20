Ontem o programa estava com problemas em ler arquivos, fazer clean, não tinha como passar nome de arquivo como argumento para testarmos ele.

## Problemas Resolvidos


| #   | Problema                                                    | Correção                                                                                                                                                                                                                                                    |
| --- | ----------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1   | Caminho fixo errado (`"../build/teste.txt"`)                | `readPokelist` recebe `nome_arquivo` e tenta abrir direto, em `build/` ou em `../build/`.                                                                                                                                                                   |
| 2   | `fscanf` lendo 5 campos quando o arquivo só tem 4           | correção: `fscanf` passou a ler 4 campos (`pokedex`, `nome`, `tipo`, `power`) e o campo `energy` foi removido pois não existe nas entradas teste.                                                                                                           |
| 3   | Acesso a lixo de memória (`i < totalPoke`)                  | os laços de impressão em `functionCall1` e `functionCall2` agora usam `pc.recuperados.quantidade`.                                                                                                                                                          |
| 4   | Loop infinito sem saída e falha com entrada não numérica    | adicionada opção `0. Sair` e parada em `EOF`;                                                                                                                                                                                                               |
| 5   | Comandos quebrados no `Makefile` (`TARGET`, `fel /f`, `./`) | `Makefile` agora detecta Windows e Linux automaticamente e escrevi as instruções de uso no topo como pedem na especificação.                                                                                                                                |
| 6   | Tempo medido no lugar errado e formato `%f`                 | a medição saiu do `main.c` e foi para dentro de `simpleSort` e `complexSort`, usando `timespec_get` (precisão de nanossegundos) em vez de `clock()`, com exibição em `%.7f`.<br>No ultimo tp também usei timespec, só adaptei do meu outro código pra esse. |
| 7   | Arquivo de saída ordenado nunca era gerado                  | correção:`functionCall1` gera `saida_simples.txt` e `functionCall2` gera `saida_sofisticada.txt`. A função `printRecoveredPokemons` não era chamada antes.                                                                                                  |
| 8   | Arquivo de entrada fixo no código                           | agora o programa aceita qualquer arquivo via argumento na linha de comando (`argv[1]`), usando `"build/teste.txt"` como padrão. Adaptei da forma de como os mains dos meus tps anteriores liam os arquivos.                                                 |



## Coisas que ainda precisam ser feitas

Se `readPokelist` não conseguir abrir ou ler 0 pokemons (`teste_null.txt`), `functionCall1`/`functionCall2` mesmo assim o programa gera os arquivos `saida_simples.txt` / `saida_sofisticada.txt` e gravam `0` comparações e `0` movimentações em `metricas_ordenacao.txt`

O programa está imprimindo todos os pokemons ordenados no terminal, percebi que no enunciado, só as métricas devem aparecer no terminal.

Melhorar o comando clean no makefile, pois ele não limpa os arquivos txt gerados no camndo clean.

