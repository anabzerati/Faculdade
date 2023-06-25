ultimo(X, [X]). % X é o ultimo da lista se a lista só tiver ele como elemento (condição de saída)
ultimo(X, [H|T]) :- ultimo(X, T). % quebra a lista nas caudas (tira a cabeça) e chama a regra 1 novamente


penultimo(Y, [Y,X]). % Y é o penúltimo elemento de uma lista se a lista só tiver dois elementos e Y não for o último
penultimo(X, [H|T]) :- penultimo(X, T). % "tira" a cabeça da lista e verifica a cauda (recursivamente diminui a lista até dois elementos)