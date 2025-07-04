#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 

int main(int argc, char const *argv[])
{
    char palavra_secreta[20], letras_erradas[20], forca[20], tentativa;
    int errou_letra = 0;

    printf("Jogador 1:\n");
    printf("Digite a palavra secreta: \n");
    scanf("%s", palavra_secreta);

    const int TAMANHO = strlen(palavra_secreta);

    for (int i = 0; i < TAMANHO; i++)
    {
        palavra_secreta[i] = tolower(palavra_secreta[i]);
    }

    system("cls");

    for (int i = 0; i < TAMANHO; i++)
    {
        forca[i] = '_';
    }

    forca[TAMANHO] = '\0';

    do
    {
        system("cls");

        if (errou_letra == TAMANHO)
        {
            break;
        }
        else
        {
            int acertou = 0;
            int ja_tentou = 0;

            printf("\t\t\t\t\t\tJogo da Forca !!! \n\n\n");

            printf("\t\t\t\t\t\t");
            for (int i = 0; i < TAMANHO; i++)
            {
                printf("%c ", forca[i]);
            }

            printf("\n\n\n letras erradas ja tentadas:  ");
            letras_erradas[errou_letra] = '\0';
            for (int i = 0; i < errou_letra; i++)
            {
                printf(" %c", letras_erradas[i]);
            }

            printf("\n\n ______________________________________________________________________________________________________________");

            int letras_faltando = 0;
            for (int i = 0; i < TAMANHO; i++)
            {
                if (forca[i] == '_')
                    letras_faltando++;
            }

            if (letras_faltando <= 3)
            {
                char chute[20];
                printf("\n\n\nFaltam apenas %d letras! Deseja chutar a palavra inteira? (s/n): ", letras_faltando);
                char opcao;
                scanf(" %c", &opcao);
                opcao = tolower(opcao);

                if (opcao == 's')
                {
                    printf("Digite seu chute: ");
                    scanf("%s", chute);

                    for (int i = 0; chute[i] != '\0'; i++)
                    {
                        chute[i] = tolower(chute[i]);
                    }

                    if (strcmp(chute, palavra_secreta) == 0)
                    {
                        strcpy(forca, palavra_secreta);
                        break;
                    }
                    else
                    {
                        printf("Voce errou o chute!\n");
                        system("pause");
                    }
                }
            }

            printf("\n\nJogador 2:\n");
            printf("Digite uma letra para tentar advinhar a palavra:\n");
            scanf(" %c", &tentativa);
            if (!isalpha(tentativa)) {
                printf("Por favor, digite apenas letras (A-Z ou a-z)!\n");
                system("pause");
                continue;
            }
            tentativa = tolower(tentativa);

            for (int i = 0; i < TAMANHO; i++)
            {
                if (tentativa == forca[i])
                {
                    ja_tentou = 1;
                    break;
                }
            }

            for (int i = 0; i < errou_letra && !ja_tentou; i++)
            {
                if (tentativa == letras_erradas[i])
                {
                    ja_tentou = 1;
                    break;
                }
            }

            if (ja_tentou)
            {
                printf("Voce ja tentou essa letra!\n");
                system("pause");
            }
            else
            {
                for (int i = 0; i < TAMANHO; i++)
                {
                    if (tentativa == palavra_secreta[i])
                    {
                        forca[i] = tentativa;
                        acertou = 1;
                    }
                }

                if (acertou)
                {
                    printf("Voce acertou a letra\n\n");
                }
                else
                {
                    letras_erradas[errou_letra] = tentativa;
                    errou_letra++;
                    printf("Voce errou a letra\n\n");
                }

                system("pause");
            }
        }

    } while (strcmp(forca, palavra_secreta) != 0);

    system("cls");
    printf("\n\nParabens! A palavra era: %s\n", palavra_secreta);

    return 0;
}