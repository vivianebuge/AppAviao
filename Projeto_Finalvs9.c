#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


void leValidaDestino(char destino[]);
int leValidaAssentos();
float leValidaValor();
char Resposta();
void areaTransicao(char *destino, char mapa[], int qtdassentos,  float valor);
void areaFuncionario(char *destino, char mapa[], int qtdassentos,  float valor);
void areaCliente(char *destino, char mapa[], int qtdassentos,  float valor);
void mostrarMapa(char mapa[], int  i);
void Reserva(char destino [], char mapa[], int i, float valor);
void Cancelamento(char mapa[], int i);
void Confirmar(char mapa[], int i);
int leValidaIdade();
float calculaPassagem (int idade, float valor);
void gotoxy (int x, int y);


void main(){
	char destino[30];
	int qtdassentos, flag, area, indice;
	char mapa[200], continuar;
	float valor, valorTotal;
	
	
	puts("================ Bem Vindo a SALUMA LINHAS AEREAS =============\n");

	puts ("================= Area de Lacamentos de Voo ==================\n\n");

		
		puts("Por favor informe os detalhes do voo: \n");
		leValidaDestino(destino);
		printf("\n");
		qtdassentos = leValidaAssentos();
		printf("\n");
		
		for(indice = 0; indice < qtdassentos ;indice++) {
			mapa[indice]= 'D';
		}
		valor = leValidaValor();
		puts("===========Cadastro Realizado com Sucesso!==============");
		

	areaTransicao(destino, mapa, qtdassentos, valor);
}

void leValidaDestino(char destino[]){

	do{
	
		printf("Digite o destino: \n");
		gets(destino);
		if (strcmp(destino, "")==0) {
			printf("Voce nao digitou um destino! \n");
		}
	}while (strcmp(destino, "")==0);
	
}

int  leValidaAssentos(){
	int assentos;
	do{
		printf("Digite a quantidade de assentos para esse voo (90 a 199): \n");
		scanf("%i", &assentos);
		if (assentos <90 || assentos >200) 
			printf("Só existem aviões de 90 a 199 assentos! \n");
	}while (assentos <90 || assentos >200);
	return assentos;
}

float leValidaValor(){

	float valor;
	do{
	
		printf("Digite o valor da Passagem \n");
		printf("R$: ");
		scanf("%f", &valor);
		if (valor <0){
			printf ("Valor da passagem invalido! \n ");
		}
	}while (valor <0);
	return valor;
}

char Resposta(){
	char resposta;
	do{
	
		printf("s-Sim ou n-Nao \n");
		resposta=getche();
		if(resposta>='A' && resposta<='Z')
			resposta=resposta+32;
				
		if(resposta != 's'&& resposta!='n')
			printf("Porfavor digite opcao valida  \n");
		

	}while(resposta != 's' && resposta!='n');
	return resposta;

}


void areaTransicao(char destino[], char mapa[], int qtdassentos,  float valor){

	int area;
	system("cls");
	gotoxy(40,8);
	printf("Digite: \n");
	gotoxy(40,9);
	printf("1 - Funcionario \n");
	gotoxy(40,10);
	printf("2 - Cliente\n");
	gotoxy(40,11);
	printf("Qualquer outro numero para sair  \n");
	scanf ("%i", &area);
	if(area == 1) {
		areaFuncionario(destino, mapa, qtdassentos, valor);
	}
	else if (area==2) {
			areaCliente(destino, mapa, qtdassentos, valor);
		}
	else
		system("pause");
}
void areaFuncionario(char destino[], char mapa[], int qtdassentos,  float valor){

	int codigo;
	char continuar;
	system("cls");
	printf("========= Bem Vindo a SALUMA LINHAS AEREAS ========= \n");
	printf("\n");
	printf ("=================Area do Funcionario==================\n\n");

	printf("Por favor Selecione uma das opções\n\n");

	printf(" 1 - Verificar Ocupacao dos voos\n");
	printf(" 2 - Efetuar Reserva\n" );
	printf(" 3 - Realizar Cancelamento \n");
	printf(" 4 - Efetuar Confirmacao\n");
	printf(" 5 - Mostrar Mapa de Assentos e Valores \n");
	printf(" 6 - Voltar ao menu Inicial \n");
	printf("\n");
	printf("Digite o codigo de preferencia: ");

	scanf("%i", &codigo);
	switch(codigo){
	
	case 1:
		system("cls");
		gotoxy(40,20);
		mostrarMapa(mapa, qtdassentos);
		printf("\n");
		printf("Gostaria de voltar ao menu de Funcionarios? \n");
		continuar = Resposta();
		if (continuar =='s') 
			areaFuncionario(destino, mapa, qtdassentos, valor);
		else
			areaTransicao(destino, mapa, qtdassentos, valor);
		
		break;
	case 2:
		system("cls");
		Reserva(destino, mapa, qtdassentos, valor);
		printf("\n");
		printf("Gostaria de voltar ao menu de Funcionarios? \n");
		continuar = Resposta();
		if (continuar =='s') 
			areaFuncionario(destino, mapa, qtdassentos, valor);
		else
			areaTransicao(destino, mapa, qtdassentos, valor);
		
		break;
	case 3:
		system("cls");
		Cancelamento(mapa, qtdassentos);
		printf("\n");
		printf("Gostaria de voltar ao menu de Funcionarios? \n");
		continuar = Resposta();
		if (continuar =='s') 
			areaFuncionario(destino, mapa, qtdassentos, valor);
		else
			areaTransicao(destino, mapa, qtdassentos, valor);
		
		break;
	case 4:
		system("cls");
		Confirmar(mapa, qtdassentos);
		printf("\n");
		printf("Gostaria de voltar ao menu de Funcionarios? \n");
		continuar = Resposta();
		if (continuar =='s') 
			areaFuncionario(destino, mapa, qtdassentos, valor);
		else
			areaTransicao(destino, mapa, qtdassentos, valor);
		
		break;
	case 5:
		system("cls");
		printf("O mapa de assentos é : \n");
		mostrarMapa(mapa, qtdassentos);
		printf("\n");
		printf("Gostaria de voltar ao menu de Funcionarios?");
		printf("\n");
		continuar = Resposta();
		if (continuar =='s') 
			areaFuncionario(destino, mapa, qtdassentos, valor);
		else
			areaTransicao(destino, mapa, qtdassentos, valor);
		
		break;
	case 6:
		areaTransicao(destino, mapa, qtdassentos, valor);
		break;
	}
}

void areaCliente(char destino[], char mapa[], int qtdassentos,  float valor){

	char confirmaReserva, reservar, continuar;
	int j, x, indice, idade, fazerReserva ;

	system("cls");

	printf("========= Bem Vindo a SALUMA LINHAS AEREAS =========\n");
	printf("\n");
	printf ("================= Area do Cliente==================\n\n");
	printf("\n");
	printf("Digite a opcao desejada: \n\n");
	printf(" 1-Fazer reserva \n");
	printf(" 2-Confirmar Reserva \n");
	printf(" 3-Cancelar Reserva \n");
	printf(" 4-Voltar ao menu Inicial\n\n");
	
	scanf("%i", &fazerReserva);

	switch (fazerReserva){
	
	case 1:
		do{
		system("cls");
		Reserva(destino, mapa, qtdassentos, valor);
		printf("\n");
		printf("Gostaria de fazer outra reserva? \n");
		continuar = Resposta();
		if (continuar =='n'){
		
			areaCliente(destino, mapa, qtdassentos, valor);
		}
		}while(continuar=='s');
		
		break;
	case 2:	
			
			do{
			system("cls");
			Confirmar(mapa, qtdassentos);
			printf("\n");
			printf("Gostaria de Confirmar mais alguma reserva ? \n");
			continuar = Resposta();
			if (continuar =='n') 
				areaCliente(destino, mapa, qtdassentos, valor);
				
			}while (continuar=='s');
		break;
	case 3:
			do {
			system("cls");
			Cancelamento(mapa, qtdassentos);
			printf("\n");
			printf("Gostaria de voltar ao menu do Cliente? \n");
			continuar = Resposta();
			if (continuar =='n') 
				areaCliente(destino, mapa, qtdassentos, valor);
			
			}while(continuar=='s');
		
		break;
	
	case 4:
		areaTransicao(destino, mapa, qtdassentos, valor);
		break;	
				
	default:
		
		printf("Digite numero valido!");
		areaCliente(destino, mapa, qtdassentos, valor);
		break;
	}
}

void mostrarMapa(char mapa[], int  i){
	
	int x, cont;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD saved_attributes;
	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	saved_attributes = consoleInfo.wAttributes;
		
	printf("\n");
	printf("Assento:Disponibilidade \n");
	printf("\n");
	
	cont = 1;
	for(x = 0; x<i; x++){
		cont = cont +1;
		SetConsoleTextAttribute(hConsole, saved_attributes);	
		printf( " %i ", x+1);
		
		if (mapa[x]=='D'){
		SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
		printf("%c", mapa[x]);
		}
		else if(mapa[x]=='C'){
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
		printf("%c", mapa[x]);
		}
		else{
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
			printf("%c", mapa[x]);
		}
		
		if(cont == 4)
			printf ("		");
		else{
		
			if(cont==7){
			
				printf("\n");
				cont=1;
			}
		}
	}
	SetConsoleTextAttribute(hConsole, saved_attributes);
	printf("\n");
}

void Reserva(char destino [], char mapa[], int i, float valor){
	char reservar;
	int x, y, cont, idade;
	float valorPassagem;
	
	
	printf("O destino do voo e %s \n", destino);
	printf ("\n");
	idade = leValidaIdade();
	printf ("\n");
	
	do{
	
		mostrarMapa(mapa, i);
		printf("\n");
		printf("Qual assento gostaria de reservar ? \n" );
		printf("Assento: ");
		scanf("%i", &y);
		if(mapa[y-1]== 'R' || mapa[y-1] == 'C'){
			printf("Este assento ja esta reservado ou confirmado, por favor, verifique o mapa de assentos \n\n");
			printf("Assento:Disponibilidade");
			printf("\n");
			mostrarMapa(mapa, i);
			printf("\n");
		}

	}while (mapa[y -1] == 'R' || mapa[y-1] == 'C');
	
	valorPassagem = calculaPassagem (idade, valor);
	printf("O valor da passagem e de R$: %.2f \n", valorPassagem);
	printf("\n");
	printf("Gostaria de Reservar? \n");
	reservar = Resposta();
	if(reservar == 's'){
	
		mapa[y-1]='R';
		mostrarMapa(mapa, i);
		printf("\n");
		printf("============ O assento %i foi reservado com Sucesso ============= \n", y);
	}
	else{
		areaTransicao(destino, mapa, i, valor);
	}	
}

void Cancelamento(char mapa[], int i){

	int y;

	do{
		printf("\n");
		printf("Qual Reserva gostaria de cancelar ?\n" );
		printf("Assento: ");
		scanf("%i", &y);
		printf("\n");
		if(mapa[y -1] == 'D') {
		
			printf("Este assento n'ao esta reservado, por favor, verifique o mapa de assentos\n");
			printf("\n");
			mostrarMapa(mapa, i);
			printf("\n");
		}
	}while (mapa[y -1] == 'D');

	mapa[y-1] ='D';
	printf("Cancelamento realizado com sucesso \n");
	printf("\n");
	mostrarMapa(mapa, i); 

	printf("============O assento %i esta novamente Disponivel ============= \n", y);
	printf("\n");
}

void Confirmar(char mapa[], int i){

	int x, y, cont;

	do{
		printf("\n");
		printf("Qual Reserva gostaria de Confirmar ? \n" );
		printf("Assento: ");
		scanf("%i", &y);
		printf("\n");
		if(mapa[y -1] == 'D') {
		
			printf("Este assento n'ao esta reservado, por favor, verifique o mapa de assentos\n");
			printf("\n");
			mostrarMapa(mapa, i);
			printf("\n");
		}
	}while (mapa[y -1] == 'D');

	mapa[y-1] ='C';
	printf("Cancelamento realizado com sucesso \n");
	printf("\n");
	mostrarMapa(mapa, i);


	printf("============O assento %i esta Confirmado ============= \n", y);
	printf("\n");
}

int leValidaIdade(){

	int idade;
	do{
	
		printf("Digite a Idade do passageiro: \n");
		scanf("%i", &idade);
		if(idade<0) 
			printf ("Idade Inválida !\n");
		
	}while (idade<0);
	return idade;
}


float calculaPassagem (int idade, float valor){
float valorCompra;

	if (idade<=5) 
		valorCompra = valor/2;
	else
		valorCompra = valor;
	
return valorCompra;
	
}

void gotoxy (int x, int y) {
	COORD c;
	c.X = x-1;
	c.Y = y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	
}
