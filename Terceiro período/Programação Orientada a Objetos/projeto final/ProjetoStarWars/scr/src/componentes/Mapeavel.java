package componentes;

/**
 * Interface que determina métodos necessários para representação de um objeto em um mapa (como coordenadas, caminho do ícone do marcador e descrição).
 */
public interface Mapeavel {
    /**
     * Método de acesso à coordenada X do objeto no mapa.
     * @return int coordenada X.
     */
    int getCoordenadaX();

    /**
     * Método de modificação da coordenada X do objeto no mapa.
     * @param coordX nova coordenada X do objeto.
     */
    void setCoordenadaX(int coordX);

    /**
     * Método de acesso à coordenada Y do objeto no mapa.
     * @return int coordenada Y.
     */
    int getCoordenadaY();

    /**
     * Método de modificação da coordenada Y do objeto no mapa.
     * @param coordY nova coordenada Y do objeto.
     */
    void setCoordenadaY(int coordY);

    /**
     * Método de acesso caminho da imagem do objeto no mapa.
     * @return String caminho da imagem.
     */
    String getCaminhoImagem();

    /**
     * Método de acesso à descrição do objeto no mapa.
     * @return String descrição.
     */
    String getDescricaoCurta();
}
