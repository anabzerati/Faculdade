package componentes;

/**
 * Classe abstrata que representa uma ameaça aos rebeldes. Estende <code>Cadastravel</code> para permitir cadastro no sistema e representação no mapa.
 */
public abstract class Ameaca extends Cadastravel {
    private String gravidade;

    /**
     * Construtor da classe. Recebe características comuns a todas as ameaças e atribui aos atributos.
     * @param coordenadaX coordenada X no mapa.
     * @param coordenadaY coordenada Y no mapa.
     * @param descricaoLonga descrição da ameaça.
     * @param numeros quantidade de representantes da ameaça.
     * @param gravidade gravidade da ameaça.
     */
    public Ameaca(int coordenadaX, int coordenadaY, String descricaoLonga, int numeros, String gravidade) {
        super(coordenadaX, coordenadaY, descricaoLonga, numeros);
        this.gravidade = gravidade;
    }

    /**
     * Método de acesso à gravidade da ameaça.
     * @return String gravidade.
     */
    public String getGravidade() {
        return gravidade;
    }

    /**
     * Método para modificação da gravidade da ameaça.
     * @param gravidade nova gravidade da ameaça.
     */
    public void setGravidade(String gravidade) {
        this.gravidade = gravidade;
    }
}
