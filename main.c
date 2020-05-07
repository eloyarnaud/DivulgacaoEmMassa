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

do{
    cabecalho();
    menu();
    op = getch();
    system("cls");

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
                printf("\n\nInforme o nome do usuário:");
                fflush(stdin);
                gets(usuario.nome);
                printf("\n|=========================================================|");
                printf("\n\nInforme o e-mail do usuário:");
                fflush(stdin);
                gets(usuario.email);
                printf("\n|=========================================================|");
             
                do
                {
                    printf("\n\nInforme o telefone do usuário:");
                    fflush(stdin);

                    scanf("%s",&usuario.telefone); 
                         if (strlen(usuario.telefone) != 11)
                    {
                        printf("\n\nPreencha o campo corretamente.");
                    }
                }while(strlen(usuario.telefone) != 11);
                
				insereLista(usuario,&lista,&codErro);
                imprimeLista(&lista);

                printf("\n\nDeseja continuar?[S/N]");
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
                    printf("\n            Alterar nota de Restaurante ");
                    if (vaziaLista(&lista)) {
                         printf("     \n\nCadastro vazio!!!\n\n");
                         system("pause");
                         continua = 'N';


                    }
                    else{
                            imprimeLista(&lista);
                    printf("\n\n\t Informe nome do restaurante: ");
                    fflush(stdin);
                    gets(usuario.nome);
                    posicao = buscaLista(usuario, &lista);
                    if(posicao == -1)
                        printf("\n\t\t Elemento %s NAO existente na lista!\n", usuario.nome);
                    else{
                        printf("\n\t\t Elemento %s encontrado na lista!\n", usuario.nome);
                        usuario = lista.usuario[posicao];
                       do{
                        printf("\n\t\tInforme a nova nota:");
                        scanf("%f",&usuario.telefone);
                            if (strlen(usuario.telefone) != 11)


                        printf("\n\nA nota tem que está entre 0 a 5.");

                       }  while(strlen(usuario.telefone) != 11); ;
                        lista.usuario[posicao] = usuario;

                    imprimeLista(&lista);
                    printf ("\nDeseja alterar nota de  outro restaurante?(S/N) ");
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
                     printf( "\t                    ::: Excluir Restaurante :::\n\n" );

                     if (vaziaLista(&lista)) {
                         printf("   \n\n  Cadastro vazio!!!\n\n");
                         system("pause");
                         continua = 'N';

                     }


                     else{
                         imprimeLista(&lista);
                         printf("\n   Informe nome do Restaurante a excluir: ");
                         fflush(stdin);
                         gets(usuario.nome);
                         excluiLista (usuario, &lista, &codErro);
                         if (codErro != 0){
                              printf("\n   Restaurante não existente no cadastro!!!");
                         }

                         else{
                        system("cls");
                         printf("\n   Exclusao realizada com sucesso!!!");
                         imprimeLista(&lista);
                         }
                         printf("\n\n   Deseja excluir outro Restaurante? (S/N) ");
                         continua = getch();
                         fflush(stdin);
                     }
                 } while(continua == 'S' || continua == 's');
                 break;
}//switch 3
    case '4':{

                    int i;
                    do{

                    cabecalho();
                    printf("\n       Buscar  por Tipo de Restaurante ");

                    if (vaziaLista(&lista)) {
                         printf("   \n\n  Cadastro vazio!!!\n\n");
                         system("pause");
                         continua = 'N';
                         break;

                     }



                    else{
                            printf("\n\nInforme o nome COMPLETO do usuário:");
                             fflush(stdin);
                            gets(usuario.nome);

                         for(i=0;i<=lista.tamanho-1;i++){
                                if(strcmp(lista.usuario[i].nome,usuario.nome)==0){

                                       printf("\n\t Elemento %s encontrado na lista!\n", usuario.nome);
                                       printf("\n\t Restaurante: %s \n Endereço %s \n Cozinha %s \n nota %s",lista.usuario[i].nome,lista.usuario[i].endereco,
                                        lista.usuario[i].telefone);

                                }

                         }


                    }
                    imprimeLista(&lista);
                    printf("\nDeseja buscar outro restaurante?");
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
                     printf( "\t                    ::: Nota do Restaurante :::\n\n" );
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
                                printf("\n Restaurante : %s \n endereco : %s \n Tipo de cozinha : %s  \n nota : %s \n" ,lista.usuario[i].nome, lista.usuario[i].endereco,
                                       lista.usuario[i].telefone );

                                       else{
                                        printf("\n\t Elemento NAO encontrado na lista!\n");
                                       }


                         }
                         printf("\n\n   Deseja buscar outro usuário ? (S/N) ");
                         continua = toupper(getch());
                         fflush(stdin);
                     }
                 } while(continua == 'S');
                 break;

    }//switch 5
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
    printf(" |  UPIS - Sistemas de Informacao                PE- Projeto Integrado |\n");
    printf(" |  Alunos: Pedro Lucas Furtado/Pedro Henrique/ Eloy Duque              |\n");
    printf(" |===========================================================================|\n");
}
//==============================================================================
void menu ()
{

    printf("\n\t     |                  Divulgação em Massa              |");
    printf("\n\t     | = = = = = = = = MENU  PRINCIPAL = = = = = = = = = |");
    printf("\n\t     |             1 - Cadastrar Usuário                 |");
    printf("\n\t     |             2 - Modificar telefone do usuário     |");
    printf("\n\t     |             3 - Excluir Usuário                   |");
    printf("\n\t     |             4 - Listar  por tipo                  |");//restaurante
    printf("\n\t     |             5 - Listar usuário por telefone       |");
    printf("\n\t     |             0 - Encerrar aplicativo               |");
    printf("\n\t     | = = = = = = = = = = = = = = = = = = = = = = = = = |\n");
    printf("\n\t                       Escolha uma opcao: ");
}

