# introducao-memoria-compartilhada
Resolução de exercicíos relacionados a *compartilhamento de memória em C 

A) Altere o programa apresentado no exemplo 1 (seção 2.2) de forma que sejam criados três programas distintos e não processos pai e filhos.

O primeiro programa deve criar a área de memória (soma), esperar os outros dois realizarem as suas ações (invente uma forma de fazer isso) e, apenas depois disso, deve imprimir o valor final, apagar a área de memória compartilhada e encerrar a sua execução.
Determine a forma como os demais processos avisarão ao primeiro que finalizaram as suas ações.
B)Faça dois programas que se comunicam usando memória compartilhada que realizam as seguintes ações:

leitor2.c: cria a área de memória compartilhada (buffer) para 5 valores inteiros e salva 5 números na mesma, digitados pelo usuário.
Ao criar a área de memória deve ser feita a verificação de que ela está livre (se não tem outra com a mesma chave).
escritor2.c: se liga à área de memória criada pelo escritor e imprime os 5 números guardados. Cada posição do buffer só é impressa quando possuir um valor diferente de zero. Após imprimir todos os números apaga a área criada.
O buffer deverá ter 20 bytes (4 bytes para cada número inteiro).
