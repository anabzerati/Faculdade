package componentes;

/**
 * Classe que representa uma operação de marcha. Estende <code>Ameaca</code> por representar uma ameaça aos rebeldes e possui atributos próprios específicos, como o tamanho da marcha.
 */
public class Marcha extends  Ameaca{
private final String caminhoImagem;

private final String descricaoCurta;
private double tamanhoMarcha;

    /**
     * Construtor da classe. Recebe como parâmetros os atributos do objeto e realiza a atribuição. Acrescenta o caminho do ícone que representa a classe e a descrição da ameaça, atributos constantes
     * compartilhados por todas as instancias da classe.
     * @param coordenadaX coordenada X no mapa.
     * @param coordenadaY coordenada Y no mapa.
     * @param descricaoLonga descrição específica da ameaça.
     * @param numeros quantidade de representantes da ameaça.
     * @param gravidade gravidade da ameaça.
     * @param tamanhoMarcha tamanho da marcha realizada em km.
     */
    public Marcha(int coordenadaX, int coordenadaY, String descricaoLonga, int numeros, String gravidade, double tamanhoMarcha) {
        super(coordenadaX, coordenadaY, descricaoLonga, numeros, gravidade);

        this.tamanhoMarcha = tamanhoMarcha;

        caminhoImagem = "/imagens/stormtrooper-marcha.png";
        descricaoCurta = "Desfile da tropa em operação ou demonstração da força imperial.";
    }

    /**
     * Método de acesso ao tamanho da marcha.
     * @return tamanho da marcha em KM.
     */
    public double getTamanhoMarcha() {
        return tamanhoMarcha;
    }

    /**
     * Método de modificação do tamanho da marcha.
     * @param tamanhoMarcha novo tamanho da marcha.
     */
    public void setTamanhoMarcha(double tamanhoMarcha) {
        this.tamanhoMarcha = tamanhoMarcha;
    }

    /**
     * Método da interface de acesso ao caminho da imagem de Combate.
     * @return String caminho da imagem.
     */
    @Override
    public String getCaminhoImagem() {
        return this.caminhoImagem;
    }

    /**
     * Método da interface de acesso à descrição genérica da classe.
     * @return String descrição genérica de marcha.
     */
    @Override
    public String getDescricaoCurta() { return this.descricaoCurta; }

    /**
     * Método de <code>Cadastravel</code> de acesso ao nome da classe.
     * @return String nome da classe.
     */
    @Override
    public String getNomeClasse(){
        return "Marcha";
    }
}
