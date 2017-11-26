/* Bernardo Hörner Lopes / 1611790 / 3wb*/
/* Matheus Loriato Homsi / 1510866 / 3wb */

#include <stdio.h>
#include <stdlib.h>
#include "cria_func.h"

unsigned char codigo[]; // Vetor que abrigará a função

typedef int (*func_ptr) (int x);

// f = end funç a chamar / params = descritor dos params / n = quant params
void* cria_func (void* f, DescParam params[], int n) 
{
	int i = 4, j;
	codigo[]= (unsigned char*)malloc(1000); //(tem 1kbytes pra ter certeza que não faltará espaço)
	codigo[]={0x55, 0x48, 0x89, 0xe5}; //Alinhamento da pilha: Sempre deve ocorrer (push %rbp etc)
	
	for (j=0 ; j<n ; j++) //Analisa params para ver quanto espaço da pilha precisa armazenar
	{
		if(params[j].tipo_val == PTR_PAR) 
		{
			codigo[i] = 
		}
	}
	/*
	A função irá analisar a descrição dos parâmetros passados e irá preencher um vetor com os códigos de máquina adequados para a situação.
		
		-> Abrimos um loop controlado por n para ver todos os parâmetros. Dentro deste, checamos o que os parâmetros têm, preenchendo o vetor com código de máquina para criar variáveis, armazenar endereços em registrador x etc.
		- Primeiro checar quanto espaço é preciso armazenar na pilha: se os parâmetros são ponteiros ou ints e ir alocando conforme o necessário (analisa um, aloca espaço. Analisa outra, aloca mais)
		- 
		
		OBS: Para descobrirmos os valores dos códigos de máquina para cada instrução, temos de programar os comandos em assembly, compilar com (gcc -c foo.s) e fazer (objdump -d foo.o)!
	*/	
	
	codigo[i] = 0xc9; //leave
	i++;
	codigo[i] = 0xc3; //ret
	
	codigo = (unsigned char*)realloc(codigo, sizeof(unsigned char)*i);
}

int mult(int x, int y) {
  return x * y;
}

int main (void) 
{
  DescParam params[2];
  func_ptr f_mult;
  int i;

  params[0].tipo_val = INT_PAR; /* o primeiro parãmetro de mult é int */
  params[0].orig_val = PARAM;   /* a nova função repassa seu parämetro */

  params[1].tipo_val = INT_PAR; /* o segundo parâmetro de mult é int */
  params[1].orig_val = FIX;     /* a nova função passa para mult a constante 10 */
  params[1].valor.v_int = 10;

  f_mult = (func_ptr) cria_func (mult, params, 2);

  for (i = 1; i <=10; i++) 
    printf("%d\n", f_mult(i)); /* a nova função só recebe um argumento */
  

  libera_func(f_mult);
  return 0;
}
  f_mult = (func_ptr) cria_func (mult, params, 2);

  for (i = 1; i <=10; i++) 
    printf("%d\n", f_mult(i)); /* a nova função só recebe um argumento */
  

  libera_func(f_mult);
  return 0;
}
