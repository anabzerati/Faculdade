package ui;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.net.URL;

/**
 * Classe que representa o painel usado como fundo no sistema. Estende <code>JLayeredPane</code>, o que permite a sobreposição de outros elementos, e possui como atributo a foto de fundo.
 */
public class PanelFundo extends JLayeredPane {
    private BufferedImage fundo;

    /**
     * Construtor da classe. Atribui ao fundo a imagem.
     */
    public PanelFundo() {
        try {
            URL url = getClass().getResource("/imagens/fundo-galaxia-preto.png");
            fundo = ImageIO.read(url);
        } catch (IOException e) {
            System.out.println(e);;
        }
    }

    /**
     * Desenha a imagem da maneira desejada para representação.
     * @param g the <code>Graphics</code> object to protect.
     */
    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (fundo != null)
        {
            g.drawImage(fundo, 0, 0, getWidth(), getHeight(), this);
        }
    }

    /**
     * Método de acesso à imagem de fundo.
     * @return <code>BufferedImage</code> imagem de fundo
     */
    public BufferedImage getFundo() {
        return fundo;
    }
}


