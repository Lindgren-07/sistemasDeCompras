
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cliente {
  char nome[100];
  char sexo;
  int idade;
};
typedef struct cliente cliente;

struct compra {
  cliente clienteInfo;
  int qtdItens;
  float totalCompra;
  char fim[100];
};
typedef struct compra compra;


int main(void) {
  FILE *arquivo;

  char resposta;
  int opcao = 0, qtdCompras = 0;
  char nomecli[30];
  char linhas[100];
  float valorTotal = 0;
  float valorAcima = 0;
  int qtd = 0;
  int comprasUm = 0;
  int homi = 0;
  float totalMuie = 0;
  char fim1[30];

  compra *compras;
  compra *comprasNomecli;
  compra *comprasMaiorNome;
  compra *comprasMaisNovo;
  compra *comprasRegistradas;
  compra *comprasRegistradas2;

  int encontrado = 0;

  int qtdTotalCompras = 0;
  int qtdTotalCompras2 = 0;

  int qtdItensNomecli = 0;
  float somaValoresNomecli = 0;
  float mediaValoresNomecli = 0;

  int qtdMaiorNome = 0;
  int qtdMaisNovo = 0;

  char nomes[100][100];
  char sexos[100];
  int idades[100];
  int qtdItens[100];
  float totalCompras[100];
  char fim[100][100];
  int contItens = 0;
  int contCompras = 0;
  float totalValorCompras = 0;
  int maiorNome = 0;
  int tam = 0;
  int indice = 0;
  int idadeMenor = 0;
  int indiceMenor = 0;
  float mediaCompras;


  compras = (compra *)malloc(qtdTotalCompras2 * sizeof(compra));

  do {
    printf("\033[0;35m----------------------------MENU-PRINCIPAL-----------"
           "----------"
           "--------\033[0m");
    printf("\n1. Cadastrar novas compras");
    printf("\n2. Ver informações de uma compra específica, baseado no nome do "
           "cliente");
    printf("\n3. Ver informações de todas as compras");
    printf("\n4. Encerrar o programa");
    printf("\033[0;35m\n-------------------------------------------------------"
           "----------"
           "------\033[0m");
    printf("\nEscolha uma opção: ");
    scanf("%i", &opcao);

    system("cls");

    switch (opcao) {
    case 1:
      do {
        resposta = ' ';
        printf("Opção 1 escolhida.");
        printf("\nDigite a quantidade de compras a cadastrar: ");
        scanf("%i", &qtdCompras);
        while (qtdCompras <= 0) {

          printf("\033[1;31mErro: valor da quantidade de compras deve ser positivo\033[0m");
          printf("\nDigite a quantidade de compras a cadastrar: ");
          scanf("%i", &qtdCompras);
        }

        compra *compras2 = (compra *)realloc(compras, (qtdTotalCompras2 + qtdCompras) * sizeof(compra));
        if(compras2 == NULL){
          printf("\033[1;31mErro na alocação de memória\033[0m");
          free(compras);
          return 1;
        }
        else {
            compras = compras2; // atualiza ptr com o novo ponteiro retornado por realloc
        }

        for (int i = 0; i < qtdCompras; i++) {
          printf("\n\nCompra %i:\n", i + 1);

          do {
            printf("Digite o nome do cliente: ");
            scanf("%s", compras[i].clienteInfo.nome);

            if (strlen(compras[i].clienteInfo.nome) < 3) {
              printf("\033[1;31mErro: o nome do cliente deve possuir 3 ou mais letras! Tente novamente.\n\n\033[0m");
              continue;
            }
          } while (strlen(compras[i].clienteInfo.nome) < 3);

          do {
            printf("Digite o sexo do cliente ('f' ou 'm'): ");
            scanf(" %c", &compras[i].clienteInfo.sexo);

            if (compras[i].clienteInfo.sexo != 'm' &&
                compras[i].clienteInfo.sexo != 'f') {
              printf(
                  "\033[1;31mErro: sexo inválido! Tente novamente.\n\n\033[0m");
            }
          } while (compras[i].clienteInfo.sexo != 'm' &&
                   compras[i].clienteInfo.sexo != 'f');

          do {
            printf("Digite a idade do cliente: ");
            scanf("%i", &compras[i].clienteInfo.idade);

            if (compras[i].clienteInfo.idade < 0) {
              printf("\033[1;31mErro: a idade não pode ser um número "
                     "negativo.\n\n\033[0m");
            }
           

          } while (compras[i].clienteInfo.idade < 0);

          do {
            printf("Digite a quantidade de itens da compra: ");
            scanf("%i", &compras[i].qtdItens);

            if (compras[i].qtdItens <= 0) {
              printf("\033[1;31mErro: o número de itens deve ser positivo! "
                     "Tente novamente.\n\n\033[0m");
            }
          } while (compras[i].qtdItens <= 0);

          do {
            printf("Digite o valor total da compra: ");
            scanf("%f", &compras[i].totalCompra);

            if (compras[i].totalCompra <= 0) {
              printf("\033[1;31mErro: o valor total da compra deve ser "
                     "positivo! Tente novamente.\n\n\033[0m");
            }
          } while (compras[i].totalCompra <= 0);

          arquivo =
              fopen("registros.txt", "a");
          if (arquivo == NULL) {
            printf("\033[1;31m\nNão foi possível abrir o arquivo.\n\033[0m");
            return 1; 
          }
          rewind(arquivo);

          printf("\033[1;32m\nCadastrado com sucesso!\033[0m\n");
          qtdTotalCompras2++;

          fprintf(arquivo, "%s\n", compras[i].clienteInfo.nome);
          fprintf(arquivo, "%c\n", compras[i].clienteInfo.sexo);
          fprintf(arquivo, "%d\n", compras[i].clienteInfo.idade);
          fprintf(arquivo, "%i\n", compras[i].qtdItens);
          fprintf(arquivo, "%.2f\n", compras[i].totalCompra);
          fprintf(arquivo, "fim\n\n");

          fclose(arquivo);





        }

        do {
          printf("\n\nDigite 's' para cadastrar mais itens ou 'v' para voltar ao menu: ");
          scanf(" %c", &resposta);

          if(resposta!='s' && resposta!='v') {
            printf("\033[1;31mErro: Opção inválida! Tente novamente.\033[0m");
          }
        } while(resposta!='s' && resposta!='v');

        system("cls");

      } while (resposta == 's');

      break;

    case 2:

      do {

        resposta = ' ';
        qtdTotalCompras = 0;
        encontrado = 0;

        printf("Opção 2 escolhida.\n");

        printf("Digite o nome do cliente: ");
        scanf("%s", nomecli);

        arquivo = fopen("registros.txt", "r");
        if(arquivo == NULL){
          printf("\033[1;31m\nNão foi possível abrir o arquivo.\n\033[0m");
          return 0;
        }

        while(fgets(linhas,sizeof(linhas),arquivo) != NULL){
          char *token = strtok(linhas, " \t\n");

              while(token != NULL){
                if(strcmp(token,"fim")==0){
                  qtdTotalCompras++;  
                } 
                if(strcmp(token,nomecli)==0){
                  encontrado++;
                }  

                token = strtok(NULL, " \t\n");
              }          

        }

       

        fclose(arquivo);

        if(encontrado == 0) {
          printf("\033[1;31mErro: nome não encontrado!\033[0m");
        }
        else {

          compra *comprasRegistradas = (compra *)malloc(qtdTotalCompras * sizeof(compra));

          int i = 0;
          arquivo = fopen("registros.txt", "r");
          rewind(arquivo);

          while(fscanf(arquivo, "%s %c %d %d %f %s", comprasRegistradas[i].clienteInfo.nome, &comprasRegistradas[i].clienteInfo.sexo, &comprasRegistradas[i].clienteInfo.idade, &comprasRegistradas[i].qtdItens, &comprasRegistradas[i].totalCompra, comprasRegistradas[i].fim) != EOF){
            i++; 
          }
          fclose(arquivo);


          comprasNomecli = (compra *)malloc(encontrado * sizeof(compra));

          if(comprasNomecli == NULL){
            printf("\033[1;31m\nNão foi possível alocar memória.\n\033[0m");
            return 1;
          }

            int index1=0;
            qtdItensNomecli = 0;
            somaValoresNomecli = 0;
            mediaValoresNomecli = 0;

            for(int i = 0; i < qtdTotalCompras; i++) {

                  
              if(strcmp(comprasRegistradas[i].clienteInfo.nome,nomecli)==0) {
                comprasNomecli[index1] = comprasRegistradas[i];

                qtdItensNomecli = qtdItensNomecli + comprasRegistradas[i].qtdItens;
                  somaValoresNomecli = somaValoresNomecli + comprasRegistradas[i].totalCompra;   

                index1++;
              
              }

            }

          mediaValoresNomecli = somaValoresNomecli / qtdItensNomecli; 

          for (int i = 0; i < encontrado; i++) {
            printf("\033[0;35m\nInformações da compra %d:\033[0m", i + 1);
            printf("\nQuantidades de itens comprados: %d", comprasNomecli[i].qtdItens);
            printf("\nValor total da compra:R$ %.2f\n", comprasNomecli[i].totalCompra);
          }
          printf("\033[0;35m\nMédia de valor dos itens comprados pelo cliente:\033[0m %.2f", mediaValoresNomecli);
          }


        do {
          printf("\n\nDigite 'b' para pesquisar outro nome ou 'v' para voltar ao menu: ");
          scanf(" %c", &resposta);

          if(resposta!='b' && resposta!='v') {
            printf("\033[1;31mErro: Opção inválida! Tente novamente.\033[0m");
          }

        } while(resposta !='b' && resposta != 'v');         

        system("cls");

      } while (resposta == 'b');

      break;

    case 3:
      printf("Opção 3 escolhida.\n");


      qtdTotalCompras = 0;

      arquivo = fopen("registros.txt", "r");
      if(arquivo == NULL){
        printf("\033[1;31m\nNão foi possível abrir o arquivo.\n\033[0m");
        return 0;
      }
      rewind(arquivo);

      while(fgets(linhas,sizeof(linhas),arquivo) != NULL){
        char *token = strtok(linhas, " \t\n");

            while(token != NULL){
              if(strcmp(token,"fim")==0){
                qtdTotalCompras++; 
                
              }  
              token = strtok(NULL, " \t\n");
            }          

      }
      fclose(arquivo);

      compra *comprasRegistradas2 = (compra *)malloc(qtdTotalCompras * sizeof(compra));
      if(comprasRegistradas2 == NULL){
        printf("\033[1;31m\nNão foi possível alocar memória.\n\033[0m");
        return 1;
      }

      int j = 0;
      arquivo = fopen("registros.txt", "r");
      rewind(arquivo);

      while(fscanf(arquivo, "%s %c %d %d %f %s", comprasRegistradas2[j].clienteInfo.nome, &comprasRegistradas2[j].clienteInfo.sexo, &comprasRegistradas2[j].clienteInfo.idade, &comprasRegistradas2[j].qtdItens, &comprasRegistradas2[j].totalCompra, comprasRegistradas2[j].fim) != EOF){
        j++; 
      }
      fclose(arquivo);







      arquivo = fopen("registros.txt", "r");
      if (arquivo == NULL) {
        printf("\033[1;31mErro: Não foi possível abrir o arquivo!\033[0m");
        return 0;
      }
      rewind(arquivo);



      printf("\nDigite um valor: ");
      scanf("%f", &valorAcima);
      printf("\n");

     
      int i = 0;
      int nomeExistente = 0;
      while (fscanf(arquivo, "%s %c %d %d %f %s", nomes[i], &sexos[i], &idades[i], &qtdItens[i], &totalCompras[i], fim[i]) != EOF) {

        nomeExistente = 0;
        for (int j = 0; j <= i; j++) {
          if (strcmp(comprasRegistradas2[j].clienteInfo.nome, nomes[i]) == 0) {
            nomeExistente++;
          }
        }

     

        if (nomeExistente==1) {
          if (sexos[i]== 'm') {
            homi++;
          }
        }



        if (totalCompras[i] > valorAcima) {
          qtd++;
        }
        if (qtdItens[i] == 1) {
          comprasUm++;
        }

        if (sexos[i] == 'f') {
          totalMuie += totalCompras[i];
        }

        contItens += qtdItens[i];
        contCompras++;
        totalValorCompras += totalCompras[i];

        tam = strlen(nomes[i]);
        if (tam > maiorNome) {
          maiorNome = tam;
          indice = i;
        }

        if (idadeMenor == 0) {
          idadeMenor = idades[i];
        } 
        else if (idades[i] < idadeMenor) {
          idadeMenor = idades[i];
          indiceMenor = i;
        }

        i++;
      }

      fclose(arquivo);

      mediaCompras = totalValorCompras / contCompras;

      printf("\033[0;35m\nDados gerais:\n\033[0m");
      printf("Número de compras acima do valor especificado: %d\n", qtd);
      printf("Número de compras com apenas 1 item: %d\n", comprasUm);
      printf("Número de compradores homens: %d\n", homi);
      printf("Valor total comprado pelas mulheres: %.2f\n", totalMuie);
      printf("Número total de itens vendidos: %d\n", contItens);
      printf("Número total de compras: %d\n", contCompras);
      printf("Valor total de compras:R$ %.2f\n", totalValorCompras);
      printf("Valor médio de uma compra: %.2f\n", mediaCompras);

      printf("\n");
      if (indice < 0 || indice <= -1) {
        printf("\033[1;31mErro: não foi possível achar algum nome\033[0m");
      } else {




       

        arquivo = fopen("registros.txt", "r");
        if(arquivo == NULL){
          printf("\033[1;31m\nNão foi possível abrir o arquivo.\n\033[0m");
          return 0;
        }
        rewind(arquivo);

        while(fgets(linhas,sizeof(linhas),arquivo) != NULL){
          char *token = strtok(linhas, " \t\n");

              while(token != NULL){
                if(strcmp(token,nomes[indice])==0){
                  qtdMaiorNome++; 
                  
                }  
                token = strtok(NULL, " \t\n");
              }          

        }
        fclose(arquivo);

        comprasMaiorNome = (compra *)malloc(qtdMaiorNome * sizeof(compra));

        if(comprasMaiorNome == NULL){
          printf("\033[1;31m\nNão foi possível alocar memória.\n\033[0m");
          return 1;
        }

          int index2=0;

          for(int i = 0; i < qtdTotalCompras; i++) {

                   
            if(strcmp(comprasRegistradas2[i].clienteInfo.nome,nomes[indice])==0) {
                comprasMaiorNome[index2] = comprasRegistradas2[i];

              index2++;
              
            }

          }

        printf("\033[0;35m\nDados do cliente de maior nome:\033[0m");
        printf("\n");
        for (int i = 0; i < qtdMaiorNome; i++) {
          if (i==0) {
            printf("\nNome: %s", comprasMaiorNome[i].clienteInfo.nome);
            printf("\nSexo: %c", comprasMaiorNome[i].clienteInfo.sexo);
            printf("\n\n");
          }
          printf("\033[0;36mInformações da compra %d:\033[0m", i + 1);
          printf("\nQuantidades de itens comprados: %d", comprasMaiorNome[i].qtdItens);
          printf("\nValor total da compra:R$ %.2f\n", comprasMaiorNome[i].totalCompra);
          printf("\n");
        }





    

      if (indiceMenor < 0 || indiceMenor <= -1) {
        printf("\033[1;31mErro: pessoa mais nova não encontrada!\033[0m");
      } else {

        arquivo = fopen("registros.txt", "r");
          if(arquivo == NULL){
            printf("\033[1;31m\nNão foi possível abrir o arquivo.\n\033[0m");
            return 0;
          }
          rewind(arquivo);

          while(fgets(linhas,sizeof(linhas),arquivo) != NULL){
            char *token = strtok(linhas, " \t\n");

                while(token != NULL){
                  if(strcmp(token,nomes[indiceMenor])==0){
                    qtdMaisNovo++; 
                    
                  }  
                  token = strtok(NULL, " \t\n");
                }          

          }
          fclose(arquivo);

          comprasMaisNovo = (compra *)malloc(qtdMaisNovo * sizeof(compra));

          if(comprasMaisNovo == NULL){
            printf("\033[1;31m\nNão foi possível alocar memória.\n\033[0m");
            return 1;
          }

            int index2=0;

            for(int i = 0; i < qtdTotalCompras; i++) {

                  
              if(strcmp(comprasRegistradas2[i].clienteInfo.nome,nomes[indiceMenor])==0) {
                    comprasMaisNovo[index2] = comprasRegistradas2[i];

                index2++;
               
              }

            }

          printf("\033[0;35m\nDados do cliente mais novo:\033[0m");
          printf("\n");
          for (int i = 0; i < qtdMaisNovo; i++) {
            if (i==0) {
              printf("\nNome: %s", comprasMaisNovo[i].clienteInfo.nome);
              printf("\nSexo: %c", comprasMaisNovo[i].clienteInfo.sexo);
              printf("\n\n");
            }
            printf("\033[0;36mInformações da compra %d:\033[0m", i + 1);
            printf("\nQuantidades de itens comprados: %d", comprasMaisNovo[i].qtdItens);
            printf("\nValor total da compra:R$ %.2f\n", comprasMaisNovo[i].totalCompra);
            printf("\n");
          }

      }
    }

     

      do {
        printf("\nDigite 'v' para voltar ao menu principal ou 'x' para encerrar o programa: ");
        scanf(" %c", &resposta);

        if(resposta!='v' && resposta!='x') {
          printf("\033[1;31mErro: Opção inválida! Tente novamente.\033[0m");
        }
      } while(resposta!='v' && resposta!='x');


      if(resposta=='x') {
        system("cls");
        printf("Encerrando o programa...");
        break;
      }

      system("cls");

      break;

    case 4:
      printf("Opção 4 escolhida. Encerrando o programa...");
      break;

    default:
      printf("\033[1;31m\nErro: Opção inválida! Tente novamente.\033[0m\n");
      break;
    }


  } while (opcao != 4 && resposta != 'x');

  printf("\nPrograma encerrado.\n");

  free(comprasMaiorNome);
  free(comprasRegistradas2);
  free(comprasRegistradas);
  free(comprasNomecli);
  free(compras);


  return 0;
}   
