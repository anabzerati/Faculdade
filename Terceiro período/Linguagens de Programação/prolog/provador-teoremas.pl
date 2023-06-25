/**
% proposições - todas verdades
1 - p
2 - (p ^ q) -> r
3 - (s v t) -> q
4- t
**/


/**
% simplificando
1-  p % se mantém

2 - (p ^ q) -> r == ~(p^q) v r == (~p v ~q) v r

3- (s v t) -> q == ~(s v t) v q == (~s ^~t) v q == (~s v q) ^ (~t v q) % proposições quebradas não podem ter AND, quebramos em 3.1 (~s v q) e 3.2 (~t v q)

4- t % se mantém
**/

/*
Exercício: provar que R é verdadeiro
Abordagem: prova por contradição. Adicionar ~r na base de fatos.
Agora a base é:
1 -  p
2 - (~p v ~q) v r
3.1 - (~s v q) 
3.2 - (~t v q) 
4 - t
5 - ~r

% começando pela última proposição

Combinando 5 com 2: ~r ^ (~p v ~q) v r == ~r ^ r v (~p v ~q) == ~p v ~q % ~r e r se cancelam
Combinando com 3.2: (~p v ~q) ^ (~t v q) == ~p v ~t  % q e ~q se cancelam
Combinando com 4: ~p v ~t ^ t == ~p
Combinando com 1: p ^ ~p == 0 == falso

A base que era verdadeira retornou falso -> há um erro -> o erro foi adicionar ~r -> r é verdadeiro

*/
