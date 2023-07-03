package ui.mapa;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.image.BufferedImage;
import java.awt.*;
import java.io.Serializable;

/**
* Representa o fundo do mapa, estendendo <code>JLayeredPane</code> para adição de icones sobre o mapa e <code>Serializable</code> para serialização e armazenamento.
* */
public class MapPane extends JLayeredPane implements Serializable {
    private transient BufferedImage mapa;
    private static final long serialVersionUID = 1234L;

    /**
     * Construtor da classe. Atribui a imagem do mapa.
     */
    public MapPane(){
        try {
            mapa = ImageIO.read(getClass().getResource("/imagens/mapa.png"));
        } catch (Exception e) {
            System.out.println(e);
        }
    }

    /**
     * Método de acesso ao tamanho do mapa.
     * @return Dimension tamanho do mapa.
     */
    @Override
    public Dimension getPreferredSize() {
        return mapa == null ? super.getPreferredSize() : new Dimension(mapa.getWidth(), mapa.getHeight());
    }

    /**
     * Método para apresentar a imagem do mapa.
     * @param g the <code>Graphics</code> object to protect
     */
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (mapa != null) {
            g.drawImage(mapa, 0, 0, this);
        }
    }
}
