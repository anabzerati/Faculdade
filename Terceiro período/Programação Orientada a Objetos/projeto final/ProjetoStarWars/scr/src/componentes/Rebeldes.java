package componentes;

/**
 * Classe que representa os grupos rebeldes. Estende <code>Cadastravel</code>, sendo cadastrável no sistema e representável no mapa, e possui sua própria imagem.
 */
public class Rebeldes  extends Cadastravel {
    private final String caminhoImagem;
    private final String descricaoCurta;

    /**
     * Construtor da classe. Recebe como parâmetros os atributos do objeto e realiza a atribuição. Acrescenta o caminho do ícone que representa a classe e a descrição da ameaça, atributos constantes
     * compartilhados por todas as instancias da classe
     * @param coordenadaX coordenada X no mapa.
     * @param coordenadaY coordenada Y no mapa.
     * @param descricaoLonga descrição específica do grupo rebelde.
     * @param numeros quantidade de representantes do grupo.
     */
    public Rebeldes(int coordenadaX, int coordenadaY, String descricaoLonga, int numeros) {
        super(coordenadaX, coordenadaY, descricaoLonga, numeros);

        caminhoImagem = "/imagens/rebeldes.png";
        descricaoCurta = "Grupos resistentes ao Império.";
    }

    /**
     * Método de <code>Cadastravel</code> de acesso ao nome da classe.
     * @return String nome da classe.
     */
    @Override
    public String getNomeClasse() {
        return "Núcelo rebelde";
    }

    /**
     * Método da interface de acesso ao caminho da imagem de grupo rebelde.
     * @return String caminho da imagem.
     */
    @Override
    public String getCaminhoImagem() {
        return caminhoImagem;
    }

    /**
     * Método da interface de acesso à descrição genérica da classe.
     * @return String descrição genérica de rebeldes.
     */
    @Override
    public String getDescricaoCurta() {
        return descricaoCurta;
    }
}