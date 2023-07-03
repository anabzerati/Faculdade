package componentes;

/**
 * Representa um evento de patrulha. Estende <code>Ameaca</code> por representar uma ameaça aos rebeldes e possui atributos próprios específicos, como seu tipo.
 */
public class Patrulha  extends  Ameaca{
    private final String caminhoImagem;
    private String tipo; // reconhecimento, assalto, desconhecido
    private final String descricaoCurta;

    /**
     * Construtor da classe. Recebe como parâmetros os atributos do objeto e realiza a atribuição. Acrescenta o caminho do ícone que representa a classe e a descrição da ameaça, atributos constantes
     * compartilhados por todas as instancias da classe.
     * @param coordenadaX coordenada X no mapa.
     * @param coordenadaY coordenada Y no mapa.
     * @param descricaoLonga descrição específica da ameaça.
     * @param numeros quantidade de representantes da ameaça.
     * @param gravidade gravidade da ameaça.
     * @param tipo tipo da patrulha.
     */
    public Patrulha(int coordenadaX, int coordenadaY, String descricaoLonga, int numeros, String gravidade, String tipo) {
        super(coordenadaX, coordenadaY, descricaoLonga, numeros, gravidade);

        this.tipo = tipo;

        caminhoImagem = "/imagens/nave-combate-patrulha.png";
        descricaoCurta = "Operações realizadas pelo Império de reconhecimento ou assalto.";
    }

    /**
     * Método de acesso ao tipo da patrulha.
     * @return String tipo da patrulha.
     */
    public String getTipo() {
        return tipo;
    }

    /**
     * Método de modificação do tipo da patrulha.
     * @param tipo novo tipo.
     */
    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    /**
     * Método da interface de acesso ao caminho da imagem de Patrulha.
     * @return String caminho da imagem.
     */
    @Override
    public String getCaminhoImagem() {
        return this.caminhoImagem;
    }

    /**
     * Método da interface de acesso à descrição genérica da classe.
     * @return String descrição genérica de patrulha.
     */
    @Override
    public String getDescricaoCurta() {
        return this.descricaoCurta;
    }

    /**
     * Método de <code>Cadastravel</code> de acesso ao nome da classe.
     * @return String nome da classe.
     */
    @Override
    public String getNomeClasse(){
        return "Patrulha";
    }
}
