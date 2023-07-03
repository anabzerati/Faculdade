package componentes;

/**
 * Classe que representa um evento de Combate. Estende <code>Ameaca</code> por representar uma ameaça aos rebeldes e possui atributos próprios específicos, como a quantidade de
 * aliados no comabte e sua situação geral.
 */
public class Combate extends Ameaca {
    private int quantidadeAliados;
    private String situacaoGeral;
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
     * @param quantidadeAliados quantidade de aliados no combate.
     * @param situacaoGeral situação geral do combate.
     */
    public Combate(int coordenadaX, int coordenadaY, String descricaoLonga, int numeros, String gravidade, int quantidadeAliados, String situacaoGeral) {
        super(coordenadaX, coordenadaY, descricaoLonga, numeros, gravidade);

        this.quantidadeAliados = quantidadeAliados;
        this.situacaoGeral = situacaoGeral;

        caminhoImagem = "/imagens/sabre-de-luz-combate.png";
        descricaoCurta = "Confonto entre rebeldes e tropas imperiais.";
    }

    /**
     * Método de acesso à quantidade de aliados.
     * @return int quantidade de aliados.
     */
    public int getQuantidadeAliados() {
        return quantidadeAliados;
    }

    /**
     * Método de modificação da quantidade de aliados.
     * @param quantidadeAliados nova quantidade de aliados.
     */
    public void setQuantidadeAliados(int quantidadeAliados) {
        this.quantidadeAliados = quantidadeAliados;
    }

    /**
     * Método de acesso à situação geral do combate.
     * @return String situação geral.
     */
    public String getSituacaoGeral() {
        return situacaoGeral;
    }

    /**
     * Método de modificação da situação geral do combate.
     * @param situacaoGeral nova situação geral.
     */
    public void setSituacaoGeral(String situacaoGeral) {
        this.situacaoGeral = situacaoGeral;
    }

    /**
     * Método da interface de acesso ao caminho da imagem de Combate.
     * @return String caminho da imagem.
     */
    @Override
    public String getCaminhoImagem() {
        return caminhoImagem;
    }

    /**
     * Método da interface de acesso à descrição genérica da classe.
     * @return String descrição genérica de combate.
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
        return "Combate";
    }
}
