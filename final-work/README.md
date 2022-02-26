# LPG-TRABALHO-FINAL
C-based program, which is a final work of the Programming Language subject in UDESC

#### O objetivo do trabalho é desenvolver um programa que gerencie um cadastro simples de uma agenda de eventos. O programa deve alocar (e realocar) um vetor de estruturas cujo modelo é apresentado a seguir.

- Tipo Evento (estrutura contendo os campos a seguir):
  - data (estrutura Data, contendo dia, mes, ano);
  - horário início (estrutura Hora, contendo hora, minuto);
  - horário fim (estrutura Hora, contendo hora, minuto);
  - local (string);
  - descrição (string);

#### O programa deve carregar a agenda armazenados em arquivo binário e oferecer um menu de texto com as seguintes opções:
1. Cadastrar um novo evento na agenda;
	 - Deve fazer a realocação do vetor;
	 - Inserção deve ser feita de modo que os eventos estejam sempre em ordem (por data e horário de início);
2. Mostrar todos os eventos da agenda;
3. Dada uma data, mostrar todos os eventos dessa data;
4. A partir da data atual, mostrar os 5 (cinco) próximos eventos;
5. Remover evento: dadas uma data e hora inicial, remover o respectivo evento;
6. Sair do programa (salva agenda de eventos em arquivo para leitura posterior).


### Requisitos do programa
- Validação da entrada (data e hora com valores válidos);
- Cuidado com a interface de usuário: coloque mensagens apropriadas para situações excepcionais, tais como
	- erro na validação da entrada ou que o evento já existe (opção 1);
	- lista de eventos vazia (opções 2, 3, 4);
	- ou que o evento não foi encontrado (opção 5);
- Uso apropriado da realocação, para utilizar a memória de maneira otimizada;
- Não se esqueça de desalocar toda a estrutura ao final do programa!

##### Critérios de avaliação
- Execução correta e alinhamento com o que foi solicitado neste enunciado. 
