/*   =====       BIBLIOTECAS        =====     */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


/*   =====       DESCRIÇÃO DAS FUNÇÕES        =====     */

void lobby(void);
void sobrePiratas(void);
void escolherPirata(int *pont1, int *pont2);
int valorAtributo (int n1);
void imprimirRegistros(struct Pirata pirata1, struct Pirata pirata2);


/*   =====       MAIN       =====     */

struct Pirata
{
  char nome[20];
  int atributos;
};

int main () {
  srand(time(NULL));

  lobby();
  sobrePiratas();

  int n1,n2;
  int* p1 = &n1;
  int* p2 = &n2;

  escolherPirata(p1,p2);

  struct Pirata pirata1;
  struct Pirata pirata2;

  printf("\nDigite o nome do pirata 1: ");
  scanf("%s",&pirata1.nome);  
  printf("Digite o nome do pirata 2: ");
  scanf("%s",&pirata2.nome);  

  pirata1.atributos = valorAtributo(n1);
  pirata2.atributos = valorAtributo(n2);

  if (pirata1.atributos > pirata2.atributos)
  {
    printf("\nO(A) pirata %s foi o(a) vencedor(a)! Ele(a) possui um poder de %d! Que incrivel!",pirata1.nome,pirata1.atributos);
  } else if (pirata2.atributos > pirata1.atributos)
  {
    printf("\nO(A) pirata %s foi o(a) vencedor(a)! Ele(a) possui um poder de %d! Que incrivel!",pirata2.nome,pirata2.atributos);
  } else {
    printf("\nOs dois piratas: %s e %s sao incrivelmente fortes! A luta deu empate! Ambos tem poder %d!",pirata1.nome,pirata2.nome,pirata1.atributos);
  }
   
 // imprimirRegistros(pirata1,pirata2);
  return 0;
}

/*   =====       FUNÇÕES        =====     */

// Essa função foi criada apenas para introduzir o usuário ao jogo.
void lobby(void) {
  printf("\n|  BEM VINDO AO DUELO DE PIRATAS  |\n");
  printf("|  .............................  |\n");
  printf("|                                 |\n");
  printf("|  Nos, da Going Merry Company,   |\n");
  printf("|  esperamos que sua experiencia  |\n");
  printf("|  com nosso programa seja unica  |\n");
  printf("|  e inesquecivel, aproveite, se  |\n");
  printf("|  prepare bastante, boa sorte!   |\n\n");
}


// Função para descrever os piratas.
void sobrePiratas(void) {
  printf("\n----- ESCOLHA CARACTERISTICAS PARA OS PIRATAS DO DUELO, BASEADO EM INSPIRACOES DO MUNDO PIRATA -----\n\n");
  printf("(1) Luffy:\n\tEle sera o rei dos piratas, e, para isso, ele deve ser muito forte e resistente!\n\n");
  printf("(2) Zoro:\n\tEle sera o melhor espadachim do mundo, Zoro deve ser muito forte!\n\n");
  printf("(3) Sanji:\n\tPor ser um cozinheiro renomado e nao lutar com as maos, se destaca com seus chutes e sua rapidez!\n\n");
  printf("(4) Usopp:\n\tPode nao ser o mais corajoso, mas certamente tem seu valor com uma mira impecavel!\n\n");
  printf("(5) Nami:\n\tA gatuna se destaca por sua habilidade de navegacao e persuasao!\n\n");
  printf("(6) Robin:\n\tA filha de Ohara e a unica capaz de ler os Poneglyphs que levam ate o maior tesouro do mundo!\n\n");
  printf("(7) Franky:\n\tO ciborgue e o maior construtor naval do mundo, alem de possuir uma armadura incrivel!\n\n");
  printf("(8) Chopper:\n\tUma rena falante que parece um guaxinim, muito FOFO e o melhor medico do mundo\n\n");
  printf("(9) Brook:\n\tApesar de ser 'puro osso', Brook nao hesita ao enfrentar novos oponentes e da o seu maximo com o poder da musica YOHOHO!\n\n");
  printf("(10) Jinbe:\n\tO cavaleiro dos mares e um homem-peixe e ja foi um dos piratas mais renomados do mundo, se destaca por sua resistencia dentro e fora d'agua!\n\n");
  printf("(11) Yamato:\n\tFilha da criatura mais forte do universo, o imperador Kaido!\n\n");
  printf("(12) Vivi e Carue:\n\tEssa dupla de princesa e e Pato corredor desbravam os desertos de Alabasta na velocidade da luz!\n\n");

}


// Função para escolher os piratas envolvidos na luta.
void escolherPirata(int *pont1, int *pont2) {
  printf("Inspiracao para o pirata 1 (1 - 12): ");
  scanf("%d",&(*pont1));
  printf("Inspiracao para o pirata 2 (1 - 12): ");
  scanf("%d",&(*pont2));
}


// Função para definir os atributos aleatórios de cada personagem baseado em suas características.
int valorAtributo (int n1) {
  int vida = (rand() % 10) + 1;
  int inteligencia = (rand() % 10) + 1;
  int forca = (rand() % 10) + 1;
  int agilidade = (rand() % 10) + 1;
  int coragem = (rand() % 10) + 1;
  
  switch (n1)
  {
  case 1:
    vida *= 2;
    forca *= 2;
    break;
  case 2:
    forca *= 4;
    break;
  case 3:
    forca *= 2;
    agilidade *= 2;
    break;
  case 4:
    coragem = 0;
    forca += 5;
    vida += 5;
    inteligencia += 5;
    agilidade += 5;
    break;
  case 5:
    agilidade *= 2;
    inteligencia *= 2;
    break;
  case 6:
    inteligencia *= 4;
    break;
  case 7:
    vida *= 2;
    inteligencia *= 2;
    break;
  case 8:
    vida += 3;
    inteligencia += 3;
    forca += 3;
    agilidade += 3;
    coragem += 3;
    break;
  case 9:
    coragem *= 3;
    break;
  case 10:
    vida *= 4;
    break;
  case 11:
    forca *= 4;
    break;
  case 12:
    agilidade *= 4;
    break;
  default:
    break;
  }

  return vida + inteligencia + forca + agilidade + coragem;
}


// Função para imprimir registros.
void imprimirRegistros(struct Pirata pirata1, struct Pirata pirata2) {
  printf("\n%s , poder: %d",pirata1.nome,pirata1.atributos);
  printf("\n%s , poder: %d",pirata2.nome,pirata2.atributos);
}
