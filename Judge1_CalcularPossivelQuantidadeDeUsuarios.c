/*
Descrição do problema

Para estimar o ritmo de crescimento da sua base de usuários, um jovem empreendedor precisa de uma
ferramenta computacional que o ajude a testar várias hipóteses baseadas em modelos de crescimento da rede. Um
possível modelo mais simples e conservador poderia se basear no histórico recente de adoção do produto para
estimar o nível de adoção dos próximos dias. Nesse modelo, o número de novos usuários em um dado dia é
sempre igual ao teto da média de novos usuários nos últimos 30 dias.

Você deve escrever um programa que implemente um algoritmo que determine, baseado no modelo
descrito anteriormente, em quantos dias seria possível alcançar um dado número de usuários na rede do novo
produto a ser lançado. Considerando que o programa será utilizado para testar vários cenários, é esperado que o
seu programa seja eficiente em retornar a estimativa rapidamente.
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    //variaveis
    int inicial, alcancada, array[30], arredondado;
    double aux;
    
    //contadores
    int i, dias = 0; 
    double somatorio = 0;

    //entrada da quantidade inicial de usuarios e a quantidade que deseja ser alcançada
    scanf("%d %d", &inicial, &alcancada);

    //ultimos 30 dias de usuarios
    for(i = 0; i < 30; i++){
        scanf("%d", &array[i]);
        somatorio += array[i];
    }


    for (i = 0; i < 30; i++)
    {
        //guarda o teto da media de usuarios dos ultimos 30 dias
        aux = somatorio/30.0;
        arredondado = ceil(aux);
        //acrescenta a media como se fosse a quantidade de usuarios novos que entraram no dia após os 30 dias
        inicial += arredondado;

        //retira o primeiro dia dos ultimos 30 dias e acrescenta a quantidade que entrou no dia de hoje
        somatorio -= array[i];
        somatorio += arredondado;

        //muda o primeiro dia mes para a quantidade que entrou hoje
        array[i] = arredondado;
        //conta os dias necessários até ser alcançada a quantidade desejada
        dias++;

        //verifica se ja bateu a quantidade de usuarios
        if(inicial >= alcancada){
            break;
        } else {
            //se nao bateu e acabou os 30 dias, começa o for novamente
            if(i == 29)
            {
                i = -1;
            }
        }
    }

    printf("%d\n", dias);
}