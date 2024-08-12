# Escapando da floresta da neblina

## Descrição do problema
O herói lendário Linque está perdido na floresta da neblina e precisa de sua ajuda para
escapar. A floresta está envolta por uma neblina mágica e quanto mais o tempo passa,
mais densa a neblina fica. Linque sabe que em pouco tempo a magia da neblina fará
com que ele fique perdido ali para sempre, mas ele já está muito cansado das batalhas
que travou. Sua única chance de sobrevivência é escapar da floresta antes que a exaustão
tome conta dele.
A floresta é composta por n clareiras e m trilhas que as conectam. As clareiras são nume-
radas de 0 até n − 1. As trilhas podem ser percorridas apenas em uma direção. Algumas
clareiras possuem portais, que as conectam por um caminho mágico de distância 0. Sem-
pre que Linque caminha por uma das trilhas, ele consome energia proporcional à distância
percorrida, o que significa que atravessar os portais não consome sua energia. No entanto
Linque já está cansado da viagem, possui apenas s de energia e pode utilizar os portais no
máximo k vezes. Sabemos que ele começa sempre na clareira 0 e a saída está na clareira
n − 1. Seu trabalho é decidir se Linque consegue escapar da floresta, dado que para isso
ele deve ser capaz de chegar na clareira n − 1 gastando no máximo s de energia e atra-
vessando no máximo k portais. Caso contrário ele ficará perdido na floresta para sempre...

## Algoritmos
Neste trabalho utilizaremos dois algoritmos. O primeiro é o algoritmo de Djikstra, um
algoritmo clássico da computação para encontrar caminhos mínimos em grafos que não
possuam arestas de peso negativo. Os detalhes do algoritmo e sua implementação estão
bem descritos no vídeo abaixo:
https://www.youtube.com/watch?v=Kue4UUxstoU&ab_channel=MaratonaUFMG
O segundo algoritmo a ser implementado é o A* (A-estrela). É importante que antes de
tentar entender este algoritmo você compreenda bem o Djikstra, uma vez que de certa
forma eles são bem semelhantes.
https://pt.wikipedia.org/wiki/Algoritmo_A*
Na implementação do A* você deve utilizar a distância euclidiana para o vértice de destino
como heurística.

## Entrada e saída
As instâncias serão lidas pela entrada padrão. A primeira linha consiste em três inteiros
n, m e k que representam, respectivamente, quantos vértices, trilhas e portais a floresta
possui. As próximas n linhas possuem dois números racionais x e y, descrevendo as coorde-
nadas de cada clareira em um plano. A seguir, as próximas m linhas possuem dois inteiros
u e v, indicando que existe uma trilha entre as duas clareiras, que só pode ser percorrida
começando em u e terminando em v. Por fim, as próximas k linhas possuem também dois
inteiros u e v, indicando quais clareiras são conectadas por portais (os portais também só
podem ser atravessados começando em u e terminando em v). A úlsubmetidotima linha
contém um número racional s indicando a quantidade de energia que Linque possui para
caminhar e um inteiro q indicando quantos portais podem ser utilizados.
A saída da execução de um algoritmo serão dois inteiros. O primeiro, utilizando o al-
goritmo Djikstra imprime 1 caso exista caminho de custo no máximo s e que cruze no
máximo q portais e 0 caso contrário. De forma análoga faça o mesmo para o algoritmo
A*.
