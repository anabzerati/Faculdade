 #primeiro exercício - imprimir hello world na tela
println("Hello World")


#segundo exercício - subprograma para cálculo de média entre dois números
function calculaMedia(num1, num2)
    result = (num1 + num2)/2
    return result
end

println(calculaMedia(5,8))


#terceiro exercício - if para checar se o número é par ou impar
function parOuImpar(num)
    result = mod(num, 2)
    if(result == 1)
      println("ímpar")
    else
      println("par")
    end
end

parOuImpar(10)
parOuImpar(123)


#quarto exercicio - laço e recursão para contar de um a dez
for i in 1:10
    println(i)
end

function contagem(n)
    if n ≤ 10
        println(n)
        contagem(n+1)
    end
end

contagem(1)