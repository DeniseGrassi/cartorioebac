#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> //biblioteca para poder usar strings no codigo

int registro() //criando a funcao registro. 
{

	setlocale(LC_ALL, "portuguese");
	
	//criando as variaveis do tipo strings (%s) para a funcao registro
	char cpf [40];
	char nome [40];
	char sobrenome[40];
	char cargo[40];
	char arquivo[40]; //toda vez que criar um usuario novo, esse arquivo ira mudar
	
	printf("Digite o CPF a ser cadastrado: "); //usuario precisa dar uma informacao
	scanf("%s", cpf); //scanf usa quando o usuario tem que dar uma resposta para continuar o programa...
	
 	//criar o nome do arquivo com o nome do cpf
	strcpy (arquivo, cpf); //copiar o valor do cpf, na variavel arquivo. Assim n vai perguntar 2x ao usuario o nome do arquivo e o cpf	
	//str = string, cpy= copiar.... strcpy !	
	
	//criando o arquivo
	FILE *file; //acesse o FILE em uma das bibliotecas e procura o nosso file. 
	file = fopen (arquivo, "w"); //O nosso file estamos criando agora. E ele sera o 'arquivo' que já é igual ao CPF. Aqui ele esta criando um novo arquivo com o nome do cpf que o usuario digitou
	// "w" é a letra para escrevendo(writing) um novo arquivo

	fprintf(file, cpf); //salvando no arquivo file a variavel cpf que o usuario digitou
	fclose(file);
	
	//Para atualizar "a" com alguma informação nova o nosso arquivo
	file = fopen (arquivo,"a"); 
	fprintf(file,","); //add a virgula
	fclose(file);
	
// fazer agora o processo com o NOME. e add no mesmo arquivo file q ja criamos
//obs: optou pelo titulo do arquivo ser o cpf, pq é uma informacao impessoal, não da erros.

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome); 
	
	file = fopen (arquivo,"a"); //abrindo o arquivo para adicionar o nome digitado pelo usuario
	fprintf(file,nome);
	fclose(file);
	
	file = fopen (arquivo,"a"); //colocando espaço entre o nome e o sobrenome
	fprintf(file," ");
	fclose(file);
	
// fazer agora o processo com o SOBRENOME. e add no mesmo arquivo file

	printf("Digite o SOBREnome a ser cadastrado: ");
	scanf("%s", sobrenome); 
	
	file = fopen (arquivo,"a"); //abrindo o arquivo para adicionar o SOBREnome digitado pelo usuario
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo,"a"); //colocando virgula (,) entre o nome completo e o cargo cadastrado
	fprintf(file,",");
	fclose(file);
	
	
// fazer agora o processo com o cargo. e add no mesmo arquivo file

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo); 
	
	file = fopen (arquivo,"a"); //abrindo o arquivo para adicionar o cargo digitado pelo usuario
	fprintf(file,cargo);
	fclose(file);	
	
	file = fopen (arquivo,"a"); //colocando ponto final
	fprintf(file,".");
	fclose(file);
		
	system("pause");
}


int consultar()
{
	setlocale(LC_ALL, "portuguese"); //para usar acentos é preciso colocar dentro dessa funcao consultar() o setlocale
	
	char cpf [40]; //como é uma outra funcao, é preciso criar outra variavel cpf dentro dela aqui
	char conteudo[200];
	char nome[40];
		
	printf("Digite o cpf a ser consultado:  ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //r de ler o arquivo cpf
	
		
	if(file == NULL) //uma validacao para um cpf que nao existe no nosso banco de dados cadastrado.
	{
		printf("Não foi possível localizar o CPF. \n"); 
	}

	//agora a funcao para salvar o arquivo dentro....
	//para fzer uma acao ate ela acabar, usa um laço de repeticao, nesse caso o ENQUANTO (while). 
	while(fgets(conteudo,200,file) != NULL) //o fgets vai buscar o conteudo la na pasta que tem o tamanho maximo de 200. Ele roda na pasta file, 200x, até dar todo o conteudo. 
	{    //enquanto for diferente (!=) de nulo ele roda, quando for nulo ele para
	   
		printf("\n Essas são as informações para o CPF/Nome completo/cargo do usuário: ");
		printf("%s",conteudo); //salvar o conteudo dentro da string
		printf("\n\n");
	}
	
	system("pause");
}


int deletar()
{
	char cpf [40]; //necessario fzer novamente a variavel pq é uma nova funcao!
	
	printf("Digite o CPF que deseja deletar:\n");
	scanf("%s",cpf);
	
	FILE *file; //abrir a pasta file para poder ler os cpf que contem nela.
	file = fopen(cpf,"r");
	
	if(file == NULL) //uma validacao para um cpf que nao existe no nosso banco de dados cadastrado.
	{
		printf("Não foi possível localizar o CPF. \n"); 
		system("pause");
	}
	
	printf("Digite o CPF que deseja deletar:\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	if(cpf != NULL); //se o cpf é diferente de nulo, entao...
	{
		printf("CPF deletado com sucesso! \n"); 
		system("pause");
	}
}


int main () //a funcao principal, sempre irá rodar primeiro
{
	int opcao=0; 
	int x=1;
	
	for (x=1;x=1;) // nao precisou usar incremento, nao ira "avancar" no giro do codigo
	{
	
		system("cls");
		
    	setlocale(LC_ALL, "portuguese");
    	
    	printf("### Cartório da EBAC ### \n\n"); // inicio do menu
		printf("Escolher a opção desejado do MENU \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n\n");
		printf("Opcao: "); //fim do menu
	
			scanf("%d", &opcao); // armazenando a escolha do usuario. Pausa o programa ate o usuario dar uma resposta.
			//%d variavel do tipo inteiro
	
		system("cls"); //limpar a tela pra ficar mais organizado
		
		switch(opcao) //pedindo ao pc para analisar a variavel opcao
		{
			case 1: //se a variavel for 1 entao segue.  usar o dois pontos : para abrir a chave
			registro(); //funcao registro aberta la em cima
    		break; //fechando a chave
    		
    		case 2:
    		consultar();
			break;
			
    		case 3:
    		deletar();
			break;
				
				
			default: //quando ele escolhe uma opcao n mapeada, uma opcao q n existe
			printf("Essa opção não está disponível. Retorne ao MENU !");
			system("pause");
			break;
		}
		
	}
}

	
