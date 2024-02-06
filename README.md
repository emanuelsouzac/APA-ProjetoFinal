# APA-ProjetoFinal

<<<<<< AVALIAÇÃO DE BRUNO >>>>>>

Talvez o projeto seja diferente, mas a lógica segue a mesma e os comentários podem ser aproveitados). Especificação desse projeto: https://www.dropbox.com/scl/fi/ebs6jue71mwabnnrmmbre/Projeto_Final.pdf?rlkey=is26y1kuq3qnubge534r3gx2y&dl=0

Segundo ele, o programa está conceitualmente certo. Ele deve gerar resultados no guloso, passar pelo VND para melhorar esse resultado e ir para o ILS com a intenção de causar alguma pertubação para tentar achar o melhor global.

No geral, um erro cometido foi o de fazer cópias. Ele não gosta de jeito nenhum, então sempre que possível as passagens de parâmetro devem ser por referência (caso a referência seja só para acessar valores, usar como const).

Ele preza muito por organização, então fazer um código limpo é importante. É preciso se atentar em cada detalhe e revisar o código a todo momento. Ele não gosta quando se cria uma variável desnecessária quando se pode usar recursos do próprio código (por exemplo, ao invés de ter usado o contVeiculos como parada nos fors, eu poderia ter usado rota.size()), ou quando se cria uma variável um pouco difícil de entender (como foi o caso da variável ref, no guloso, ou das variáveis A, B, x e y no vnd para salvar as informações para a troca) e também quando se repete uma estrutura desnecessária.

Uma outra coisa que ele gosta é passar o arquivo da instância como parâmetro na main. Assim, na chamada da execução do programa no terminal, passa nele qual instância você que usar. Não sei bem explicar como é isso, mas ele disse que é bem melhor e gosta quando faz.

O guloso poderia ter sido melhor implementado. Ao invés de já finalizar ao ver que o mais próximo não cabe na rota, tentar procurar o outro mais próximo que talvez caiba na rota. Uma outra ideia é, ao encontrar o mais próximo e ver que ele cabe na rota, analisar se vale a pena entregar ou deixar para terceirizar. Caso seja melhor terceirizar, não significa que deva ser feito isso automaticamente. Deixa em stand-by e terceiriza no final caso em nenhum momento entregar ele tenha sido melhor que terceirizar. Além disso, o guloso pode ser feito na main mesmo, não precisa de classe.

No VND, os erros estão nas cópias, na organização e em algumas ideias mal elaboradas. O VND em si tem que ser o mais limpo possível, façam as verificações de respeito às restrições dentro das estruturas de vizinhança, o VND só precisa chamar elas.

O ILS foi igual ao VND, erros nas cópias, organização e ideias mal elaboradas. Uma ideia que ele deu foi não estabelecer o mesmo número de repetições para todas as instâncias. Umas precisam de mais repetições do que outras. Ele sugeriu estabelecer um valor x que multiplica o número n de clientes e esse valor resultante é que será usado no while. Exemplo, caso x = 20:
n = 9 -> while(9x20)
n = 199 -> while(199x20)

Bruno é bem rigoroso e pergunta cada trecho do projeto. Tem que saber tudo do projeto (se possível nos mínimos detalhes), mesmo que não você não tenha feito aquela parte. A nota do projeto foi 8,5.

Coma bem antes e tome um bom café. A apresentação com ele demora bastante, no mínimo uma hora kkkkkkkkkkkkkk

Vídeo explicando o projeto: https://youtu.be/zqZFcEd4y2A
