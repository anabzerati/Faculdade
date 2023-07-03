package componentes;

/**
 * Classe que representa um evento de Combate. Estende <code>Ameaca</code> por representar uma ameaça aos rebeldes e possui atributos próprios específicos, como o tipo de carga recebida e
 * seu peso.
 */
public class Recebimento extends Ameaca {
    private String carga;
    private double peso;
    private final String caminhoImagem;
    private final String descricaoCurta;

    /**
     * Construtor da classe. Recebe como parâmetros os atributos do objeto e realiza a atribuição. Acrescenta o caminho do ícone que representa a classe e a descrição da ameaça, atributos constantes
     * compartilhados por todas as instancias da classe.
     * @param coordenadaX coordenada X no mapa.
     * @param coordenadaY coordenada Y no mapa.
     * @param descricaoLonga descrição específica da ameaça.
     * @param numeros quantidade de representantes da ameaça.
     * @param gravidade gravidade da ameaça.
     * @param carga tipo de carga recebida.
     * @param peso peso da carga.
     */
    public Recebimento(int coordenadaX, int coordenadaY, String descricaoLonga, int numeros, String gravidade, String carga, double peso) {
        super(coordenadaX, coordenadaY, descricaoLonga, numeros, gravidade);

        this.carga = carga;
        this.peso = peso;

        caminhoImagem = "/imagens/naboo-ship-carga.png";
        descricaoCurta = "Recebimento de cargas ou escravos pelo Império.";
    }

    /**
     * Método de acesso ao tipo de carga do recebimento.
     * @return String tipo de carga.
     */
    public String getCarga() {
        return carga;
    }

    /**
     * Método de modificação da carga do recebimento.
     * @param carga nova carga.
     */
    public void setCarga(String carga) {
        this.carga = carga;
    }

    /**
     * Método de acesso ao peso da carga.
     * @return double peso.
     */
    public double getPeso() {
        return peso;
    }

    /**
     * Método de modificação ao peso da carga.
     * @param peso novo peso.
     */
    public void setPeso(double peso) {
        this.peso = peso;
    }

    /**
     * Método da interface de acesso ao caminho da imagem de Recebimento.
     * @return String caminho da imagem.
     */
    @Override
    public String getCaminhoImagem() {
        return caminhoImagem;
    }

    /**
     * Método da interface de acesso à descrição genérica da classe.
     * @return String descrição genérica de recebimento de carga.
     */
    @Override
    public String getDescricaoCurta() {
        return descricaoCurta;
    }

    /**
     * Método de <code>Cadastravel</code> de acesso ao nome da classe.
     * @return String nome da classe.
     */
    @Override
    public String getNomeClasse(){
        return "Recebimento";
    }

}
