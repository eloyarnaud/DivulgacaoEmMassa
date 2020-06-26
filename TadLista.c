#define MAX 10
// Estrutura de Dados oara ALUNO
typedef struct {
    char  nome[30],email[300],telefone[11],endereco[50];
    
}Usuario;

//Estrutura de Dados da LISTA

typedef struct {
        Usuario usuario [MAX];
        int  tamanho;
}Lista;

// ============= CÓDIGOS DE ERRO DEFINIDOS NO TAD LISTA ========================
//     erro = 10 --> LISTA VAZIA (underflow de memória no arranjo)
//     erro = 20 --> Lista Cheia (overflow de memória no arranjo)
//     erro = 30 --> Aluno não encontrado
// =============================================================================

// ======================== OPERAÇÕES DO TAD LISTA =============================
// ===== criaLista =============================================================
void criaLista (Lista *lst)
{
   lst->tamanho  =  0;
}
// ===== vaziaLista ============================================================
int vaziaLista (Lista *lst)
{
    return (lst->tamanho == 0);
}
// ===== cheiaLista ============================================================
int cheiaLista (Lista *lst)
{
    return (lst->tamanho >= MAX);
}
// ===== insereLista ===========================================================
void insereLista (Usuario a, Lista *lst, int *codErro)
/*  Insere Aluno, passado pelo parâmetro a, no final da Lista  */
/*  No caso de overflow do Arranjo, retorna código de erro adequado */
{
      *codErro = 0;
      if (cheiaLista(lst)) {
          *codErro = 20;   // overflow de memória no arranjo
          return;
      }
      lst->usuario[lst->tamanho] = a;
      lst->tamanho++;
}
// ===== buxcaLista ============================================================
int buscaLista(Usuario a, Lista *lst)
//     Pesquisa (pelo nome) se Aluno a está na Lista e retorna sua posição
//     Caso não encontre, retorna -1
{
   int  pos = 0;
   while (pos < lst->tamanho) {
      if (strcmp(lst->usuario[pos].nome, a.nome)==0)
          return(pos);
      else pos++;
   }
   return(-1) ;
}
// ===== excluiLista ===========================================================
void excluiLista(Usuario a, Lista *lst, int *codErro)
/*  Pesquisa o Aluno a e o exclui da Lista;
      Se Lista Vazia, retorna codErro adequado;
      Se Aluno não encontrado, retorna codErro adequado    */
{
   *codErro = 0;
   int i, j;
   if (vaziaLista (lst)) {
      *codErro = 10;   //   Lista vazia!
      return;
   }
   i = buscaLista(a, lst);
   if  (i == -1) {
        *codErro = 30;  //  Restaurante não encontrado!!!
        return;
   }
   for (j = i+1; j <= lst->tamanho; j++)  //  “Tapa buraco” !!!
        lst->usuario[j-1] = lst->usuario[j];
   lst->tamanho--;
}
// ===== imprimeLista ==========================================================
void imprimeLista(Lista *lst)
{
    int i;
    for(i = 0; i <= lst->tamanho-1; i++){
       printf("\n\n%dº Usuário: \n\nNome: %s \n E-mail: %s   \n Telefone = %s",
               i+1, lst->usuario[i].nome, lst->usuario[i].email,lst->usuario[i].telefone);
    }
    
    printf("\n\n");
}


