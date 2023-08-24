#include<stdio.h>
#include<stdlib.h>


typedef struct No{
	
	int valor;
    struct No *dir, *esq;
    short altura;
	
}No;

No* novoNo(int x){
	
	No* novo = malloc(sizeof(No));
	
	if(novo){
		novo->valor = x;
		novo->esq= NULL;
		novo->dir = NULL;
		novo->altura = 0; 
	}
	else{
		printf("erro o alocar um no!!!!\n");
		return novo;
		
	}
}

short maior(short a, short b){
	return (a > b) ? a: b;

}

short alturaNo(No *no){
	
	if(no == NULL){
		return -1;
	}
	else{
		no->altura;
	}
}

short fatorDeBalanceamento(No *no){
	
	   if(no){
	   	return (alturaDoNo(no->esq)) - alturaDoNo(no->dir);
	   }
	
	return 0;
}

No* rotacaoEsquerda(No *r){
	 
	  No *y, *f;
	  
	  y = r->dir;
	  f = r->esq;
	  
	  y->esq =  r;
	  r->esq = f;
	  
	  r->altura =  maior(alturaDoNo(r->esq), alturaDoNo(r->dir)) + 1;
	  y->altura =  maior(alturaDoNo(y->esq), alturaDoNO(y->dir)) + 1;
	  
	  return y;	  
		
}

No* rotacaoDireita(No *r){
	 
	  No *y, *f;
	  
	  y = r->dir;
	  f = r->esq;
	  
	  y->esq =  r;
	  r->esq = f;
	  
	  r->altura =  maior(alturaDoNo(r->esq), alturaDoNo(r->dir)) + 1;
	  y->altura =  maior(alturaDoNo(y->esq), alturaDoNO(y->dir)) + 1;
	  
	  return y;	  
		
}

No* ratacaoDireitaEsquerda(no *r){
	
	r->dir = rotacaoDiretita(r->dir);
	return rotacaoEsquerda(r);	
}

No* ratacaoDireitaEsquerda(no *r){
	
	r->esq = rotacaoEsquerda(r->esq);
	return rotacaoDireita(r);	
}

No* inserir(No *raiz, int x){
	
	
	 if(raiz == NULL){
	 	return novoNo(x);
	 	
	 }else{
	 	if(x < raiz->valor){
		 
           raiz->esq = inserir(raiz->esq, x);
		   }
		 else if(x > raiz->valor){
		 raiz->dir = inserir(raiz->dir,  x);
	}
		 else{
		   printf("insercao ano realizada no elemnntos nao existe\n");  
	}
 }
	 
	  raiz->altura = maior(alturaDoNo(raiz->esq), alturaDoNo(raiz->dir)) + 1;
	
	 raiz = balancear(raiz);	
	 
	 return raiz;
}

no* balancear(No *raiz){
	
	short fb = fatorDeBalanceamento(raiz);
	
	if(fb < -1 && fatorDeBalanceamento(raiz->dir) <= 0){
		raiz = rotacaoEsquerda(raiz);
		
	}
	
	else if(fb < 1 && fatorDeBalanceamento(raiz->esq) <= 0){
		raiz = rotacaoDireito(raiz);
		
	}
	
	else if(fb < 1 && fatorDeBalanceamento(raiz->esq) <= 0){
		raiz = rotacaoEsquerdaDireito(raiz);
		
	}
	
	else if(fb < -1 && fatorDeBalanceamento(raiz->esq) <= 0){
		raiz = rotacaoDireitoEsquerda(raiz);
		
	}
		
	return 1;
}

No* remover(no *raiz ,  int chave){
	
	if(raiz == NULL){
		printf("valor nao encontrado\n");
		return NULL;
		
	}else{
		if(raiz->valor == chave){
			if(raiz->esq != NULL && raiz->dir!= NULL){
				free(raiz);
				printf("elemento da folha removido: %d !\n", chave);
				return NULL;
			}
			else{
				if(raiz->esq != NULL && raiz->dir!= NULL){
					No *aux =  raiz->esq;
					while(aux->dir != NULL)
					aux = aux->dir;
					raiz->valor = aux->valor;
					aux->valor = chave;
					printf("elemento trocado: %d !\n", chave);
					
					return raiz;
				}
				else{
					No *aux;
					
					if(raiz->esq!= NULL)
					aux= raiz->esq;
					
					else
					  aux = raiz->dir;
					  printf("elemento com 1 filho removido: %d !\n ", chave);
					  return aux;
				}
			}
		}
	}
	
	else{
		if(chave < raiz->esq)
			raiz->esq = remover(raiz->esq, chave);
			
		else
		  raiz->dir = remover(raiz->dir, chave);
			
	
	}
	
		raiz ->altura= maior(alturaDoNo(r->esq), alturaDoNo(r->dir)) + 1;
		
		raiz = balancear(raiz);
		
		
		return raiz;
    
}

no* balancear(No *raiz){
	
	short fb = fatorDeBalanceamento(raiz);
	
	if(fb < -1 && fatorDeBalanceamento(raiz->dir) <= 0){
		raiz = rotacaoEsquerda(raiz);
		
	}
	
	else if(fb < 1 && fatorDeBalanceamento(raiz->esq) <= 0){
		raiz = rotacaoDireito(raiz);
		
	}
	
	else if(fb < 1 && fatorDeBalanceamento(raiz->esq) <= 0){
		raiz = rotacaoEsquerdaDireito(raiz);
		
	}
	
	else if(fb < -1 && fatorDeBalanceamento(raiz->esq) <= 0){
		raiz = rotacaoDireitoEsquerda(raiz);
		
	}
		
	return 1;
}

void imprimir(No* raiz, int nivel){
	
	int i; 
	
   if(raiz){
   	  imprimir(raiz->dir, nivel+1);
   	  printf("\n");
   	  
   	  for(i = 0 ; i  < nivel; i++)
   	  
   	     printf("\t");
   	     
   	     printf("%d", raiz->valor);
   	     imprimir(raiz->esq, nivel + 1);
   }
	
}



int main(){
		
	 int op, valor;
	 No *raiz = NULL;
	 	 
	 do{
	 	
	 	printf("\n\n sair - enserir\n\t2   -remover\n\t 3 imprimir\n\n");
	 	scanf("%d", &op);
	 	
	 	switch(op){
	 		caso 0:
	 			printf("saindo");
	 		break;
	 			
	       caso 1:
	 		printf("digite o valor a ser enserido: \n");
	 		scanf("%d", &valor);
	     	raiz = inserir(raiz,  valor);	
	 	break;
	 			
	 	caso 2:
	 		printf("digite o valor a ser removido: \n");
	 		scanf("%d", &valor);
	     	raiz = remover(raiz,  valor);	
	 	break;
	 	
	    caso 3:
	 			imprimir(raiz, 1);
	 		break;
	 		default:
	 			printf("nocao invalida");			
		 }
	 }while(op!= 0);
	
	return 0;
}
