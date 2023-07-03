package ui.mapa;

import componentes.Cadastravel;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.geom.RoundRectangle2D;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.Serializable;
import java.util.ArrayList;

/**
 * Classe responsável por controlar mapa e cadastros. Possui como atributos o frame, o MapPane (fundo do mapa) e uma lista de Markers cadastrados. Permite o cadastro de Markers,
 * adicionando-os à tela (ao mapa). Implemente <code>Serializable</code>, o que permite sua serialização e armazenamento.
 */
public class Tracker extends JPanel implements Serializable {
    private JFrame frame;
    private static final long serialVersionUID = 1234L;
    private MapPane paneMapa;
    private ArrayList<Marker> markers = new ArrayList<>();

    /**
     * Instancia objetos de MapPane e de JFrame, dimensionando e organizando a tela. Chama o método privado refresh, que percorre os markers cadastrados e adiciona ao mapa.
     */
    public void run() {
        paneMapa = new MapPane();

        frame = new JFrame("Mapa");
        frame.setUndecorated(true);
        frame.setSize(1200, 900);
        frame.setShape(new RoundRectangle2D.Double(10, 10, paneMapa.getWidth(), paneMapa.getHeight(), 50, 50));
        frame.setLayout(new BorderLayout());
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        frame.add(paneMapa, BorderLayout.CENTER);

        JButton voltar = new JButton();
        try {
            BufferedImage img = ImageIO.read(getClass().getResource("/imagens/botao-voltar-amarelo.png"));
            voltar.setIcon(new ImageIcon(img));
            voltar.setBorderPainted(false);
            voltar.setFocusPainted(false);
            voltar.setOpaque(false);
            voltar.setContentAreaFilled(false);
            voltar.setBorder(BorderFactory.createEmptyBorder(0, 0, 0, 0));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        voltar.addActionListener(e -> {
            paneMapa = null;
            frame.dispose();
        });

        paneMapa.setLayout(null);
        paneMapa.add(voltar);
        voltar.setBounds(new java.awt.Rectangle(20, 20, 50, 50));

        refresh();
    }


    /**
     * Método para cadastro de novos markers. Recebe o objeto a ser cadastrado e instancia um Marker, define o texto de foco com a descrição curta do objeto e o posiciona nas coordenadas determinadas.
     * @param objeto obejto que estende a classe <code>Cadastravel</code>.
     */
    public <T extends Cadastravel> void cadastrar(T objeto) {
        Marker<T> marker = new Marker<>(objeto);
        this.markers.add(marker);
    }

    /**
     * Adiciona ao mapa todos os Markers cadastrados.
     */
    public void refresh() { //quando for testar, tentar das duas formas
        for (Marker atual : markers) {
            atual.setToolTipText("<html>" + atual.getObjeto().getNomeClasse() + "<br>" + atual.getObjeto().getDescricaoCurta() + "</html>");
            UIManager.put("ToolTip.background", new Color(249, 224, 124));
            UIManager.put("ToolTip.foreground", Color.BLACK);
            UIManager.put("ToolTip.font", new Font("Arial", Font.PLAIN, 12));

            atual.setSize(atual.getPreferredSize());
            atual.setLocation(atual.getObjeto().getCoordenadaX(), atual.getObjeto().getCoordenadaY());

            paneMapa.add(atual);
        }
    }

    public <T extends Cadastravel> void excluir(T objeto) {
        for(Marker marker : markers) {
            if(marker.getObjeto().equals(objeto)){
                markers.remove(marker);
            }
        }
    }

    /**
     * Método de acesso ao frame do mapa.
     * @return <code>Jframe</code> frame do mapa.
     */
    public JFrame getFrame() {
        return frame;
    }

    /**
     * Método de acesso ao panel do mapa.
     * @return <code>MapPane</code> panel do mapa..
     */
    public MapPane getPaneMapa() {
        return paneMapa;
    }

    /**
     * Método de modificação do panel do mapa.
     * @param paneMapa objeto de <code>MapPane</code>, panel do mapa.
     */
    public void setPaneMapa(MapPane paneMapa) {
        this.paneMapa = paneMapa;
    }

    /**
     * Método de acesso à ArrayList de markers.
     * @return markers, ArrayList<Marker>
     */
    public ArrayList<Marker> getMarkers() {
        return markers;
    }

    /**
     * Método de mpdificação da ArrayList de markers.
     * @param markers nova ArrayList<Marker>
     */
    public void setMarkers(ArrayList<Marker> markers) {
        this.markers = markers;
    }

}
