package ui.mapa;

import componentes.Cadastravel;

import javax.imageio.ImageIO;
import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.LineBorder;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.Serializable;

/**
* Classe abstrata que representa marcadores de mapa, estendendo JLabel. Possui como atributos o objeto que representa e seu ícone.
* */
public class Marker <T extends Cadastravel> extends JLabel implements Serializable {
    private T objeto;
    private ImageIcon imagem;
    private static final long serialVersionUID = 1234L;

    /**
     * Construtor da classe. Recebe o objeto (Cadastravel) que o marcador representa e armazena ele e sua imagem.
     * @param objeto objeto que o marcador representa.
     */
    public Marker(T objeto) {
        this.objeto = objeto;
        try {
            imagem = new ImageIcon(ImageIO.read(getClass().getResource(objeto.getCaminhoImagem())));
            setIcon(imagem);

            setBorder(BorderFactory.createLineBorder(Color.white, 2));
        } catch (Exception e) {
        }
    }

    /**
     * Método de acesso ao objeto armazenado.
     * @return T objeto que estende <code>Cadastravel</code>.
     */
    public T getObjeto() {
        return objeto;
    }

    /**
     * Método de modificação do objeto armazenado.
     * @param objeto objeto que estende <code>Cadastravel</code>.
     */
    public void setObjeto(T objeto) {
        this.objeto = objeto;
    }

    /**
     * Método de acesso à imagem.
     * @return <code>ImageIcon</code> imagem do objeto.
     */
    public ImageIcon getImagem() {
        return imagem;
    }
}
