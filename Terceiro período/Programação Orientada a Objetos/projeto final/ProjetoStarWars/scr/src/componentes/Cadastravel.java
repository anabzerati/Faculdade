package componentes;

import java.io.Serializable;

/**
 * Classe abstrata que representa um objeto que pode ser cadastrado no sistema. Implementa a interface <code>Mapeavel</code>, o que permite a representação do objeto via mapa, e <code>Serializable</code>, para serialização e armazenamento.
 */
public abstract class Cadastravel implements Mapeavel, Serializable {
    private int coordenadaX;
    private int coordenadaY;
    private String descricaoLonga;
    private int numeros;
    private static final long serialVersionUID = 1234L;

    /**
     * Construtor da classe. Recebe como parâmetros os atributos do básicos para cadastro e realiza a atribuição.
     * @param coordenadaX coordenada X no mapa.
     * @param coordenadaY coordenada Y no mapa.
     * @param descricaoLonga decsrição sobre o objeto.
     * @param numeros quantidade de representantes.
     */
    public Cadastravel(int coordenadaX, int coordenadaY, String descricaoLonga, int numeros) {
        this.coordenadaX = coordenadaX;
        this.coordenadaY = coordenadaY;
        this.descricaoLonga = descricaoLonga;
        this.numeros = numeros;
    }

    /**
     * Método da interface de acesso à coordenada X cadastrada.
     * @return coordenada X.
     */
    @Override
    public int getCoordenadaX() {
        return coordenadaX;
    }

    /**
     * Método da interface de modificação da coordenada X cadastrada.
     * @param coordenadaX nova coordenada X.
     */
    @Override
    public void setCoordenadaX(int coordenadaX) {
        this.coordenadaX = coordenadaX;
    }

    /**
     * Método da interface de acesso à coordenada Y cadastrada.
     * @return coordenada Y.
     */
    @Override
    public int getCoordenadaY() {
        return coordenadaY;
    }

    /**
     * Método da interface de mdoficação da coordenada Y cadastrada.
     * @param coordenadaY nova coordenada Y.
     */
    @Override
    public void setCoordenadaY(int coordenadaY) {
        this.coordenadaY = coordenadaY;
    }

    /**
     * Método de acesso à descrição cadastrada.
     * @return String descrição cadastrada.
     */
    public String getDescricaoLonga() {
        return descricaoLonga;
    }

    /**
     * Método de modificação da descrição cadastrada.
     * @param descricaoLonga nova descrição.
     */
    public void setDescricaoLonga(String descricaoLonga) {
        this.descricaoLonga = descricaoLonga;
    }

    /**
     * Método de acesso do número cadastrado.
     * @return número cadastrado.
     */
    public int getNumeros() {
        return numeros;
    }

    /**
     * Método de modificação do número cadastrado.
     * @param numeros novo número.
     */
    public void setNumeros(int numeros) {
        this.numeros = numeros;
    }

    /**
     * Método abstrato que retorna o nome da classe.
     * @return String nome da classe.
     */
    public abstract String getNomeClasse();
}
