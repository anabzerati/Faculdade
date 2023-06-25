% base de dados
progenitor(pamela, bob).
progenitor(pamela, sam).
progenitor(tom, bob).
progenitor(tom, sam).
progenitor(tom, liz).
progenitor(bob, ana).
progenitor(bob, patricia).
progenitor(patricia, jim).

male(bob).
male(sam).
male(jim).
male(tom).

female(pamela).
female(liz).
female(ana).
female(patricia).

% regras 
pai(X, Y) :- progenitor(X,Y), male(X). % só é pai se for progenitor e homem.
mae(X, Y) :- progenitor(X,Y), female(X). % só é mãe se for progenitor e mulher

avo(X,Y) :- progenitor(X,Z) , progenitor(Z,Y). % é avô/avó se for progenitor do progenitor
netas(X, Y) :- avo(Y,X) , female(X). % X é neta de Y se Y for avô de X e X for mulher

irmaos(X,Y) :- progenitor(Z, X) , progenitor(Z, Y), X \= Y.  % são irmãos se tiverem o mesmo progenitor (X != Y)

ancestral(X,Z) :- progenitor(X, Z).   % condição de parada - é ancestral se for progenitor
ancestral(X,Z) :- progenitor(X,Y),  ancestral(Y,Z).  % recursão - vai verificando se há uma ligação de progenitores entre X e Z

ancestralFeminino(X,Z) :- mae(X,Z).   % condição de parada - é ancestral feminino se for progenitor e mulher (mãe)
ancestralFeminino(X,Z) :- progenitor(X,Y), female(X),  ancestral(Y,Z).  % recursão - vai verificando se há uma ligação de progenitores entre X e Z

ancestralMasculino(X,Z) :- pai(X, Z).   % condição de parada - é ancestral feminino se for progenitor e homem (pai)
ancestralMasculino(X,Z) :- progenitor(X,Y),  male(X), ancestral(Y,Z).  % recursão - vai verificando se há uma ligação de progenitores entre X e Z