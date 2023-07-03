package componentes;

/**
 * Classe que representa um evento Blitz. Estende <code>Ameaca</code> por representar uma ameaça aos rebeldes e possui atributos próprios específicos, como o tipo de veículo da blitz.
 */
public class Blitz extends Ameaca {
    private String veiculo;
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
     * @param veiculo veículos da Blitz.
     */
    public Blitz(int coordenadaX, int coordenadaY, String descricaoLonga, int numeros, String gravidade, String veiculo) {
        super(coordenadaX, coordenadaY, descricaoLonga, numeros, gravidade);

        this.veiculo = veiculo;

        caminhoImagem = "/imagens/walker-blitz.png";
        descricaoCurta = "Paradas em estradas por tropas imperiais para revistar cidadãos.";
    }

    /**
     * Método de acesso ao veículo da Blitz.
     * @return String nome do veículo.
     */
    public String getVeiculo() {
        return veiculo;
    }

    /**
     * Método para modificação do veículo da Blitz.
     * @param veiculo novo veículo.
     */
    public void setVeiculo(String veiculo) {
        this.veiculo = veiculo;
    }

    /**
     * Método de acesso ao caminho da imagem da Blitz.
     * @return String caminho da imagem.
     */
    @Override
    public String getCaminhoImagem() {
        return caminhoImagem;
    }

    /**
     * Método de acesso à descrição curta da Blitz.
     * @return String descrição genérica da classe.
     */
    @Override
    public String getDescricaoCurta() {
        return descricaoCurta;
    }

    /**
     * Método de acesso ao nome da classe.
     * @return String nome da classe.
     */
    @Override
    public String getNomeClasse(){
        return "Blitz";
    }
}
