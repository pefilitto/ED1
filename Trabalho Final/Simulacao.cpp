#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "TADTrabalho.h"

//Comentario Git

void verificaPrioridade(TpReg &reg){
	if(strcmp(reg.processo,"Gravar Dispositivo Interno")==0)
		reg.prioridade = 1;
	else if(strcmp(reg.processo,"Gravar Dispositivo Externo")==0)
		reg.prioridade = 2;
	else if(strcmp(reg.processo,"Deletar")==0)
		reg.prioridade = 3;
	else if(strcmp(reg.processo,"Ler")==0)
		reg.prioridade = 4;
	else if(strcmp(reg.processo,"Imprimir")==0)
		reg.prioridade =5;
}

void exibir(TpDesc Desc1, TpDesc Desc2,TpDesc Desc3,TpDesc Desc4){
	printf("\n------------------------------\n");
	TpPont *aux1=Desc1.inicio,*aux2 = Desc2.inicio,*aux3 = Desc3.inicio,*aux4 = Desc4.inicio;
	printf("Processador 1: \n");
	while(aux1!=NULL){
		printf("%s\t%s\t%d",aux1->reg.nomearq,aux1->reg.processo,aux1->reg.tempo);
		if(aux1->prox == NULL)
			aux1=NULL;
		else aux1=aux1->prox;
		printf("\n");
	}
	printf("------------------------------\n");
	printf("Processador 2: \n");
	while(aux2!=NULL){
		printf("%s\t%s\t%d",aux2->reg.nomearq,aux2->reg.processo,aux2->reg.tempo);
		if(aux2->prox == NULL)
			aux2=NULL;
		else aux2=aux2->prox;
		printf("\n");
	}
	printf("------------------------------\n");
	printf("Processador 3: \n");
	while(aux3!=NULL){
		printf("%s\t%s\t%d",aux3->reg.nomearq,aux3->reg.processo,aux3->reg.tempo);
		if(aux3->prox == NULL)
			aux3=NULL;
		else aux3=aux3->prox;
		printf("\n");
	}
	printf("------------------------------\n");
	printf("Processador 4: \n");
	while(aux4!=NULL){
		printf("%s\t%s\t%d",aux4->reg.nomearq,aux4->reg.processo,aux4->reg.tempo);
		if(aux4->prox == NULL)
			aux4=NULL;
		else aux4=aux4->prox;
		printf("\n");
	}
	printf("\n------------------------------\n");
}


void simulacao(FILE *ptr, TpDesc desc1, TpDesc desc2, TpDesc desc3, TpDesc desc4,int ifbkp){
	TpReg reg, regaux;
	TpPont *caixa, *atual;
	char click,opc;
	char nomeprocesso1[50],nomeprocesso2[50],nomeprocesso3[50],nomeprocesso4[50];
	int tempo=0, cont1=0, cont2=0, cont3=0, cont4=0, conttotal=0, menor = 10,flag=0;
	if(ifbkp==1)
	{
		FILE *bkp = fopen("bkptempo.txt","r");
		fscanf(bkp,"%d\n%d\n%d\n%d\n%d\n%d",&tempo,&conttotal,&cont1,&cont2,&cont3,&cont4);
		fclose(bkp);
		int flag2 = 0;
		while(flag2==0){
			fscanf(ptr, "%d,%[^,],%[^,],%d,%c\n", &reg.processador, &reg.nomearq, &reg.processo, &reg.tempo,&opc);
			verificaPrioridade(reg);
			caixa = novaCaixa(reg);
			if(reg.processador == 1){
				if(desc1.inicio == NULL){
					desc1.inicio = desc1.fim = caixa;
				}
				else{
					desc1.fim -> prox = caixa;
					caixa -> ant = desc1.fim;
					desc1.fim = caixa;
				
					atual = desc1.fim;
					TpReg regaux;
					while(atual -> ant != NULL && atual -> reg.prioridade < atual -> ant -> reg.prioridade){
						regaux = atual->reg;
						atual->reg = atual -> ant -> reg;
						atual -> ant -> reg = regaux;
						
						atual = atual -> ant;
					}
				}
			}
			else if(reg.processador == 2){
				if(desc2.inicio == NULL){
					desc2.inicio = desc2.fim = caixa;
				}
				else{
					desc2.fim -> prox = caixa;
					caixa -> ant = desc2.fim;
					desc2.fim = caixa;
				
					atual = desc2.fim;
					TpReg regaux;
					while(atual -> ant != NULL && atual -> reg.prioridade < atual -> ant -> reg.prioridade){
						regaux = atual->reg;
						atual->reg = atual -> ant -> reg;
						atual -> ant -> reg = regaux;
						atual = atual -> ant;
					}
				}
			}
			else if(reg.processador == 3){
				if(desc3.inicio == NULL){
					desc3.inicio = desc3.fim = caixa;
				}
				else{
					desc3.fim -> prox = caixa;
					caixa -> ant = desc3.fim;
					desc3.fim = caixa;
				
					atual = desc3.fim;
					TpReg regaux;
					while(atual -> ant != NULL && atual -> reg.prioridade < atual -> ant -> reg.prioridade){
						regaux = atual->reg;
						atual->reg = atual -> ant -> reg;
						atual -> ant -> reg = regaux;
						
						atual = atual -> ant;
					}
				}
			}
			else{
				if(desc4.inicio == NULL){
					desc4.inicio = desc4.fim = caixa;
				}
				else{
					desc4.fim -> prox = caixa;
					caixa -> ant = desc4.fim;
					desc4.fim = caixa;
				
					atual = desc4.fim;
					TpReg regaux;
					while(atual -> ant != NULL && atual -> reg.prioridade < atual -> ant -> reg.prioridade){
						regaux = atual->reg;
						atual->reg = atual -> ant -> reg;
						atual -> ant -> reg = regaux;
						
						atual = atual -> ant;
					}
				}
			}
			if(opc!='*')
				flag2=1;
		}
	}
	while(!kbhit()){
		system("cls");	
		if(tempo % 2 == 0&&!feof(ptr)){
			fscanf(ptr, "%d,%[^,],%[^,],%d,%c\n", &reg.processador, &reg.nomearq, &reg.processo, &reg.tempo,&opc);
			verificaPrioridade(reg);
			caixa = novaCaixa(reg);
			if(reg.processador == 1){
				if(desc1.inicio == NULL){
					desc1.inicio = desc1.fim = caixa;
				}
				else{
					desc1.fim -> prox = caixa;
					caixa -> ant = desc1.fim;
					desc1.fim = caixa;
				
					atual = desc1.fim;
					TpReg regaux;
					while(atual -> ant != NULL && atual -> reg.prioridade < atual -> ant -> reg.prioridade){
						regaux = atual->reg;
						atual->reg = atual -> ant -> reg;
						atual -> ant -> reg = regaux;
						
						atual = atual -> ant;
					}
				}
			}
			else if(reg.processador == 2){
				if(desc2.inicio == NULL){
					desc2.inicio = desc2.fim = caixa;
				}
				else{
					desc2.fim -> prox = caixa;
					caixa -> ant = desc2.fim;
					desc2.fim = caixa;
				
					atual = desc2.fim;
					TpReg regaux;
					while(atual -> ant != NULL && atual -> reg.prioridade < atual -> ant -> reg.prioridade){
						regaux = atual->reg;
						atual->reg = atual -> ant -> reg;
						atual -> ant -> reg = regaux;
						atual = atual -> ant;
					}
				}
			}
			else if(reg.processador == 3){
				if(desc3.inicio == NULL){
					desc3.inicio = desc3.fim = caixa;
				}
				else{
					desc3.fim -> prox = caixa;
					caixa -> ant = desc3.fim;
					desc3.fim = caixa;
				
					atual = desc3.fim;
					TpReg regaux;
					while(atual -> ant != NULL && atual -> reg.prioridade < atual -> ant -> reg.prioridade){
						regaux = atual->reg;
						atual->reg = atual -> ant -> reg;
						atual -> ant -> reg = regaux;
						
						atual = atual -> ant;
					}
				}
			}
			else{
				if(desc4.inicio == NULL){
					desc4.inicio = desc4.fim = caixa;
				}
				else{
					desc4.fim -> prox = caixa;
					caixa -> ant = desc4.fim;
					desc4.fim = caixa;
				
					atual = desc4.fim;
					TpReg regaux;
					while(atual -> ant != NULL && atual -> reg.prioridade < atual -> ant -> reg.prioridade){
						regaux = atual->reg;
						atual->reg = atual -> ant -> reg;
						atual -> ant -> reg = regaux;
						
						atual = atual -> ant;
					}
				}
			}
		}
		char auxprocesso[50];
		decrementa(desc1,cont1,conttotal,auxprocesso);
			if(strcmp(auxprocesso," ")!=0)
				strcpy(nomeprocesso1,auxprocesso);
		decrementa(desc2,cont2,conttotal,auxprocesso);
			if(strcmp(auxprocesso," ")!=0)
				strcpy(nomeprocesso2,auxprocesso);
		decrementa(desc3,cont3,conttotal,auxprocesso);
			if(strcmp(auxprocesso," ")!=0)
				strcpy(nomeprocesso3,auxprocesso);
		decrementa(desc4,cont4,conttotal,auxprocesso);
			if(strcmp(auxprocesso," ")!=0)
				strcpy(nomeprocesso4,auxprocesso);
		exibir(desc1,desc2,desc3,desc4);
		tempo++;
		printf("Tempo decorrido: %d \nAtividades Processador 1: %d \nAtividades Processador 2: %d\nAtividades Processador 3: %d\nAtividades Processador 4: %d\nAtividades total: %d\n",tempo,cont1,cont2,cont3,cont4,conttotal);
		Sleep(500);
	}
	
	if(kbhit()){
		/*printf("Desc1: \n");
		Exibir2(desc1);
		printf("Desc2: \n");
		Exibir2(desc2);
		printf("Desc3: \n");
		Exibir2(desc3);
		printf("Desc4: \n");
		Exibir2(desc4);*/
		TpReg aux2;
		int cont=0;
		FILE *ptr5 = fopen("auxiliar.txt","w");
		if(ptr5 == NULL)
			printf("Erro ao abrir aux.txt\n");
		else{
			int ok=0;
			while(ok==0){
				if(desc1.inicio!=NULL){
					fprintf(ptr5,"%d,%s,%s,%d,*\n",desc1.inicio->reg.processador,desc1.inicio->reg.nomearq,desc1.inicio->reg.processo,desc1.inicio->reg.tempo);
					if(desc1.inicio->prox!=NULL){
						desc1.inicio = desc1.inicio->prox;
						desc1.inicio->ant=NULL;
					}	
					else{
						desc1.inicio=NULL;
					}
				}
				
				if(desc2.inicio!=NULL){
					fprintf(ptr5,"%d,%s,%s,%d,*\n",desc2.inicio->reg.processador,desc2.inicio->reg.nomearq,desc2.inicio->reg.processo,desc2.inicio->reg.tempo);
					if(desc2.inicio->prox!=NULL){
						desc2.inicio = desc2.inicio->prox;
						desc2.inicio->ant=NULL;
					}else
						desc2.inicio=NULL;
				}
				
				if(desc3.inicio!=NULL){
					fprintf(ptr5,"%d,%s,%s,%d,*\n",desc3.inicio->reg.processador,desc3.inicio->reg.nomearq,desc3.inicio->reg.processo,desc3.inicio->reg.tempo);
					if(desc3.inicio->prox!=NULL){
						desc3.inicio = desc3.inicio->prox;
						desc3.inicio->ant=NULL;
					}else
						desc3.inicio=NULL;
				}
				
				if(desc4.inicio!=NULL){
					fprintf(ptr5,"%d,%s,%s,%d,*\n",desc4.inicio->reg.processador,desc4.inicio->reg.nomearq,desc4.inicio->reg.processo,desc4.inicio->reg.tempo);
					if(desc4.inicio->prox!=NULL){
						desc4.inicio = desc4.inicio->prox;
						desc4.inicio->ant=NULL;
					}else
						desc4.inicio=NULL;	
				}
				if(desc1.inicio == NULL && desc2.inicio == NULL && desc3.inicio == NULL && desc4.inicio == NULL)
					ok=1;
			}
			fscanf(ptr, "%d,%[^,],%[^,],%d,%c\n", &reg.processador, &reg.nomearq, &reg.processo, &reg.tempo,&opc);
			while(!feof(ptr)){
				fprintf(ptr5,"%d,%s,%s,%d,-\n",reg.processador,reg.nomearq,reg.processo,reg.tempo);
				fscanf(ptr, "%d,%[^,],%[^,],%d,%c\n", &reg.processador, &reg.nomearq, &reg.processo, &reg.tempo,&opc);
			}
			fclose(ptr5);
			fclose(ptr);		
			FILE *ptr4 = fopen("auxiliar.txt","r");
			FILE *ptr2 = fopen("backup.txt", "w");
			fseek(ptr4,0,SEEK_SET);
			char c = fgetc(ptr4);
			while(!feof(ptr4)){
				fputc(c,ptr2);
				c=fgetc(ptr4);
			}
			FILE *bkp = fopen("bkptempo.txt","w");
			fprintf(bkp,"%d\n%d\n%d\n%d\n%d\n%d",tempo,conttotal,cont1,cont2,cont3,cont4);
			fclose(ptr4);
			fclose(ptr2);
			remove("auxiliar.txt");
		}
	}
	getch();
}



int main()
{
	TpDesc desc1, desc2, desc3, desc4;
	int ifbkp = 0;
	char resposta[5];
	Inicializar(desc1);
	Inicializar(desc2);
	Inicializar(desc3);
	Inicializar(desc4);
	FILE *teste = fopen("backup.txt", "r");
	
	if (teste == NULL) {
		FILE *ptrcom = fopen("comandos.txt", "r");
		simulacao(ptrcom, desc1, desc2, desc3, desc4, ifbkp);
	} 
	else {
		fclose(teste);
		printf("Existe um Backup. Quer utiliza-lo? (S/N)\n");
		//fflush(stdin);
		gets(resposta);
		//while ((resposta = getchar()) != '\n' && resposta != EOF);
		if (strcmp(resposta, "Sim") == 0) {
			FILE *ptrback = fopen("backup.txt", "r");
			simulacao(ptrback, desc1, desc2, desc3, desc4, 1);
		} 
		else {
			FILE *ptrcom = fopen("comandos.txt", "r");
			simulacao(ptrcom, desc1, desc2, desc3, desc4, ifbkp);
		}
	}	
}
