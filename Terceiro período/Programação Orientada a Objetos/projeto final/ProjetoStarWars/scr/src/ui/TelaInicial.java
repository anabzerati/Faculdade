package ui;
import services.Util;
import ui.mapa.Tracker;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.geom.RoundRectangle2D;
import java.io.IOException;

/**
 * Tela inicial da aplicação. Apresenta opções e redireciona para a tela da escolhida.
 * Em particular, a opção de sair realiza o salvamento do Tracker em um arquivo serializável.
 * */
public class TelaInicial extends JFrame {

    /**
     * Construtor da classe. Dimensiona o frame, adiciona fundo e os botões (e seus eventos). Recebe o objeto de <code>Tracker</code> lido do arquivo.
     * @param tracker objeto lido do arquivo.
     * */
    public TelaInicial(Tracker tracker){
        this.setSize(1200, 900);
        this.setLocationRelativeTo(null);
        setUndecorated(true);
        setShape(new RoundRectangle2D.Double(10, 10, getWidth(),getHeight(), 50, 50));

        JPanel opcoes = new JPanel();
        opcoes.setLayout(new BoxLayout(opcoes, BoxLayout.Y_AXIS));
        opcoes.setOpaque(false);

        PanelFundo fundo = new PanelFundo();
        fundo.setLayout(new BorderLayout());

        JButton botaoMapa = new JButton();
        JButton botaoCadastro = new JButton();
        JButton botaoLista = new JButton();
        JButton botaoSair = new JButton();

        try {
            Image botaoMapaImg = ImageIO.read(getClass().getResource("/imagens/visualizar mapa.png"));
            Image botaoCadastroImg = ImageIO.read(getClass().getResource("/imagens/cadastrar.png"));
            Image botaoListaImg = ImageIO.read(getClass().getResource("/imagens/visualizar lista.png"));
            Image botaoSairImg = ImageIO.read(getClass().getResource("/imagens/sair.png"));

            botaoMapa.setIcon(new ImageIcon(botaoMapaImg));
            botaoMapa.setBackground(Color.black);
            botaoMapa.setBorderPainted(false);
            botaoMapa.setFocusPainted(false);
            botaoMapa.setOpaque(false);
            botaoMapa.setContentAreaFilled(false);

            Image botaoMapaImgHover = ImageIO.read(getClass().getResource("/imagens/visualizar mapa hover.png"));
            botaoMapa.setRolloverIcon(new ImageIcon(botaoMapaImgHover));
            botaoMapa.setPressedIcon(new ImageIcon(botaoMapaImgHover));

            botaoCadastro.setIcon(new ImageIcon(botaoCadastroImg));
            botaoCadastro.setBackground(Color.black);
            botaoCadastro.setBorderPainted(false);
            botaoCadastro.setFocusPainted(false);
            botaoCadastro.setOpaque(false);
            botaoCadastro.setContentAreaFilled(false);

            Image botaoCadastroImgHover = ImageIO.read(getClass().getResource("/imagens/cadastrar hover.png"));
            botaoCadastro.setRolloverIcon(new ImageIcon(botaoCadastroImgHover));
            botaoCadastro.setPressedIcon(new ImageIcon(botaoCadastroImgHover));

            botaoLista.setIcon(new ImageIcon(botaoListaImg));
            botaoLista.setBackground(Color.black);
            botaoLista.setBorderPainted(false);
            botaoLista.setFocusPainted(false);
            botaoLista.setOpaque(false);
            botaoLista.setContentAreaFilled(false);

            Image botaoListaImgHover = ImageIO.read(getClass().getResource("/imagens/visualizar lista hover.png"));
            botaoLista.setRolloverIcon(new ImageIcon(botaoListaImgHover));
            botaoLista.setPressedIcon(new ImageIcon(botaoListaImgHover));

            botaoSair.setIcon(new ImageIcon(botaoSairImg));
            botaoSair.setBackground(Color.black);
            botaoSair.setBorderPainted(false);
            botaoSair.setFocusPainted(false);
            botaoSair.setOpaque(false);
            botaoSair.setContentAreaFilled(false);

            Image botaoSairImgHover = ImageIO.read(getClass().getResource("/imagens/sair hover.png"));
            botaoSair.setRolloverIcon(new ImageIcon(botaoSairImgHover));
            botaoSair.setPressedIcon(new ImageIcon(botaoSairImgHover));
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        botaoSair.addActionListener(e -> {
            Util.writeFile(tracker);
            System.exit(0);
        });

        botaoMapa.addActionListener(e -> {
            tracker.run();
        });

        botaoLista.addActionListener(e -> {
            new ListarInformacoes(tracker);
        });

        botaoCadastro.addActionListener(e -> {
            new Cadastrar(tracker);
        });

        opcoes.add(botaoMapa);
        opcoes.add(Box.createRigidArea(new Dimension(0, 15)));

        opcoes.add(botaoCadastro);
        opcoes.add(Box.createRigidArea(new Dimension(0, 15)));

        opcoes.add(botaoLista);
        opcoes.add(Box.createRigidArea(new Dimension(0, 15)));

        opcoes.add(botaoSair);
        opcoes.add(Box.createRigidArea(new Dimension(0, 30)));

        opcoes.add(Box.createRigidArea(new Dimension(10, 0)));

        fundo.add(opcoes, BorderLayout.PAGE_END);

        this.add(fundo);
        this.setVisible(true);
    }
}