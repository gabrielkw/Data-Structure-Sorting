/*
 * Feito por Gabriel Kwiecinski Antunes e Guilherme Hermes
 * Estruturas de Dados I
 * Universidade Federal da Fronteira Sul
 * 2014/2
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _contato {
	char nome[40];
	char fone[30];
} TpContato;

typedef struct _nodo {
	TpContato *info;
	struct _nodo *next;
	struct _nodo *prev;
} TpNodo;

typedef struct _lista {
	int tamanho;
	TpNodo *first;
	TpNodo *last;
} TpLista;

char *to_string(int i) {
	char numstr[8];
	return itoa(i,numstr,10);
}

TpContato *alocaContato() {
	TpContato *novoContato = malloc(sizeof(TpContato));
	return novoContato;
}

TpNodo *alocaNodo(TpContato *pContato) {
	TpNodo *novoNodo = malloc(sizeof(TpNodo));
	novoNodo->info = pContato;
	novoNodo->next = NULL;
	novoNodo->prev = NULL;
	return novoNodo;
}

TpLista *alocaLista() {
	TpLista *novaLista = malloc(sizeof(TpLista));
	novaLista->tamanho = 0;
	novaLista->first = NULL;
	novaLista->last = NULL;
	return novaLista;
}

void copiaNodo(TpNodo *original, TpNodo *alvo) {
	alvo->next = original->next;
	alvo->prev = original->prev;
	alvo->info = original->info;
}

const char *nomes[] = {"Miguel","Davi","Arthur","Gabriel","Pedro","Lucas","Matheus","Bernardo","Rafael","Guilherme","Enzo","Felipe","Gustavo","Nicolas","Heitor","Samuel","Joao Pedro","Pedro Henrique","Caua","Henrique","Murilo","Eduardo","Vitor","Daniel","Lorenzo","Vinicius","Pietro","Joao Vitor","Leonardo","Theo","Caio","Isaac","Lucca","Joao","Davi Lucas","Enzo Gabriel","Yuri","Bryan","Thiago","Joao Gabriel","Benjamin","Joaquim","Emanuel","Thomas","Ryan","Carlos Eduardo","Rodrigo","Ian","Fernando","Bruno","Otavio","Francisco","Calebe","Igor","Antonio","Erick","Joao Lucas","Luiz Felipe","Andre","Davi Lucca","Kaique","Nathan","Luiz Miguel","Breno","Vitor Hugo","Joao Guilherme","Benicio","Augusto","Joao Miguel","Pedro Lucas","Levi","Anthony","Yago","Danilo","Juan","Kaue","Diego","Vicente","Davi Luiz","Luiz Gustavo","Alexandre","Raul","Luan","Diogo","Marcelo","Ricardo","Luiz Henrique","Henry","Noah","Enrico","Lucas Gabriel","Renan","Luiz Otavio","Pedro Miguel","William","Icaro","Giovanni","Joao Paulo","Paulo","Adryan","Sophia","Julia","Alice","Manuela","Isabella","Laura","Maria Eduarda","Giovanna","Valentina","Beatriz","Luiza","Helena","Maria Luiza","Isadora","Mariana","Gabriela","Ana Clara","Rafaela","Maria Clara","Isabelly","Yasmin","Ana Julia","Livia","Lara","Lorena","Heloisa","Melissa","Sarah","Ana Luiza","Leticia","Nicole","Ana Beatriz","Emanuelly","Esther","Lavinia","Marina","Cecilia","Rebeca","Vitoria","Maria Fernanda","Larissa","Clara","Carolina","Bianca","Alicia","Fernanda","Gabrielly","Catarina","Ana Laura","Emilly","Eduarda","Amanda","Pietra","Agatha","Milena","Maria Alice","Lais","Maria Julia","Maria","Elisa","Stella","Maria Vitoria","Bruna","Ana Sophia","Barbara","Maria Cecilia","Olivia","Nathalia","Camila","Ana Carolina","Maite","Eloa","Luana","Luna","Ana Livia","Brenda","Alana","Sophie","Ana","Isabel","Mirella","Juliana","Marcela","Isis","Iara","Antonia","Kamilly","Alexia","Lis","Maria Sophia","Joana","Clarice","Ayla","Caroline","Antonella","Evellyn","Malu","Maria Laura","Mikaela","Stefany"};

const char *sobrenomes[] = {"Abreu","Afonso","Aguiar","Almeida","Alonso","Alvarenga","Amaral","Andrade","Antunes","Araujo","Avila","Azevedo","Barbosa","Barboza","Barros","Bastos","Borges","Braga","Brandao","Brito","Bueno","Camargo","Campos","Cardoso","Carneiro","Carvalho","Castro","Chaves","Clemente","Coelho","Cordeiro","Correa","Correia","Costa","Coutinho","Cohen","Cruz","Cunha","David","Paula","Dias","Diniz","Domingues","Dourado","Duarte","Esteves","Falcao","Faria","Farias","Fernades","Ferreira","Figueira","Flores","Fonseca","Franco","Freire","Freitas","Furtado","Gabriel","Galvao","Gama","Garcia","Gomes","Goncalves","Guedes","Guerra","Henrique","Henriques","Jacinto","Jorge","Lara","Leal","Leao","Lemos","Lima","Lobo","Lopes","Lourenco","Lucena","Macedo","Machado","Maia","Marcos","Maria","Marques","Martinez","Martins","Matos","Mattos","Mello","Melo","Mendes","Mendonca","Meneses","Menezes","Mercado","Mesquita","Miguel","Miranda","Monteiro","Moraes","Morais","Moreira","Moreno","Mota","Motta","Moura","Muller","Munhoz","Muniz","Navarro","Netto","Neves","Nogueira","Nunes","Oliveira","Oliveiro","Olivero","Pacheco","Paes","Paiva","Paz","Peixoto","Penha","Pereira","Peres","Perez","Pessoa","Pimenta","Pimentel","Pinheiro","Pinto","Pires","Porto","Prado","Rabelo","Ramalho","Ramos","Rangel","Rego","Reis","Resende","Ribas","Ribeiro","Ricardo","Rios","Rodrigues","Romero","Rosa","Ruiz","Sa","Salgado","Salvador","Sampaio","Sanches","Santiago","Santo","Santos","Saraiva","Serra","Silva","Silveira","Simao","Simoes","Siqueira","Soares","Sobrinho","Sousa","Souza","Tavares","Teixeira","Teles","Toledo","Torres","Trindade","Vale","Valle","Vargas","Vaz","Veiga","Ventura","Vicente","Vidal","Vieira"};

char *criaNomeAleatorio() {
	char novoNome[40];
	int i;
	strcpy(novoNome,nomes[rand()%200]);
	for(i = 0; i <= rand()%2; i++) {
		strcat(novoNome," ");
		strcat(novoNome,sobrenomes[rand()%184]);
	}
	return novoNome;
}

char *criaFoneAleatorio() {
	char numero[8];
	int base;
	int distancia;
	if(rand()%2) {
		base = 8400;
		distancia = 1600;
	} else {
		base = 3300;
		distancia = 100;
	}
	strcpy(numero,to_string((rand()%distancia)+base));
	strcat(numero,to_string(rand()%9999));
	return numero;
}

TpContato *criaContatoAleatorio() {
	TpContato *novoContato = alocaContato();
	strcpy(novoContato->nome,criaNomeAleatorio());
	strcpy(novoContato->fone,criaFoneAleatorio());
	return novoContato;
}

void insereNaLista(TpLista *pLista, TpNodo *nodo) {
	if(!pLista || !nodo) {
		return;
	}
	if(!pLista->first) {
		pLista->first = nodo;
		pLista->last = nodo;
	}
	else {
		pLista->last->next = nodo;
		nodo->prev = pLista->last;
		pLista->last = nodo;
	}
	pLista->tamanho++;
}

void imprimeLista(TpLista *pLista) {
	TpNodo *pNodo;
	printf("\n--------------------\n");
	for(pNodo = pLista->first; pNodo != NULL; pNodo = pNodo->next) {
		printf("Nome: %s\n", pNodo->info->nome);
		printf("Fone: %s\n", pNodo->info->fone);
		printf("--------------------\n");
	}
}

void imprimeVetor(TpContato vetor[], int tamanho) {
	int i;
	printf("\n--------------------\n");
	for(i = 0; i < tamanho; i++) {
		printf("Nome: %s\n",vetor[i].nome);
		printf("Telefone: %s\n",vetor[i].fone);
		printf("--------------------\n");
	}
}

int comparar(TpContato contato1, TpContato contato2) {
	return strcmp(contato1.nome,contato2.nome);
}

int compararPonteiro(TpContato *contato1, TpContato *contato2) {
	if(contato1 == NULL) {
		return 0;
	}
	if(contato2 == NULL) {
		return 0;
	}
	return strcmp(contato1->nome,contato2->nome);
}

TpContato *copiarVetor(TpContato vetor[], int tamanho) {
	int i;
	TpContato *novoVetor;
	novoVetor = malloc(tamanho*sizeof(TpContato));
	for(i = 0; i < tamanho; i++) {
		novoVetor[i] = vetor[i];
	}

	return novoVetor;
}

TpContato *copiaContato(TpContato *c) {
	TpContato *novoContato = alocaContato();
	strcpy(novoContato->nome,c->nome);
	strcpy(novoContato->fone,c->fone);
	return novoContato;
}

TpLista *copiaLista(TpLista *alista) {
	TpNodo *aux, *nnodo, *aux1;
	TpLista *novaLista = alocaLista();
	for (aux = alista->first; aux != NULL; aux = aux->next) {
		if(aux == alista->first) {
			nnodo = alocaNodo(copiaContato(aux->info));
			novaLista->first = nnodo;
			nnodo->prev = NULL;
			nnodo->next = NULL;
			novaLista->tamanho = novaLista->tamanho++;
		}
		else {
			aux1 = nnodo;
			nnodo = alocaNodo(copiaContato(aux->info));
			aux1->next = nnodo;
			nnodo->prev = aux1;
			nnodo->next = NULL;
			novaLista->last = nnodo;
		}
	}
	return novaLista;
}

void freeLista(TpLista *lista) {
	TpNodo *pNodo, *aux;
	pNodo = lista->first;
	while(pNodo != NULL) {
		aux = pNodo->next;
		free(pNodo->info);
		free(pNodo);
		pNodo = aux;
	}
	free(lista);
}

void swapDados(TpNodo *nodo1, TpNodo *nodo2) {
	TpContato *aux = nodo1->info;
	nodo1->info = nodo2->info;
	nodo2->info = aux;
}

void swapVetor(TpContato vetor[], int a, int b) {
	TpContato aux;
	aux = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = aux;
}

TpContato *listaParaVetor(TpLista *lista) {
	TpContato *novoVetor;
	novoVetor = malloc(lista->tamanho*sizeof(TpContato));
	TpNodo *aux;
	int i = 0;
	for(aux = lista->first; aux != NULL; aux = aux->next) {
		novoVetor[i] = *aux->info;
		i++;
	}
	return novoVetor;
}

TpLista *vetorParaLista(TpContato vetor[], int tamanho) {
	TpLista *novaLista = alocaLista();
	TpNodo *novoNodo;
	int i;
	for(i = 0; i < tamanho; i++) {
		novoNodo = alocaNodo(copiaContato(&vetor[i]));
		insereNaLista(novaLista,novoNodo);
	}
	return novaLista;
}

/*
 * Funções de Ordenação a seguir
 * Ordem organizacional indicada:
 *
 * 1- cópia da lista/vetor
 * 2- início do timer
 * 3- declaração de variáveis
 * 4- ordenação da cópia da lista/vetor
 * 5- fim do timer
 * 6- impressão dos resultados
 * 7- limpeza de memória
 */

void insertionSortVetor(TpContato vetor[], int tamanho) {
	TpContato *novoVetor;

	clock_t start;
	clock_t end;
	start = clock();

	novoVetor = copiarVetor(vetor, tamanho);

	int i,j;
	TpContato chave;

	for(i = 1; i < tamanho; i++) {
		chave = novoVetor[i];
		j = i-1;
		while(j >= 0 && comparar(novoVetor[j],chave) > 0) {
			novoVetor[j+1] = novoVetor[j];
			j--;
		}
		novoVetor[j+1] = chave;
	}

	end = clock();

	imprimeVetor(novoVetor,tamanho);
	printf("%lf milissegundos.\n",(double)(end - start) / (CLOCKS_PER_SEC / 1000.0));
}

void insertionSortLista(TpLista *lista) {
	TpLista *novaLista;
	TpNodo *pNodo, *lastUnsorted;

	clock_t start;
	clock_t end;
	start = clock();

	novaLista = copiaLista(lista);

	pNodo = lastUnsorted = novaLista->first->next;
	while(lastUnsorted != NULL) {
		lastUnsorted = lastUnsorted->next;
		while(pNodo->prev != NULL && compararPonteiro(pNodo->info,pNodo->prev->info) < 0) {
			swapDados(pNodo,pNodo->prev);
			pNodo = pNodo->prev;
		}
		pNodo = lastUnsorted;
	}

	end = clock();

	imprimeLista(novaLista);
	printf("%lf milissegundos.\n",(double)(end - start) / (CLOCKS_PER_SEC / 1000.0));

	freeLista(novaLista);
}

void selectionSortVetor(TpContato vetor[], int tamanho) {
	TpContato *novoVetor;

	clock_t start;
	clock_t end;
	start = clock();

	novoVetor = copiarVetor(vetor,tamanho);

	TpContato smaller,aux;
	int i,j,position;

	for(i = 0; i < tamanho; i++) {
		smaller = novoVetor[i];
		position = i;
		for(j = i+1; j < tamanho; j++) {
			if(comparar(novoVetor[j],smaller) < 0) {
				smaller = novoVetor[j];
				position = j;
			}
		}
		aux = novoVetor[i];
		novoVetor[i] = smaller;
		novoVetor[position] = aux;
	}

	end = clock();

	imprimeVetor(novoVetor,tamanho);
	printf("%lf milissegundos.\n",(double)(end - start) / (CLOCKS_PER_SEC / 1000.0));
}

void selectionSortLista(TpLista *lista) {
	TpLista *novaLista;
	TpNodo *firstUnsorted, *pNodo, *smaller;

	clock_t start;
	clock_t end;
	start = clock();

	novaLista = copiaLista(lista);

	firstUnsorted = pNodo = smaller = novaLista->first;
	pNodo = pNodo->next;

	while(firstUnsorted !=novaLista->last) {
		while(pNodo != NULL) {
			if(compararPonteiro(pNodo->info,smaller->info) < 0) {
				smaller = pNodo;
			}
			pNodo = pNodo->next;
		}
		swapDados(smaller,firstUnsorted);
		firstUnsorted = pNodo = smaller = firstUnsorted->next;
	}

	end = clock();

	imprimeLista(novaLista);
	printf("%lf milissegundos.\n",(double)(end - start) / (CLOCKS_PER_SEC / 1000.0));

	freeLista(novaLista);
}

int partitionVetor(TpContato A[], int p, int q) {
	TpContato x = A[p];
	int i = p;
	int j;
	for(j=p+1; j<=q; j++) {
		if(comparar(A[j],x) <= 0) {
			i++;
			swapVetor(A,i,j);
		}
	}
	swapVetor(A,p,i);
	return i;
}

void quickSortVetor_processo(TpContato A[], int p, int q) {
	int r;
	if(p<q) {
		r = partitionVetor(A,p,q);
		quickSortVetor_processo(A,p,r-1);
		quickSortVetor_processo(A,r+1,q);
	}
}

void quickSortVetor(TpContato vetor[], int tamanho) {
	TpContato *novoVetor;

	clock_t start;
	clock_t end;
	start = clock();

	novoVetor = copiarVetor(vetor,tamanho);

	quickSortVetor_processo(novoVetor,0,tamanho-1);

	end = clock();

	imprimeVetor(novoVetor,tamanho);
	printf("%lf milissegundos.\n",(double)(end - start) / (CLOCKS_PER_SEC / 1000.0));
}

void quickSortLista(TpLista *lista) {
	TpLista *novaLista;
	TpContato *novoVetor;
	int tamanho;

	clock_t start;
	clock_t end;
	start = clock();

	novoVetor = listaParaVetor(lista);
	tamanho = lista->tamanho;

	quickSortVetor_processo(novoVetor,0,tamanho-1);
	novaLista = vetorParaLista(novoVetor,tamanho);

	end = clock();

	imprimeLista(novaLista);
	printf("%lf milissegundos.\n",(double)(end - start) / (CLOCKS_PER_SEC / 1000.0));

	freeLista(novaLista);
}

void mergeVetor(TpContato A[], int p, int q, int r) {
	int i,j,k;

	int n1 = q-p+1;
	int n2 = r-q;
	TpContato L[n1+1];
	TpContato R[n2+1];

	for(i=0; i<n1; i++) {
		L[i] = A[p+i];
	}
	for(j=0; j<n2; j++) {
		R[j] = A[q+1+j];
	}
	strcpy(L[n1].nome,"~");
	strcpy(R[n2].nome,"~");
	i = j = 0;
	for(k=p; k<=r; k++) {
		if(comparar(L[i],R[j]) <= 0) {
			A[k] = L[i];
			i++;
		} else {
			A[k] = R[j];
			j++;
		}
	}
}

void mergeSortVetor_processo(TpContato A[], int p, int r) {
	int q;
	if(p<r) {
		q = (p+r)/2;
		mergeSortVetor_processo(A,p,q);
		mergeSortVetor_processo(A,q+1,r);
		mergeVetor(A,p,q,r);
	}
}

void mergeSortVetor(TpContato vetor[], int tamanho) {
	TpContato *novoVetor;

	clock_t start;
	clock_t end;
	start = clock();

	novoVetor = copiarVetor(vetor,tamanho);

	mergeSortVetor_processo(novoVetor,0,tamanho-1);

	end = clock();

	imprimeVetor(novoVetor,tamanho);
	printf("%lf milissegundos.\n",(double)(end - start) / (CLOCKS_PER_SEC / 1000.0));
}

void mergeSortLista(TpLista *lista) {
	TpLista *novaLista;
	TpContato *novoVetor;
	int tamanho;

	clock_t start;
	clock_t end;
	start = clock();

	novoVetor = listaParaVetor(lista);
	tamanho = lista->tamanho;

	mergeSortVetor_processo(novoVetor,0,tamanho-1);
	novaLista = vetorParaLista(novoVetor,tamanho);

	end = clock();

	imprimeLista(novaLista);
	printf("%lf milissegundos.\n",(double)(end - start) / (CLOCKS_PER_SEC / 1000.0));

	freeLista(novaLista);
}

int main() {

	int option;
	int type;
	int i, tamanho;
	TpContato *arr = NULL;
	TpLista *lista = NULL;
	srand(time(NULL));

	while(1) {
		printf("\n1) Criar Lista\n2) Criar Vetor\n3) Insertion Sort\n4) Selection Sort\n5) Quick Sort\n6) Merge Sort\n7)Sair\nEscolha uma opcao:");
		scanf("%i",&option);

		switch(option) {
		case 1:
			printf("\nEscolha o tamanho da lista:");
			scanf("%i",&tamanho);
			if(tamanho > 0) {
				if(lista != NULL) {
					freeLista(lista);
				}
				lista = alocaLista();
				for(i = 0; i < tamanho; i++) {
					TpNodo *nodoParaInserir = alocaNodo(criaContatoAleatorio());
					insereNaLista(lista,nodoParaInserir);
				}
				imprimeLista(lista);
			} else {
				printf("\nERRO! Tamanho invalido.\n");
			}
			break;
		case 2:
			printf("\nEscolha o tamanho do vetor:");
			scanf("%i",&tamanho);
			if(tamanho > 0) {
				arr = malloc(tamanho*sizeof(TpContato));
				for(i = 0; i < tamanho; i++) {
					arr[i] = *criaContatoAleatorio();
				}
				imprimeVetor(arr,tamanho);
			} else {
				printf("\nERRO! Tamanho invalido.\n");
			}
			break;
		case 3:
			printf("\n1) Lista \n2) Vetor\nEscolha um alvo:");
			scanf("%d", &type);
			switch(type) {
			case 1:
				if(lista == NULL) {
					printf("\nERRO! Nenhuma lista criada.\n");
				} else {
					printf("\nProcessando...\n");
					insertionSortLista(lista);
				}
				break;
			case 2:
				if(arr == NULL) {
					printf("\nERRO! Nenhum vetor criado.\n");
				} else {
					printf("\nProcessando...\n");
					insertionSortVetor(arr,tamanho);
				}
				break;
			default:
				printf("\nERRO! Opcao invalida.\n");
				break;
			}
			break;
		case 4:
			printf("\n1) Lista \n2) Vetor\nEscolha um alvo:");
			scanf("%d", &type);
			switch(type) {
			case 1:
				if(lista == NULL) {
					printf("\nERRO! Nenhuma lista criada.\n");
				} else {
					printf("\nProcessando...\n");
					selectionSortLista(lista);
				}
				break;
			case 2:
				if(arr == NULL) {
					printf("\nERRO! Nenhum vetor criado.\n");
				} else {
					printf("\nProcessando...\n");
					selectionSortVetor(arr,tamanho);
				}
				break;
			default:
				printf("\nERRO! Opcao invalida.\n");
				break;
			}
			break;
		case 5:
			printf("\n1) Lista \n2) Vetor\nEscolha um alvo:");
			scanf("%d", &type);
			switch(type) {
			case 1:
				if(lista == NULL) {
					printf("\nERRO! Nenhuma lista criada.\n");
				} else {
					printf("\nProcessando...\n");
					quickSortLista(lista);
				}
				break;
			case 2:
				if(arr == NULL) {
					printf("\nERRO! Nenhum vetor criado.\n");
				} else {
					printf("\nProcessando...\n");
					quickSortVetor(arr,tamanho);
				}
				break;
			default:
				printf("\nERRO! Opcao invalida.\n");
				break;
			}
			break;
		case 6:
			printf("\n1) Lista \n2) Vetor\nEscolha um alvo:");
			scanf("%d", &type);
			switch(type) {
			case 1:
				if(lista == NULL) {
					printf("\nERRO! Nenhuma lista criada.\n");
				} else {
					printf("\nProcessando...\n");
					mergeSortLista(lista);
				}
				break;
			case 2:
				if(arr == NULL) {
					printf("\nERRO! Nenhum vetor criado.\n");
				} else {
					printf("\nProcessando...\n");
					mergeSortVetor(arr,tamanho);
				}
				break;
			default:
				printf("\nERRO! Opcao invalida.\n");
				break;
			}
			break;
		case 7:
			return 0;
		case 421:
			/*
			 * ATENÇÃO
			 * OPÇÃO APENAS PARA DEBUG
			 */
			if(lista!=NULL)imprimeLista(lista);
			else printf("\nERRO! Nenhuma lista criada.\n");
			break;
		case 422:
			/*
			 * ATENÇÃO
			 * OPÇÃO APENAS PARA DEBUG
			 */
			if(arr!=NULL)imprimeVetor(arr,tamanho);
			else printf("\nERRO! Nenhum vetor criado.\n");
			break;
		default:
			printf("\nERRO! Opcao invalida.\n");
			break;
		}
	}
	return 0;
}
