#include <locale.h>
#include <stdio.h>
#include"TadLista.c"
#include <string.h>

void menu ();
void cabecalho();
void imprimeLista();

void main ()
{
    setlocale(LC_ALL,"Portuguese");
    Usuario usuario;
    Lista lista;
    criaLista(&lista);
    int posicao,op,tamanho;
    int codErro;
    char continua;
    char mensagem[1000];

do{
    cabecalho();
    menu();
    op = getch();
    system("cls");
	int contador=0;
    switch (op)
    {

        case '1':
        {
            do
            {
               if (cheiaLista(&lista)) {
                         printf("     Cadastro cheio!!!\n\n");
                         system("pause");
                         continua = 'N';
                }
                else
                printf("\n|=========================================================|");
                printf("\n\nInforme o nome do usu�rio:");
                fflush(stdin);
                gets(usuario.nome);
                printf("\n|=========================================================|");
                printf("\n\nInforme o e-mail do usu�rio:");
                fflush(stdin);
                gets(usuario.email);
                printf("\n|=========================================================|");
             
                do
                {
                    printf("\n\nInforme o telefone do usu�rio:");
                    fflush(stdin);

                    scanf("%s",&usuario.telefone); 
                         if (strlen(usuario.telefone) != 11)
                    {
                        printf("\n\nPreencha o campo corretamente.");
                    }
                }while(strlen(usuario.telefone) != 11);
                contador ++;    
				insereLista(usuario,&lista,&codErro);
                imprimeLista(&lista);
                printf("\n\nUsu�rio Cadastrado com sucesso.");
                printf("\n\nN�mero de usu�rio cadastrados:%d",contador);
                printf("\n\n\nDeseja continuar?[S/N]");
                continua = toupper(getch());
                system("cls");

            }
            while(continua=='S');
            break;

        }//SWITCH CASE 1



    case '2':{
            do
                {
                    cabecalho();
                    printf("\n            Alterar telefone de usu�rio ");
                    if (vaziaLista(&lista)) {
                         printf("     \n\nCadastro vazio!!!\n\n");
                         system("pause");
                         continua = 'N';


                    }
                    else{
                    printf("\n\n\t Informe nome do usu�rio: ");
                    fflush(stdin);
                    gets(usuario.nome);
                    posicao = buscaLista(usuario, &lista);
                    if(posicao == -1)
                        printf("\n\t\t Usu�rio %s NAO existente na lista!\n", usuario.nome);
                    else{
                        printf("\n\t\t Usu�rio %s encontrado na lista!\n", usuario.nome);
                        usuario = lista.usuario[posicao];
                       do{
                        printf("\n\t\tInforme o novo telefone:");
                        scanf("%f",&usuario.telefone);
                            if (strlen(usuario.telefone) != 11)


                        printf("\n\nPreencha o campo corretamente.");

                       }  while(strlen(usuario.telefone) != 11); ;
                        lista.usuario[posicao] = usuario;

                    imprimeLista(&lista);
                    printf ("\nDeseja alterar outro telefone?(S/N) ");
                    continua = toupper(getch());
                }
                    }
                }
 while (continua == 'S');
                break;
system("cls");


    }//switch case 2

case '3':{

                  do {
                     cabecalho();
                     printf( "\t                    ::: Excluir Usu�rio :::\n\n" );

                     if (vaziaLista(&lista)) {
                         printf("   \n\n  Cadastro vazio!!!\n\n");
                         system("pause");
                         continua = 'N';

                     }


                     else{
                         imprimeLista(&lista);
                         printf("\n   Informe nome do Usu�rio a excluir: ");
                         fflush(stdin);
                         gets(usuario.nome);
                         excluiLista (usuario, &lista, &codErro);
                         if (codErro != 0){
                              printf("\n   Usu�rio n�o existente no cadastro!!!");
                         }

                         else{
                        system("cls");
                         printf("\n   Exclusao realizada com sucesso!!!");
                         imprimeLista(&lista);
                         }
                         printf("\n\n   Deseja excluir outro Usu�rio (S/N) ");
                         continua = getch();
                         fflush(stdin);
                     }
                 } while(continua == 'S' || continua == 's');
                 break;
}//switch 3
    case '4':{                                                                // Faz busca do usu�rio pelo nome

                    int i;
                    do{

                    cabecalho();
                    printf("\n       Buscar  por USU�RIO - NOME ");

                    if (vaziaLista(&lista)) {
                         printf("   \n\n  Cadastro vazio!!!\n\n");
                         system("pause");
                         continua = 'N';
                         break;

                     }



                    else{
                            printf("\n\nInforme o nome do usu�rio:");
                             fflush(stdin);
                            gets(usuario.nome);

                         for(i=0;i<=lista.tamanho-1;i++){
                                if(strcmp(lista.usuario[i].nome,usuario.nome)==0){

                                       printf("\n\t Usu�rio %s encontrado na lista!\n", usuario.nome);
                                       printf("\n\t Nome: %s \n E-mail: %s\n Telefone: %s",lista.usuario[i].nome,
                                        lista.usuario[i].telefone);

                                }

                         }
                         printf("\n\nUsu�rio NAO encontrado na lista!\n\n");


                    }
                    //imprimeLista(&lista);
                    printf("\nDeseja buscar outro USU�RIO?[S/N]");
                    continua = toupper(getch());
                    fflush(stdin);

                } while (continua == 'S');
                break;
system("cls");

    }//switch 4

    case '5':{

do {
                     cabecalho();
                     int i;
                     printf( "\t                    ::: Pesquisa de USU�RIO - TELEFONE :::\n\n" );
                     if (vaziaLista(&lista)) {
                         printf("     Cadastro vazio!!!\n\n");
                         system("pause");
                         continua = 'N';
                     }
                     else {

                         printf("\n   Informe o telefone que deseja encontrar: ");
                         scanf("%f",&usuario.telefone);
                         for(i = 0; i <=lista.tamanho-1; i++ ){
                            if(lista.usuario[i].telefone == usuario.telefone)
                            printf("\n\t Nome: %s \n E-mail: %s \n Endere�o: %s \n Telefone: %s",lista.usuario[i].nome,lista.usuario[i].endereco,
                                        lista.usuario[i].telefone);
                            
                                       else{
                                        printf("\n\t Usu�rio NAO encontrado na lista!\n");
                                       }


                         }
                         printf("\n\n   Deseja buscar outro usu�rio ? (S/N) ");
                         continua = toupper(getch());
                         fflush(stdin);
                     }
                 } while(continua == 'S');
                 break;

    }//switch 5
       
	   case '6':
        {
                    cabecalho();
                    printf("\n            Campo de divulga��o ");
                    if (vaziaLista(&lista)) {
                         printf("     \n\nCadastro vazio!!!\n\n");
                         system("pause");
                         continua = 'N';


                    }
                    else{
                    printf("\n\nInforme a mensagem:\t");
                    fflush(stdin);
                    scanf("%s",&mensagem);
                    printf("\n\nTodos os usu�rio cadastrados no sistema receber�o a mensagem. \nDeseja continuar? [S/N] !!!\n\n");
                         continua = toupper(getch());
                         if(continua =='S'){
						 
                    
                     printf("     \n\nMensagem enviada com SUCESSO.\n\n");
                         system("pause");
              
		}
		else {
			printf("Mensagem n�o enviada.");
		}
			
        }
    }
	   
	    case '0':
        case 'f':
        case 'F':
        {
          void cabecalho();
            printf ("\n\n    Programa ENCERRANDO ... Obrigado!!! \n\n");
            printf ("\t        Aperte qualquer tecla... \n");
            getch();
            break;
        }
        default:
        {
            printf ("\n\t\t Opcao invalida! ");
            printf ("\n\t\t\t Aperte qualquer tecla... \n \n");
            getch();
        }

    }//switch op
}while(op!='0' && op != 'f' && op !='F');
}

void cabecalho ()
{
    system("cls");
    printf("\n");
    printf(" |===========================================================================|\n");
    printf(" |  UPIS - Sistemas de Informacao                PE- Projeto Integrado       |\n");
    printf(" |  Alunos: Pedro Lucas Furtado/Pedro Henrique/ Eloy Duque                   |\n");
    printf(" |===========================================================================|\n");
}
//==============================================================================
void menu ()
{

    printf("\n\t     |                  DIVULGA��O EM MASSA              |");
    printf("\n\t     | = = = = = = = = MENU  PRINCIPAL = = = = = = = = = |");
    printf("\n\t     |             1 - Cadastrar Usu�rio                 |");
    printf("\n\t     |             2 - Modificar telefone do usu�rio     |");
    printf("\n\t     |             3 - Excluir Usu�rio                   |");
    printf("\n\t     |             4 - Pesquisar - NOME                  |");
    printf("\n\t     |             5 - Pesquiar - Telefone               |");
    printf("\n\t     |             6 - Inserir Mensagem                  |");
    printf("\n\t     |             0 - Encerrar aplicativo               |");
    printf("\n\t     | = = = = = = = = = = = = = = = = = = = = = = = = = |\n");
    printf("\n\t                       Escolha uma opcao: ");
}

