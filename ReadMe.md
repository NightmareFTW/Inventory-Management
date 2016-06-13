# Trabalho Prático

## 1. Objetivo

Pretendese implementar um sistema minimalista de gestão de inventário, na empresa virtual XYZ.
A empresa usa o sistema FIFO, em que os produtos mais antigos são os que devem ser consumidos 
primeiro.

## 2. Problema

A gestão de produtos que existem em stock numa empresa é um problema complexo. Os produtos devem entrar e sair seguindo uma ordem preestabelecida, por exemplo FIFO – First In / First Out.  
No modelo FIFO, os produtos mais antigos devem ser os primeiros a ser consumidos. A empresa XYZ agrupa os produtos por lote. A gestão informatizada de inventário deve permitir, pelo menos, saber que produtos existem em stock, e quando foi adquirido ou consumido cada lote. Os lotes mais antigos devem ser os consumidos.

## 3. Caraterísticas da aplicação

1. A informação deve ser guardada em ficheiros:  
    1. Ficheiro de Produtos. Cada produto tem, pelo menos, o nome, descrição, referência interna e estado (válido/inválido).  
    2. Ficheiro de existências. Neste ficheiro deve ficar guardado, para cada produto, a quantidade por cada lote e a data de aquisição.  
    3. Movimentos. No ficheiro de movimentos deve ficar registado (log) cada movimento de entrada ou saída.  
2. O programa deve permitir:
    1. Ver produtos em stock, com informação das quantidades disponíveis por lote.  
    2. Acrescentar produtos novos.  
    3. Alterar dados de um produto existente.  
    4. Registar entrada de produtos em armazém (acrescentando no ficheiro de existências e registando no ficheiro de movimentos).  
    5. Registar saída de produtos (retirando do ficheiro de existências a quantidade consumida por cada lote e registando no ficheiro de
movimentos).
    6. Verificar os movimentos de entradas e saídas de um produto.  
    7. Ajuda – informação sobre como usar a aplicação. 
    
O programa a desenvolver deve ainda:  
1. Para maior rapidez de execução, as operações devem ser realizadas de preferência em listas ligadas na memória. O programa deve carregar a informação para as listas quando é lançado e atualizar os ficheiros sempre que se justifique.  
2. Para grupos com 2 alunos:  
    1. O programa deve ter ainda a “autenticação” de utilizadores. Para cada movimento registado no ficheiro de movimentos, deve ser guardada a informação do utilizador que realizou a operação.

### Implementação
- A implementação deve ser feita em ANSI C, em modo de texto.
- Podem ser utilizadas as funções getch(), get_random() e read_str() disponíveis no elearning, para melhorar a usabilidade do programa.
- Procure que o programa seja completo e fácil de usar.

**Regras importantes**
- O trabalho deve ser acompanhado de um relatório explicativo de, no máximo, 10 páginas, segundo o modelo fornecido. Esse relatório deve incidir obrigatoriamente sobre os algoritmos principais, explicando-os com recurso a fluxogramas ou pseudocódigo. Deve explicar o funcionamento do programa na perspetiva do utilizador e do programador.
- O relatório deverá seguir o modelo disponibilizado.
- O código do trabalho e o relatório devem ser submetidos no elearning, em ficheiro  compactado com zip, gzip ou bzip2, num só ficheiro.
- O prazo de entrega é definido no elearning. 

Trabalhos entregues depois desta data não serão considerados.  
- O trabalho deverá estar sujeito a uma apresentação, em data a ser marcada. Esta apresentação deve incluir uma explicação do trabalho e uma demonstração de funcionalidades. Em anexo é disponibilizado um modelo de diapositivos a usar na apresentação.
- Trabalhos copiados totalmente, ou parcialmente sem citação dos respetivos autores, ou que o aluno não saiba explicar convenientemente na apresentação, serão anulados.
