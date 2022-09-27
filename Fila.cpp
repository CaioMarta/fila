// Estrutura heterogênea - Criando novo tipo de dado chamado "Fila"
struct Fila
{
	   int elementos[10];
	   int comeco;
	   int final;
};

// Protótipos das funções
void iniciarFila(struct Fila *F);

void inserirFila(struct Fila *F, int num);

void removerFila(struct Fila *F);

void mostrar(struct Fila F);

void visualizar1(struct Fila F);


#include <stdio.h>
#define tam 10

int main()
{
   struct Fila F;
   int op, num;
   
// Menu em loop
	do
	{
		printf("\n Opcoes para usar o menu: ");
		printf("\n 1 - Iniciar nova fila ");
		printf("\n 2 - Adicionar novo elemento ");
		printf("\n 3 - Retirar um elemento ");
		printf("\n 4 - Monstar fila ");
		printf("\n 5 - Visualizar primeiro elemento");
		printf("\n 6 - Visualizar ultimo elemento");
        printf("\n 7 - Sair do menu");
		printf("\n Digite sua escolha: ");
		scanf("%d", &op);
		
		
       switch(op)
		{
		case 1:
			iniciarFila(&F);
			break;
		
		case 2:
			//adicionar
			if(F.final==9)
			{
				printf("Fila cheia");
			}
			else 
			{
				printf("Digite um numero inteiro a ser adicionado na fila");
				scanf("%d", &num);
				inserirFila(&F, num);
			}
			
			break;
		
        case 3:
        	//retirar
			if(F.final <F.comeco)
			{
				printf("Fila vazia");
			}
			else
			{
				removerFila(&F);
			}
   	   	   	   break;
		
		case 4:
			//monstrar fila
			mostrar(F);
			break;
		case 5:
			visualizar1(F);
		default:
			break;
		}
	}while(op!=6); // Encerra o loop
	
	return 0;
}



// Métodos 
void iniciarFila(struct Fila *F)
{
	F->comeco = 0;
	F->final = -1; 
}

void  inserirFila (struct Fila *F, int num)
{
	F->final++;
	F->elementos[F->final] = num;
} 

void  removerFila (struct Fila *F)
{
	F->comeco++;
}

void mostrar(struct Fila F)
{
	int i;
	for(i=F.comeco; i<=F.final;i++)
	{
		printf("%d",F.elementos[i]);
	}
}

void visualizar1(struct Fila F)
{
  printf("primeiro elemento da fila = %d",F.elementos[F.comeco]);
}