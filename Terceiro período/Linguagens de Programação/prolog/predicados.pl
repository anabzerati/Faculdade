progenitor(sara, isaque).
progenitor(abraao, isaque).
progenitor(abraao, ismael).
progenitor(isaque, esau).
progenitor(isaque, jaco).
progenitor(jaco, jose).

//regras
filho(X, Y) :- progenitor(Y, X).
avo(X, Y) :- progenitor(X, Z) , progenitor(Z, Y).
//para recursão
ancestral(X, Y) :- progenitor(X, Y).
ancestral(X, Y) :- progenitor(X, Z) , ancestral(Z, Y).

//perguntas
?- progenitor(isaque, esau). //responde yes ou no

?- progenitor(isaque, X). //ve de quem o isaque é pai

?- progenitor(isaque, _) //vê se tem algum filho (não importa quem)

?- progenitor(abraao, X) , progenitor(X, Y). //vê filho de abraão que também tem filho

?- avo(sara, X). //ve de quem a sara é avó